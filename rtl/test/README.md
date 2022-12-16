#Our F1 Program

## The Program:

```

.text
.globl main
main:
    #noOps are there just to make the lights easier to visulise else they go 
    #by very quickly


    addi    a0, zero, 0x0000
    addi    a0, zero, 0x0000
    addi    x0, zero, 0x0000    
    addi    a0, a0, 0x0001
    addi    x0, zero, 0x0000    #nop
    addi    a0, a0, 0x0002
    addi    x0, zero, 0x0000    #nop
    addi    a0, a0, 0x0004
    addi    x0, zero, 0x0000    #nop
    addi    a0, a0, 0x0008
    addi    x0, zero, 0x0000    #nop

    addi    a0, a0, 0x0010
    addi    x0, zero, 0x0000    #nop
    addi    a0, a0, 0x0020
    addi    x0, zero, 0x0000    #nop
    addi    a0, a0, 0x0040
    addi    x0, zero, 0x0000    #nop
    addi    a0, a0, 0x0080
    addi    x0, zero, 0x0000    #nop
    addi    a1, zero, 0xFF
    sub     a0, a1, a0
    
    jal     a3, ploop
    addi    x0, zero, 0x0000    #nop

ploop: #this is the pause loop, if there were to be a "random delay" this is where it would be
    addi    a0, zero, 0x0000    #nop
    addi    a0, zero, 0x0000    #nop
    addi    a0, zero, 0x0000    #nop
    addi    a0, zero, 0x0000    #nop
oloop:
    addi  a0, zero, 0xFF
    addi  a0, zero, 0xFF
    addi  a0, zero, 0xFF
    addi  a0, zero, 0xFF
    addi  a0, zero, 0x00 #reset lights to off when program is over

```


## Explanation:

This program requires for the register of a0 to go from 1 -> 11 -> 111 ect ... to make all 8 lights light up sequentially. Once allthe lights are on, they need to all be turned off, and then after a delay, turned on again.

The code accomplishes this simply by using add-immidiate instructions. Each step it adds the needed power of 2 (next 1 digit) required to have the next light increment. Afterwards, once all the lights are on, theystay on for a bit longer, once cycle to be exact, where the value of all lights being on, 0xFF, is stored in a1, then a subtraction operation occurs, immidiately turning all the lights off. 

Then the first jump operation occurs, this jumps to the ploop (pause-loop). This is a segment of code that is currently full of no-ops, to simulate the random delay. THe reaso for this is that it with our reduced-RSIC-V instruction set, simulating random time delays is very difficult, but if the instruction set were to be expanded, it can easily be done by just inserting instructions between lines 42 and 43. Thus, without any major reworks, the code can be expanded upon easily.

Finally, the code enters the oloop (on-loop), where the lights stay on, to simulate "go", then turn off after a random interval of time.

The code is designed to be minimalistic, and as lightweight as possible to allow for it to be implemented in as small a chip as possible. The no-ops inbetwen the immidiate commands are just there to help visualise the led bar lighting up, else it goes very quickly. This can be fixed just by turning down the clock cycle on the cpu for a real world solution without having noOps.

Overall the code works as intended and has achieved the goal of being as minimalist as possible, while allowing for room to expand