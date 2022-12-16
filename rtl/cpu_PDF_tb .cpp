#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vcpu.h"
#include "vbuddy.cpp"

#define MAX_SIM_CYC 1000000

int main(int argc, char **argv, char **env) {
    int simcyc;     // simulation clock count
    int tick;       // each clk cycle has two ticks for two edges

    Verilated::commandArgs(argc, argv);
    Vcpu* top = new Vcpu;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("cpu.vcd");


    top->clk = 0;
    top->rst = 0;

    if (vbdOpen()!=1) return(-1);
    
    for (simcyc=0; simcyc < MAX_SIM_CYC; simcyc++){
        for (tick=0; tick<2; tick++){
            tfp->dump (2*simcyc+tick);
            top->clk = !top->clk;
            top->eval();
        }

  //for Reference Program

        if (simcyc > 10000){
            vbdPlot(int (top->a0), 0, 255);
            vbdCycle(simcyc);
        }

        if (Verilated::gotFinish()){
            exit(0);
        }

        if((Verilated::gotFinish()) || (vbdGetkey()  == 'q')) exit(0);
    }


    tfp->close();
    printf("Exiting\n");
    exit(0);
}