# Team 9 - Single Cycle CPU

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
![](/videos/noisy.mp4)