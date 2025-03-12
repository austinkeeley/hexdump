CC=gcc
CFLAGS=-DHEX_MAIN

demo: hex.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<

.PHONY: clean
clean:
	rm -f *.o
	rm -f demo


