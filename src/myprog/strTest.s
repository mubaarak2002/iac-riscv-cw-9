.text
.globl main
main:
    addi    x0, zero, 0x00      # zero register
    addi    t1, zero, 0xff      # load t1 with 32
    addi    t2, zero, 0x20      # load a2 with 16
    addi    t3, zero, 0x08      # load a3 with 8

    sw      t1, 0x10(x0)
    sw      t2, 0x11(x0)
    sw      t3, 0x12(x0)

    addi    x1, zero, 0x0000    #nop
    addi    x1, zero, 0x0000    #nop
    addi    x1, zero, 0x0000    #nop

    lw      t4, 0x10(x0)
    lw      t5, 0x11(x0)
    lw      t6, 0x12(x0)

    addi    x1, zero, 0x0000    #nop
    addi    x1, zero, 0x0000    #nop    



