#include "Sudoku.h"
#include <QCoreApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QFileDialog>

Sudoku::Sudoku(QWidget *parent)
    : QWidget(parent) {

  QVBoxLayout *windowLayout = new QVBoxLayout(this);

  hours = 0;
  minutes = 0;
  seconds = 0;
  timerGroup = new QGroupBox();
  QHBoxLayout *timerBox = new QHBoxLayout(this);
  QSizePolicy timerGroupHeight(QSizePolicy::Preferred, QSizePolicy::Preferred);
  timerGroupHeight.setVerticalStretch(1);
  timerGroup->setSizePolicy(timerGroupHeight);
  timerLabel = new QLabel(QString("%1:%2:%3").arg(QString::number(hours))
                                                .arg(QString::number(minutes))
                                                .arg(QString::number(seconds)));
  timerLabel->setAlignment(Qt::AlignCenter);
  QTimer *timer = new QTimer(this);
  QObject::connect(timer, SIGNAL(timeout()),
                   this,  SLOT(timerUpdate()));
  timer->start(1000);
  timerBox->addWidget(timerLabel);
  timerGroup->setLayout(timerBox);

  sudokuPuzzleGroup = new QGroupBox();
  sudokuGrid = new Board(this);
  QSizePolicy sudokuPuzzleGroupHeight(QSizePolicy::Preferred, QSizePolicy::Preferred);
  sudokuPuzzleGroupHeight.setVerticalStretch(8);
  sudokuPuzzleGroup->setSizePolicy(sudokuPuzzleGroupHeight);
  QObject::connect(this, &Sudoku::puzzleSelected,
                   sudokuGrid, &Board::openPuzzle);
  QObject::connect(this, &Sudoku::puzzleSaved,
                   sudokuGrid, &Board::savePuzzle);
  QObject::connect(this,       &Sudoku::solveRequest,
                   sudokuGrid, &Board::solvePuzzle);
  QObject::connect(sudokuGrid, &Board::sudokuSolved,
                   this,       &Sudoku::openWinWindow);
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
  QPushButton *saveGame = new QPushButton(tr("Save puzzle!"), this);
  horizontalButtonsBox->addWidget(saveGame);
  QObject::connect(saveGame, &QPushButton::released,
                   this,     &Sudoku::saveGame);
  QPushButton *solveGame = new QPushButton(tr("Solve puzzle!"), this);
  horizontalButtonsBox->addWidget(solveGame);
  QObject::connect(solveGame, &QPushButton::released,
                   this,      &Sudoku::solveGame);
  buttonsGroup->setLayout(horizontalButtonsBox);

  windowLayout->addWidget(timerGroup);
  windowLayout->addWidget(sudokuPuzzleGroup);
  windowLayout->addWidget(buttonsGroup);

  this->setLayout(windowLayout);
}

void Sudoku::openWinWindow() {

  WinWindow popup_dialog(this, hours, minutes, seconds);
  popup_dialog.setModal(true);
  popup_dialog.exec();
}

void Sudoku::timerUpdate() {
  seconds++;
  if(seconds == 60) {
    seconds = 0;
    minutes++;
  }
  if(minutes == 60) {
    minutes = 0;
    hours++;
  }

  timerLabel->clear();
  timerLabel->setText(QString("%1:%2:%3").arg(QString::number(hours))
                                    .arg(QString::number(minutes))
                                    .arg(QString::number(seconds)));
}

void Sudoku::selectGame() {
  std::string puzzlePath;
  puzzlePath = QFileDialog::getOpenFileName(this, tr("Pick a puzzle!")).toUtf8().constData();
  if(!puzzlePath.empty()) {
    emit puzzleSelected(puzzlePath);
  }
}

void Sudoku::saveGame() {
  std::string puzzlePath;
  puzzlePath = QFileDialog::getSaveFileName(this, tr("Pick a location to save puzzle!"))
                                    .toUtf8().constData();
  if(!puzzlePath.empty()) {
    emit puzzleSaved(puzzlePath);
  }
}

void Sudoku::solveGame() {
  emit solveRequest();
}

void Sudoku::restartGame() {
  hours = 0;
  minutes = 0;
  seconds = 0;
}

void Sudoku::closeGame() {

  QCoreApplication::exit();
}
