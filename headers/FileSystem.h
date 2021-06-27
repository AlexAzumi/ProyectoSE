
#include "AlimentoNode.h"
#include "Menu.h"

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

Menu getMyMenu();
void addElementToFile(Alimento data);
void deleteElementFromFile(int id);
void getAlimentosFromFile(AlimentoNode **anchor, string season, string category);

#endif