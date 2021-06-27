#include <iostream>
#include "../headers/Alimento.h"

Alimento::Alimento()
{
  Alimento::id = 0;
  Alimento::nombre = "";
  Alimento::costo_comensal = 0.0f;
  Alimento::costo_restaurante = 0.0f;
  Alimento::tiempo_preparacion = 0.0f;
  Alimento::temporada = "";
  Alimento::categoria = "";
  Alimento::preparacion = "";
  Alimento::tipo = "";
}

Alimento::Alimento(int id)
{
  Alimento::id = id;
  Alimento::nombre = "";
  Alimento::costo_comensal = 0.0f;
  Alimento::costo_restaurante = 0.0f;
  Alimento::tiempo_preparacion = 0.0f;
  Alimento::temporada = "";
  Alimento::categoria = "";
  Alimento::preparacion = "";
  Alimento::tipo = "";
}

/* Setters */

void Alimento::set_id(int nuevo_id)
{
  this->id = nuevo_id;
}

void Alimento::set_nombre(string nuevo_nombre)
{
  this->nombre = nuevo_nombre;
}

void Alimento::set_costo_restaurante(float nuevo_costo_restaurante)
{
  this->costo_restaurante = nuevo_costo_restaurante;
}

void Alimento::set_costo_comensal(float nuevo_costo_comensal)
{
  this->costo_comensal = nuevo_costo_comensal;
}

void Alimento::set_tiempo_preparacion(float nuevo_tiempo_preparacion)
{
  this->tiempo_preparacion = nuevo_tiempo_preparacion;
}

void Alimento::set_temporada(string nueva_temporada)
{
  this->temporada = nueva_temporada;
}

void Alimento::set_categoria(string nueva_categoria)
{
  this->categoria = nueva_categoria;
}

void Alimento::set_preparacion(string nuevo_preparacion)
{
  this->preparacion = nuevo_preparacion;
}

void Alimento::set_tipo(string tipo)
{
  this->tipo = tipo;
}

/* Getters */

int Alimento::get_id() const
{
  return id;
}

string Alimento::get_nombre() const
{
  return nombre;
}

float Alimento::get_costo_restaurante() const
{
  return costo_restaurante;
}

float Alimento::get_costo_comensal() const
{
  return costo_comensal;
}

float Alimento::get_tiempo_preparacion() const
{
  return tiempo_preparacion;
}

string Alimento::get_temporada() const
{
  return temporada;
}

string Alimento::get_categoria() const
{
  return categoria;
}

string Alimento::get_preparacion() const
{
  return preparacion;
}

string Alimento::get_tipo() const
{
  return this->tipo;
}