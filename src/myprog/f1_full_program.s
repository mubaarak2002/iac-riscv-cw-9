.text
.globl main
main:

    addi    x1, zero, 0x0000

iloop:

    addi    x1, zero, 0x0000
    addi    x1, x1, 0x0001
    addi    x1, x1, 0x0002
    addi    x1, x1, 0x0004
    addi    x1, x1, 0x0008
    addi    x1, x1, 0x0010
    addi    x1, x1, 0x0020
    addi    x1, x1, 0x0040
    addi    x1, x1, 0x0080
    addi    x2, zero, 0xFF
    sub     x1, x2, x1
    jal     x3, ploop
ploop:
    addi    x1, zero, 0x0000    #nop
    addi    x1, zero, 0x0000    #nop
    addi    x1, zero, 0x0000    #nop
    addi    x1, zero, 0x0000    #nop
    jal    x3, oloop
oloop:
    addi  x1, zero, 0xFF
    addi  x1, zero, 0xFF
    addi  x1, zero, 0xFF
    addi  x1, zero, 0xFF
    addi  x1, zero, 0x00
    jal   x3, main


