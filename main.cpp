#include <iostream>
#include <string>
// Classes
#include "Platillo.h"
#include "Orden.h"
#include "Menu.h"
#include "Ingrediente.h"
// Struct nodes
#include "PlatilloNode.h"

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

typedef PlatilloNode *PlatilloNodePointer;
// Methods: Platillo
void deleteByID(PlatilloNodePointer *nodeAnchor);
void editFood(PlatilloNodePointer *nodeAnchor);
void insertElementEnd(PlatilloNodePointer *nodeAnchor, int *lastID);
void insertElementInPosition(PlatilloNodePointer *nodeAnchor, int *lastID);
void insertElementStart(PlatilloNodePointer *nodeAnchor, int *lastID);
void printAllElements(PlatilloNodePointer nodeAnchor);
void searchByID(PlatilloNodePointer *nodeAnchor);
//Ordenamientos en la Lista Simp. Ligada
void bubbleSortByName(PlatilloNodePointer *nodeAnchor);
void bubbleSortByCTime(PlatilloNodePointer *nodeAnchor);
// Helpers
int getMenu();
void clearConsole();
void pauseScreen();

int main()
{
  int option = 0;
  int lastID = 0;
  PlatilloNode *nodeAnchor = nullptr;

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
      cout << "Ordenando por nombre...";
      bubbleSortByName(&nodeAnchor);
      break;
    }
    case 7:
    {
      cout << "Ordenando por tiempo de preparacion...";
      bubbleSortByCTime(&nodeAnchor);
      break;
    }
    case 8:
    {
      printAllElements(nodeAnchor);
      break;
    }
    case 9:
    {
      editFood(&nodeAnchor);
      break;
    }
    case 10:
    {
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

/**
 * Clears the console
 */
void clearConsole()
{
  system("clear || cls");
}

/**
 * Pauses the execution
 */
void pauseScreen()
{
  cout << "Presione ENTER para continuar...";
  cin.get();
}

/**
 * Shows and returns the selected menu option
 */
int getMenu()
{
  char option[99];

  // Show title
  cout << "Proyecto - Seminario de estructura de datos I" << endl;
  // Show menu options
  cout << endl
       << "- Opciones -" << endl;
  cout << "1. Insertar platillo al frente" << endl;
  cout << "2. Insertar platillo al final" << endl;
  cout << "3. Insertar platillo por posición" << endl;
  cout << "4. Eliminar por ID" << endl;
  cout << "5. Mostrar por ID" << endl;
  cout << "6. Ordenar por nombre" << endl;
  cout << "7. Ordenar por tiempo de preparación" << endl;
  cout << "8. Mostrar todo los platillos" << endl;
  cout << "9. Editar platillo" << endl;
  cout << "10. Finalizar programa" << endl;
  cout << "Opción: ";
  cin >> option;

  return atoi(option);
}

/**
 * Inserts a "platillo" node in the start
 */
void insertElementEnd(PlatilloNodePointer *nodeAnchor, int *lastID)
{
  string nombre;
  float costo_restaurante;
  float costo_comensal;
  float tiempo_preparacion;
  string temporada;
  string categoria;
  string preparacion;

  clearConsole();

  // Title
  cout << endl;
  cout << "- Ingresar nuevo platillo al frente -" << endl;
  // Ask data
  cout << "Nombre: ";
  cin >> nombre;
  cin.ignore();
  cout << "Costo al restaurante: ";
  cin >> costo_restaurante;
  cin.ignore();
  cout << "Costo al comensal: ";
  cin >> costo_comensal;
  cin.ignore();
  cout << "Temporada (Primavera, Verano, Otoño, Invierno o Navideño): ";
  cin >> temporada;
  cin.ignore();
  cout << "Tipo (Desayuno, Comida o Cena): ";
  cin >> categoria;
  cin.ignore();
  cout << "Explicación de preparación: ";
  cin >> preparacion;
  cin.ignore();

  PlatilloNodePointer previousNode;
  PlatilloNodePointer currentNode;
  PlatilloNodePointer newNode;

  newNode = new PlatilloNode;

  if (newNode != nullptr)
  {
    newNode->data.set_id(*lastID + 1);
    newNode->data.set_nombre(nombre);
    newNode->data.set_costo_restaurante(costo_restaurante);
    newNode->data.set_costo_comensal(costo_comensal);
    newNode->data.set_tiempo_preparacion(tiempo_preparacion);
    newNode->data.set_temporada(temporada);
    newNode->data.set_categoria(categoria);
    newNode->data.set_preparacion(preparacion);

    previousNode = nullptr;
    currentNode = *nodeAnchor;

    while (currentNode != nullptr)
    {
      previousNode = currentNode;
      currentNode = currentNode->nextNode;
    }

    if (previousNode == nullptr)
    {
      newNode->nextNode = *nodeAnchor;
      *nodeAnchor = newNode;
    }
    else
    {
      previousNode->nextNode = newNode;
      newNode->nextNode = currentNode;
    }

    *lastID = *lastID + 1;

    cout << endl;
    cout << "El platillo se agregó correctamente" << endl;

    pauseScreen();
  }
  else
  {
    cout << endl;
    cout << "No se insertó el elemento, no hay memoria disponible" << endl;

    pauseScreen();
  }
}

/**
 * Inserta un nuevo platillo al inicio de la lista
 */
void insertElementStart(PlatilloNodePointer *nodeAnchor, int *lastID)
{
  string nombre;
  float costo_restaurante;
  float costo_comensal;
  float tiempo_preparacion;
  string temporada;
  string categoria;
  string preparacion;

  clearConsole();

  // Title
  cout << endl;
  cout << "- Ingresar nuevo platillo al frente -" << endl;
  // Ask data
  cout << "Nombre: ";
  cin >> nombre;
  cin.ignore();
  cout << "Costo al restaurante: ";
  cin >> costo_restaurante;
  cin.ignore();
  cout << "Costo al comensal: ";
  cin >> costo_comensal;
  cin.ignore();
  cout << "Temporada (Primavera, Verano, Otoño, Invierno o Navideño): ";
  cin >> temporada;
  cin.ignore();
  cout << "Tipo (Desayuno, Comida o Cena): ";
  cin >> categoria;
  cin.ignore();
  cout << "Explicación de preparación: ";
  cin >> preparacion;
  cin.ignore();

  PlatilloNodePointer newNode;

  newNode = new PlatilloNode;

  if (newNode != nullptr)
  {
    newNode->data.set_id(*lastID + 1);
    newNode->data.set_nombre(nombre);
    newNode->data.set_costo_restaurante(costo_restaurante);
    newNode->data.set_costo_comensal(costo_comensal);
    newNode->data.set_tiempo_preparacion(tiempo_preparacion);
    newNode->data.set_temporada(temporada);
    newNode->data.set_categoria(categoria);
    newNode->data.set_preparacion(preparacion);

    newNode->nextNode = *nodeAnchor;
    *nodeAnchor = newNode;

    *lastID = *lastID + 1;

    cout << endl;
    cout << "El platillo se agregó correctamente" << endl;

    pauseScreen();
  }
  else
  {
    cout << endl;
    cout << "No se insertó el elemento, no hay memoria disponible" << endl;

    pauseScreen();
  }
}

/**
 * Inserta un platillo al final de la lista
 */
void printAllElements(PlatilloNodePointer nodeAnchor)
{
  PlatilloNodePointer currentNode = nodeAnchor;

  clearConsole();
  // Title
  cout << endl;
  cout << "- Mostrar platillos -" << endl;

  if (nodeAnchor == nullptr)
  {
    cout << endl;
    cout << "La lista está vacía" << endl;

    pauseScreen();

    return;
  }

  cout << endl;

  while (currentNode != nullptr)
  {
    cout << "ID: " << currentNode->data.get_id() << endl;
    cout << "Nombre: " << currentNode->data.get_nombre() << endl;
    cout << "Costo para restaurante: " << currentNode->data.get_costo_restaurante() << endl;
    cout << "Costo para comensal: " << currentNode->data.get_costo_comensal() << endl;
    cout << "Temporada: " << currentNode->data.get_temporada() << endl;
    cout << "Tipo: " << currentNode->data.get_categoria() << endl;
    cout << "Preparación: " << currentNode->data.get_preparacion() << endl;
    cout << endl;

    // Go to next node
    currentNode = currentNode->nextNode;
  }

  pauseScreen();
}

/**
 * Elimina un elemento buscandolo por ID
 */
void deleteByID(PlatilloNodePointer *nodeAnchor)
{
  int id;

  clearConsole();
  // Title
  cout << endl;
  cout << "- Eliminar platillo por ID -" << endl;

  if (*nodeAnchor == nullptr)
  {
    cout << endl;
    cout << "La lista está vacía" << endl;

    pauseScreen();

    return;
  }

  cout << "ID del elemento: ";
  cin >> id;
  cin.ignore();

  PlatilloNodePointer previousNode;
  PlatilloNodePointer currentNode;
  PlatilloNodePointer tempNode;

  currentNode = *nodeAnchor;

  while (currentNode != nullptr)
  {
    if (currentNode->data.get_id() == id)
    {
      break;
    }

    previousNode = currentNode;
    currentNode = currentNode->nextNode;
  }

  if (currentNode != nullptr)
  {
    if ((*nodeAnchor)->data.get_id() == id)
    {
      tempNode = *nodeAnchor;
      *nodeAnchor = (*nodeAnchor)->nextNode;
    }
    else
    {
      tempNode = currentNode;
      previousNode->nextNode = currentNode->nextNode;
    }

    delete tempNode;

    cout << endl;
    cout << "El elemento fue eliminado correctamente" << endl;

    pauseScreen();
  }
  else
  {
    cout << endl;
    cout << "No se encontró el elemento con ID: " << id << endl;

    pauseScreen();
  }
}

/**
 * Busca un platillo por ID
 */
void searchByID(PlatilloNodePointer *nodeAnchor)
{
  int id;

  clearConsole();
  // Title
  cout << endl;
  cout << "- Buscar platillo por ID -" << endl;

  if (*nodeAnchor == nullptr)
  {
    cout << endl;
    cout << "La lista está vacía" << endl;

    pauseScreen();

    return;
  }

  cout << "ID del elemento: ";
  cin >> id;
  cin.ignore();

  PlatilloNodePointer previousNode;
  PlatilloNodePointer currentNode;
  PlatilloNodePointer tempNode;

  currentNode = *nodeAnchor;

  while (currentNode != nullptr)
  {
    if (currentNode->data.get_id() == id)
    {
      break;
    }

    previousNode = currentNode;
    currentNode = currentNode->nextNode;
  }

  if (currentNode != nullptr)
  {
    cout << endl;
    cout << "ID: " << currentNode->data.get_id() << endl;
    cout << "Nombre: " << currentNode->data.get_nombre() << endl;
    cout << "Costo para restaurante: " << currentNode->data.get_costo_restaurante() << endl;
    cout << "Costo para comensal: " << currentNode->data.get_costo_comensal() << endl;
    cout << "Temporada: " << currentNode->data.get_temporada() << endl;
    cout << "Tipo: " << currentNode->data.get_categoria() << endl;
    cout << "Preparación: " << currentNode->data.get_preparacion() << endl;
    cout << endl;

    pauseScreen();
  }
  else
  {
    cout << endl;
    cout << "No se encontró el elemento con ID: " << id << endl;

    pauseScreen();
  }
}

/**
 * Edita un platillo
 */
void editFood(PlatilloNodePointer *nodeAnchor)
{
  int id;
  int opc;
  char op;

  int newId;
  string newName;
  float newCostRest;
  float newCostClient;
  float newPrepTime;
  string newSeason;
  string newCategory;
  string newPreparation;

  clearConsole();
  // Title
  cout << endl;
  cout << "- Buscar platillo por ID -" << endl;

  if (*nodeAnchor == nullptr)
  {
    cout << endl;
    cout << "La lista está vacía" << endl;

    pauseScreen();

    return;
  }

  cout << "ID del elemento: ";
  cin >> id;
  cin.ignore();

  PlatilloNodePointer previousNode;
  PlatilloNodePointer currentNode;
  PlatilloNodePointer tempNode;

  currentNode = *nodeAnchor;

  while (currentNode != nullptr)
  {
    if (currentNode->data.get_id() == id)
    {
      break;
    }

    previousNode = currentNode;
    currentNode = currentNode->nextNode;
  }

  if (currentNode != nullptr)
  {
    do
    {
      clearConsole();
      cout << endl;
      cout << "Elige el campo del platillo que deseas editar" << endl;
      cout << "1. ID" << endl
           << "2. Nombre" << endl
           << "3. Costo para el restaurante" << endl
           << "4. Costo para el comensal" << endl
           << "5. Temporada" << endl
           << "6. Tipo" << endl
           << "7. Preparacion" << endl
           << "8. Tiempo de preparacion" << endl
           << endl;
      cin >> opc;
      cin.ignore();
      switch (opc)
      {
      case 1:
        clearConsole();
        cout << "Ingresa el nuevo ID del platillo" << endl;
        cin >> newId;
        currentNode->data.set_id(newId);
        cout << "ID modificado exitosamente" << endl;
        break;

      case 2:
        clearConsole();
        cout << "Ingresa el nuevo nombre del platillo" << endl;
        std::getline(cin, newName);
        currentNode->data.set_nombre(newName);
        cout << "Nombre del platillo modificado exitosamente" << endl;
        break;

      case 3:
        clearConsole();
        cout << "Ingresa el nuevo costo del platillo para el restaurante" << endl;
        cin >> newCostRest;
        currentNode->data.set_costo_restaurante(newCostRest);
        cout << "Costo del platillo para el restaurante modificado exitosamente" << endl;
        break;

      case 4:
        clearConsole();
        cout << "Ingresa el nuevo costo del platillo para el comensal" << endl;
        cin >> newCostClient;
        currentNode->data.set_costo_comensal(newCostClient);
        cout << "Costo del platillo para el comensal modificado exitosamente" << endl;
        break;

      case 5:
        clearConsole();
        cout << "Ingresa la nueva temporada del platillo" << endl;
        std::getline(cin, newSeason);
        currentNode->data.set_temporada(newSeason);
        cout << "Temporada del platillo modificada exitosamente" << endl;
        break;

      case 6:
        clearConsole();
        cout << "Ingresa la nueva categoria del platillo" << endl;
        std::getline(cin, newCategory);
        currentNode->data.set_categoria(newCategory);
        cout << "Categoria del platillo modificada exitosamente" << endl;
        break;

      case 7:
        clearConsole();
        cout << "Ingresa la nueva preparacion del platillo" << endl;
        std::getline(cin, newPreparation);
        currentNode->data.set_preparacion(newPreparation);
        cout << "Preparacion del platillo modificada exitosamente" << endl;
        break;

      case 8:
        clearConsole();
        cout << "Ingresa el nuevo tiempo de preparacion del platillo" << endl;
        cin >> newPrepTime;
        currentNode->data.set_tiempo_preparacion(newPrepTime);
        cout << "Tiempo de preparacion del platillo modificado exitosamente" << endl;
        break;

      default:
        clearConsole();
        cout << "Opcion desconocida" << endl;
        break;
      }

      pauseScreen();

      cout << "Desea editar un campo mas?" << endl;
      cout << "Si(s) | No(n)" << endl;
      cin >> op;
      cin.ignore();

    } while (op == 's');
  }
  else
  {
    cout << endl;
    cout << "No se encontró el elemento con ID: " << id << endl;

    pauseScreen();
  }
}

/**
 * Inserta un platillo en una posición en especifico
 */
void insertElementInPosition(PlatilloNodePointer *nodeAnchor, int *lastID)
{
  int position;
  string nombre;
  float costo_restaurante;
  float costo_comensal;
  float tiempo_preparacion;
  string temporada;
  string categoria;
  string preparacion;

  clearConsole();

  // Title
  cout << endl;
  cout << "- Ingresar nuevo platillo al frente -" << endl;
  cout << endl;
  // Ask data
  cout << "Posición: ";
  cin >> position;
  cin.ignore();
  cout << "Nombre: ";
  cin >> nombre;
  cin.ignore();
  cout << "Costo al restaurante: ";
  cin >> costo_restaurante;
  cin.ignore();
  cout << "Costo al comensal: ";
  cin >> costo_comensal;
  cin.ignore();
  cout << "Temporada (Primavera, Verano, Otoño, Invierno o Navideño): ";
  cin >> temporada;
  cin.ignore();
  cout << "Tipo (Desayuno, Comida o Cena): ";
  cin >> categoria;
  cin.ignore();
  cout << "Explicación de preparación: ";
  cin >> preparacion;
  cin.ignore();

  PlatilloNodePointer previousNode;
  PlatilloNodePointer currentNode;
  PlatilloNodePointer newNode;

  newNode = new PlatilloNode;

  if (newNode != nullptr)
  {
    newNode->data.set_id(*lastID + 1);
    newNode->data.set_nombre(nombre);
    newNode->data.set_costo_restaurante(costo_restaurante);
    newNode->data.set_costo_comensal(costo_comensal);
    newNode->data.set_tiempo_preparacion(tiempo_preparacion);
    newNode->data.set_temporada(temporada);
    newNode->data.set_categoria(categoria);
    newNode->data.set_preparacion(preparacion);

    currentNode = *nodeAnchor;

    // Search position
    while (position > 0)
    {
      if (currentNode->nextNode == nullptr)
      {
        break;
      }

      previousNode = currentNode;
      currentNode = currentNode->nextNode;
      position--;
    }

    // Insert in position
    if (previousNode == nullptr)
    {
      newNode->nextNode = *nodeAnchor;
      *nodeAnchor = newNode;
    }
    else
    {
      previousNode->nextNode = newNode;
      newNode->nextNode = currentNode;
    }

    cout << endl;
    cout << "El platillo se agregó correctamente" << endl;

    pauseScreen();
  }
  else
  {
    cout << endl;
    cout << "No se insertó el elemento, no hay memoria disponible" << endl;

    pauseScreen();
  }
}

/*
 * Ordenamiento burbuja por nombre
*/
void bubbleSortByName(PlatilloNodePointer *nodeAnchor)
{
    PlatilloNodePointer puntero = *nodeAnchor;
    PlatilloNodePointer aux = nullptr;
    Platillo dato;

    while (puntero->nextNode != nullptr)
    {
        aux = puntero->nextNode;

        while (aux != nullptr)
        {
            if (puntero->data.get_nombre() > aux->data.get_nombre())
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


/*
 * Ordenamiento burbuja por tiempo de preparacion
*/
void bubbleSortByCTime(PlatilloNodePointer *nodeAnchor)
{
    PlatilloNodePointer puntero = *nodeAnchor;
    PlatilloNodePointer aux = nullptr;
    Platillo dato;

    while (puntero->nextNode != nullptr)
    {
      aux = puntero->nextNode;

      while (aux != nullptr)
      {
        if (puntero->data.get_tiempo_preparacion() > aux->data.get_tiempo_preparacion())
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