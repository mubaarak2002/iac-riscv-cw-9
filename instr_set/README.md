# Instruction Set

1. lui: load upper Immediate (type U instruction)
    
    Format: lui rd, imm
    
    ![Screenshot 2022-12-05 at 11.39.21 PM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-05_at_11.39.21_PM.png)
    
2. lw (load all 32 bits) (type I1 instruction)
    
    Format: lw rd, offset(rs1)
    
    ![Screenshot 2022-12-05 at 11.40.38 PM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-05_at_11.40.38_PM.png)
    
    Loads a 32-bit value from memory and sign-extends before storing it in register rd.
    
    offset is immediate
    
3. add (type R instruction)
    
    Format: add rd, rs1, rs2
    
    ![Screenshot 2022-12-05 at 11.41.28 PM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-05_at_11.41.28_PM.png)
    
    Adds the registers rs1 and rs2 and stores the result in rd.
    
4. addi (type I1 instruction)
    
    Format: addi rd, rs1, imm
    
    ![Screenshot 2022-12-05 at 11.44.08 PM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-05_at_11.44.08_PM.png)
    
    Adds the sign-extended 12-bit immediate to register rs1.
    
5. sub (type R instruction)
    
    Format: sub rd, rs1, rs2
    
    ![Screenshot 2022-12-05 at 11.54.12 PM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-05_at_11.54.12_PM.png)
    
    Subs the register rs2 from rs1 and stores the result in rd.
    
6. OR (type R instruction)
    
    Format: or rd, rs1, rs2
    
    ![Screenshot 2022-12-05 at 11.56.39 PM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-05_at_11.56.39_PM.png)
    
    Performs bitwise OR on registers rs1 and rs2 and place the result in rd
    
7. ori (type I1 instruction)
    
    Format: ori rd, rs1, imm
    
    ![Screenshot 2022-12-05 at 11.57.06 PM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-05_at_11.57.06_PM.png)
    
    Performs bitwise OR on register rs1 and the sign-extended 12-bit immediate and place the result in rd
    
8. xor (type R instruction)
    
    Format: xor rd, rs1, rs2
    
    ![Screenshot 2022-12-05 at 11.57.49 PM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-05_at_11.57.49_PM.png)
    
    Performs bitwise XOR on registers rs1 and rs2 and place the result in rd
    
9. xori (type I1 instruction)
    
    Format: xori rd, rs1, imm
    
    ![Screenshot 2022-12-05 at 11.58.22 PM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-05_at_11.58.22_PM.png)
    
    Performs bitwise XOR on register rs1 and the sign-extended 12-bit immediate and place the result in rd
    
10. and (type R instruction)
    
    Format: and rd, rs1, rs2
    
    ![Screenshot 2022-12-05 at 11.59.29 PM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-05_at_11.59.29_PM.png)
    
    Performs bitwise AND on registers rs1 and rs2 and place the result in rd
    
11. andi (type I1 instruction)
    
    Format: andi rd, rs1, imm
    
    ![Screenshot 2022-12-05 at 11.59.49 PM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-05_at_11.59.49_PM.png)
    
    Performs bitwise AND on register rs1 and the sign-extended 12-bit immediate and place the result in rd
    
12. sll: shift left logical (type R instruction)
    
    Format: sll rd, rs1, rs2
    
    ![Screenshot 2022-12-06 at 12.00.12 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.00.12_AM.png)
    
    Performs logical left shift on the value in register rs1 by the shift amount held in the lower 5 bits of register rs2.
    
13. slli (type I1 instruction)
    
    Format: slli rd, rs1, shamt
    
    ![Screenshot 2022-12-06 at 12.00.34 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.00.34_AM.png)
    
    Performs logical left shift on the value in register rs1 by the shift amount held in the lower 5 bits of the immediate
    
14. srl: shift right logical (type R instruction)
    
    Format: srl rd, rs1, rs2
    
    ![Screenshot 2022-12-06 at 12.01.01 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.01.01_AM.png)
    
    Logical right shift on the value in register rs1 by the shift amount held in the lower 5 bits of register rs2
    
15. srli (type I1 instruction)
    
    Format: srli rd, rs1, shamt
    
    ![Screenshot 2022-12-06 at 12.01.25 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.01.25_AM.png)
    
    Performs logical right shift on the value in register rs1 by the shift amount held in the lower 5 bits of the immediate
    
16. sra: shift right arithmetic (type R instruction)
    
    Format: sra rd, rs1, rs2
    
    ![Screenshot 2022-12-06 at 12.01.46 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.01.46_AM.png)
    
    Performs arithmetic right shift on the value in register rs1 by the shift amount held in the lower 5 bits of register rs2
    
17. srai (type I1 instruction)
    
    Format: srai rd, rs1, shamt
    
    ![Screenshot 2022-12-06 at 12.02.08 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.02.08_AM.png)
    
    Performs arithmetic right shift on the value in register rs1 by the shift amount held in the lower 5 bits of the immediate
    
18. slt: set less than (type R instruction)
    
    Format: slt rd, rs1, rs2
    
    ![Screenshot 2022-12-06 at 12.02.26 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.02.26_AM.png)
    
    Place the value 1 in register rd if register rs1 is less than register rs2 when both are treated as signed numbers, else 0 is written to rd.
    
19. sltu: set less than unsigned (type R instruction)
    
    Format: sltu rd, rs1, rs2
    
    ![Screenshot 2022-12-06 at 12.02.45 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.02.45_AM.png)
    
    Place the value 1 in register rd if register rs1 is less than register rs2 when both are treated as unsigned numbers, else 0 is written to rd.
    
20. beq (type B instruction)
    
    Format: beq rs1, rs2, imm
    
    ![Screenshot 2022-12-06 at 12.03.05 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.03.05_AM.png)
    
    Take the branch if registers rs1 and rs2 are equal.
    
21. bne (type B instruction)
    
    Format: bne rs1, rs2, offset
    
    ![Screenshot 2022-12-06 at 12.03.58 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.03.58_AM.png)
    
    Take the branch if registers rs1 and rs2 are not equal.
    
22. bge (greater than so could add a not gate for less than) (type B instruction)
    
    Format: bge rs1, rs2, offset
    
    ![Screenshot 2022-12-06 at 12.05.04 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.05.04_AM.png)
    
    Take the branch if registers rs1 is greater than or equal to rs2, using signed comparison.
    
23. jal (type J instruction)
    
    Format: jal rd,offset
    
    ![Screenshot 2022-12-06 at 12.05.41 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.05.41_AM.png)
    
    Jump to address and place return address in rd.
    
24. auipc (type U instruction)
    
    Format: auipc rd,imm
    
    ![Screenshot 2022-12-06 at 12.06.24 AM.png](Instruction%20Set%20c7d50501949a4ae28f45f19314d12465/Screenshot_2022-12-06_at_12.06.24_AM.png)
    
    AUIPC forms a 32-bit offset from the 20-bit U-immediate, filling in the lowest 12 bits with zeros, adds this offset to the pc, then places the result in register rd.
