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
    // Setters
    void set_id(int id)
    {
      this->id = id;
    }
    void set_nombre(string nombre)
    {
      this->nombre = nombre;
    }
    void set_costo_restaurante(float costo_restaurante)
    {
      this->costo_restaurante = costo_restaurante;
    }
    void set_costo_restaurante(float costo_comensal)
    {
      this->costo_comensal = costo_comensal;
    }
    void set_costo_restaurante(float tiempo_preparacion)
    {
      this->tiempo_preparacion = tiempo_preparacion;
    }
    void set_temporada(string temporada)
    {
      this->temporada = temporada;
    }
    void set_categoria(string categoria)
    {
      this->categoria = categoria;
    }
    void set_preparacion(string preparacion)
    {
      this->preparacion = preparacion;
    }
    // Getters
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