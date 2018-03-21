#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QGridLayout>
#include <string>
#include "Group.h"
#include "Sudoku.h"

class Board : public QGridLayout {
Q_OBJECT
friend class Sudoku;

private:
  Group rows[9];
  Group columns[9];
  Group boxes[9];
  bool checkWin();
  bool backtrackPuzzle();
  void repaint();

public:
  Board(QWidget* parent = 0, std::string puzzlePath = "./saved_puzzles/test.txt");

protected slots:
  virtual void openPuzzle(std::string puzzlePath);
  virtual void savePuzzle(std::string puzzlePath);
  virtual void solvePuzzle();
  virtual void checkCell(int row, int column);

signals:
  void sudokuSolved();
};

#endif
