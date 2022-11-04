

main: mallocfree
	gcc -o main main.c -ldl

mallocfree:
	gcc -shared -fpic -o mallocfree.so mallocfree.c -ldl

clean:
	rm -f main
	rm -f *.o
	rm -f *.a
	rm -f *.so