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
  void repaint();

public:
  Board(QWidget* parent = 0, std::string puzzlePath = "./Sudoku_lib/game.txt");

protected slots:
  virtual void redrawPuzzle(std::string puzzlePath);
  virtual void savePuzzle(std::string puzzlePath);
  virtual void checkCell(int row, int column);

signals:
  void sudokuSolved();
};

#endif
