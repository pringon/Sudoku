#ifndef SUDOKU_H
#define SUDOKU_H

#include <QString>
#include <QTimer>
#include <QWidget>
#include <QLabel>
#include <QGroupBox>

class Sudoku : public QWidget {
Q_OBJECT

private:
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
  virtual void timerUpdate();
  virtual void selectGame();
  virtual void saveGame();
  virtual void solveGame();
  virtual void closeGame();

signals:
  void puzzleSelected(std::string puzzlePath);
  void puzzleSaved(std::string puzzlePath);
  void solveRequest();
};

#endif
