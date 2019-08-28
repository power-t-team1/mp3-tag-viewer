 
SRC:=$(wildcard *.c)
OBJ:= $(patsubst *.c, *.o, $(SRC))
 
mp3_tag_reader.exe: $(OBJ)
	gcc -o  $@ $^ -g 
 
clean:
	rm *.o *.exe
 
run:
	make && ./mp3_tag_reader.exe                           
