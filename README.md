# Group 9

## Team Statement:

The team hopes to complete the project, as well as the two extension tasks of pipelining the RISC-V processor as well as implementing a cacheing system. The team intends to first do this by working to complete the base, single cycle (no cache) model of the CPU, and then alter that model into a pipelined model, then implement the cache. Our team hopes to implement all functional operations avalable in the RISC-V instruction set. This includes all branch, jump, arithmatic (immidiate and register), and upper immidiate instructions. Fence, interupt, CSR, and trap functions were not implemented.

## Team Members and Personal Commitments:

## Note From the Team on Initial Agreed Deliverables:

As a team, we did not initially subdivied the tasks. We decided to dynamically allocate tasks for each member to do on a rolling basis. This did go directly in opposition of the advice from the module leader, however we decided it would be the most effective way of tackling this challenge. The logic behind this was it meant for an optimal usage of the members time, in that instead of waiting for group members they could crack on with the project. This sounds like an ineffective strategy, however the team was very respectful not to do too much or too little work, and it did result in a fair portion of the project being distributed evenly.

### Omar Ben-Gacem:

Github Username: omarbengacem
Email: ob420@ic.ac.uk
CID: 01883771

#### Personal Statement:
I contributed many of the files to the single cycle cpu such as the decode block, alu and data memory. I also created the first draft of the cache, as well as the top level files for the single cycle CPU and pipeline-cached CPU. I also helped debug files that needed editing, as well as wrote the F1 program. I could improve on ensuring my files were written correctly, as many of my files needed medium to heavy debugging after being written, and I could be more thorough with my testing, as some of my functions were unknowingly incorrect as I did not test them.


### Yomna Mohammed:

Github Username: 
Email: 
CID: 

#### Personal Statement:




### Mubaarak Kahn:

Github Username: 
Email: 
CID: 

#### Personal Statement:




### Will Blaney:


Github Username: 
Email: 
CID: 

#### Personal Statement:








# Team 9 RISC-V CPU

| module      | Yomna | Omar | Mubaraak | Will |
| :------:    | :------: | :------: | :------: | :------: |
| ALU.sv |  | a |  |  |
| Data_Memory.sv |  |  |  |  |
| Decode.sv |  | a |  |  |
| DtoEReg.sv |  | h |  |  |
| EtoMReg.sv |  | h |  |  |
| FtoDReg.sv |  | h |  |  |
| MtoWReg.sv |  | h |  |  |
| PCTarget.sv |  |  |  |  |
| PC_reg.sv |  |  |  |  |
| ProgramCounter.sv |  |  |  |  |
| README.md |  | a |  |  |
| Sign_Extend.sv |  |  |  |  |
| cpu.sv |  | a |  |  |
| cpu_tb.cpp |  |  |  |  |
| instr_mem.sv |  | d |  |  |
| jump_calc.sv |  |  |  |  |
| mux_2.sv |  |  |  |  |
| pc_inc.sv |  |  |  |  |
| pipeline.md |  |  |  |  |
| reg_file.sv |  | a |  |  |
| runCPU.sh |  | a |  |  |
| instr_set |  |  |  |  |
| cache.sv |  | h |  |  |
| cache_tb.cpp |  |  |  |  |
| JumpLogic.sv |  |  |  |  |
|  |  |  |  |  |


**Key**
'a' = author
'c' = coAuthor (when applicable)
'd' = helped debug (if not authors)
'h' = not author, but contributed later on 
 
## Team Reflection:

The teams two main points of improvement for the next project would be to be more diligant in dividing up tasks, and to merge branches more frequently. The first note is that the team mostly worked on everything together, and helped author/debug most of the files as a group. While boosting each member's familiarity with the project, it meant that different syntax conventions were used within the same document, and sometimes conflicting logical methods within a file caused bugs (as they were written by different people). Overall, the project would have probably been done more effectively had the group been more diligant with subdividing. The second point of improvement is the group were very diligant with creating seperate branches, however the group rarely merged branches before they became too seperate from the origional branch, such that it was more work to complete the merge than it is to just work on the new branch. The team could have been more vigilant on the amount of deviation from the main, and could have been more focused on merging and re-branching rather than continue diverging on their own branch.

Overall the team worked effectively together, and the strengths of the team such as constant checkups and communication, frequent commits and contributions to the repo, as well as a prolonged effort not concentraited around the due date made for the project to be completed in a timely manner such that it best reflects the abilities of the groups members.