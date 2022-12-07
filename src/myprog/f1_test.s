.text
.globl main
main:
    addi    t1, zero, 0xff      # load t1 with 255
    addi    a0, zero, 0x0       # a0 is used for output

    addi    a6, zero, 0x0000
    addi    a6, zero, 0x0001
    addi    a6, zero, 0x0002
    addi    a6, zero, 0x0004
    addi    a6, zero, 0x0008
    addi    a6, zero, 0x0010
    addi    a6, zero, 0x0020
    addi    a6, zero, 0x0040
    addi    a6, zero, 0x0080
    addi    a7, zero, 0x00FF
    sub     a6, a6, a7



