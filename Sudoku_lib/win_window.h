#ifndef WIN_WINDOW_H
#define WIN_WINDOW_H

#include <iostream>
#include "Sudoku.h"
#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QGroupBox>
#include <QLabel>

class WinWindow : public QDialog {
Q_OBJECT
friend class Sudoku;

private:
  QGroupBox *scoreGroup;
  QGroupBox *buttonsGroup;
  QLabel *scoreLabel;

public:
  WinWindow(QWidget *parent = 0, int = 0, int = 0, int = 0);

signals:
  void restartButtonPressed();
  void closeButtonPressed();

protected slots:
  virtual void hideWindow();
};

#endif
