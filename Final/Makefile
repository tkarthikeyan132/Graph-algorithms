#declare variables
CC=g++

CFLAGS=-c -w

all:	app1 app2 app3_lpath app3_spath app4 app5

app1:	app1.o
	$(CC) app1.o Module1.o GraphSTL.o -o app1
app2:	app2.o
	$(CC) app2.o Module2.o GraphSTL.o -o app2
app3_lpath: 	App3_LPATH_ALGOS.o
	$(CC) App3_LPATH_ALGOS.o Module3.o Module5.o Module1.o GraphSTL.o -o app3_lpath
app3_spath: 	App3_SPATH_ALGOS.o
	$(CC) App3_SPATH_ALGOS.o Module3.o Module5.o Module1.o GraphSTL.o -o app3_spath
app4: 	app4.o
	$(CC) app4.o Module4.o GraphSTL.o -o app4
app5: 	app5.o
	$(CC) GraphSTL.o Module1.o Module5.o app5.o -o app5
app1.o: Module1.o app1.cpp
	$(CC) $(CFLAGS) app1.cpp
app2.o: Module2.o app2.cpp
	$(CC) $(CFLAGS) app2.cpp
App3_LPATH_ALGOS.o: Module3.o App3_LPATH_ALGOS.cpp
	$(CC) $(CFLAGS) App3_LPATH_ALGOS.cpp
App3_SPATH_ALGOS.o: Module3.o App3_SPATH_ALGOS.cpp
	$(CC) $(CFLAGS) App3_SPATH_ALGOS.cpp
app4.o: Module4.o app4.cpp
	$(CC) $(CFLAGS) app4.cpp
app5.o: Module5.o app1.cpp
	$(CC) $(CFLAGS) app5.cpp
Module1.o:	GraphSTL.o Module1.cpp
	$(CC) $(CFLAGS) Module1.cpp
Module2.o:	GraphSTL.o Module2.cpp
	$(CC) $(CFLAGS) Module2.cpp
Module3.o:	Module5.o Module3.cpp
	$(CC) $(CFLAGS) Module3.cpp
Module4.o:	GraphSTL.o Module4.cpp
	$(CC) $(CFLAGS) Module4.cpp
Module5.o:	Module1.o Module5.cpp
	$(CC) $(CFLAGS) Module5.cpp
GraphSTL.o: GraphSTL.cpp
	$(CC) $(CFLAGS) GraphSTL.cpp
clear:
	rm -rf *o
	find . -maxdepth 1 -type f -executable -exec rm {} +