#include "Board.h"
#include "Cell.h"
#include <fstream>

Board::Board(QWidget* parent) : QGridLayout(parent) {
  std::ifstream in("./Sudoku_lib/game.txt");
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

     this->redRows[i] = false;
     this->redColumns[i] = false;
     this->redBoxes[i] = false;
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

void Board::checkCell(int row, int column) {
  bool notDuplicate = true;

  if(rows[row].checkSameValues()) {
    notDuplicate = false;
    this->redRows[row] = true;
  } else {
    this->redRows[row] = false;
  }

  if(columns[column].checkSameValues()) {
    notDuplicate = false;
    this->redColumns[column] = true;
  } else {
    this->redColumns[column] = false;
  }

  int boxNumber = (row/3)*3 + (column/3);
  if(boxes[boxNumber].checkSameValues()) {
    notDuplicate = false;
    this->redBoxes[boxNumber] = true;
  } else {
    this->redBoxes[boxNumber] = false;
  }

  rows[row].paint("black");
  columns[column].paint("black");
  boxes[boxNumber].paint("black");

  this->repaint();

  if(notDuplicate && this->checkWin()) {
    emit sudokuSolved();
  }
}

void Board::repaint() {
  for(int i = 0; i < 9; i++) {
    if(this->redRows[i]) {
      this->rows[i].paint("red");
    }
    if(this->redColumns[i]) {
      this->columns[i].paint("red");
    }
    if(this->redBoxes[i]) {
      this->boxes[i].paint("red");
    }
  }
}
