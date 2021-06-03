app: main.o Platillo.o Orden.o Menu.o
	g++ -o app main.o Platillo.o Orden.o

main.o: main.cpp Platillo.h PlatilloNode.h
	g++ -c main.cpp

Platillo.o: Platillo.cpp Platillo.h
	g++ -c Platillo.cpp

Orden.o: Orden.cpp Orden.h PlatilloNode.h
	g++ -c Orden.cpp

Menu.o: Menu.cpp Menu.h PlatilloNode.h
	g++ -c Menu.cpp

clean:
	rm -f *.o
