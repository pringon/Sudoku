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
    }
  }

  in.close();
}

bool Board::checkWin() {
  for(int i = 0; i < 9; i++) {
    if(this->rows[i].checkSameValues() ||
        this->columns[i].checkSameValues() ||
        this->boxes[i].checkSameValues()) {
      return false;
    }
  }
  return true;
}

void Board::checkCell(int row, int column) {
  bool notDuplicate = true;

  if(rows[row].checkSameValues()) {
    notDuplicate = false;
    rows[row].paint("red");
  } else {
    rows[row].paint("black");
  }

  if(columns[column].checkSameValues()) {
    notDuplicate = false;
    columns[column].paint("red");
  } else {
    columns[column].paint("black");
  }

  int boxNumber = (row/3)*3 + (column/3);
  if(boxes[boxNumber].checkSameValues()) {
    notDuplicate = false;
    boxes[boxNumber].paint("red");
  } else {
    boxes[boxNumber].paint("black");
  }

  if(notDuplicate && this->checkWin()) {
    emit sudokuSolved();
  }
}
