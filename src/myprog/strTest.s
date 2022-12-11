.text
.globl main
main:
    addi    x0, zero, 0x00      # zero register
    addi    t1, zero, 0xff      # load t1 with 32
    addi    t2, zero, 0x20      # load a2 with 16
    addi    t3, zero, 0x08      # load a3 with 8

    addi    x0, zero, 0x0000    #nop
    addi    x0, zero, 0x0000    #nop
    addi    x0, zero, 0x0000    #nop

    sw      t1, 10(x0)
    sw      t2, 11(x0)
    sw      t3, 12(x0)

    addi    x0, zero, 0x0000    #nop
    addi    x0, zero, 0x0000    #nop
    addi    x0, zero, 0x0000    #nop

    lw      t4, 10(x0)
    lw      t5, 11(x0)
    lw      t6, 12(x0)

    addi    x0, zero, 0x0000    #nop
    addi    x0, zero, 0x0000    #nop    



