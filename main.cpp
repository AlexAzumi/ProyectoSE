#include <iostream>
#include <string>

// Declarations
#define MAX_MENU 50
#define MAX_ORDER 5

// Needed stuff from std
using std::string;
using std::cout;

/**
 * - Integrantes del equipo -
 * Hernández Suárez Cesar Alejandro (Nuevo líder)
 * Guillen Aguallo Diego
 * Gonzalez Barrientos Alberto
 * Valdivia Nario Julián André
 * Bañuelos Rivas Jose Alfredo
 */


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
    Platillo() {
      this->id = 0;
      this->nombre = "";
      this->costo_comensal = 0.0f;
      this->tiempo_preparacion = 0.0f;
      this->temporada = "";
      this->categoria = "";
      this->preparacion = "";
    }
    Platillo(int id) {
      this->id = id;
      this->nombre = "";
      this->costo_comensal = 0.0f;
      this->tiempo_preparacion = 0.0f;
      this->temporada = "";
      this->categoria = "";
      this->preparacion = "";
    }
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

// Clase ingrediente
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
    id = valor;
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
};

// Clase Menu
class Menu
{
  private:
    Platillo platillos[MAX_MENU];
    string temporada;

  public:
    Menu(){ }
    
    ~Menu() { }
    
    // Ingresar los platillos de temporada
    void setPlatillos(Platillo platillos[MAX_MENU])
    {
      for (int i = 0; i < MAX_MENU; i++)
      {
        this->platillos[i] = platillos[i];
      }
    }

    // Ingresar la temporada del Menu
    void setTemporadaMenu(string nvaTemp)
    {
      this->temporada = nvaTemp;
    }

    // Mostrar temporada del menu
    string getTemporada()
    {
      return this->temporada;
    }

};

// Clase Orden
class Orden
{
  private:
    int id;
    int mesa;
    Platillo platillo[5];
    float total;
    int contP = 0;
  public:
    Orden(int id,int mesa,Platillo platillos[MAX_ORDER])
    {
        this->id = id;
        this->mesa = mesa;
        // Guardar todos los platillos
        for (int i = 0; i < MAX_ORDER; i++)
        {
          this->platillo[i] = platillos[i];
        }
        this->set_total();
    }
    void set_id(int id)
    {
      this->id=id;
    }
    void set_platillo(Platillo platillo)
    {
      this->platillo[contP]=  platillo;
      contP++;
    }
    int get_id()
    {
      return id;
    }
    Platillo get_platillo(int pos)
    {
      return platillo[pos];
    }
    float get_total()
    {
        return this->total;
    }
    void set_total()
    {
      for (int i = 0; i < MAX_ORDER; i++)
      {
        this->total += platillo[i].get_costo_comensal();
      }
    }
};

int main() {
  cout << "Funciona! :)\n";
}