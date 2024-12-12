all: Laba3
clean:
	rm -f Laba3 *.o
Laba3: main.c stek.c sort_pryam.c
	gcc -o Laba3 main.c stek.c sort_pryam.c
start:
	@echo "Running with arguments: $(args)"
	./Laba3 $(args)