#include "AlimentoNode.h"

#ifndef ALIMENTOLISTFUNCTIONS_H
#define ALIMENTOLISTFUNCTIONS_H

void bubbleSortByCookTime(AlimentoNode **nodeAnchor);
void bubbleSortByName(AlimentoNode **nodeAnchor);
void deleteByID(AlimentoNode **nodeAnchor);
void editElement(AlimentoNode **nodeAnchor);
void insertElementEnd(AlimentoNode **nodeAnchor, int *lastID);
void insertElementInPosition(AlimentoNode **nodeAnchor, int *lastID);
void insertElementStart(AlimentoNode **nodeAnchor, int *lastID);
void printAllElements(AlimentoNode **nodeAnchor);
void searchByID(AlimentoNode **nodeAnchor);

#endif