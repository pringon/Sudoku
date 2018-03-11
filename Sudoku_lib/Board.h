#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QGridLayout>
#include "Group.h"

class Board : public QGridLayout {
Q_OBJECT
private:
  Group rows[9];
  Group columns[9];
  Group boxes[9];
  bool checkWin();

public:
  Board(QWidget* parent = 0);

protected slots:
  virtual void checkCell(int row, int column);

signals:
  void sudokuSolved();
};

#endif
