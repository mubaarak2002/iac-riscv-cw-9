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