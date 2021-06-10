#include <iostream>

using std::string;

#ifndef INGREDIENTE_H
#define INGREDIENTE_H

class Ingrediente
{
private:
  int id;
  string name;
  int amount;

public:
  Ingrediente();
  Ingrediente(int id, string name, int amount);
  // Setters
  void set_id(int id);
  void set_name(string name);
  void set_amount(int amount);
  // Getters
  int get_id() const;
  string get_name() const;
  int get_amount() const;
};

#endif