#include <iostream>
#include "../headers/AlimentoNode.h"
#include "../headers/AlimentoListFunctions.h"
// App useful functions
#include "../headers/AppFunctions.h"

using std::cin;
using std::cout;
using std::endl;

/**
 * Revisa si la pila se encuentra vacía
 */
bool isEmpty(AlimentoNode **nodeAnchor)
{
  return *nodeAnchor = nullptr;
}

/**
 * Añade todos los alimentos a la pila
 */
void addToStack(AlimentoNode **nodeAnchor, Alimento alimentos[], int length)
{
  AlimentoNode *tempNode = *nodeAnchor;
  AlimentoNode *previousNode = nullptr;

  for (int i = 0; i < length; i++)
  {
    if (isEmpty(nodeAnchor))
    {
      (*nodeAnchor) = new AlimentoNode();
      (*nodeAnchor)->data = alimentos[i];
    }
    else
    {
      AlimentoNode *newNode = new AlimentoNode();
      newNode->data = alimentos[i];
    }
  }
}
