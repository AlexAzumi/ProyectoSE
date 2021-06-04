#include "Alimento.h"

#ifndef ALIMENTONODE_H
#define ALIMENTONODE_H

struct AlimentoNode
{
  Alimento data;
  AlimentoNode *previousNode;
  AlimentoNode *nextNode;
};

#endif