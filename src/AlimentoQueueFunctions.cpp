#include <iostream>
#include "../headers/AlimentoNode.h"
#include "../headers/AlimentoListFunctions.h"
// App useful functions
#include "../headers/AppFunctions.h"

using std::cin;
using std::cout;
using std::endl;

/**
 * Checks if the stack is empty
 * @returns true if the stack is empty
 */
bool isEmpty(AlimentoNode **nodeAnchor)
{
  return *nodeAnchor = nullptr;
}

/**
 * Unstacks the last inserted element (on the top)
 */
void unstack(AlimentoNode **nodeAnchor)
{
  clearConsole();

  cout << endl;
  cout << "- Desapilar elemento -" << endl;

  if (isEmpty(nodeAnchor))
  {
    cout << endl;
    cout << "La pila esta vacia" << endl;
    pauseScreen();

    return;
  }

  AlimentoNode *tempNode = *nodeAnchor;
  AlimentoNode *nextNode = tempNode->nextNode;

  *nodeAnchor = nextNode;

  delete tempNode;

  cout << endl;
  cout << "El elemento fue desapilado correctamente" << endl;

  pauseScreen();
}
