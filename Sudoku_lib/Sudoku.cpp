#include "Sudoku.h"
#include "Board.h"
#include <QCoreApplication>

Sudoku::Sudoku(QWidget *parent)
    : QWidget(parent) {

  Board *grid = new Board(this);

  QObject::connect(grid, &Board::sudokuSolved,
                   this, &Sudoku::closeGame);

  setLayout(grid);
}

void Sudoku::closeGame() {

  QCoreApplication::exit();
}
