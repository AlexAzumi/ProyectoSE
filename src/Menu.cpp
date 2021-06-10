#include <iostream>
#include "../headers/Menu.h"
#include "../headers/AlimentoNode.h"

using std::string;

Menu::Menu(AlimentoNode **platilloAnchor, string season)
{
  this->platilloAnchor = *platilloAnchor;
  this->season = season;
}

void Menu::set_platillo_anchor(AlimentoNode **platilloAnchor)
{
  this->platilloAnchor = *platilloAnchor;
}

void Menu::set_season(string season)
{
  this->season = season;
}

AlimentoNode *Menu::get_platillo_anchor() const
{
  return this->platilloAnchor;
}

string Menu::get_season() const
{
  return this->season;
}