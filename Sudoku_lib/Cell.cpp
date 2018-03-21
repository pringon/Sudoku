#include "Cell.h"
#include <QSizePolicy>

Cell::Cell(QWidget *parent, int row, int column, int value) : QLabel(parent) {
  this->row = row;
  this->column = column;
  this->value = value;

  this->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
  this->setText(QString::number(this->value));
  this->setStyleSheet("border: 1px solid black");
  if(this->value == 0) {
    this->clickable = true;
    this->setCursor(Qt::PointingHandCursor);
  } else {
    this->clickable = false;
  }
  this->backtracked = false;
}

int Cell::getValue() {
  return this->value;
}

void Cell::incrementValue() {
  if(this->clickable) {
    this->value = (this->value == 9) ? 0 : this->value + 1;
    this->setText(QString::number(this->value));
    emit valueChanged(this->row, this->column);
  }
}

bool Cell::wasBacktracked() {
  return this->backtracked;
}

void Cell::toggleBacktracked() {
  this->backtracked = !this->backtracked;
}

bool Cell::isClickable() {
  return this->clickable;
}

void Cell::resizeEvent(QResizeEvent *event) {
  QFont font = this->font();
  font.setPixelSize(this->height() * 0.8);
  this->setFont(font);
}

void Cell::mousePressEvent(QMouseEvent *event) {
  if(this->clickable) {
    this->value = (this->value == 9) ? 0 : this->value + 1;
    this->setText(QString::number(this->value));
    emit valueChanged(this->row, this->column);
  }
}
