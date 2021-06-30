#include <iostream>
#include "../headers/AlimentoNode.h"
#include "../headers/AlimentoListFunctions.h"
#include "../headers/DynamicStack.h"
#include "../headers/DynamicQueue.h"
#include "../headers/FileSystem.h"

// App useful functions
#include "../headers/AppFunctions.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::to_string;

/**
 * Elimina un alimento buscandolo por ID
 */
void deleteByID(AlimentoNode **nodeAnchor)
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

  cout << "ID del alimento: ";
  cin >> id;
  cin.ignore();

  AlimentoNode *previousNode;
  AlimentoNode *currentNode;
  AlimentoNode *tempNode;

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

    deleteElementFromFile(id);

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
 * Inserta un alimento al final de la lista
 */
void insertElementEnd(AlimentoNode **nodeAnchor, int *lastID)
{
  string nombre;
  float costo_restaurante;
  float costo_comensal;
  float tiempo_preparacion;
  string temporada;
  string categoria;
  string preparacion;
  string tipo;

  clearConsole();

  // Title
  cout << endl;
  cout << "- Ingresar nuevo platillo al final -" << endl;
  // Ask data
  cout << "Nombre: ";
  getline(cin, nombre);
  cout << "Costo al restaurante: ";
  cin >> costo_restaurante;
  cin.ignore();
  cout << "Costo al comensal: ";
  cin >> costo_comensal;
  cin.ignore();
  cout << "Temporada (Primavera, Verano, Otoño, Invierno o Navideño): ";
  getline(cin, temporada);
  cout << "Categoría (Desayuno, Comida o Cena): ";
  getline(cin, categoria);
  cout << "Tiempo de preparación: ";
  cin >> tiempo_preparacion;
  cin.ignore();
  cout << "Explicación de preparación: ";
  getline(cin, preparacion);
  cout << "Tipo (Platillo o Bebida): ";
  getline(cin, tipo);

  AlimentoNode *previousNode;
  AlimentoNode *currentNode;
  AlimentoNode *newNode;

  newNode = new AlimentoNode;

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
    newNode->data.set_tipo(tipo);

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

    addElementToFile(newNode->data);

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
 * Inserta un alimento en una posición específica
 */
void insertElementInPosition(AlimentoNode **nodeAnchor, int *lastID)
{
  int position;
  string nombre;
  float costo_restaurante;
  float costo_comensal;
  float tiempo_preparacion;
  string temporada;
  string categoria;
  string preparacion;
  string tipo;

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
  getline(cin, nombre);
  cout << "Costo al restaurante: ";
  cin >> costo_restaurante;
  cin.ignore();
  cout << "Costo al comensal: ";
  cin >> costo_comensal;
  cin.ignore();
  cout << "Temporada (Primavera, Verano, Otoño, Invierno o Navideño): ";
  getline(cin, temporada);
  cout << "Categoría (Desayuno, Comida o Cena): ";
  getline(cin, categoria);
  cout << "Tiempo de preparación: ";
  cin >> tiempo_preparacion;
  cin.ignore();
  cout << "Explicación de preparación: ";
  getline(cin, preparacion);
  cout << "Tipo (Platillo o Bebida): ";
  getline(cin, tipo);

  AlimentoNode *previousNode;
  AlimentoNode *currentNode;
  AlimentoNode *newNode;

  newNode = new AlimentoNode;

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
    newNode->data.set_tipo(tipo);

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

    addElementToFile(newNode->data);

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
 * Inserta un nuevo alimento al inicio de la lista
 */
void insertElementStart(AlimentoNode **nodeAnchor, int *lastID)
{
  string nombre;
  float costo_restaurante;
  float costo_comensal;
  float tiempo_preparacion;
  string temporada;
  string categoria;
  string preparacion;
  string tipo;

  clearConsole();

  // Title
  cout << endl;
  cout << "- Ingresar nuevo platillo al frente -" << endl;
  // Ask data
  cout << "Nombre: ";
  getline(cin, nombre);
  cout << "Costo al restaurante: ";
  cin >> costo_restaurante;
  cin.ignore();
  cout << "Costo al comensal: ";
  cin >> costo_comensal;
  cin.ignore();
  cout << "Temporada (Primavera, Verano, Otoño, Invierno o Navideño): ";
  getline(cin, temporada);
  cout << "Categoría (Desayuno, Comida o Cena): ";
  getline(cin, categoria);
  cout << "Tiempo de preparación: ";
  cin >> tiempo_preparacion;
  cin.ignore();
  cout << "Explicación de preparación: ";
  getline(cin, preparacion);
  cout << "Tipo (Platillo o Bebida): ";
  getline(cin, tipo);
  cin.ignore();

  AlimentoNode *newNode;

  newNode = new AlimentoNode;

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
    newNode->data.set_tipo(tipo);

    newNode->nextNode = *nodeAnchor;
    *nodeAnchor = newNode;

    *lastID = *lastID + 1;

    addElementToFile(newNode->data);

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
 * Imprime todos los alimentos en pantalla
 */
void printAllElements(AlimentoNode **nodeAnchor)
{
  AlimentoNode *currentNode = *nodeAnchor;

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
    cout << "Categoría: " << currentNode->data.get_categoria() << endl;
    cout << "Tiempo de preparación: " << currentNode->data.get_tiempo_preparacion() << endl;
    cout << "Preparación: " << currentNode->data.get_preparacion() << endl;
    cout << "Tipo: " << currentNode->data.get_tipo() << endl;
    cout << endl;

    // Go to next node
    currentNode = currentNode->nextNode;
  }

  pauseScreen();
}

/**
 * Busca un alimento por ID
 */
void searchByID(AlimentoNode **nodeAnchor)
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

  AlimentoNode *previousNode;
  AlimentoNode *currentNode;
  AlimentoNode *tempNode;

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
    cout << "Categoría: " << currentNode->data.get_categoria() << endl;
    cout << "Tiempo de reparación: " << currentNode->data.get_preparacion() << endl;
    cout << "Preparación: " << currentNode->data.get_tipo() << endl;
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
void editElement(AlimentoNode **nodeAnchor)
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

  cout << "ID del platillo: ";
  cin >> id;
  cin.ignore();

  AlimentoNode *previousNode;
  AlimentoNode *currentNode;
  AlimentoNode *tempNode;

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
      cout << "1. ID" << endl;
      cout << "2. Nombre" << endl;
      cout << "3. Costo para el restaurante" << endl;
      cout << "4. Costo para el comensal" << endl;
      cout << "5. Temporada" << endl;
      cout << "6. Tipo" << endl;
      cout << "7. Preraración" << endl;
      cout << "8. Tiempo de preparación" << endl;
      cout << endl;
      cin >> opc;
      cin.ignore();

      switch (opc)
      {
      case 1:
        clearConsole();
        cout << "Ingresa el nuevo ID del platillo" << endl;
        cin >> newId;
        currentNode->data.set_id(newId);

        editElementFromFile(id, "id", to_string(newId));

        cout << "ID modificado exitosamente" << endl;
        break;

      case 2:
        clearConsole();
        cout << "Ingresa el nuevo nombre del platillo" << endl;
        std::getline(cin, newName);
        currentNode->data.set_nombre(newName);
        cout << "Nombre del platillo modificado exitosamente" << endl;

        editElementFromFile(id, "nombre", newName);

        break;

      case 3:
        clearConsole();
        cout << "Ingresa el nuevo costo del platillo para el restaurante" << endl;
        cin >> newCostRest;
        currentNode->data.set_costo_restaurante(newCostRest);
        cout << "Costo del platillo para el restaurante modificado exitosamente" << endl;

        editElementFromFile(id, "costo_restaurante", to_string(newCostRest));

        break;

      case 4:
        clearConsole();
        cout << "Ingresa el nuevo costo del platillo para el comensal" << endl;
        cin >> newCostClient;
        currentNode->data.set_costo_comensal(newCostClient);
        cout << "Costo del platillo para el comensal modificado exitosamente" << endl;

        editElementFromFile(id, "costo_comensal", to_string(newCostClient));

        break;

      case 5:
        clearConsole();
        cout << "Ingresa la nueva temporada del platillo" << endl;
        std::getline(cin, newSeason);
        currentNode->data.set_temporada(newSeason);
        cout << "Temporada del platillo modificada exitosamente" << endl;

        editElementFromFile(id, "temporada", newSeason);

        break;

      case 6:
        clearConsole();
        cout << "Ingresa la nueva categoria del platillo" << endl;
        std::getline(cin, newCategory);
        currentNode->data.set_categoria(newCategory);
        cout << "Categoria del platillo modificada exitosamente" << endl;

        editElementFromFile(id, "categoria", newCategory);

        break;

      case 7:
        clearConsole();
        cout << "Ingresa la nueva preparacion del platillo" << endl;
        std::getline(cin, newPreparation);
        currentNode->data.set_preparacion(newPreparation);
        cout << "Preparacion del platillo modificada exitosamente" << endl;

        editElementFromFile(id, "preparacion", newPreparation);

        break;

      case 8:
        clearConsole();
        cout << "Ingresa el nuevo tiempo de preparacion del platillo" << endl;
        cin >> newPrepTime;
        currentNode->data.set_tiempo_preparacion(newPrepTime);
        cout << "Tiempo de preparacion del platillo modificado exitosamente" << endl;

        editElementFromFile(id, "tiempo_preparacion", to_string(newPrepTime));

        break;

      default:
        clearConsole();
        cout << "Opcion desconocida" << endl;
        break;
      }

      pauseScreen();

      cout << "¿Desea editar un campo más?" << endl;
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

/*
 * Ordenar alimentos por nombre usando "bubble sort"
 */
void bubbleSortByName(AlimentoNode **nodeAnchor)
{
  clearConsole();
  // Title
  cout << endl;
  cout << "- Ordenar alimentos por nombre -" << endl;

  if (*nodeAnchor == nullptr)
  {
    cout << endl;
    cout << "La lista está vacía" << endl;

    pauseScreen();

    return;
  }

  AlimentoNode *puntero = *nodeAnchor;
  AlimentoNode *aux = nullptr;
  Alimento dato;

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

  cout << endl;
  cout << "Los platillos fueron ordenados correctamente" << endl;

  pauseScreen();
}

/*
 * Ordenar alimentos por tiempo de peparación usando "bubble sort"
 */
void bubbleSortByCookTime(AlimentoNode **nodeAnchor)
{
  clearConsole();
  // Title
  cout << endl;
  cout << "- Ordenar alimentos por tiempo de preparación -" << endl;

  if (*nodeAnchor == nullptr)
  {
    cout << endl;
    cout << "La lista está vacía" << endl;
    cout << endl;

    pauseScreen();

    return;
  }

  AlimentoNode *puntero = *nodeAnchor;
  AlimentoNode *aux = nullptr;
  Alimento dato;

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

  cout << endl;
  cout << "Los platillos fueron ordenados correctamente" << endl;

  pauseScreen();
}

/*
 * Busca por id el elemento para agregar a la comanda
 */
Alimento searchFood(AlimentoNode **nodeAnchor, int id)
{
  Alimento result;

  if (*nodeAnchor == nullptr)
  {
    cout << endl;
    cout << "La lista está vacía" << endl;
  }

  cin.ignore();

  AlimentoNode *previousNode;
  AlimentoNode *currentNode;
  AlimentoNode *tempNode;

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
    result = currentNode->data;
  }
  else
  {
    cout << endl;
    cout << "No se encontró el elemento con ID: " << id << endl;

    pauseScreen();
  }

  return result;
  pauseScreen();
}

/*
 * Funcion para hacer el cambio
 */
void swapData(Alimento &a, Alimento &b)
{
  Alimento aux(a);
  a = b;
  b = aux;
}

/* 
 * QuickSort
 */
void quickSort(Alimento *array, int left, int right)
{
  int i = left, j = right;
  Alimento aux;
  Alimento piv = array[static_cast<int>((left + right) / 2)];

  while (i <= j)
  {
    while (&array[i] != nullptr && array[i].get_tiempo_preparacion() < piv.get_tiempo_preparacion())
    {
      i++;
    }

    while (&array[i] != nullptr && array[j].get_tiempo_preparacion() > piv.get_tiempo_preparacion())
    {
      j--;
    }

    if (i < j)
    {
      aux = array[i];
      array[i] = array[j];
      array[j] = aux;
      i++;
      j--;
    }
  }

  if (left < j)
  {
    quickSort(array, left, j);
  }
  else if (i < right)
  {
    quickSort(array, i, right);
  }
}

/*
 * Registra la comanda, la ordena por tiempo y apila los platillos
*/
void registerOrder(AlimentoNode **nodeAnchor)
{
  int N, id;
  Stack<Alimento> pila;
  Queue<Alimento> cola;
  Alimento *platillo;

  clearConsole();

  cout << endl;
  cout << "- Registrar una comanda - " << endl;

  if (*nodeAnchor == nullptr)
  {
    cout << endl;
    cout << "No existen platillos registrados" << endl;

    pauseScreen();

    return;
  }

  cout << "Ingresa la cantidad de platillos que deseas registrar para esta comanda: ";
  cin >> N;

  Alimento *comanda[N];

  // Ingresa los platillos a un arreglo
  for (int i = 0; i < N; i++)
  {
    cout << "Ingresa el ID del platillo " << i + 1 << " que deseas registrar en la comanda: ";
    cin >> id;
    platillo = new Alimento;
    *platillo = searchFood(nodeAnchor, id);
    comanda[i] = platillo;
  }

  // Ordenamiento de los platillos, de mayor a menor para que
  // los menores sean preparados primero
  // cout << endl;
  // cout << "Haciendo ordenamiento..." << endl;
  // quickSort(*comanda, 0, N - 1);

  // Apilamiento de los platillos
  cout << endl
       << "Apilando platillos..." << endl;
  for (int i = 0; i < N; i++)
  {
    pila.push(*comanda[i]);
  }

  // Desapila (volcado de pila) y encola los platillos
  cout << endl;
  cout << "Desapilando y encolando platillos..." << endl;
  while (!pila.isEmpty())
  {
    cola.enqueue(pila.pop());
  }

  int count = 1;
  // Desencola y muestra los platillos
  cout << endl;
  cout << "Desencolando platillos..." << endl;
  cout << endl;
  cout << "Orden de preparación de platillos:" << endl;
  while (!cola.isEmpty())
  {
    *platillo = cola.dequeue();
    // Mostrando solo el nombre
    cout << count << ". " << platillo->get_nombre() << endl;

    count++;
  }

  cout << endl;
  pauseScreen();
}
