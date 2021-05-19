#include <iostream>

class Platillo {
  private:
    int id;
    string nombre;
    float costo_restaurante;
    float costo_comensal;
    // Ingrediente ingredientes[];
    float tiempo_preparación;
    string temporada;
    string categoria;
    string preparacion;
  public:
    int get_id()
    {
      return id;
    }
    string get_nombre()
    {
      return nombre;
    }
    float get_costo_restaurante()
    {
      return costo_restaurante;
    }
    float get_costo_comensal()
    {
      return costo_comensal;
    }
    float get_tiempo_preparacion()
    {
      return tiempo_preparacion;
    }
    string get_temporada()
    {
      return temporada;
    }
    string get_categoria()
    {
      return categoria;
    }
    string get_preparacion()
    {
      return preparacion;
    }
}

int main() {
  std::cout << "Hello World!\n";
}