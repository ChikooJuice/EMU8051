[ ] Write Readme and push it to github repo

``` diff 
- WARNING !!!

EMU8051 is under development and is not working yet.
We would be vary happy to welcome contributors to the project !

You are welcome to ask if you need any help or have any question regarding this project.
```
## Introduction and Motive

Emu8051 is emulates the hardware of AT89C51. The Emulator is purely for educational purpose, to know what goes inside a micro contoller when it executes the program you wrote. 

Generally the way in which we are taught micro-controller and processor, is that we learn about its architecture, how much RAM, ROM is there, the registers in it etc, we write program in assembly or C or any high level language, compile it and load it using some loader readily available, and observe the output like blinking of LED or anything like that.

In this way, we only know the architecture of it, never understands it. Micro-controller is like black box to you where you just load program in it, apply Vcc and ground and with appropriate connection to pins in IC you can have your output. But **what is happening inside the microcontroller  when we load our program? where are those registers? Are they in ROM or some RAM? is compiler only compiling the program I wrote or also adding some startup code with that? where is ISR written? is it added my compiler or assembler or its just written in ROM permanent in hardware? can we change ISR ?**

8051 was among first micro-controllers that came in the world, and it is based on MCS-51 Architecture. It consist of 8 bit CPU, 64k program and code memory. 4K On-Chip memory. 128 bytes on chip RAM. Two 16 bits timers. Full duplex UART. Simple enough to program, but big enough to understand the vitals of micro-controller. 

At its Core, we have an array of memory and micro-controller just expresses the value of those memory location onto some terminals to outside world. If we look at Memory Map of 8051 given in refrence manual, we can see that inside the upper 128 byte internal RAM, location of Port 1, Port2, accumulator, IP etc, all are defined. Whatever value we write to for example memory location defined for port 1, it gets reflected in output peripheral of port 1. While programming the emulator we keep same perpective in mind.

Whole 8051 is struct of memory array and all the instructions read/write and do operation on these memory locations.


## Datasheet and Refrence Manual

[Ref Manual](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwigk5vP9MLwAhUZxTgGHZVlB8wQFjAAegQIBRAD&url=http%3A%2F%2Fweb.mit.edu%2F6.115%2Fwww%2Fdocument%2F8051.pdf&usg=AOvVaw2_1KC25oDgpoVARNveiqCC) to download the refrence manual of 8051.

[Datasheet](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwjF0JKS9cLwAhWPyzgGHTw6CWMQFjAAegQIBRAD&url=https%3A%2F%2Fwww.keil.com%2Fdd%2Fdocs%2Fdatashts%2Fatmel%2Fat89c51_ds.pdf&usg=AOvVaw1ikG_PGQSUg0tY-GexdDCz) to download at89c51 datasheet.


# Checklist

- [ ] program function to update PSW after each individual instruction
- [ ] program Instructions variations of ADD.
