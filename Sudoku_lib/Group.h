#ifndef GROUP_H
#define GROUP_H

#include "Cell.h"
#include <vector>
#include <string>
#include <QString>

class Group {
private:
  std::vector<Cell*> members;

public:
  Group() {}
  void addCell(Cell *newCell);
  bool checkSameValues();
  bool checkZeroes();
  void paint(std::string color);
};

#endif
