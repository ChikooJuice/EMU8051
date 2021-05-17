[ ] Write Readme and push it to github repo

``` diff 
- WARNING !!!

EMU8051 is under development and is not working yet.
We would be vary happy to welcome contributors to the project !

You are welcome to ask if you need any help or have any question regarding this project.
```
## Introduction and Motive

Emu8051 emulates hardware of AT89C51. This project is purely for educational purpose, to know what goes inside a micro contoller when it executes the program we upload. 

Generally the way in which we are taught micro-controller or processor, is that we learn about its architecture, how much RAM, ROM is there, the registers in it etc and we write program in assembly or C or any high level language, compile it and load it using some loader readily available, and observe the output like blinking of LED or anything like that.

In this way, we are only able to know architecture of it, we never understands it, or feel it. Micro-controller is like black box to us where we just load program in it, apply Vcc and ground and with appropriate connection to pins in IC you can have your output. **what is happening inside the microcontroller  when we load our program? where are those registers? Are they in ROM or some RAM? Is compiler only compiling the program I wrote or also adding some startup code with that? where is ISR written? Is it added by compiler or assembler or its just written in ROM permanent in hardware? Can we change ISR ?**

8051 was first micro-controllers through which I was introduced with world of micro-controllers. It is based on MCS-51 Architecture. It consist of 8 bit CPU, upto 64k program and code memory. 4K On-Chip memory. 128 bytes on chip RAM. Two 16 bits timers. Full duplex UART. Simple enough to program, and big enough to understand the vitals of micro-controller. 

At the Core, 8051 is an array of memory and micro-controller just expresses the value of those memory location onto some terminals to outside world. If we look at Memory Map of 8051 given in refrence manual, we can see that inside the upper 128 byte internal RAM, location of Port 1, Port2, accumulator, IP etc, all are defined. Whatever value we write to for example memory location defined for port 1, it gets reflected in output peripheral of port 1. While programming the emulator we keep same perpective in mind.

Whole 8051 is struct of memory array and all the instructions read/write and do operation on these memory locations.


## Datasheet and Refrence Manual

[Ref Manual](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwigk5vP9MLwAhUZxTgGHZVlB8wQFjAAegQIBRAD&url=http%3A%2F%2Fweb.mit.edu%2F6.115%2Fwww%2Fdocument%2F8051.pdf&usg=AOvVaw2_1KC25oDgpoVARNveiqCC) to download the refrence manual of 8051.

[Datasheet](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwjF0JKS9cLwAhWPyzgGHTw6CWMQFjAAegQIBRAD&url=https%3A%2F%2Fwww.keil.com%2Fdd%2Fdocs%2Fdatashts%2Fatmel%2Fat89c51_ds.pdf&usg=AOvVaw1ikG_PGQSUg0tY-GexdDCz) to download at89c51 datasheet.


# Checklist

- [*] Init Memory with their initial value as given in ref manual
- [*] program function to update Parity after each individual instruction involving A.
- [ ] program function to choose bank of registers.
- [ ] 
