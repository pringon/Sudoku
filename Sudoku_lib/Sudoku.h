class Sudoku;

#ifndef SUDOKU_H
#define SUDOKU_H

#include <QString>
#include <QTimer>
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include "win_window.h"
#include "Board.h"

class Sudoku : public QWidget {
Q_OBJECT
friend class WinWindow;

private:
  Board *sudokuGrid;
  QGroupBox *sudokuPuzzleGroup;
  QGroupBox *buttonsGroup;
  QGroupBox *timerGroup;
  QLabel *timerLabel;
  int seconds;
  int minutes;
  int hours;

public:
  Sudoku(QWidget *parent = 0);

protected slots:
  virtual void openWinWindow();
  virtual void timerUpdate();
  virtual void selectGame();
  virtual void saveGame();
  virtual void solveGame();
  virtual void restartGame();
  virtual void closeGame();

signals:
  void puzzleSelected(std::string puzzlePath);
  void puzzleSaved(std::string puzzlePath);
  void solveRequest();
};

#endif
