#include "Sudoku.h"
#include "Board.h"
#include <QCoreApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QFileDialog>

Sudoku::Sudoku(QWidget *parent)
    : QWidget(parent) {

  QVBoxLayout *windowLayout = new QVBoxLayout(this);

  sudokuPuzzleGroup = new QGroupBox();
  Board *sudokuGrid = new Board(this);
  QSizePolicy sudokuPuzzleGroupHeight(QSizePolicy::Preferred, QSizePolicy::Preferred);
  sudokuPuzzleGroupHeight.setVerticalStretch(9);
  sudokuPuzzleGroup->setSizePolicy(sudokuPuzzleGroupHeight);
  QObject::connect(sudokuGrid, &Board::sudokuSolved,
                   this, &Sudoku::closeGame);
  QObject::connect(this, &Sudoku::puzzleSelected,
                   sudokuGrid, &Board::redrawPuzzle);
  sudokuPuzzleGroup->setLayout(sudokuGrid);

  buttonsGroup = new QGroupBox();
  QHBoxLayout *horizontalButtonsBox = new QHBoxLayout(this);
  QSizePolicy buttonsGroupHeight(QSizePolicy::Preferred, QSizePolicy::Preferred);
  buttonsGroupHeight.setVerticalStretch(1);
  buttonsGroup->setSizePolicy(buttonsGroupHeight);

  QPushButton *selectGame = new QPushButton(tr("Upload puzzle!"), this);
  horizontalButtonsBox->addWidget(selectGame);
  QObject::connect(selectGame, &QPushButton::released,
                   this,       &Sudoku::selectGame);
  buttonsGroup->setLayout(horizontalButtonsBox);

  windowLayout->addWidget(sudokuPuzzleGroup);
  windowLayout->addWidget(buttonsGroup);

  this->setLayout(windowLayout);
}

void Sudoku::selectGame() {
  std::string puzzlePath;
  puzzlePath = QFileDialog::getOpenFileName(this, tr("Pick a puzzle!")).toUtf8().constData();
  if(!puzzlePath.empty()) {
    emit puzzleSelected(puzzlePath);
  }
}

void Sudoku::closeGame() {

  QCoreApplication::exit();
}
