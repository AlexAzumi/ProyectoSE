#include <iostream>
#include <fstream>
#include "../headers/FileSystem.h"
#include "../headers/Alimento.h"
#include "../headers/AlimentoNode.h"

using std::cout;
using std::endl;
using std::exit;
using std::fstream;
using std::getline;
using std::ios;
using std::stof;
using std::stoi;
using std::string;

string tokenize(string s);
void printNode(AlimentoNode **node);

/**
 * Obtiene todos los alimentos necesarios para la iniciación del menú
 */
void getAlimentosFromFile(AlimentoNode **anchor, string type)
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

        AlimentoNode *currentNode = *anchor;

        // IMPRIMIR NODO. ¡ELIMINAR AL FIN DEL DESARROLLO!
        printNode(&newNode);

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
      else
      {
        continue;
      }
    }
  }

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
