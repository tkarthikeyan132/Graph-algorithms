all:	app

app: main.o
	g++ main.o -o app
main.o:	Module5.o
	g++ -c main.cpp Module5.o -o main.o
Module1.o:	Module2.o
	g++ -c Module1.cpp Module2.o -o Module1.o
Module2.o:	GraphSTL.o
	g++ -c Module2.cpp GraphSTL.o -o Module2.o
Module3.o:	GraphSTL.o
	g++ -c Module3.cpp
Module4.o:	Module1.o
	g++ -c Module4.cpp Module1.o -o Module4.o
Module5.o:	Module4.o
	g++ -c Module5.cpp Module4.o -o Module5.o
GraphSTL.o:
	g++ -c GraphSTL.cpp -o GraphSTL.o
clear:
	rm -rf *o hello