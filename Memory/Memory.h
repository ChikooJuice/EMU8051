/** Memory outline of 80c51
 * 
 * Total 128 byte RAM
 * 
 * R0 - R7 general purpose registers 
 * 4 General purpose register banks : 0x00 to 0x1F
 * 
 * bit addressable Segment : 0x20 - 0x2F
 * scratch pad area : 0x30 - 0x7F 
 * 
 * Special Function Memory Map : 0x80 - 0xFF
 * 
 * here, we along with internal data memory or RAM we assume, there
 * is external DATA memory attached to out microcontroller of size 8k
 **/

#ifndef MEMORY_H
#define MEMORY_H
#include <stdint.h>
#include <stdlib.h>

#define FLASH 4096

// SFR Memory Map from 0x80 - 0xFF
#define 	P0 	0x80	// Port 0
#define 	SP 	0x81	// Stack Pointer
#define 	DPL 	0x82	// DPTR Low byte
#define 	DPH 	0x83	// DPTR High Byte
#define 	PCON	0x87	// Power Control
#define 	TCON 	0x88	// Timer Control
#define 	TMOD 	0x89	// Timer Mode Control
#define 	TL0 	0x8A	// Timer 0 Low Byte 
#define 	TL1 	0x8B	// Timer 1 Low byte
#define 	TH0 	0x8C	// Timer 0 High Byte
#define 	TH1 	0x8D	// Timer 1 High Byte
#define 	P1 	0x90	// Port 1
#define 	SCON 	0x98	// Serial Control
#define 	SBUF 	0x99	// Serial Buffer
#define 	P2 	0xA0	// Port 2
#define 	IE 	0xA8	// Interrupt Enable
#define 	P3 	0xB0	// Port 3
#define 	IP 	0xB8	// Interrupt Priorit
#define 	PSW 	0xD0	// Program Status Word
#define 	ACC 	0xE0	// Accumulator
#define 	B 	0xF0	// B register


/** PCON : Program Status Word. Bit Addressable
 * 
 * |	P	|	PSW.0	|	Parity Flag			|	
 * |	_	|	PSW.1	|	User defined			|
 * |	OV 	|	PSW.2	|	Overflow flag			|
 * |	RS0	|	PSw.3	|	Register bank selector bit 0	|
 * |	RS1	| 	PSW.4	|	Register bank selector bit 1	| 
 * |	F0	| 	PSw.5	| 	Flag 0 available for user	|
 * |    AC	| 	PSw.6	|	Aux carry flag			|
 * |	CY	|	PSW.7	|	Carry flag			|
 *
 **/

#define		P	(1 << 0)
//#define 	XX	(1 << 1)
#define		OV	(1 << 2)
#define		RS0 	(1 << 3)
#define		RS1 	(1 << 4)
#define 	F0	(1 << 5)
#define 	AC	(1 << 6)
#define		CY 	(1 << 7)

/** PCON : Power Control Register. Not Bit Addressable
 * 
 * |	IDL	|	PCON.0	|	Idle mode bit			|	
 * |	PD	|	PCON.1	|	Power Down bit			|
 * |	GF0 	|	PCON.2	|	General purpose bit		|
 * |	GF1	|	PCON.3	|	General Purpose bit		|
 * |	_	| 	PCON.4	|	reserved for future use		| 
 * |	_	| 	PCON.5	| 	reserved for future use		|
 * |    _	| 	PCON.6	|	reserved for future use		|
 * |	SMOD	|	PCON.7	|	Double baud Rate bit		|
 *
 **/


#define		IDL 	(1 << 0)
#define 	PD	(1 << 1)
#define		GF0	(1 << 2)
#define		GF1	(1 << 3)
//#define	xx 	(1 << 4)
//#define 	xx	(1 << 5)
//#define 	xx	(1 << 6)
#define		SMOD 	(1 << 7)

/** IE : Interrupt Enable. Bit Addressable
 * 
 * |	EX0	|	IE.0	|	external interrupt 0		|				
 * |	ET0	|	IE.1	|	Timer 0 overflow interrupt	|			
 * |	EX1	|	IE.2	|	External interrupt 0		|
 * |	ET1	|	IE.3	|	Timer 1 Overflow flag		|
 * |	ES	| 	IE.4	|	Enable/Disable Serial Port Int	| 
 * |	__	| 	IE.5	| 	___				|
 * |    ___	| 	IE.6	|	___				|
 * |	EA	|	IE.7	|	Disable all interrupts.		|
 *
 **/


#define		EX0 	(1 << 0)
#define 	ET0	(1 << 1)
#define		EX1	(1 << 2)
#define		ET1 	(1 << 3)
#define		ES 	(1 << 4)
#define 	ET2	(1 << 5)
//#define 	XX	(1 << 6)
#define		EA 	(1 << 7)

