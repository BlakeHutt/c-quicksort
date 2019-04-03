CC=gcc
CFLAGS = -Wall -w -g -lm

build: DPR.c iterativeQS.c recursiveQS.c quickSort.c
		$(CC) $(CFLAGS) -o DPR DPR.c
		$(CC) $(CFLAGS) -o iterativeQS iterativeQS.c
		$(CC) $(CFLAGS) -o recursiveQS recursiveQS.c
		$(CC) $(CFLAGS) -o quickSort quickSort.c

clean:
		$(RM) DPR
		$(RM) iterativeQS
		$(RM) recursiveQS
		$(RM) quickSort
