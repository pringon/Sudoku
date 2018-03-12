#include "Group.h"

void Group::addCell(Cell *newCell) {
  members.push_back(newCell);
}

bool Group::checkSameValues() {
  bool seen[10] = {};

  std::vector<Cell*>::iterator it = this->members.begin();
  while(it != this->members.end()) {
    if(seen[(*it)->getValue()] && (*it)->getValue() != 0) {
      return true;
    }
    seen[(*it)->getValue()] = true;
    it++;
  }

  return false;
}

bool Group::checkZeroes() {
  std::vector<Cell*>::iterator it = this->members.begin();
  while(it != this->members.end()) {
    if(!(*it)->getValue()) {
      return true;
    }
    it++;
  }

  return false;
}

void Group::paint(std::string color) {
  std::vector<Cell*>::iterator it = this->members.begin();
  while(it != this->members.end()) {
    std::string styleSheet = "border: 1px solid " + color;
    (*it)->setStyleSheet(QString::fromStdString(styleSheet));
    it++;
  }
}
