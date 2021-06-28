
#include "AlimentoNode.h"
#include "Menu.h"

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

int getLastIDFromFile();
Menu getMyMenu();
void addElementToFile(Alimento data);
void deleteElementFromFile(int id);
void editElementFromFile(int id, string key, string newValue);
void getAlimentosFromFile(AlimentoNode **anchor, string season, string category);

#endif