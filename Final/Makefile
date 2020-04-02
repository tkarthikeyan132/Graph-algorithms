all:	app

app: main.o
	g++ main.o -o app
main.o:	Module1.o Module2.o Module3.o Module4.o Module5.o
	g++ -c main.cpp
Module1.o:	GraphSTL.o
	g++ -c Module1.cpp
Module2.o:	GraphSTL.o
	g++ -c Module2.cpp
Module3.o:	GraphSTL.o
	g++ -c Module3.cpp
Module4.o:	GraphSTL.o
	g++ -c Module4.cpp
Module5.o:	GraphSTL.o
	g++ -c Module5.cpp
GraphSTL.o: GraphSTL.cpp
	g++ -c GraphSTL.cpp
clear:
	rm -rf *o hello