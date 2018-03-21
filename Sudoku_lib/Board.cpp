#include "Board.h"
#include "Cell.h"
#include <iostream>
#include <fstream>

Board::Board(QWidget* parent, std::string puzzlePath) : QGridLayout(parent) {
  std::ifstream in(puzzlePath);
  int cellValue,
      boxNumber;

  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {

      boxNumber = (i/3)*3 + (j/3);

      in>>cellValue;
      Cell *label = new Cell(parent, i, j, cellValue);
      this->addWidget(label, i, j);
      this->rows[i].addCell(label);
      this->columns[j].addCell(label);
      this->boxes[boxNumber].addCell(label);
      QObject::connect(label, &Cell::valueChanged,
                       this, &Board::checkCell);

     this->rows[i].setColor(false);
     this->columns[i].setColor(false);
     this->boxes[i].setColor(false);
    }
  }

  in.close();
}

bool Board::checkWin() {
  for(int i = 0; i < 9; i++) {
    if((this->rows[i].checkSameValues() ||
        this->columns[i].checkSameValues() ||
        this->boxes[i].checkSameValues()) ||
        this->rows[i].checkZeroes() ||
        this->columns[i].checkZeroes() ||
        this->boxes[i].checkZeroes()) {
      return false;
    }
  }
  return true;
}

bool Board::backtrackPuzzle() {

  for(int i = 0; i < 9; i++) {
    std::vector<Cell*>::iterator it = rows[i].iterateCells(0);
    std::vector<Cell*>::iterator end = rows[i].iterateCells(-1);

    while(it != end) {

      if((*it)->isClickable() && !(*it)->wasBacktracked()) {
        (*it)->toggleBacktracked();
        for(int j = 0; j < 9; j++) {
          if(this->backtrackPuzzle()) {
            return true;
          }
          (*it)->incrementValue();
        }
        (*it)->toggleBacktracked();
        return false;
      }
      it++;
    }
  }

  if(this->checkWin()) {
    return true;
  }
  return false;
}

void Board::repaint() {
  for(int i = 0; i < 9; i++) {
    if(this->rows[i].isRed()) {
      this->rows[i].paint("red");
    }
    if(this->columns[i].isRed()) {
      this->columns[i].paint("red");
    }
    if(this->boxes[i].isRed()) {
      this->boxes[i].paint("red");
    }
  }
}

void Board::openPuzzle(std::string puzzlePath) {

  QLayoutItem *item;
  while((item = this->takeAt(0)) != NULL) {
    delete item->widget();
    delete item;
  }

  std::ifstream in(puzzlePath);
  int cellValue,
      boxNumber;

  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {

      boxNumber = (i/3)*3 + (j/3);

      in>>cellValue;
      Cell *label = new Cell(this->parentWidget(), i, j, cellValue);
      this->addWidget(label, i, j);
      this->rows[i].addCell(label);
      this->columns[j].addCell(label);
      this->boxes[boxNumber].addCell(label);
      QObject::connect(label, &Cell::valueChanged,
                       this, &Board::checkCell);

     this->rows[i].setColor(false);
     this->columns[i].setColor(false);
     this->boxes[i].setColor(false);
    }
  }

  in.close();
}

void Board::savePuzzle(std::string puzzlePath) {
  std::ofstream out(puzzlePath);

  for(int i = 0; i < 9; i++) {
    std::vector<Cell*>::iterator it = this->rows[i].iterateCells(0);
    std::vector<Cell*>::iterator end = this->rows[i].iterateCells(-1);
    while(it != end) {
      out<<(*it)->getValue()<<' ';
      it++;
    }
    out<<'\n';
  }

  out.close();
}

void Board::solvePuzzle() {
  if(this->backtrackPuzzle()) {
    std::cout<<"Solved!";
  } else {
    std::cout<<"Can't be solved";
  }
}

void Board::checkCell(int row, int column) {
  bool notDuplicate = true;

  if(rows[row].checkSameValues()) {
    notDuplicate = false;
    this->rows[row].setColor(true);
  } else {
    this->rows[row].setColor(false);
  }

  if(columns[column].checkSameValues()) {
    notDuplicate = false;
    this->columns[column].setColor(true);
  } else {
    this->columns[column].setColor(false);
  }

  int boxNumber = (row/3)*3 + (column/3);
  if(boxes[boxNumber].checkSameValues()) {
    notDuplicate = false;
    this->boxes[boxNumber].setColor(true);
  } else {
    this->boxes[boxNumber].setColor(false);
  }

  rows[row].paint("black");
  columns[column].paint("black");
  boxes[boxNumber].paint("black");

  this->repaint();

  if(notDuplicate && this->checkWin()) {
    emit sudokuSolved();
  }
}
