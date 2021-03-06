#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <QLabel>

class Cell : public QLabel {
Q_OBJECT
private:
  int row;
  int column;
  int value;
  bool clickable;
  bool backtracked;

public:
  Cell(QWidget* parent, int row, int column, int value);
  int getValue();
  void incrementValue();
  bool wasBacktracked();
  void toggleBacktracked();
  bool isClickable();

protected slots:
  virtual void resizeEvent(QResizeEvent *event);
  virtual void mousePressEvent(QMouseEvent *event);

signals:
  void valueChanged(int row, int column);
};

#endif
