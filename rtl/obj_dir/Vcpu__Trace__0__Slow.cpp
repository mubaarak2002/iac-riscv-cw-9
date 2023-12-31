// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu__Syms.h"


VL_ATTR_COLD void Vcpu___024root__trace_init_sub__TOP__0(Vcpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+73,"clk", false,-1);
    tracep->declBit(c+74,"rst", false,-1);
    tracep->declBus(c+75,"ImmExt_Out", false,-1, 31,0);
    tracep->declBus(c+76,"PC_Out", false,-1, 15,0);
    tracep->declBus(c+77,"PC_Target_Out", false,-1, 15,0);
    tracep->declBus(c+78,"Instruction_Out", false,-1, 31,0);
    tracep->declBus(c+79,"PC_new_Out", false,-1, 15,0);
    tracep->declBus(c+80,"RD1_Out", false,-1, 31,0);
    tracep->declBus(c+81,"RD2_Out", false,-1, 31,0);
    tracep->declBus(c+82,"MemAddr_Out", false,-1, 31,0);
    tracep->declBus(c+83,"MemData_Out", false,-1, 31,0);
    tracep->declBit(c+84,"ZERO_Out", false,-1);
    tracep->declBus(c+85,"RA1_Out", false,-1, 4,0);
    tracep->declBus(c+86,"RA2_Out", false,-1, 4,0);
    tracep->declBus(c+87,"PCsrc_Out", false,-1, 1,0);
    tracep->declBus(c+88,"Resultsrc_Out", false,-1, 1,0);
    tracep->declBit(c+89,"MemWrite_Out", false,-1);
    tracep->declBus(c+90,"ALUctrl_Out", false,-1, 3,0);
    tracep->declBit(c+91,"ALUsrc_Out", false,-1);
    tracep->declBus(c+92,"Immsrc_Out", false,-1, 2,0);
    tracep->declBit(c+93,"RegWrite_Out", false,-1);
    tracep->declBus(c+94,"ImmOp_Out", false,-1, 24,0);
    tracep->declBus(c+95,"Decode_PC_Out", false,-1, 15,0);
    tracep->declBus(c+96,"WrAddr_Out", false,-1, 4,0);
    tracep->declBus(c+97,"Data_Out", false,-1, 31,0);
    tracep->declBus(c+98,"a0", false,-1, 31,0);
    tracep->pushNamePrefix("cpu ");
    tracep->declBus(c+102,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+103,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+103,"INSTR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+104,"PC_WIDTH", false,-1, 31,0);
    tracep->declBus(c+105,"ALUCTRL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+106,"IMMSRC_WIDTH", false,-1, 31,0);
    tracep->declBus(c+107,"IMMOP_WIDTH", false,-1, 31,0);
    tracep->declBit(c+73,"clk", false,-1);
    tracep->declBit(c+74,"rst", false,-1);
    tracep->declBus(c+75,"ImmExt_Out", false,-1, 31,0);
    tracep->declBus(c+76,"PC_Out", false,-1, 15,0);
    tracep->declBus(c+77,"PC_Target_Out", false,-1, 15,0);
    tracep->declBus(c+78,"Instruction_Out", false,-1, 31,0);
    tracep->declBus(c+79,"PC_new_Out", false,-1, 15,0);
    tracep->declBus(c+80,"RD1_Out", false,-1, 31,0);
    tracep->declBus(c+81,"RD2_Out", false,-1, 31,0);
    tracep->declBus(c+82,"MemAddr_Out", false,-1, 31,0);
    tracep->declBus(c+83,"MemData_Out", false,-1, 31,0);
    tracep->declBit(c+84,"ZERO_Out", false,-1);
    tracep->declBus(c+85,"RA1_Out", false,-1, 4,0);
    tracep->declBus(c+86,"RA2_Out", false,-1, 4,0);
    tracep->declBus(c+87,"PCsrc_Out", false,-1, 1,0);
    tracep->declBus(c+88,"Resultsrc_Out", false,-1, 1,0);
    tracep->declBit(c+89,"MemWrite_Out", false,-1);
    tracep->declBus(c+90,"ALUctrl_Out", false,-1, 3,0);
    tracep->declBit(c+91,"ALUsrc_Out", false,-1);
    tracep->declBus(c+92,"Immsrc_Out", false,-1, 2,0);
    tracep->declBit(c+93,"RegWrite_Out", false,-1);
    tracep->declBus(c+94,"ImmOp_Out", false,-1, 24,0);
    tracep->declBus(c+95,"Decode_PC_Out", false,-1, 15,0);
    tracep->declBus(c+96,"WrAddr_Out", false,-1, 4,0);
    tracep->declBus(c+97,"Data_Out", false,-1, 31,0);
    tracep->declBus(c+98,"a0", false,-1, 31,0);
    tracep->declBus(c+65,"PC", false,-1, 15,0);
    tracep->declBus(c+108,"PC_new", false,-1, 15,0);
    tracep->declBus(c+109,"PC_to_PCreg", false,-1, 15,0);
    tracep->declBus(c+66,"PC_Next_Cycle", false,-1, 15,0);
    tracep->declBus(c+1,"PC_Target", false,-1, 15,0);
    tracep->declBus(c+2,"PC_to_Extend", false,-1, 15,0);
    tracep->declBus(c+3,"PCsrc", false,-1, 1,0);
    tracep->declBit(c+4,"zero", false,-1);
    tracep->declBus(c+5,"Resultsrc", false,-1, 1,0);
    tracep->declBit(c+6,"MemWrite", false,-1);
    tracep->declBit(c+7,"WEn", false,-1);
    tracep->declBus(c+110,"MemWrAdd", false,-1, 31,0);
    tracep->declBus(c+8,"RA1", false,-1, 4,0);
    tracep->declBus(c+9,"RD1", false,-1, 31,0);
    tracep->declBus(c+10,"RA2", false,-1, 4,0);
    tracep->declBus(c+11,"RD2", false,-1, 31,0);
    tracep->declBus(c+12,"WA3", false,-1, 4,0);
    tracep->declBus(c+67,"Instr", false,-1, 31,0);
    tracep->declBus(c+13,"ALUctrl", false,-1, 3,0);
    tracep->declBit(c+14,"ALUsrc", false,-1);
    tracep->declBus(c+15,"ImmSel", false,-1, 2,0);
    tracep->declBus(c+16,"ImmOp", false,-1, 24,0);
    tracep->declBus(c+17,"ImmExt", false,-1, 31,0);
    tracep->declBus(c+18,"ALU_OP2", false,-1, 31,0);
    tracep->declBus(c+19,"ALU_Result", false,-1, 31,0);
    tracep->declBus(c+20,"DOut", false,-1, 31,0);
    tracep->declBus(c+21,"Memory_Read", false,-1, 31,0);
    tracep->declBus(c+99,"Jump_Calc_Input", false,-1, 31,0);
    tracep->declBit(c+22,"isJALR", false,-1);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+103,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+105,"ALUCTRL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+13,"ALUCtrl", false,-1, 3,0);
    tracep->declBus(c+9,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+18,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+19,"SUM", false,-1, 31,0);
    tracep->declBit(c+4,"ZERO", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ALUMux ");
    tracep->declBus(c+103,"WORD_WIDTH", false,-1, 31,0);
    tracep->declBus(c+11,"option0", false,-1, 31,0);
    tracep->declBus(c+17,"option1", false,-1, 31,0);
    tracep->declBit(c+14,"sel", false,-1);
    tracep->declBus(c+18,"dout", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("Decoder ");
    tracep->declBus(c+103,"INSTRW", false,-1, 31,0);
    tracep->declBus(c+111,"ZEROW", false,-1, 31,0);
    tracep->declBus(c+105,"ALUCTRLW", false,-1, 31,0);
    tracep->declBus(c+112,"UPPERIMW", false,-1, 31,0);
    tracep->declBus(c+102,"SHORTIMMW", false,-1, 31,0);
    tracep->declBus(c+106,"IMMSELW", false,-1, 31,0);
    tracep->declBus(c+107,"IMMOPW", false,-1, 31,0);
    tracep->declBus(c+102,"RDADDR1W", false,-1, 31,0);
    tracep->declBus(c+102,"RDADDR2W", false,-1, 31,0);
    tracep->declBus(c+102,"WRADDRW", false,-1, 31,0);
    tracep->declBus(c+113,"OPCODEW", false,-1, 31,0);
    tracep->declBus(c+104,"PCWIDTH", false,-1, 31,0);
    tracep->declBus(c+106,"BRCHCDEW", false,-1, 31,0);
    tracep->declBus(c+114,"RESULTSRCW", false,-1, 31,0);
    tracep->declBus(c+67,"Instruction", false,-1, 31,0);
    tracep->declBus(c+4,"ZERO", false,-1, 0,0);
    tracep->declBus(c+108,"PC_next", false,-1, 15,0);
    tracep->declBus(c+13,"ALUctrl", false,-1, 3,0);
    tracep->declBit(c+14,"ALUsrc", false,-1);
    tracep->declBus(c+5,"ResultSrc", false,-1, 1,0);
    tracep->declBus(c+8,"RdAdd1", false,-1, 4,0);
    tracep->declBus(c+10,"RdAdd2", false,-1, 4,0);
    tracep->declBus(c+12,"WrAddr", false,-1, 4,0);
    tracep->declBit(c+7,"RegWrite", false,-1);
    tracep->declBit(c+6,"MemWrite", false,-1);
    tracep->declBus(c+16,"ImmOp", false,-1, 24,0);
    tracep->declBus(c+15,"Immsrc", false,-1, 2,0);
    tracep->declBus(c+2,"PC", false,-1, 15,0);
    tracep->declBus(c+3,"PCSrc", false,-1, 1,0);
    tracep->declBit(c+22,"isJALR", false,-1);
    tracep->declBit(c+23,"cacheEn", false,-1);
    tracep->declBus(c+24,"rd", false,-1, 4,0);
    tracep->declBus(c+25,"rs1", false,-1, 4,0);
    tracep->declBus(c+26,"rs2", false,-1, 4,0);
    tracep->declBus(c+27,"Imm", false,-1, 24,0);
    tracep->declBus(c+115,"UpperImm", false,-1, 19,0);
    tracep->declBus(c+116,"ShortImm", false,-1, 4,0);
    tracep->declBus(c+28,"opcode", false,-1, 6,0);
    tracep->declBus(c+29,"ALUopcode", false,-1, 3,0);
    tracep->declBus(c+30,"r0", false,-1, 4,0);
    tracep->declBus(c+31,"branchcode", false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("DoutMux ");
    tracep->declBus(c+103,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+104,"PC_WIDTH", false,-1, 31,0);
    tracep->declBus(c+19,"ALU_result", false,-1, 31,0);
    tracep->declBus(c+21,"ReadData", false,-1, 31,0);
    tracep->declBus(c+66,"PC", false,-1, 15,0);
    tracep->declBus(c+5,"sel", false,-1, 1,0);
    tracep->declBus(c+20,"dout", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("JumpMux ");
    tracep->declBus(c+103,"WORD_WIDTH", false,-1, 31,0);
    tracep->declBus(c+68,"option0", false,-1, 31,0);
    tracep->declBus(c+9,"option1", false,-1, 31,0);
    tracep->declBit(c+22,"sel", false,-1);
    tracep->declBus(c+99,"dout", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MemFile ");
    tracep->declBus(c+112,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+103,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+19,"ALUresult", false,-1, 31,0);
    tracep->declBit(c+73,"clk", false,-1);
    tracep->declBit(c+6,"WEN", false,-1);
    tracep->declBus(c+11,"WriteData", false,-1, 31,0);
    tracep->declBus(c+21,"ReadData", false,-1, 31,0);
    tracep->declBus(c+32,"addr", false,-1, 19,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PCMem ");
    tracep->declBus(c+104,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+103,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+65,"PC", false,-1, 15,0);
    tracep->declBus(c+67,"instr", false,-1, 31,0);
    tracep->declBus(c+69,"instrByte1", false,-1, 7,0);
    tracep->declBus(c+70,"instrByte2", false,-1, 7,0);
    tracep->declBus(c+71,"instrByte3", false,-1, 7,0);
    tracep->declBus(c+72,"instrByte4", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PCTarget ");
    tracep->declBus(c+104,"PC_WIDTH", false,-1, 31,0);
    tracep->declBus(c+103,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+17,"ImmExt", false,-1, 31,0);
    tracep->declBus(c+100,"PC", false,-1, 15,0);
    tracep->declBus(c+1,"PC_Target", false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ProgramCounter ");
    tracep->declBus(c+104,"PC_WIDTH", false,-1, 31,0);
    tracep->declBit(c+73,"clk", false,-1);
    tracep->declBit(c+74,"rst", false,-1);
    tracep->declBus(c+3,"PCsrc", false,-1, 1,0);
    tracep->declBus(c+1,"PC_Target", false,-1, 15,0);
    tracep->declBus(c+20,"Return", false,-1, 31,0);
    tracep->declBus(c+65,"PC", false,-1, 15,0);
    tracep->declBus(c+66,"inc_PC", false,-1, 15,0);
    tracep->declBus(c+1,"branch_PC", false,-1, 15,0);
    tracep->declBus(c+101,"next_PC", false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("RegFile ");
    tracep->declBus(c+103,"WORD_WIDTH", false,-1, 31,0);
    tracep->declBus(c+102,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBit(c+73,"clk", false,-1);
    tracep->declBus(c+8,"RA1", false,-1, 4,0);
    tracep->declBus(c+10,"RA2", false,-1, 4,0);
    tracep->declBus(c+12,"WA3", false,-1, 4,0);
    tracep->declBus(c+20,"WD3", false,-1, 31,0);
    tracep->declBit(c+7,"WEN", false,-1);
    tracep->declBus(c+9,"RD1", false,-1, 31,0);
    tracep->declBus(c+11,"RD2", false,-1, 31,0);
    tracep->declBus(c+98,"a0", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+33+i*1,"rom_array", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("SignExt ");
    tracep->declBus(c+103,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+15,"ImmSel", false,-1, 2,0);
    tracep->declBus(c+16,"Imm", false,-1, 31,7);
    tracep->declBus(c+17,"ImmExt", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vcpu___024root__trace_init_top(Vcpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_init_top\n"); );
    // Body
    Vcpu___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vcpu___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcpu___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vcpu___024root__trace_register(Vcpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vcpu___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vcpu___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vcpu___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vcpu___024root__trace_full_sub_0(Vcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vcpu___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_full_top_0\n"); );
    // Init
    Vcpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu___024root*>(voidSelf);
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vcpu___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vcpu___024root__trace_full_sub_0(Vcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(vlSelf->cpu__DOT__PC_Target),16);
    bufp->fullSData(oldp+2,(vlSelf->cpu__DOT__PC_to_Extend),16);
    bufp->fullCData(oldp+3,(vlSelf->cpu__DOT__PCsrc),2);
    bufp->fullBit(oldp+4,(vlSelf->cpu__DOT__zero));
    bufp->fullCData(oldp+5,(vlSelf->cpu__DOT__Resultsrc),2);
    bufp->fullBit(oldp+6,(vlSelf->cpu__DOT__MemWrite));
    bufp->fullBit(oldp+7,(vlSelf->cpu__DOT__WEn));
    bufp->fullCData(oldp+8,(vlSelf->cpu__DOT__RA1),5);
    bufp->fullIData(oldp+9,(vlSelf->cpu__DOT__RD1),32);
    bufp->fullCData(oldp+10,(vlSelf->cpu__DOT__RA2),5);
    bufp->fullIData(oldp+11,(vlSelf->cpu__DOT__RD2),32);
    bufp->fullCData(oldp+12,(vlSelf->cpu__DOT__WA3),5);
    bufp->fullCData(oldp+13,(vlSelf->cpu__DOT__ALUctrl),4);
    bufp->fullBit(oldp+14,(vlSelf->cpu__DOT__ALUsrc));
    bufp->fullCData(oldp+15,(vlSelf->cpu__DOT__ImmSel),3);
    bufp->fullIData(oldp+16,(vlSelf->cpu__DOT__ImmOp),25);
    bufp->fullIData(oldp+17,(vlSelf->cpu__DOT__ImmExt),32);
    bufp->fullIData(oldp+18,(vlSelf->cpu__DOT__ALU_OP2),32);
    bufp->fullIData(oldp+19,(vlSelf->cpu__DOT__ALU_Result),32);
    bufp->fullIData(oldp+20,(vlSelf->cpu__DOT__DOut),32);
    bufp->fullIData(oldp+21,(vlSelf->cpu__DOT__Memory_Read),32);
    bufp->fullBit(oldp+22,(vlSelf->cpu__DOT__isJALR));
    bufp->fullBit(oldp+23,(vlSelf->cpu__DOT__Decoder__DOT__cacheEn));
    bufp->fullCData(oldp+24,(vlSelf->cpu__DOT__Decoder__DOT__rd),5);
    bufp->fullCData(oldp+25,(vlSelf->cpu__DOT__Decoder__DOT__rs1),5);
    bufp->fullCData(oldp+26,(vlSelf->cpu__DOT__Decoder__DOT__rs2),5);
    bufp->fullIData(oldp+27,(vlSelf->cpu__DOT__Decoder__DOT__Imm),25);
    bufp->fullCData(oldp+28,(vlSelf->cpu__DOT__Decoder__DOT__opcode),7);
    bufp->fullCData(oldp+29,(vlSelf->cpu__DOT__Decoder__DOT__ALUopcode),4);
    bufp->fullCData(oldp+30,(vlSelf->cpu__DOT__Decoder__DOT__r0),5);
    bufp->fullCData(oldp+31,(vlSelf->cpu__DOT__Decoder__DOT__branchcode),3);
    bufp->fullIData(oldp+32,(vlSelf->cpu__DOT__MemFile__DOT__addr),20);
    bufp->fullIData(oldp+33,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[0]),32);
    bufp->fullIData(oldp+34,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[1]),32);
    bufp->fullIData(oldp+35,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[2]),32);
    bufp->fullIData(oldp+36,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[3]),32);
    bufp->fullIData(oldp+37,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[4]),32);
    bufp->fullIData(oldp+38,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[5]),32);
    bufp->fullIData(oldp+39,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[6]),32);
    bufp->fullIData(oldp+40,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[7]),32);
    bufp->fullIData(oldp+41,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[8]),32);
    bufp->fullIData(oldp+42,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[9]),32);
    bufp->fullIData(oldp+43,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[10]),32);
    bufp->fullIData(oldp+44,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[11]),32);
    bufp->fullIData(oldp+45,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[12]),32);
    bufp->fullIData(oldp+46,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[13]),32);
    bufp->fullIData(oldp+47,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[14]),32);
    bufp->fullIData(oldp+48,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[15]),32);
    bufp->fullIData(oldp+49,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[16]),32);
    bufp->fullIData(oldp+50,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[17]),32);
    bufp->fullIData(oldp+51,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[18]),32);
    bufp->fullIData(oldp+52,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[19]),32);
    bufp->fullIData(oldp+53,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[20]),32);
    bufp->fullIData(oldp+54,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[21]),32);
    bufp->fullIData(oldp+55,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[22]),32);
    bufp->fullIData(oldp+56,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[23]),32);
    bufp->fullIData(oldp+57,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[24]),32);
    bufp->fullIData(oldp+58,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[25]),32);
    bufp->fullIData(oldp+59,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[26]),32);
    bufp->fullIData(oldp+60,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[27]),32);
    bufp->fullIData(oldp+61,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[28]),32);
    bufp->fullIData(oldp+62,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[29]),32);
    bufp->fullIData(oldp+63,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[30]),32);
    bufp->fullIData(oldp+64,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[31]),32);
    bufp->fullSData(oldp+65,(vlSelf->cpu__DOT__PC),16);
    bufp->fullSData(oldp+66,((0xffffU & ((IData)(4U) 
                                         + (IData)(vlSelf->cpu__DOT__PC)))),16);
    bufp->fullIData(oldp+67,(vlSelf->cpu__DOT__Instr),32);
    bufp->fullIData(oldp+68,(vlSelf->cpu__DOT__PC),32);
    bufp->fullCData(oldp+69,(vlSelf->cpu__DOT__PCMem__DOT__instrByte1),8);
    bufp->fullCData(oldp+70,(vlSelf->cpu__DOT__PCMem__DOT__instrByte2),8);
    bufp->fullCData(oldp+71,(vlSelf->cpu__DOT__PCMem__DOT__instrByte3),8);
    bufp->fullCData(oldp+72,(vlSelf->cpu__DOT__PCMem__DOT__instrByte4),8);
    bufp->fullBit(oldp+73,(vlSelf->clk));
    bufp->fullBit(oldp+74,(vlSelf->rst));
    bufp->fullIData(oldp+75,(vlSelf->ImmExt_Out),32);
    bufp->fullSData(oldp+76,(vlSelf->PC_Out),16);
    bufp->fullSData(oldp+77,(vlSelf->PC_Target_Out),16);
    bufp->fullIData(oldp+78,(vlSelf->Instruction_Out),32);
    bufp->fullSData(oldp+79,(vlSelf->PC_new_Out),16);
    bufp->fullIData(oldp+80,(vlSelf->RD1_Out),32);
    bufp->fullIData(oldp+81,(vlSelf->RD2_Out),32);
    bufp->fullIData(oldp+82,(vlSelf->MemAddr_Out),32);
    bufp->fullIData(oldp+83,(vlSelf->MemData_Out),32);
    bufp->fullBit(oldp+84,(vlSelf->ZERO_Out));
    bufp->fullCData(oldp+85,(vlSelf->RA1_Out),5);
    bufp->fullCData(oldp+86,(vlSelf->RA2_Out),5);
    bufp->fullCData(oldp+87,(vlSelf->PCsrc_Out),2);
    bufp->fullCData(oldp+88,(vlSelf->Resultsrc_Out),2);
    bufp->fullBit(oldp+89,(vlSelf->MemWrite_Out));
    bufp->fullCData(oldp+90,(vlSelf->ALUctrl_Out),4);
    bufp->fullBit(oldp+91,(vlSelf->ALUsrc_Out));
    bufp->fullCData(oldp+92,(vlSelf->Immsrc_Out),3);
    bufp->fullBit(oldp+93,(vlSelf->RegWrite_Out));
    bufp->fullIData(oldp+94,(vlSelf->ImmOp_Out),25);
    bufp->fullSData(oldp+95,(vlSelf->Decode_PC_Out),16);
    bufp->fullCData(oldp+96,(vlSelf->WrAddr_Out),5);
    bufp->fullIData(oldp+97,(vlSelf->Data_Out),32);
    bufp->fullIData(oldp+98,(vlSelf->a0),32);
    bufp->fullIData(oldp+99,(((IData)(vlSelf->cpu__DOT__isJALR)
                               ? vlSelf->cpu__DOT__RD1
                               : (IData)(vlSelf->cpu__DOT__PC))),32);
    bufp->fullSData(oldp+100,((0xffffU & ((IData)(vlSelf->cpu__DOT__isJALR)
                                           ? vlSelf->cpu__DOT__RD1
                                           : (IData)(vlSelf->cpu__DOT__PC)))),16);
    bufp->fullSData(oldp+101,((0xffffU & ((2U & (IData)(vlSelf->cpu__DOT__PCsrc))
                                           ? ((1U & (IData)(vlSelf->cpu__DOT__PCsrc))
                                               ? ((IData)(4U) 
                                                  + (IData)(vlSelf->cpu__DOT__PC))
                                               : vlSelf->cpu__DOT__DOut)
                                           : ((1U & (IData)(vlSelf->cpu__DOT__PCsrc))
                                               ? (IData)(vlSelf->cpu__DOT__PC_Target)
                                               : ((IData)(4U) 
                                                  + (IData)(vlSelf->cpu__DOT__PC)))))),16);
    bufp->fullIData(oldp+102,(5U),32);
    bufp->fullIData(oldp+103,(0x20U),32);
    bufp->fullIData(oldp+104,(0x10U),32);
    bufp->fullIData(oldp+105,(4U),32);
    bufp->fullIData(oldp+106,(3U),32);
    bufp->fullIData(oldp+107,(0x19U),32);
    bufp->fullSData(oldp+108,(vlSelf->cpu__DOT__PC_new),16);
    bufp->fullSData(oldp+109,(vlSelf->cpu__DOT__PC_to_PCreg),16);
    bufp->fullIData(oldp+110,(vlSelf->cpu__DOT__MemWrAdd),32);
    bufp->fullIData(oldp+111,(1U),32);
    bufp->fullIData(oldp+112,(0x14U),32);
    bufp->fullIData(oldp+113,(7U),32);
    bufp->fullIData(oldp+114,(2U),32);
    bufp->fullIData(oldp+115,(vlSelf->cpu__DOT__Decoder__DOT__UpperImm),20);
    bufp->fullCData(oldp+116,(vlSelf->cpu__DOT__Decoder__DOT__ShortImm),5);
}
