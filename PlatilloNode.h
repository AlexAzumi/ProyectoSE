#include "Platillo.h"

#ifndef PLATILLONODE_H
#define PLATILLONODE_H

struct PlatilloNode
{
  Platillo data;
  PlatilloNode *previousNode;
  PlatilloNode *nextNode;
};

#endif