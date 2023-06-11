run: main.o administrator.o check.o file.o queue.o reader.o sort.o
	gcc -o run main.o administrator.o check.o file.o queue.o reader.o sort.o 

main.o: total.h main.c
	gcc -c main.c

administrator.o: total.h administrator.c
	gcc -c administrator.c

check.o: total.h check.c
	gcc -c check.c

file.o: total.h file.c
	gcc -c file.c

queue.o: total.h queue.c
	gcc -c queue.c

reader.o: total.h reader.c
	gcc -c reader.c

sort.o: total.h sort.c
	gcc -c sort.c

