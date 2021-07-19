# Introduction 

Emu8051 emulates hardware of AT89C51. This project is purely for educational purpose, to know what goes inside a micro contoller when it executes the program we upload. 

Generally the way in which we are taught micro-controller or processor, is that we learn about its architecture, how much RAM, ROM is there, the registers in it etc . We write programs in Assembly or C or any high level language, compile it, load it using some loader readily available, and observe the output like blinking of LED or anything like that.

We are only able to know its architecture, we never understands it, or feel it. Micro-controller is like black box to us where we just load program in it, apply Vcc and ground and with appropriate connection to pins in IC you can have your output. **what is happening inside the microcontroller  when we load our program? where are those registers? Are they in ROM or some RAM? Is compiler only compiling the program I wrote or also adding some startup code with that? where is ISR written? Is it added by compiler or assembler or its just written in ROM permanent in hardware? Can we change ISR ?**

8051 was first micro-controllers I learnt. It is based on MCS-51 Architecture, consist of 8 bit CPU, upto 64k program and code memory. 4K On-Chip memory. 128 bytes on chip RAM. Two 16 bits timers. Full duplex UART. Simple enough to program, and big enough to understand the vitals of micro-controller. 

At the Core, 8051 is an array of memory and micro-controller just expresses the value of those memory location onto some terminals or pins to outside world. If we look at Memory Map of 8051 given in refrence manual, we can see that inside the upper 128 byte internal RAM, location of Port 1, Port2, accumulator, IP etc, all are defined. Whatever value we write to for example memory location defined for port 1, it gets reflected in output peripheral of port 1. While programming the emulator we keep same perpective in mind.

Whole 8051 is struct of memory array and all the instructions read/write and do operation on these memory locations.

Also, at hardware level Opcodes are decoded using some kind of jump table, here also, we try to implement all instruction using some kind of jump table.


## Datasheet and Refrence Manual

[Ref Manual](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwigk5vP9MLwAhUZxTgGHZVlB8wQFjAAegQIBRAD&url=http%3A%2F%2Fweb.mit.edu%2F6.115%2Fwww%2Fdocument%2F8051.pdf&usg=AOvVaw2_1KC25oDgpoVARNveiqCC) to download the refrence manual of 8051.

[Datasheet](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwjF0JKS9cLwAhWPyzgGHTw6CWMQFjAAegQIBRAD&url=https%3A%2F%2Fwww.keil.com%2Fdd%2Fdocs%2Fdatashts%2Fatmel%2Fat89c51_ds.pdf&usg=AOvVaw1ikG_PGQSUg0tY-GexdDCz) to download at89c51 datasheet.

## important
The 8051 LCALL instruction stores the address of the next instruction on the stack. The address is pushed onto the stack low-order byte first. The address is, therefore, stored in memory in little endian format.

All other 16-bit and 32-bit values are stored, contrary to other Intel processors, in big endian format, with the high-order byte stored first. For example, the LJMP and LCALL instructions expect 16-bit addresses that are in big endian format.

# How to use the emulator?

> just do $ make and it will compile giving a EMU8051 elf.

> ./EMU8051 < address of .hex file >


## emulator commands 

reg : to view the general purpose registers. Registers of all 4 banks are shown.

mem [ low range of address ] [ high range of address ] : will show memory content in given range of memory.

code [ lower range address ] [ higher range address ] : shows content of code memory in range given as argument

sfr < sfr name > : will give particular SFR content given as argument. If argument passed is 'all' then it shows all SFR contents.

bit : shows contents of bit addressable area

pc : shows current pc value 

set [ SFR name ] [ value ] : set the specified SFR value to value given as argument.

next : emulate the instruction PC currently pointing at.

wr [ memory address ] [ value ] : will write the specified value byte to specified memory address.

clear : clear the screen


> we can write to any register, SFR, or any memory address using wr instruction.