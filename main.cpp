#include <iostream>

using std::string;

class Platillo {
  private:
    int id;
    string nombre;
    float costo_restaurante;
    float costo_comensal;
    float tiempo_preparacion;
    string temporada;
    string categoria;
    string preparacion;
  public:
    // Setters
    void set_id(int id)
    {
      Platillo::id = id;
    }
    void set_nombre(string nombre)
    {
      Platillo::nombre = nombre;
    }
    void set_costo_restaurante(float costo_restaurante)
    {
      Platillo::costo_restaurante = costo_restaurante;
    }
    void set_costo_comensal(float costo_comensal)
    {
      Platillo::costo_comensal = costo_comensal;
    }
    void set_tiempo_preparacion(float tiempo_preparacion)
    {
      Platillo::tiempo_preparacion = tiempo_preparacion;
    }
    void set_temporada(string temporada)
    {
      Platillo::temporada = temporada;
    }
    void set_categoria(string categoria)
    {
      Platillo::categoria = categoria;
    }
    void set_preparacion(string preparacion)
    {
      Platillo::preparacion = preparacion;
    }
    // Getters
    int get_id() const
    {
      return id;
    }
    string get_nombre() const
    {
      return nombre;
    }
    float get_costo_restaurante() const
    {
      return costo_restaurante;
    }
    float get_costo_comensal() const
    {
      return costo_comensal;
    }
    float get_tiempo_preparacion() const
    {
      return tiempo_preparacion;
    }
    string get_temporada() const
    {
      return temporada;
    }
    string get_categoria() const
    {
      return categoria;
    }
    string get_preparacion() const
    {
      return preparacion;
    }
};


class Ingrediente
{
    private:
        int id;
        string nombreIngrediente;
        int cantidad;
        string medida;
        float Tcoccion;

      Ingrediente()
{
        id=0;
        nombreIngrediente="-";
        cantidad=0;
        medida="-";
        Tcoccion=0;
}
public:


friend class Platillo;
void setId(const int& valor)
{
   id=valor;
}
int getId()const
{
    return id;
}



void setNombreIngrediente(const string& valor)
{
    nombreIngrediente=valor;
}
string getNombreIngrediente()const
{
    return nombreIngrediente;
}



void setCantidad(const int& valor)
{
    cantidad=valor;
}
int getCantidad()const
{
    return cantidad;
}



void setMedida(const string& valor)
{
    medida=valor;
}
string getMedida()const
{
    return medida;
}



void setTcoccion(const float& valor)
{
    Tcoccion=valor;

}
float getTcoccion()const
{
    return Tcoccion;
}



~Ingrediente()
{
    //dtor
}

};


int main() {
  std::cout << "Hello World!\n";
}