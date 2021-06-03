#include <iostream>
#include "Menu.h"
#include "PlatilloNode.h"

using std::string;

Menu::Menu(PlatilloNode **platilloAnchor, string season)
{
  this->platilloAnchor = *platilloAnchor;
  this->season = season;
}

void Menu::set_platillo_anchor(PlatilloNode **platilloAnchor)
{
  this->platilloAnchor = *platilloAnchor;
}

void Menu::set_season(string season)
{
  this->season = season;
}

PlatilloNode *Menu::get_platillo_anchor() const
{
  return this->platilloAnchor;
}

string Menu::get_season() const
{
  return this->season;
}