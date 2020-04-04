all:	app1 app2 app4 app5

app1:	app1.o
	g++ app1.o Module1.o GraphSTL.o -o app1
app2:	app2.o
	g++ app2.o Module2.o GraphSTL.o -o app2
app3: 	GraphSTL.o Module3.o app3.o
	g++ app3.o Module3.o GraphSTL.o -o app3
app4: 	app4.o
	g++ app4.o Module4.o GraphSTL.o -o app4
app5: 	app5.o
	g++ GraphSTL.o Module1.o Module5.o app5.o -o app5
app1.o: Module1.o app1.cpp
	g++ -c app1.cpp
app2.o: Module2.o app2.cpp
	g++ -c app2.cpp
app3.o: Module3.o app3.cpp
	g++ -c app3.cpp
app4.o: Module4.o app4.cpp
	g++ -c app4.cpp
app5.o: Module5.o app1.cpp
	g++ -c app5.cpp
Module1.o:	GraphSTL.o Module1.cpp
	g++ -c Module1.cpp
Module2.o:	GraphSTL.o Module2.cpp
	g++ -c Module2.cpp
Module3.o:	GraphSTL.o Module3.cpp
	g++ -c Module3.cpp
Module4.o:	GraphSTL.o Module4.cpp
	g++ -c Module4.cpp
Module5.o:	Module1.o Module5.cpp
	g++ -c Module5.cpp
GraphSTL.o: GraphSTL.cpp
	g++ -c GraphSTL.cpp
clear:
	rm -rf *o hello