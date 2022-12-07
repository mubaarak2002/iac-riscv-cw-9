#!/bin/sh

#cleanup
rm -rf obj_dir
rm -f cpu.vcd

#compile the test file

#run Verilator to translate Verilog into C++, including the C++ testbench
verilator -Wall --cc --trace cpu.sv --exe cpu_tb.cpp

#build C++ project via make automatically generated by verilator
make -j -C obj_dir/ -f Vcpu.mk Vcpu

#clears up all the compile time junk
#if youre having problems and need to see the errors comment the clear
#clear

#run executable simulation file
obj_dir/Vcpu


#to run:
#source ./doit.sh