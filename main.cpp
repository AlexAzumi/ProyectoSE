#include <iostream>
#include <string>
// Classes
#include "Platillo.h"

// Declarations
#define MAX_MENU 50
#define MAX_ORDER 5

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

// Clase ingrediente
class Ingrediente
{
  private:
    int id;
    string nombreIngrediente;
    int cantidad;
    string medida;
    float Tcoccion;

    Ingrediente()
    {
      id=0;
      nombreIngrediente="-";
      cantidad=0;
      medida="-";
      Tcoccion=0;
    }
  public:

  friend class Platillo;

  void setId(const int& valor)
  {
    id = valor;
  }
  int getId()const
  {
    return id;
  }
  void setNombreIngrediente(const string& valor)
  {
    nombreIngrediente=valor;
  }
  string getNombreIngrediente()const
  {
    return nombreIngrediente;
  }
  void setCantidad(const int& valor)
  {
    cantidad=valor;
  }
  int getCantidad()const
  {
    return cantidad;
  }
  void setMedida(const string& valor)
  {
    medida=valor;
  }
  string getMedida()const
  {
    return medida;
  }
  void setTcoccion(const float& valor)
  {
    Tcoccion=valor;

  }
  float getTcoccion()const
  {
    return Tcoccion;
  }
};

// Clase Menu
class Menu
{
  private:
    Platillo platillos[MAX_MENU];
    string temporada;

  public:
    Menu(){ }
    
    ~Menu() { }
    
    // Ingresar los platillos de temporada
    void setPlatillos(Platillo platillos[MAX_MENU])
    {
      for (int i = 0; i < MAX_MENU; i++)
      {
        this->platillos[i] = platillos[i];
      }
    }

    // Ingresar la temporada del Menu
    void setTemporadaMenu(string nvaTemp)
    {
      this->temporada = nvaTemp;
    }

    // Mostrar temporada del menu
    string getTemporada()
    {
      return this->temporada;
    }

};

// Clase Orden
class Orden
{
  private:
    int id;
    int mesa;
    Platillo platillo[5];
    float total;
    int contP = 0;
  public:
    Orden(int id,int mesa,Platillo platillos[MAX_ORDER])
    {
        this->id = id;
        this->mesa = mesa;
        // Guardar todos los platillos
        for (int i = 0; i < MAX_ORDER; i++)
        {
          this->platillo[i] = platillos[i];
        }
        this->set_total();
    }
    void set_id(int id)
    {
      this->id=id;
    }
    void set_platillo(Platillo platillo)
    {
      this->platillo[contP]=  platillo;
      contP++;
    }
    int get_id()
    {
      return id;
    }
    Platillo get_platillo(int pos)
    {
      return platillo[pos];
    }
    float get_total()
    {
        return this->total;
    }
    void set_total()
    {
      for (int i = 0; i < MAX_ORDER; i++)
      {
        this->total += platillo[i].get_costo_comensal();
      }
    }
};

struct PlatilloNode
{
  Platillo data;
  struct PlatilloNode *nextNode;
};

typedef PlatilloNode *PlatilloNodePointer;
// Methods: Platillo
void deleteByID(PlatilloNodePointer *nodeAnchor);
void insertElementEnd(PlatilloNodePointer *nodeAnchor, int *lastID);
void insertElementStart(PlatilloNodePointer *nodeAnchor, int *lastID);
void printAllElements(PlatilloNodePointer nodeAnchor);
void searchByID(PlatilloNodePointer *nodeAnchor);
// Helpers
int clearConsole();
int getMenu();
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

    switch(option) {
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
      case 8:
      {
        printAllElements(nodeAnchor);
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
int clearConsole()
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
    currentNode  = currentNode->nextNode;
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
    currentNode  = currentNode->nextNode;
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