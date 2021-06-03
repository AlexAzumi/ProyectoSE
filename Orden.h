#include <iostream>
// Struct nodes
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
    void get_id() const;
    void get_table() const;
    void get_total() const;
    void get_platillo_anchor() const;

  private:
    int id;
    int table;
    PlatilloNode *anchorNode;
    float total;
    int count;
}