# Team 9 - Single Cycle CPU

## Our Design

### Single Cycle

On this branch (master), there is the single cycle RISC-V processor. The Diagram of the processor shows all the connections made, as well as their bit lengths. This processor was "chopped up", and a cache was added to form or pipelined and cached version.

![](/rtl/videos/SingleCycle.png)


The CPU is unpipelined, and thus data and control signals flow linearly from left to right in the diagram. It is a Harvard Architecture, and thus the data and instruction memories are seperate, and do not interact. The SystemVerilog files are constructed all entirely of fundamental blocks (except for the program counter), and thus there is only one top level file cpu.sv to connect all the sub modules together. The CPU design is very heavily inspired by Digital Design and Computer Architecture by Harris/Harris (*Harris, Sarah and David, Harris. DIGITAL DESIGN and COMPUTER ARCHITECTURE : Risc-v Edition. S.L., Morgan Kaufmann Publisher, 2021.*).

### Pipelined and Cached

To view the pipeline/cached verison of this CPU, as well as a full technical breakdown of all changes made, switch to the "advanced" branch, and within that branch will be the fully functional pipelined and cached version of this CPU.


## How to Test the Program:

The execute files correspond to the relevant test benches for each of the programs. Each program will require a different instruction memory file to be loaded into instr_mem.sv. Below are steps to run each command:

### Run F1 Program:

This is the default program loaded on the cpu. To run it, ensure that line 19 of instr_mem.sv reads:
```
    $readmemh("f1.hex", rom_array);
```
This means the F1 instructons are loaded into the program memory. The code can be found in the ./test file. To run the program, a shell script is already prepared, simply entire the "rtl" directory and run
```
    source F1.sh
```
If a vbuddy is connected, this should immidiately begin the F1 light squence on the bar

### Run PDF Sequence:
To run the PDF sequence, the correct data set will need to be loaded into the data memory to act as the basis for the pdf function. To change it, go into the file Data_Memory.sv, line 15, and change the following code
```
$readmemh("gaussian.mem", ram_array, 65536);
```
to be the .mem file you want. simply replace the word "gaussian" with either "noisy", "sine", or "triangle". This will allow for the different datasets to be visualised. To run, enter the command in the terminal:
```
source PDF.sh
```
If a vbuddy is connected, the PDF should begin plotting after a short pause.

## Results:

The team was able to implement all programs to work on the vbuddy, and below are videos of all the results:

### PDF of Formula 1 File
https://youtube.com/shorts/bpn-pUrOQ-U?feature=share


### PDF of Noisy Data File
https://youtube.com/shorts/cATN2SxZqAs?feature=share


### PDF of Gaussian Data File
https://youtube.com/shorts/fZy88M6KGbo?feature=share


### PDF of Sine Data File
https://youtube.com/shorts/r_wv4N8ye9E?feature=share


### PDF of Triangle Data File
https://youtube.com/shorts/aMlT6UiXkZQ?feature=share

