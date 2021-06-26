app: main.o Alimento.o Orden.o Menu.o Ingrediente.o AlimentoListFunctions.o AppFunctions.o AlimentoQueueFunctions.o FileSystem.o
	g++ -o app main.o Alimento.o Orden.o Menu.o Ingrediente.o AlimentoListFunctions.o AppFunctions.o AlimentoQueueFunctions.o FileSystem.o

main.o: main.cpp headers/Alimento.h headers/AlimentoNode.h headers/AlimentoListFunctions.h headers/AppFunctions.h
	g++ -c main.cpp

AppFunctions.o: src/AppFunctions.cpp headers/AppFunctions.h
	g++ -c src/AppFunctions.cpp

FileSystem.o: src/FileSystem.cpp headers/FileSystem.h
	g++ -c src/FileSystem.cpp

Alimento.o: src/Alimento.cpp headers/Alimento.h
	g++ -c src/Alimento.cpp

Orden.o: src/Orden.cpp headers/Orden.h headers/AlimentoNode.h
	g++ -c src/Orden.cpp

Menu.o: src/Menu.cpp headers/Menu.h headers/AlimentoNode.h
	g++ -c src/Menu.cpp

Ingrediente.o: src/Ingrediente.cpp headers/Ingrediente.h
	g++ -c src/Ingrediente.cpp

AlimentoListFunctions.o: src/AlimentoListFunctions.cpp headers/AlimentoListFunctions.h headers/AlimentoNode.h headers/AppFunctions.h
	g++ -c src/AlimentoListFunctions.cpp

AlimentoQueueFunctions.o: src/AlimentoQueueFunctions.cpp headers/AlimentoQueueFunctions.h headers/AlimentoNode.h headers/AppFunctions.h
	g++ -c src/AlimentoQueueFunctions.cpp

clean:
	rm -f *.o
