app: main.o Platillo.o
	g++ -o app main.o Platillo.o

main.o: main.cpp Platillo.h
	g++ -c main.cpp

Platillo.o: Platillo.cpp Platillo.h
	g++ -c Platillo.cpp

clean:
	rm -f *.o
