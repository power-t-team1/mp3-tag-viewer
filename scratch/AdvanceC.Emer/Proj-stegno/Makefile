SRC:= $(wildcard *.c)
OBJ:= $(patsubst %.c, %.o, $(SRC))

steno.exe: $(OBJ)
	gcc -o $@ $^

clean:
	rm *.o *.exe
run:
	make && ./steno.exe

