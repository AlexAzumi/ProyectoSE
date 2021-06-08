#include <iostream>
#include "AppFunctions.h"

using std::atoi;
using std::cin;
using std::cout;
using std::endl;

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
  cout << "10. Buscar platillo" << endl;
  cout << "11. Finalizar programa" << endl;
  cout << "Opción: ";
  cin >> option;

  return atoi(option);
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