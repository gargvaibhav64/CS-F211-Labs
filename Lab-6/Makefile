runRecMS : Rec_main.c compRecMS
	gcc -o runRecMS Rec_main.c RecMS.o merge.o

runIterMS : Iter_main.c compRecMS
	gcc -o runIterMS Iter_main.c IterMS.o merge.o

compRecMS : RecMS.c merge.o recMS.h
	gcc -c RecMS.c 

compIterMS : IterMS.c merge.o IterMS.h
	gcc -c IterMS.c 

merge.o : merge.h merge.c struct.h
	gcc -c merge.c

compare : compare.c compIterMS merge.o compRecMS
	gcc -o compare compare.c IterMS.o merge.o RecMS.o
