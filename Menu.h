#include <iostream>
#include "PlatilloNode.h"

using std::string;

#ifndef MENU_H
#define MENU_H

class Menu
{
private:
  PlatilloNode *platilloAnchor;
  string season;

public:
  Menu(PlatilloNode **platilloAnchor, string season);
  // Setters
  void set_platillo_anchor(PlatilloNode **platilloAnchor);
  void set_season(string season);
  // Getters
  PlatilloNode *get_platillo_anchor() const;
  string get_season() const;
};

#endif