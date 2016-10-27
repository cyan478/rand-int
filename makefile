randfiletest.out: main.c
	gcc main.c -o randfiletest.out

run: randfiletest.out
	./randfiletest.out

clean:
	rm randfiletest.out