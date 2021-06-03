#include <iostream>
#include "Ingrediente.h"

using std::string;

Ingrediente::Ingrediente()
{
  this->id = 0;
  this->name = "";
  this->amount = 0;
}

Ingrediente::Ingrediente(int id, string name, int amount)
{
  this->id = id;
  this->name = name;
  this->amount = amount;
}

void Ingrediente::set_id(int id)
{
  this->id = id;
}

void Ingrediente::set_name(string name)
{
  this->name = name;
}

void Ingrediente::set_amount(int amount)
{
  this->amount = amount;
}

int Ingrediente::get_id() const
{
  return this->id;
}

string Ingrediente::get_name() const
{
  return this->name;
}

int Ingrediente::get_amount() const
{
  return this->amount;
}