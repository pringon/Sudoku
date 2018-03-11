#ifndef SUDOKU_H
#define SUDOKU_H

#include <QWidget>

class Sudoku : public QWidget {
Q_OBJECT

public:
  Sudoku(QWidget *parent = 0);

protected slots:
  virtual void closeGame();
};

#endif
