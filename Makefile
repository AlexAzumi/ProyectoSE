app: main.o Alimento.o Orden.o Menu.o Ingrediente.o
	g++ -o app main.o Alimento.o Orden.o

main.o: main.cpp Alimento.h AlimentoNode.h
	g++ -c main.cpp

Alimento.o: Alimento.cpp Alimento.h
	g++ -c Alimento.cpp

Orden.o: Orden.cpp Orden.h AlimentoNode.h
	g++ -c Orden.cpp

Menu.o: Menu.cpp Menu.h AlimentoNode.h
	g++ -c Menu.cpp

Ingrediente.o: Ingrediente.cpp Ingrediente.h
	g++ -c Ingrediente.cpp

clean:
	rm -f *.o
