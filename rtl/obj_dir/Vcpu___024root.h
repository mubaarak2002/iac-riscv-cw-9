// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcpu.h for the primary calling header

#ifndef VERILATED_VCPU___024ROOT_H_
#define VERILATED_VCPU___024ROOT_H_  // guard

#include "verilated.h"

class Vcpu__Syms;

class Vcpu___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_OUT8(ZERO_Out,0,0);
        VL_OUT8(RA1_Out,4,0);
        VL_OUT8(RA2_Out,4,0);
        VL_OUT8(PCsrc_Out,1,0);
        VL_OUT8(Resultsrc_Out,1,0);
        VL_OUT8(MemWrite_Out,0,0);
        VL_OUT8(ALUctrl_Out,3,0);
        VL_OUT8(ALUsrc_Out,0,0);
        VL_OUT8(Immsrc_Out,2,0);
        VL_OUT8(RegWrite_Out,0,0);
        VL_OUT8(WrAddr_Out,4,0);
        CData/*1:0*/ cpu__DOT__PCsrc;
        CData/*0:0*/ cpu__DOT__zero;
        CData/*1:0*/ cpu__DOT__Resultsrc;
        CData/*0:0*/ cpu__DOT__MemWrite;
        CData/*0:0*/ cpu__DOT__WEn;
        CData/*4:0*/ cpu__DOT__RA1;
        CData/*4:0*/ cpu__DOT__RA2;
        CData/*4:0*/ cpu__DOT__WA3;
        CData/*3:0*/ cpu__DOT__ALUctrl;
        CData/*0:0*/ cpu__DOT__ALUsrc;
        CData/*2:0*/ cpu__DOT__ImmSel;
        CData/*0:0*/ cpu__DOT__isJALR;
        CData/*7:0*/ cpu__DOT__PCMem__DOT__instrByte1;
        CData/*7:0*/ cpu__DOT__PCMem__DOT__instrByte2;
        CData/*7:0*/ cpu__DOT__PCMem__DOT__instrByte3;
        CData/*7:0*/ cpu__DOT__PCMem__DOT__instrByte4;
        CData/*0:0*/ cpu__DOT__Decoder__DOT__cacheEn;
        CData/*4:0*/ cpu__DOT__Decoder__DOT__rd;
        CData/*4:0*/ cpu__DOT__Decoder__DOT__rs1;
        CData/*4:0*/ cpu__DOT__Decoder__DOT__rs2;
        CData/*4:0*/ cpu__DOT__Decoder__DOT__ShortImm;
        CData/*6:0*/ cpu__DOT__Decoder__DOT__opcode;
        CData/*3:0*/ cpu__DOT__Decoder__DOT__ALUopcode;
        CData/*4:0*/ cpu__DOT__Decoder__DOT__r0;
        CData/*2:0*/ cpu__DOT__Decoder__DOT__branchcode;
        CData/*0:0*/ __Vclklast__TOP__clk;
        CData/*0:0*/ __Vclklast__TOP__rst;
        CData/*0:0*/ __Vchglast__TOP__cpu__DOT__zero;
        VL_OUT16(PC_Out,15,0);
        VL_OUT16(PC_Target_Out,15,0);
        VL_OUT16(PC_new_Out,15,0);
        VL_OUT16(Decode_PC_Out,15,0);
        SData/*15:0*/ cpu__DOT__PC;
        SData/*15:0*/ cpu__DOT__PC_new;
        SData/*15:0*/ cpu__DOT__PC_to_PCreg;
        SData/*15:0*/ cpu__DOT__PC_Target;
        SData/*15:0*/ cpu__DOT__PC_to_Extend;
        SData/*15:0*/ cpu__DOT__ProgramCounter__DOT__next_PC;
        VL_OUT(ImmExt_Out,31,0);
        VL_OUT(Instruction_Out,31,0);
        VL_OUT(RD1_Out,31,0);
        VL_OUT(RD2_Out,31,0);
        VL_OUT(MemAddr_Out,31,0);
        VL_OUT(MemData_Out,31,0);
        VL_OUT(ImmOp_Out,24,0);
        VL_OUT(Data_Out,31,0);
        VL_OUT(a0,31,0);
        IData/*31:0*/ cpu__DOT__MemWrAdd;
        IData/*31:0*/ cpu__DOT__RD1;
        IData/*31:0*/ cpu__DOT__RD2;
        IData/*31:0*/ cpu__DOT__Instr;
    };
    struct {
        IData/*24:0*/ cpu__DOT__ImmOp;
        IData/*31:0*/ cpu__DOT__ImmExt;
        IData/*31:0*/ cpu__DOT__ALU_OP2;
        IData/*31:0*/ cpu__DOT__ALU_Result;
        IData/*31:0*/ cpu__DOT__DOut;
        IData/*31:0*/ cpu__DOT__Memory_Read;
        IData/*24:0*/ cpu__DOT__Decoder__DOT__Imm;
        IData/*19:0*/ cpu__DOT__Decoder__DOT__UpperImm;
        IData/*19:0*/ cpu__DOT__MemFile__DOT__addr;
        VlUnpacked<CData/*7:0*/, 65536> cpu__DOT__PCMem__DOT__rom_array;
        VlUnpacked<IData/*31:0*/, 32> cpu__DOT__RegFile__DOT__rom_array;
        VlUnpacked<IData/*31:0*/, 1048576> cpu__DOT__MemFile__DOT__ram_array;
        VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vcpu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcpu___024root(Vcpu__Syms* symsp, const char* name);
    ~Vcpu___024root();
    VL_UNCOPYABLE(Vcpu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
