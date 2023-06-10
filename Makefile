run: main.o administrator_function.o check.o file.o queue.o Reader_function.o sort.o
	gcc -o run main.o administrator_function.o check.o file.o queue.o Reader_function.o sort.o

main.o: total.h main.c
	gcc -c main.c

administrator_function.o: total.h administrator_function.c
	gcc -c administrator_function.c

check.o: total.h check.c
	gcc -c check.c

file.o: total.h file.c
	gcc -c file.c

queue.o: total.h queue.c
	gcc -c queue.c

Reader_function.o: total.h Reader_function.c
	gcc -c Reader_function.c

sort.o: total.h sort.c
	gcc -c sort.c

