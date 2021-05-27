#include <iostream>
#include "Platillo.h"

Platillo::Platillo()
{
  Platillo::id = 0;
  Platillo::nombre = "";
  Platillo::costo_comensal = 0.0f;
  Platillo::tiempo_preparacion = 0.0f;
  Platillo::temporada = "";
  Platillo::categoria = "";
  Platillo::preparacion = "";
}

/* Setters */

void Platillo::set_id(int nuevo_id)
{
  id = nuevo_id;
}

void Platillo::set_nombre(string nuevo_nombre)
{
  nombre = nuevo_nombre;
}

void Platillo::set_costo_restaurante(float nuevo_costo_restaurante)
{
  costo_restaurante = nuevo_costo_restaurante;
}

void Platillo::set_costo_comensal(float nuevo_costo_comensal)
{
  costo_comensal = nuevo_costo_comensal;
}

void Platillo::set_tiempo_preparacion(float nuevo_tiempo_preparacion)
{
  tiempo_preparacion = nuevo_tiempo_preparacion;
}

void Platillo::set_temporada(string nueva_temporada)
{
  temporada = nueva_temporada;
}

void Platillo::set_categoria(string nueva_categoria)
{
  categoria = nueva_categoria;
}

void Platillo::set_preparacion(string nuevo_preparacion)
{
  preparacion = nuevo_preparacion;
}

/* Getters */

int Platillo::get_id() const
{
  return id;
}

string Platillo::get_nombre() const
{
  return nombre;
}

float Platillo::get_costo_restaurante() const
{
  return costo_restaurante;
}

float Platillo::get_costo_comensal() const
{
  return costo_comensal;
}

float Platillo::get_tiempo_preparacion() const
{
  return tiempo_preparacion;
}

string Platillo::get_temporada() const
{
  return temporada;
}

string Platillo::get_categoria() const
{
  return categoria;
}

string Platillo::get_preparacion() const
{
  return preparacion;
}