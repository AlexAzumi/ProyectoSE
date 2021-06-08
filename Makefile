app: main.o Alimento.o Orden.o Menu.o Ingrediente.o AlimentoListFunctions.o AppFunctions.o
	g++ -o app main.o Alimento.o Orden.o Menu.o Ingrediente.o AlimentoListFunctions.o AppFunctions.o

main.o: main.cpp Alimento.h AlimentoNode.h
	g++ -c main.cpp

AppFunctions.o: AppFunctions.cpp AppFunctions.h
	g++ -c AppFunctions.cpp

Alimento.o: Alimento.cpp Alimento.h
	g++ -c Alimento.cpp

Orden.o: Orden.cpp Orden.h AlimentoNode.h
	g++ -c Orden.cpp

Menu.o: Menu.cpp Menu.h AlimentoNode.h
	g++ -c Menu.cpp

Ingrediente.o: Ingrediente.cpp Ingrediente.h
	g++ -c Ingrediente.cpp

AlimentoListFunctions.o: AlimentoListFunctions.cpp AlimentoListFunctions.h Alimento.h AlimentoNode.h AppFunctions.h
	g++ -c AlimentoListFunctions.cpp

clean:
	rm -f *.o
