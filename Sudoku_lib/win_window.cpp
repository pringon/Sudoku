#include "win_window.h"

WinWindow::WinWindow(QWidget *parent, int hours, int minutes, int seconds)
      : QDialog(parent) {

  QVBoxLayout *windowLayout = new QVBoxLayout(this);

  scoreGroup = new QGroupBox();
  QHBoxLayout *scoreBox = new QHBoxLayout(this);
  QSizePolicy scoreGroupHeight(QSizePolicy::Preferred, QSizePolicy::Preferred);
  scoreGroupHeight.setVerticalStretch(1);
  scoreGroup->setSizePolicy(scoreGroupHeight);
  scoreLabel = new QLabel(QString("%1:%2:%3").arg(QString::number(hours))
                                    .arg(QString::number(minutes))
                                    .arg(QString::number(seconds)));
  scoreLabel->setAlignment(Qt::AlignCenter);
  scoreBox->addWidget(scoreLabel);
  scoreGroup->setLayout(scoreBox);


  buttonsGroup = new QGroupBox();
  QHBoxLayout *buttonsBox = new QHBoxLayout(this);
  QSizePolicy buttonsGroupHeight(QSizePolicy::Preferred, QSizePolicy::Preferred);
  buttonsGroupHeight.setVerticalStretch(1);
  buttonsGroup->setSizePolicy(buttonsGroupHeight);

  QPushButton *restartGame = new QPushButton(tr("Restart game!"), this);
  buttonsBox->addWidget(restartGame);
  QObject::connect(restartGame, &QPushButton::released,
                   this,        &WinWindow::hideWindow);
  QObject::connect(restartGame, &QPushButton::released,
                   dynamic_cast<Sudoku*>(parent),        &Sudoku::restartGame);
  QPushButton *closeGame = new QPushButton(tr("Close game!"), this);
  buttonsBox->addWidget(closeGame);
  QObject::connect(closeGame, &QPushButton::released,
                   dynamic_cast<Sudoku*>(parent),      &Sudoku::closeGame);
  buttonsGroup->setLayout(buttonsBox);


  windowLayout->addWidget(scoreGroup);
  windowLayout->addWidget(buttonsGroup);

  this->setLayout(windowLayout);
}

void WinWindow::hideWindow() {
  this->close();
}