/** IP : Interrupt Priority Register. Bit Addressable
 * 
 * |	PX0	|	IP.0	|	Ext Interrupt 0 priority level	|				
 * |	PT0	|	IP.1	|	Timer 0 interrupt priority level|			
 * |	PX1 	|	IP.2	|	Ext interrupt 1 priority level	|			
 * |	PT1	|	IP.3	|	Timer 1 Interrupt priority level|
 * |	PS	| 	IP.4	|	Serial port priority level	| 
 * |	__	| 	IP.5	| 	___				|
 * |    __	| 	IP.6	|	___				|
 * |	__	|	IP.7	|	___				|
 *
 **/


#define		PX0 	(1 << 0)
#define 	PT0	(1 << 1)
#define		PX1	(1 << 2)
#define		PT1 	(1 << 3)
#define		PS 	(1 << 4)
//#define 	XX	(1 << 5)
//#define 	XX	(1 << 6)
//#define	XX 	(1 << 7)


/** TCON : Timer/Counter Control Register. Bit Addressable
 * 
 * |	IT0	|	TCON.0	|	Interrupt 0 type control	|				
 * |	IE0	|	TCON.1	|	Ext Int 0 edge flag		|		
 * |	IT1 	|	TCON.2	|	Interrupt 1 type control	|		
 * |	IE1	|	TCON.3	|	Ext Int 1 edge flag		|
 * |	TR0	| 	TCON.4	|	Timer 0 run control bit		| 
 * |	TF0	| 	TCON.5	| 	Timer 0 overflow flag		|
 * |    TR1	| 	TCON.6	|	Timer 1 run control bit		|
 * |	TF1	|	TCON.7	|	Timer 1 overflow flag		|
 **/

#define		IT0 	(1 << 0)
#define 	IE0	(1 << 1)
#define		IT1	(1 << 2)
#define		IE1 	(1 << 3)
#define		TR0 	(1 << 4)
#define 	TF0	(1 << 5)
#define 	TR1	(1 << 6)
#define		TF1	(1 << 7)


/** TMOD : Timer/Counter Mode Control. Not Bit Addressable
 * |	M0	|	PSW.0/4	|	Mode selector bit 0		|	
 * |	M1	|	PSW.1/5	|	Mode selector bit 1		|
 * |	C/T 	|	PSW.2/6	|	Timer or counter selector	|
 * |	GATE	|	PSw.3/7	|	more info down			|
 *
 * 
 * GATE : when TRx(in TCON) is 1 and GATE = 1, timer counter will run only when
 * INTx pin is high, it is hardware controlled.
 * GATE = 0, Timer/counter will run only when when TRx = 1 (software controlled)
 * 
 * bits 0 - 3 : Timer 0
 * bits 4 - 7 : Timer 1
 **/


#define		M0_T0 	(1 << 0)
#define 	M1_T0	(1 << 1)
#define		CT_T0	(1 << 2)
#define		GATE_T0	(1 << 3)
#define		M0_T1	(1 << 4)
#define 	M1_T1	(1 << 5)
#define 	CT_T1	(1 << 6)
#define		GATE_T1	(1 << 7)



// T2CON pending for future


/** SCON : Serial Port Control Register. Bit Addressable
 * 
 * |	RI	|	SCON.0	|	Receive Interrupt flag				|				
 * |	TI	|	SCON.1	|	Transmit Interrupt Flag				|			
 * |	RB8 	|	SCON.2	|	9th data bit received when mode 2 & 3		|			
 * |	TB8	|	SCON.3	|	9th data received when mode 2 & 3		|
 * |	REN	| 	SCON.4	|	Enable/Disable Reception. control by SW		| 
 * |	SM2	| 	SCON.5	| 	Enables multiprocessor communication in mode 2&3|
 * |    SM1	| 	SCON.6	|	Serial Port Mode specifier			|			
 * |	SM0	|	SCON.7	|	Serial port mode specifier			|
 *
 **/

#define		RI 	(1 << 0)
#define 	TI	(1 << 1)
#define		RB8	(1 << 2)
#define		TB8 	(1 << 3)
#define		REN 	(1 << 4)
#define 	SM2	(1 << 5)
#define 	SM1	(1 << 6)
#define		SM0	(1 << 7)



struct GPR {
	int8_t R0;
	int8_t R1;
	int8_t R2;
	int8_t R3;
	int8_t R4;
	int8_t R5;
	int8_t R6;
	int8_t R7;
};


typedef struct cpu {
	struct GPR REGISTERS[4]; // 4 memory bank registers
	int8_t Bit_Addressable[0xF]; // bit addressable area
	int8_t ScratchPad[0x4F];
	int8_t SFR[0x7F];
	int8_t Code_Memory[FLASH];
	uint16_t PC;
	int8_t Bank;
}CPU;

CPU CPU_8051;

#define BANK CPU_8051.Bank




#endif