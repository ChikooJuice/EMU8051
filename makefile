Debug = -g

test : main_test.o disassembler.o
	gcc $^ -o $@ $(Debug)
	make clean

main_test.o : main_test.c 
	gcc -c $^ $(Debug)
disassembler.o : disassembler.c 
	gcc -c $^ $(Debug)

clean:
	rm -r *.o
