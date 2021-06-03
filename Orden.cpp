#include <iostream>
#include "Orden.h"
#include "Platillo.h"

Orden::Orden(int id, int table)
{
  this->id = id;
  this->table = table;
  this->total = 0.0f;
  this->count = 0;
  this->platilloAnchor = nullptr;
}

void Orden::set_id(int id)
{
  this->id = id;
}

void Orden::set_table(int table)
{
  this->table = table;
}

void Orden::set_total(int total)
{
  this->total = total;
}

int Orden::get_id() const
{
  return this->id;
}

int Orden::get_table() const
{
  return this->table;
}

float Orden::get_total() const
{
  return this->total;
}

PlatilloNode *Orden::get_platillo_anchor() const
{
  return this->platilloAnchor;
}

void Orden::calculate_and_assign_total()
{
  float tempTotal = 0.0f;
  PlatilloNode *currentNode;

  currentNode = this->platilloAnchor;

  while (currentNode->nextNode != nullptr)
  {
    tempTotal += currentNode->data.get_costo_comensal();
    currentNode = currentNode->nextNode;
  }

  // Assign total
  this->total = tempTotal;
}