CC=gcc
CFLAGS = -Wall -w -g -lm

quick: quickSort.c
	$(CC) $(CFLAGS) -o quickSort quickSort.c

all: DPR.c iterativeQS.c recursiveQS.c quickSort.c smallquickSort.c
		$(CC) $(CFLAGS) -o DPR DPR.c
		$(CC) $(CFLAGS) -o iterativeQS iterativeQS.c
		$(CC) $(CFLAGS) -o recursiveQS recursiveQS.c
		$(CC) $(CFLAGS) -o quickSort quickSort.c
		$(CC) $(CFLAGS) -o small smallquickSort.c

small: smallquickSort.c
	$(CC) $(CFLAGS) -o small smallquickSort.c

clean:
		$(RM) DPR
		$(RM) iterativeQS
		$(RM) recursiveQS
		$(RM) quickSort
		$(RM) small
