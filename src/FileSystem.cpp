#include <iostream>
#include <fstream>
#include "../headers/FileSystem.h"
#include "../headers/Alimento.h"
#include "../headers/AlimentoNode.h"
#include "../headers/Menu.h"
#include "../headers/AppFunctions.h"

using std::cin;
using std::cout;
using std::endl;
using std::exit;
using std::fstream;
using std::getline;
using std::ios;
using std::ofstream;
using std::remove;
using std::rename;
using std::stof;
using std::stoi;
using std::string;

string tokenize(string s);
void printNode(AlimentoNode **node);
Menu getMyMenu();

/**
 * Obtiene y regresa un menú completo
 */
Menu getMyMenu()
{
  string category = "";
  string season = "";

  clearConsole();

  cout << "- GENERAR MENÚ -" << endl;

  // Obtener temporada
  while (season == "")
  {
    char option[99];

    cout << endl;
    cout << "SELECCIONE TEMPORADA" << endl;
    cout << "1. Primavera" << endl;
    cout << "2. Verano" << endl;
    cout << "3. Otoño" << endl;
    cout << "4. Invierno" << endl;
    cout << "5. Navideño" << endl;
    cout << "Opción: ";
    cin >> option;
    cin.ignore();

    switch (atoi(option))
    {
    case 1:
      season = "Primavera";
      break;
    case 2:
      season = "Verano";
      break;
    case 3:
      season = "Otoño";
      break;
    case 4:
      season = "Invierno";
      break;
    case 5:
      season = "Navideño";
      break;
    default:
      cout << endl;
      cout << "Opción no válida" << endl;
      pauseScreen();
      break;
    }
  }

  // Obtener categoría
  while (category == "")
  {
    char option[99];

    cout << endl;
    cout << "SELECCIONE TIPO/CATEGORÍA" << endl;
    cout << "1. Desayuno" << endl;
    cout << "2. Comida" << endl;
    cout << "3. Cena" << endl;
    cout << "Opción: ";
    cin >> option;
    cin.ignore();

    switch (atoi(option))
    {
    case 1:
      category = "Desayuno";
      break;
    case 2:
      category = "Comida";
      break;
    case 3:
      category = "Cena";
      break;
    default:
      cout << endl;
      cout << "Opción no válida" << endl;
      pauseScreen();
      break;
    }
  }

  // Generar menú
  AlimentoNode *anchor = nullptr;

  getAlimentosFromFile(&anchor, season, category);

  Menu myMenu = Menu(&anchor, season);

  return myMenu;
}

/**
 * Obtiene todos los alimentos necesarios para la iniciación del menú
 */
void getAlimentosFromFile(AlimentoNode **anchor, string season, string category)
{
  string text;
  fstream dataFile;

  // Load the file
  dataFile.open("data.txt", ios::in);

  // Read the file line by line
  while (getline(dataFile, text))
  {
    if (text.find("id") != string::npos)
    {
      // Get ID
      string value = tokenize(text);
      // Save ID
      if (value != "")
      {
        AlimentoNode *newNode = new AlimentoNode;

        if (newNode == nullptr)
        {
          cout << "Error de memoria" << endl;
          cout << "La memoria está llena" << endl;

          exit(0);
        }

        newNode->nextNode = nullptr;
        newNode->data.set_id(stoi(value));

        // Get more elements
        while (getline(dataFile, text))
        {
          if (text.find("nombre") != string::npos)
          {
            string nombre = tokenize(text);
            newNode->data.set_nombre(nombre);
          }
          else if (text.find("costo_comensal") != string::npos)
          {
            string costo_comensal = tokenize(text);
            newNode->data.set_costo_comensal(stof(costo_comensal));
          }
          else if (text.find("costo_restaurante") != string::npos)
          {
            string costo_restaurante = tokenize(text);
            newNode->data.set_costo_restaurante(stof(costo_restaurante));
          }
          else if (text.find("temporada") != string::npos)
          {
            string temporada = tokenize(text);
            newNode->data.set_temporada(temporada);
          }
          else if (text.find("categoria") != string::npos)
          {
            string categoria = tokenize(text);
            newNode->data.set_categoria(categoria);
          }
          else if (text.find("tiempo_preparacion") != string::npos)
          {
            string tiempo_preparacion = tokenize(text);
            newNode->data.set_tiempo_preparacion(stof(tiempo_preparacion));
          }
          else if (text.find("preparacion") != string::npos)
          {
            string preparacion = tokenize(text);
            newNode->data.set_preparacion(preparacion);
          }
          else if (text.find("tipo") != string::npos)
          {
            string tipo = tokenize(text);
            newNode->data.set_tipo(tipo);
          }
          else
          {
            break;
          }
        }

        // Revisar si categoría coincide con la deseada
        if (newNode->data.get_categoria().compare(category) != 0 || newNode->data.get_temporada().compare(season) != 0)
        {
          delete newNode;
        }
        else
        {
          AlimentoNode *currentNode = *anchor;

          // IMPRIMIR NODO. ¡ELIMINAR AL FIN DEL DESARROLLO!
          // printNode(&newNode);

          // Guardar en lista
          if (currentNode == nullptr)
          {
            *anchor = newNode;
          }
          else
          {
            while (currentNode->nextNode != nullptr)
            {
              currentNode = currentNode->nextNode;
            }

            currentNode->nextNode = newNode;
          }
        }
      }
      else
      {
        continue;
      }
    }
  }

  dataFile.close();
}

