#include "Alimento.h"
#include "AlimentoNode.h"

#ifndef ALIMENTOQUEUEFUNCIONS_H
#define ALIMENTOQUEUEFUNCIONS_H

bool isEmpty(AlimentoNode **nodeAnchor);
void addToStack(AlimentoNode **nodeAnchor, Alimento alimentos[]);

#endif