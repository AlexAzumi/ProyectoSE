#include <iostream>
#include <fstream>
#include "../headers/FileSystem.h"
#include "../headers/Alimento.h"

using std::cout;
using std::endl;
using std::fstream;
using std::getline;
using std::ios;
using std::stof;
using std::stoi;
using std::string;

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
 * Obtiene todos los alimentos necesarios para la iniciación del menú
 */
void getAlimentosFromFile(Alimento **anchor, string type)
{
  string text;
  fstream dataFile;

  string delimeter = "=";

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
        Alimento *newElement = new Alimento(stoi(value));
        // Get more elements
        while (getline(dataFile, text))
        {
          if (text.find("nombre") != string::npos)
          {
            string nombre = tokenize(text);
            newElement->set_nombre(nombre);
          }
          else if (text.find("costo_comensal") != string::npos)
          {
            string costo_comensal = tokenize(text);
            newElement->set_costo_comensal(stof(costo_comensal));
          }
          else if (text.find("costo_restaurante") != string::npos)
          {
            string costo_restaurante = tokenize(text);
            newElement->set_costo_restaurante(stof(costo_restaurante));
          }
          else if (text.find("temporada") != string::npos)
          {
            string temporada = tokenize(text);
            newElement->set_temporada(temporada);
          }
          else if (text.find("categoria") != string::npos)
          {
            string categoria = tokenize(text);
            newElement->set_categoria(categoria);
          }
          else if (text.find("preparacion") != string::npos)
          {
            string preparacion = tokenize(text);
            newElement->set_preparacion(preparacion);
          }
          else if (text.find("tipo") != string::npos)
          {
            string tipo = tokenize(text);
            newElement->set_tipo(tipo);
          }
          else
          {
            break;
          }
        }
        // Save to list
        if (anchor == nullptr)
        {
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