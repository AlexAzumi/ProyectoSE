#include <iostream>
#include "AlimentoNode.h"

using std::string;

#ifndef MENU_H
#define MENU_H

class Menu
{
private:
  AlimentoNode *platilloAnchor;
  string season;

public:
  Menu(AlimentoNode **platilloAnchor, string season);
  // Setters
  void set_platillo_anchor(AlimentoNode **platilloAnchor);
  void set_season(string season);
  // Getters
  AlimentoNode *get_platillo_anchor() const;
  string get_season() const;
};

#endif