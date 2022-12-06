.text
.globl main
main:
    addi    t0, zero, 0x02      # load t1 with 2
    addi    t1, zero, 0x00      # load t2 with 0
    addi    t2, zero, 0x06      # load t3 with 6
iloop:
    add     a1, t0, t1          # add t2 and t2 in a1
    bne     a1, t2, iloop       # if a1 != 6, branch to iloop

    