/**
 * Eliminar un elemento del archivo
 */
void deleteElementFromFile(int id)
{
  string text;
  ofstream temp;
  fstream dataFile;

  // Load the file
  dataFile.open("data.txt", ios::in);

  // Create temporary file
  temp.open("temp.txt");

  bool foundElement = false;

  while (getline(dataFile, text))
  {
    if (text.find("id") != string::npos && !foundElement)
    {
      // Obtener ID
      string value = tokenize(text);
      // Revisar ID
      if (value != "" && stoi(value) == id)
      {
        foundElement = true;
        continue;
      }
      else
      {
        temp << text << endl;
      }
    }
    else if (foundElement)
    {
      // Revisar si se encontró una linea vacía
      // Si esto es así significa que todas las propiedades del elemento que no se deseaba
      // ya fueron ignoradas
      if (text == "")
      {
        foundElement = false;
      }
    }
    else
    {
      // Sigue escribiendo el archivo
      temp << text << endl;
    }
  }

  // Cerrar archivos
  dataFile.close();
  temp.close();

  remove("data.txt");
  rename("temp.txt", "data.txt");
}

/**
 * Añade un elemento al archivo
 */
void addElementToFile(Alimento data)
{
  ofstream dataFile;

  dataFile.open("data.txt", ios::app);

  dataFile << endl;
  dataFile << "id=" << data.get_id() << endl;
  dataFile << "nombre=" << data.get_nombre() << endl;
  dataFile << "costo_comensal=" << data.get_costo_comensal() << endl;
  dataFile << "costo_restaurante=" << data.get_costo_restaurante() << endl;
  dataFile << "tiempo_preparacion=" << data.get_tiempo_preparacion() << endl;
  dataFile << "temporada=" << data.get_temporada() << endl;
  dataFile << "categoria=" << data.get_categoria() << endl;
  dataFile << "preparacion=" << data.get_preparacion() << endl;
  dataFile << "tipo=" << data.get_tipo() << endl;

  dataFile.close();
}

/**
 * Extraer información de la línea de texto
 */
string tokenize(string s)
{
  string del = "=";
  int start = 0;
  int end = s.find(del);

  string lastString = "";

  while (end != -1)
  {
    start = end + del.size();
    end = s.find(del, start);
  }

  return s.substr(start, end - start);
}

/**
 * Imprime toda la información de un nodo
 * ADVERTENCIA: SÓLO PARA DESARROLLO
 */
void printNode(AlimentoNode **node)
{
  cout << endl;
  cout << "ID: " << (*node)->data.get_id() << endl;
  cout << "Nombre: " << (*node)->data.get_nombre() << endl;
  cout << "Costo comensal: " << (*node)->data.get_costo_comensal() << endl;
  cout << "Costo restaurante: " << (*node)->data.get_costo_restaurante() << endl;
  cout << "Tiempo preparación: " << (*node)->data.get_tiempo_preparacion() << endl;
  cout << "Temporada: " << (*node)->data.get_temporada() << endl;
  cout << "Categoría: " << (*node)->data.get_categoria() << endl;
  cout << "Preparación: " << (*node)->data.get_preparacion() << endl;
  cout << "Tipo: " << (*node)->data.get_tipo() << endl;
  cout << endl;
}
