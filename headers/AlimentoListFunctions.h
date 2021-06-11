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
//Para la entrega del 10/06
Alimento searchFood(AlimentoNode **nodeAnchor, int id);
void registerOrder(AlimentoNode **nodeAnchor);
void swapData(Alimento &a, Alimento &b);
//quickSort 1
//void quickSort(Alimento data[], const int &leftEdge, const int &rightEdge);
//quickSort 2
void quickSort(Alimento *array, int left, int right);
#endif