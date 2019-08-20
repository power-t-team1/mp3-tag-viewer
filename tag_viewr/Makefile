SRC:= $(wildcard *.c)
OBJ:= $(patsubst %.c, %.o, $(SRC))

tags.exe: $(OBJ)
	gcc -o $@ $^

clean:
	rm *.o *.exe

run:
	make && ./tags.exe

