#include <iostream>
#include <string>
// Clases
#include "headers/Alimento.h"
#include "headers/Orden.h"
#include "headers/Menu.h"
#include "headers/Ingrediente.h"
// Nodos de clases
#include "headers/AlimentoNode.h"
// Funciones de listas
#include "headers/AlimentoListFunctions.h"
// Funciones generales
#include "headers/AppFunctions.h"

// Needed stuff from std
using std::atoi;
using std::cin;
using std::cout;
using std::endl;
using std::exit;
using std::string;
using std::system;

/**
 * - Integrantes del equipo -
 * Hernández Suárez Cesar Alejandro
 * Guillen Aguallo Diego
 * Gonzalez Barrientos Alberto
 * Valdivia Nario Julián André
 * Bañuelos Rivas Jose Alfredo
 */

typedef AlimentoNode *AlimentoNodePointer;

//nuevas funciones para usar Binary search
int Size(AlimentoNodePointer nodeAnchor);
AlimentoNodePointer SearchBinary(int data, int Ini, int Fin, AlimentoNodePointer *nodeAnchor);
void bubbleSortByID(AlimentoNodePointer *nodeAnchor);

int main()
{
  int option = 0;
  int lastID = 0;
  AlimentoNode *nodeAnchor = nullptr;

  clearConsole();

  while (true)
  {
    option = getMenu();
    cin.ignore();

    switch (option)
    {
    case 1:
    {
      insertElementStart(&nodeAnchor, &lastID);
      break;
    }
    case 2:
    {
      insertElementEnd(&nodeAnchor, &lastID);
      break;
    }
    case 3:
    {
      insertElementInPosition(&nodeAnchor, &lastID);
      break;
    }
    case 4:
    {
      deleteByID(&nodeAnchor);
      break;
    }
    case 5:
    {
      searchByID(&nodeAnchor);
      break;
    }
    case 6:
    {
      bubbleSortByName(&nodeAnchor);
      break;
    }
    case 7:
    {
      bubbleSortByCookTime(&nodeAnchor);
      break;
    }
    case 8:
    {
      printAllElements(&nodeAnchor);
      break;
    }
    case 9:
    {
      editElement(&nodeAnchor);
      break;
    }
    case 10:
    {
      int Ini = 1, Fin = Size(nodeAnchor), data;
      bubbleSortByID(&nodeAnchor);
      cout << "Ingrese el ID del platillo a buscar:";
      cin >> data;
      SearchBinary(data, Ini, Fin, &nodeAnchor);
      break;
    }
    case 11:
    {
      //Instrucciones
      break;
    }
    case 12:
    {
      cout << endl;
      cout << "Saliendo del programa..." << endl;

      exit(0);
    }
    default:
    {
      cout << endl;
      cout << "Opción no válida" << endl;

      pauseScreen();

      break;
    }
    }

    clearConsole();
  }
}

void bubbleSortByID(AlimentoNode **nodeAnchor)
{
  AlimentoNode *puntero = *nodeAnchor;
  AlimentoNode *aux = nullptr;
  Alimento dato;

  while (puntero->nextNode != nullptr)
  {
    aux = puntero->nextNode;

    while (aux != nullptr)
    {
      if (puntero->data.get_id() > aux->data.get_id())
      {
        dato = aux->data;
        aux->data = puntero->data;
        puntero->data = dato;
      }

      aux = aux->nextNode;
    }

    puntero = puntero->nextNode;
  }
}

int Size(AlimentoNodePointer nodeAnchor)
{
  int i = 0;
  AlimentoNodePointer currentNode = nodeAnchor;
  if (nodeAnchor == nullptr)
  {
    cout << endl;
    cout << "La lista está vacía" << endl;

    pauseScreen();

    return i;
  }
  while (currentNode != nullptr)
  {
    // Go to next node
    i++;
    currentNode = currentNode->nextNode;
  }
  return i;
}

AlimentoNodePointer SearchBinary(int data, int Ini, int Fin, AlimentoNodePointer *nodeAnchor)
{
  if (Ini > Fin)
  {
    cout << "Entro a busqueda invalida, este valor nose encuentra en la lista:";
    return 0;
  }
  if (*nodeAnchor == nullptr)
  {
    cout << endl;
    cout << "La lista está vacía" << endl;

    pauseScreen();

    return 0;
  }

  int mid = (Ini + Fin) / 2; // Posicion
  AlimentoNodePointer mitad; // Direccion
  AlimentoNodePointer previousNode;
  AlimentoNodePointer currentNode;
  AlimentoNodePointer tempNode;

  currentNode = *nodeAnchor;

  for (int i = 1; i <= mid; i++)
  {
    if (i == mid)
    {
      mitad = currentNode;
      break;
    }
    previousNode = currentNode;
    currentNode = currentNode->nextNode;
  }

  if (mitad->data.get_id() == data)
  {
    pauseScreen();

    cout << endl;
    cout << "ID: " << currentNode->data.get_id() << endl;
    cout << "Nombre: " << currentNode->data.get_nombre() << endl;
    cout << "Costo para restaurante: " << currentNode->data.get_costo_restaurante() << endl;
    cout << "Costo para comensal: " << currentNode->data.get_costo_comensal() << endl;
    cout << "Tiempo de preparacion: " << currentNode->data.get_tiempo_preparacion() << endl;
    cout << "Temporada: " << currentNode->data.get_temporada() << endl;
    cout << "Categoría: " << currentNode->data.get_categoria() << endl;
    cout << "Preparación: " << currentNode->data.get_preparacion() << endl;
    cout << "Preparación: " << currentNode->data.get_tipo() << endl;
    cout << endl;

    pauseScreen();

    return currentNode;
  }

  if (data < mitad->data.get_id())
  {

    SearchBinary(data, Ini, mid - 1, nodeAnchor);
  }
  else
  {

    SearchBinary(data, mid + 1, Fin, nodeAnchor);
  };
}
