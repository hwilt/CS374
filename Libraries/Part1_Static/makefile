

main: createlibrary
	g++ -c -o main.o main.cpp
	g++ -o main main.o library.a

createlibrary:
	g++ -c -o library.o library.cpp
	ar rcs library.a library.o

clean:
	rm -f main
	rm -f *.o
	rm -f *.a