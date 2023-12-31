# Group 9
### Note
As we deleted other branches we worked on, including the inital Pipeline branch, I (Yomna) am unable to link the commits where I implemented these contributions

## Branch Designations: 

On this branch (master), there is the single cycle RISC-V processor. The Diagram of the processor shows all the connections made, as well as their bit lengths. This processor was "chopped up", and a cache was added to form a more advanced version of this RISC-V CPU. This can be found on the branch named "Advanced", along with a full technical writeup of all changes made as well as added logic and modules.

## Team Statement:

The team hopes to complete the project, as well as the two extension tasks of pipelining the RISC-V processor as well as implementing a cacheing system. The team intends to first do this by working to complete the base, single cycle (no cache) model of the CPU, and then alter that model into a pipelined model, then implement the cache. Our team hopes to implement all functional operations avalable in the RISC-V instruction set. This includes all branch, jump, arithmatic (immidiate and register), and upper immidiate instructions. Fence, interupt, CSR, and trap functions were not implemented.  

To view the instruction set that our team has chosen to implement, see the readme in the instr_set file.

## Team Members and Personal Commitments:

## Note From the Team on Initial Agreed Deliverables:

As a team, we did not initially subdivied the tasks. We decided to dynamically allocate tasks for each member to do on a rolling basis. This did go directly in opposition of the advice from the module leader, however we decided it would be the most effective way of tackling this challenge. The logic behind this was it meant for an optimal usage of the members time, in that instead of waiting for group members they could crack on with the project. This sounds like an ineffective strategy, however the team was very respectful not to do too much or too little work, and it did result in a fair portion of the project being distributed evenly.

### Omar Ben-Gacem:

Github Username: omarbengacem  
Email: ob420@ic.ac.uk  
CID: 01883771  

#### Personal Statement:
I contributed many of the files to the single cycle cpu such as the decode block, alu and data memory. I also created the first draft of the cache, as well as the top level files for the single cycle CPU and pipeline-cached CPU. I also helped debug files that needed editing, as well as wrote the F1 program. I could improve on ensuring my files were written correctly, as many of my files needed medium to heavy debugging after being written, and I could be more thorough with my testing, as some of my functions were unknowingly incorrect as I did not test them. In a now deleted branch, I wrote the first versions of ALU.sv, Decode.sv, and CPU.sv. I also wrote the first versions of CPU.sv for the "advanced" branch containing pipelining and cacheing, and I also wrote the first version of the integrated cache/pipelining branch. I also came up with and implemented the first versions of the interupt mechanism which was used to allow for our cache to be one or two cycles depending on a hit or miss. I also introduced functionality of expanding ALUCtrl to 4 bits, as well as other functional control signals used in the cpu that weren't labled in the Harris & Harris diagrams we followed. Finally I drew most of the hand-drawn images and wrote most of the README's.


### Yomna Mohammed:

Github Username:  YumiA

Email:  ym2021@ic.ac.uk

CID: 02027189

#### Personal Statement:
In Lab 4, I was responsible for working on the Instruction Memory, Control Unit, and the Sign Extend blocks. In this project, I started by working on a few blocks like the Sign Extend, Instruction Memory and etc. Following that I helped make edits and fix debugs of some other basic blocks as well created the README for our Instruction Set. Once the Single Cycle CPU was implemented, I was responsible for implementing the pipeline model and writing the pipeline MD which was based off of the Harris and Harris book model. After that I helped around where needed and debugged instructions like JAL, JALR, load and store, particularly in the cache implementation. I also debugged the cpu top level block, the decode block and other blocks. I believe I could have been more thorough with testing from the start and would have liked to contribute more to caching.


### Mubaarak Khan:

Github Username: mubaarak2002

Email: mmk120@ic.ac.uk

CID: 01928696

#### Personal Statement:
Initially I was responsible for the program counter block. https://github.com/EIE2-IAC-Labs/iac-riscv-cw-9/blob/master/rtl/ProgramCounter.sv During the making of the single cycle cpu I was mainly responsible for the verifiaction of the design by using using gtkWave and fixing the many bugs that appeared. I was also laregly responsible for the implementation of the JAL and JALR instructions. I managed to solve the issue of storing the PC into the register and returning the value of the register into the program counter. In pipelining, there were errors where branch instructions werent functioning as the result required from the ALU was no in the same stage of the pipeline. I solved this issue by creating the JumpLogic block. I was mainly responsible for implementing caching, unfortunately due to limited time I was unable to iron out every bug with caching. https://github.com/EIE2-IAC-Labs/iac-riscv-cw-9/blob/Advanced/rtl/cache.sv The cache reads and stores to itself correctly but there are times where memory locations seem to be overwrittern incorrectly. Given more time I would have liked to have solved this issue.



### Will Blayney: 


Github Username:  blayney

Email:   wb320@ic.ac.uk

CID:   01884020


#### Personal Statement:

Minimal contribution to final stages of project - please see relevant MCs. Yomna, Omar & Mubaraak did the CPU as a three!






# Team 9 RISC-V CPU

| module      | Yomna | Omar | Mubaraak | Will |
| :------:    | :------: | :------: | :------: | :------: |
| ALU.sv |  | * |  |  |
| Data_Memory.sv |  |  | * |  |
| Decode.sv |  | * | X |  |
| DtoEReg.sv | * | X | X |  |
| EtoMReg.sv | * | X | X |  |
| FtoDReg.sv | * | X | X |  |
| MtoWReg.sv | * | X | X |  |
| PCTarget.sv | X |  | * |  |
| ProgramCounter.sv | X |  | * |  |
| README.md | * | * |  |  |
| Sign_Extend.sv | * |  |  |  |
| cpu.sv | X | * | X |  |
| cpu_tb.cpp |  | * | X |  |
| instr_mem.sv | * | X | X |  |
| mux_2.sv | * |  |  |  |
| pipeline.md | * |  |  |  |
| reg_file.sv | X | * |  |  |
| runCPU.sh |  | * |  |  |
| instr_set | * |  |  |  |
| cache.sv |  | X | * |  |
| cache_tb.cpp |  |  | * |  |
| F1_tb.cpp |  | * |  |  |
| JumpLogic.sv |  |  | * |  |
| mux_3.sv | * |  |  |  |


**Key**
| Key      | Role | 
| :------:    | :------: | 
| * | Principal Contributor | 
| x | Also helped | 
 
## Team Reflection:

The teams two main points of improvement for the next project would be to be more diligant in dividing up tasks, and to merge branches more frequently. The first note is that the team mostly worked on everything together, and helped author/debug most of the files as a group. While boosting each member's familiarity with the project, it meant that different syntax conventions were used within the same document, and sometimes conflicting logical methods within a file caused bugs (as they were written by different people). Overall, the project would have probably been done more effectively had the group been more diligant with subdividing. The second point of improvement is the group were very diligant with creating seperate branches, however the group rarely merged branches before they became too seperate from the origional branch, such that it was more work to complete the merge than it is to just work on the new branch. The team could have been more vigilant on the amount of deviation from the main, and could have been more focused on merging and re-branching rather than continue diverging on their own branch.

Overall the team worked effectively together, and the strengths of the team such as constant checkups and communication, frequent commits and contributions to the repo, as well as a prolonged effort not concentraited around the due date made for the project to be completed in a timely manner such that it best reflects the abilities of the groups members.
