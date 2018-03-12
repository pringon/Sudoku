#include <QApplication>
#include <QDesktopWidget>
#include <QIcon>
#include "Sudoku_lib/Sudoku.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  QDesktopWidget screen;
  Sudoku window;

  window.resize(screen.width()*0.5, screen.height()*0.5);
  window.setWindowTitle("Sudoku");
  window.setWindowIcon(QIcon("SudokuIcon.png"));
  window.show();

  return app.exec();
}
