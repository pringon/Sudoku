#ifndef SUDOKU_H
#define SUDOKU_H

#include <QWidget>
#include <QGroupBox>

class Sudoku : public QWidget {
Q_OBJECT

private:
  QGroupBox *sudokuPuzzleGroup;
  QGroupBox *buttonsGroup;

public:
  Sudoku(QWidget *parent = 0);

protected slots:
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
