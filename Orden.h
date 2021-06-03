#include "PlatilloNode.h"

#ifndef ORDEN_H
#define ORDEN_H

class Orden
{
public:
  Orden(int id, int table);
  // Setters
  void set_id(int id);
  void set_table(int id);
  void set_total(int id);
  // Getters
  float get_total() const;
  int get_count() const;
  int get_id() const;
  int get_table() const;
  PlatilloNode *get_platillo_anchor() const;
  // More
  void calculate_and_assign_total();

private:
  int id;
  int table;
  PlatilloNode *platilloAnchor;
  float total;
  int count;
};

#endif