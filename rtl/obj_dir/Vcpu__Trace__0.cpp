// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu__Syms.h"


void Vcpu___024root__trace_chg_sub_0(Vcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vcpu___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_chg_top_0\n"); );
    // Init
    Vcpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu___024root*>(voidSelf);
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vcpu___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vcpu___024root__trace_chg_sub_0(Vcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelf->cpu__DOT__PC_Target),16);
        bufp->chgSData(oldp+1,(vlSelf->cpu__DOT__PC_to_Extend),16);
        bufp->chgCData(oldp+2,(vlSelf->cpu__DOT__PCsrc),2);
        bufp->chgBit(oldp+3,(vlSelf->cpu__DOT__zero));
        bufp->chgCData(oldp+4,(vlSelf->cpu__DOT__Resultsrc),2);
        bufp->chgBit(oldp+5,(vlSelf->cpu__DOT__MemWrite));
        bufp->chgBit(oldp+6,(vlSelf->cpu__DOT__WEn));
        bufp->chgCData(oldp+7,(vlSelf->cpu__DOT__RA1),5);
        bufp->chgIData(oldp+8,(vlSelf->cpu__DOT__RD1),32);
        bufp->chgCData(oldp+9,(vlSelf->cpu__DOT__RA2),5);
        bufp->chgIData(oldp+10,(vlSelf->cpu__DOT__RD2),32);
        bufp->chgCData(oldp+11,(vlSelf->cpu__DOT__WA3),5);
        bufp->chgCData(oldp+12,(vlSelf->cpu__DOT__ALUctrl),4);
        bufp->chgBit(oldp+13,(vlSelf->cpu__DOT__ALUsrc));
        bufp->chgCData(oldp+14,(vlSelf->cpu__DOT__ImmSel),3);
        bufp->chgIData(oldp+15,(vlSelf->cpu__DOT__ImmOp),25);
        bufp->chgIData(oldp+16,(vlSelf->cpu__DOT__ImmExt),32);
        bufp->chgIData(oldp+17,(vlSelf->cpu__DOT__ALU_OP2),32);
        bufp->chgIData(oldp+18,(vlSelf->cpu__DOT__ALU_Result),32);
        bufp->chgIData(oldp+19,(vlSelf->cpu__DOT__DOut),32);
        bufp->chgIData(oldp+20,(vlSelf->cpu__DOT__Memory_Read),32);
        bufp->chgBit(oldp+21,(vlSelf->cpu__DOT__isJALR));
        bufp->chgBit(oldp+22,(vlSelf->cpu__DOT__Decoder__DOT__cacheEn));
        bufp->chgCData(oldp+23,(vlSelf->cpu__DOT__Decoder__DOT__rd),5);
        bufp->chgCData(oldp+24,(vlSelf->cpu__DOT__Decoder__DOT__rs1),5);
        bufp->chgCData(oldp+25,(vlSelf->cpu__DOT__Decoder__DOT__rs2),5);
        bufp->chgIData(oldp+26,(vlSelf->cpu__DOT__Decoder__DOT__Imm),25);
        bufp->chgCData(oldp+27,(vlSelf->cpu__DOT__Decoder__DOT__opcode),7);
        bufp->chgCData(oldp+28,(vlSelf->cpu__DOT__Decoder__DOT__ALUopcode),4);
        bufp->chgCData(oldp+29,(vlSelf->cpu__DOT__Decoder__DOT__r0),5);
        bufp->chgCData(oldp+30,(vlSelf->cpu__DOT__Decoder__DOT__branchcode),3);
        bufp->chgIData(oldp+31,(vlSelf->cpu__DOT__MemFile__DOT__addr),20);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+32,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[0]),32);
        bufp->chgIData(oldp+33,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[1]),32);
        bufp->chgIData(oldp+34,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[2]),32);
        bufp->chgIData(oldp+35,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[3]),32);
        bufp->chgIData(oldp+36,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[4]),32);
        bufp->chgIData(oldp+37,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[5]),32);
        bufp->chgIData(oldp+38,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[6]),32);
        bufp->chgIData(oldp+39,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[7]),32);
        bufp->chgIData(oldp+40,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[8]),32);
        bufp->chgIData(oldp+41,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[9]),32);
        bufp->chgIData(oldp+42,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[10]),32);
        bufp->chgIData(oldp+43,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[11]),32);
        bufp->chgIData(oldp+44,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[12]),32);
        bufp->chgIData(oldp+45,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[13]),32);
        bufp->chgIData(oldp+46,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[14]),32);
        bufp->chgIData(oldp+47,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[15]),32);
        bufp->chgIData(oldp+48,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[16]),32);
        bufp->chgIData(oldp+49,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[17]),32);
        bufp->chgIData(oldp+50,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[18]),32);
        bufp->chgIData(oldp+51,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[19]),32);
        bufp->chgIData(oldp+52,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[20]),32);
        bufp->chgIData(oldp+53,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[21]),32);
        bufp->chgIData(oldp+54,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[22]),32);
        bufp->chgIData(oldp+55,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[23]),32);
        bufp->chgIData(oldp+56,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[24]),32);
        bufp->chgIData(oldp+57,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[25]),32);
        bufp->chgIData(oldp+58,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[26]),32);
        bufp->chgIData(oldp+59,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[27]),32);
        bufp->chgIData(oldp+60,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[28]),32);
        bufp->chgIData(oldp+61,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[29]),32);
        bufp->chgIData(oldp+62,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[30]),32);
        bufp->chgIData(oldp+63,(vlSelf->cpu__DOT__RegFile__DOT__rom_array[31]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgSData(oldp+64,(vlSelf->cpu__DOT__PC),16);
        bufp->chgSData(oldp+65,((0xffffU & ((IData)(4U) 
                                            + (IData)(vlSelf->cpu__DOT__PC)))),16);
        bufp->chgIData(oldp+66,(vlSelf->cpu__DOT__Instr),32);
        bufp->chgIData(oldp+67,(vlSelf->cpu__DOT__PC),32);
        bufp->chgCData(oldp+68,(vlSelf->cpu__DOT__PCMem__DOT__instrByte1),8);
        bufp->chgCData(oldp+69,(vlSelf->cpu__DOT__PCMem__DOT__instrByte2),8);
        bufp->chgCData(oldp+70,(vlSelf->cpu__DOT__PCMem__DOT__instrByte3),8);
        bufp->chgCData(oldp+71,(vlSelf->cpu__DOT__PCMem__DOT__instrByte4),8);
    }
    bufp->chgBit(oldp+72,(vlSelf->clk));
    bufp->chgBit(oldp+73,(vlSelf->rst));
    bufp->chgIData(oldp+74,(vlSelf->ImmExt_Out),32);
    bufp->chgSData(oldp+75,(vlSelf->PC_Out),16);
    bufp->chgSData(oldp+76,(vlSelf->PC_Target_Out),16);
    bufp->chgIData(oldp+77,(vlSelf->Instruction_Out),32);
    bufp->chgSData(oldp+78,(vlSelf->PC_new_Out),16);
    bufp->chgIData(oldp+79,(vlSelf->RD1_Out),32);
    bufp->chgIData(oldp+80,(vlSelf->RD2_Out),32);
    bufp->chgIData(oldp+81,(vlSelf->MemAddr_Out),32);
    bufp->chgIData(oldp+82,(vlSelf->MemData_Out),32);
    bufp->chgBit(oldp+83,(vlSelf->ZERO_Out));
    bufp->chgCData(oldp+84,(vlSelf->RA1_Out),5);
    bufp->chgCData(oldp+85,(vlSelf->RA2_Out),5);
    bufp->chgCData(oldp+86,(vlSelf->PCsrc_Out),2);
    bufp->chgCData(oldp+87,(vlSelf->Resultsrc_Out),2);
    bufp->chgBit(oldp+88,(vlSelf->MemWrite_Out));
    bufp->chgCData(oldp+89,(vlSelf->ALUctrl_Out),4);
    bufp->chgBit(oldp+90,(vlSelf->ALUsrc_Out));
    bufp->chgCData(oldp+91,(vlSelf->Immsrc_Out),3);
    bufp->chgBit(oldp+92,(vlSelf->RegWrite_Out));
    bufp->chgIData(oldp+93,(vlSelf->ImmOp_Out),25);
    bufp->chgSData(oldp+94,(vlSelf->Decode_PC_Out),16);
    bufp->chgCData(oldp+95,(vlSelf->WrAddr_Out),5);
    bufp->chgIData(oldp+96,(vlSelf->Data_Out),32);
    bufp->chgIData(oldp+97,(vlSelf->a0),32);
    bufp->chgIData(oldp+98,(((IData)(vlSelf->cpu__DOT__isJALR)
                              ? vlSelf->cpu__DOT__RD1
                              : (IData)(vlSelf->cpu__DOT__PC))),32);
    bufp->chgSData(oldp+99,((0xffffU & ((IData)(vlSelf->cpu__DOT__isJALR)
                                         ? vlSelf->cpu__DOT__RD1
                                         : (IData)(vlSelf->cpu__DOT__PC)))),16);
    bufp->chgSData(oldp+100,((0xffffU & ((2U & (IData)(vlSelf->cpu__DOT__PCsrc))
                                          ? ((1U & (IData)(vlSelf->cpu__DOT__PCsrc))
                                              ? ((IData)(4U) 
                                                 + (IData)(vlSelf->cpu__DOT__PC))
                                              : vlSelf->cpu__DOT__DOut)
                                          : ((1U & (IData)(vlSelf->cpu__DOT__PCsrc))
                                              ? (IData)(vlSelf->cpu__DOT__PC_Target)
                                              : ((IData)(4U) 
                                                 + (IData)(vlSelf->cpu__DOT__PC)))))),16);
}

void Vcpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_cleanup\n"); );
    // Init
    Vcpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu___024root*>(voidSelf);
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
