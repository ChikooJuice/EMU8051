Debug = -g

Disassembler = disassembler
Init = Init
Instruction = Instructions
UI = UI
obj = main/obj
main = main



EMU8051 : main.o Instruction.o Init.o Disassembler.o ui.o
	gcc $(obj)/main.o $(obj)/Instruction.o $(obj)/Init.o $(obj)/Disassembler.o $(obj)/ui.o -o $@ $(Debug)
	
main.o : $(main)/main.c
	gcc -c $^ -o $(obj)/main.o $(Debug)

Init.o : $(Init)/Init.c
	gcc -c $^ -o $(obj)/$@ $(Debug)

Instruction.o : $(Instruction)/INSTRUCTION.c
	gcc -c $^ -o $(obj)/$@ $(Debug)

Disassembler.o : $(Disassembler)/disassembler.c
	gcc -c $^ -o $(obj)/$@ $(Debug)

ui.o : $(UI)/ui.c
	gcc -c $^ -o $(obj)/$@ $(Debug)

clean:
	rm -r obj/*
