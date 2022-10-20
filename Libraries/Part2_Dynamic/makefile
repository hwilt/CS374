

main: mallocfree
	g++ -c -o main.o main.cpp
	g++ -o main main.o mallocfree.c

mallocfree:
	gcc mallocfree.c -ldl

clean:
	rm -f main
	rm -f *.o
	rm -f *.a