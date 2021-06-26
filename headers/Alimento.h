#include <iostream>

#ifndef ALIMENTO_H
#define ALIMENTO_H

using std::string;

class Alimento
{
public:
  Alimento();
  Alimento(int id);
  // Setters
  void set_id(int nuevo_id);
  void set_nombre(string nuevo_nombre);
  void set_costo_restaurante(float nuevo_costo_restaurante);
  void set_costo_comensal(float nuevo_costo_comensal);
  void set_tiempo_preparacion(float nuevo_tiempo_preparacion);
  void set_temporada(string nueva_temporada);
  void set_categoria(string nueva_categoria);
  void set_preparacion(string nueva_preparacion);
  void set_tipo(string tipo);
  // Getters
  int get_id() const;
  string get_nombre() const;
  float get_costo_restaurante() const;
  float get_costo_comensal() const;
  float get_tiempo_preparacion() const;
  string get_temporada() const;
  string get_categoria() const;
  string get_preparacion() const;
  string get_tipo() const;

private:
  int id;
  string nombre;
  float costo_restaurante;
  float costo_comensal;
  float tiempo_preparacion;
  string temporada;
  string categoria;
  string preparacion;
  string tipo;
};

#endif