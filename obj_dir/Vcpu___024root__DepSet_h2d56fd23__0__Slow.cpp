// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu.h for the primary calling header

#include "verilated.h"

#include "Vcpu___024root.h"

VL_ATTR_COLD void Vcpu___024root___settle__TOP__0(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->ZERO_Out = vlSelf->cpu__DOT__zero;
    vlSelf->MemAddr_Out = vlSelf->cpu__DOT__MemWrAdd;
    vlSelf->PC_Out = vlSelf->cpu__DOT__PC;
    vlSelf->PC_new_Out = vlSelf->cpu__DOT__PC_new;
    vlSelf->Decode_PC_Out = vlSelf->cpu__DOT__PC_to_PCreg;
    vlSelf->MemData_Out = vlSelf->cpu__DOT__Memory_Read;
}

VL_ATTR_COLD void Vcpu___024root___initial__TOP__0(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___initial__TOP__0\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h5d3392b8__0;
    VlWide<4>/*127:0*/ __Vtemp_h08a4866f__0;
    // Body
    __Vtemp_h5d3392b8__0[0U] = 0x2e6d656dU;
    __Vtemp_h5d3392b8__0[1U] = 0x6e737472U;
    __Vtemp_h5d3392b8__0[2U] = 0x69U;
    VL_READMEM_N(true, 8, 65536, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h5d3392b8__0)
                 ,  &(vlSelf->cpu__DOT__PCMem__DOT__rom_array)
                 , 0, ~0ULL);
    __Vtemp_h08a4866f__0[0U] = 0x2e686578U;
    __Vtemp_h08a4866f__0[1U] = 0x74732e73U;
    __Vtemp_h08a4866f__0[2U] = 0x5f746573U;
    __Vtemp_h08a4866f__0[3U] = 0x6631U;
    VL_READMEM_N(true, 32, 65536, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_h08a4866f__0)
                 ,  &(vlSelf->cpu__DOT__MemFile__DOT__rom_array)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vcpu___024root___settle__TOP__1(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___settle__TOP__1\n"); );
    // Body
    vlSelf->cpu__DOT__PCMem__DOT__instrByte1 = vlSelf->cpu__DOT__PCMem__DOT__rom_array
        [vlSelf->cpu__DOT__PC_Next_Cycle];
    vlSelf->cpu__DOT__PCMem__DOT__instrByte2 = vlSelf->cpu__DOT__PCMem__DOT__rom_array
        [(0xffffU & ((IData)(1U) + (IData)(vlSelf->cpu__DOT__PC_Next_Cycle)))];
    vlSelf->cpu__DOT__PCMem__DOT__instrByte3 = vlSelf->cpu__DOT__PCMem__DOT__rom_array
        [(0xffffU & ((IData)(2U) + (IData)(vlSelf->cpu__DOT__PC_Next_Cycle)))];
    vlSelf->cpu__DOT__PCMem__DOT__instrByte4 = vlSelf->cpu__DOT__PCMem__DOT__rom_array
        [(0xffffU & ((IData)(3U) + (IData)(vlSelf->cpu__DOT__PC_Next_Cycle)))];
    vlSelf->cpu__DOT__Instr = (((IData)(vlSelf->cpu__DOT__PCMem__DOT__instrByte4) 
                                << 0x18U) | (((IData)(vlSelf->cpu__DOT__PCMem__DOT__instrByte3) 
                                              << 0x10U) 
                                             | (((IData)(vlSelf->cpu__DOT__PCMem__DOT__instrByte2) 
                                                 << 8U) 
                                                | (IData)(vlSelf->cpu__DOT__PCMem__DOT__instrByte1))));
    vlSelf->Instruction_Out = vlSelf->cpu__DOT__Instr;
    vlSelf->cpu__DOT__Decoder__DOT__rd = (0x1fU & (vlSelf->cpu__DOT__Instr 
                                                   >> 7U));
    vlSelf->cpu__DOT__Decoder__DOT__r0 = 0U;
    vlSelf->cpu__DOT__Decoder__DOT__rs1 = (0x1fU & 
                                           (vlSelf->cpu__DOT__Instr 
                                            >> 0xfU));
    vlSelf->cpu__DOT__Decoder__DOT__rs2 = (0x1fU & 
                                           (vlSelf->cpu__DOT__Instr 
                                            >> 0x14U));
    vlSelf->cpu__DOT__Decoder__DOT__Imm = (vlSelf->cpu__DOT__Instr 
                                           >> 7U);
    vlSelf->cpu__DOT__Decoder__DOT__opcode = (0x7fU 
                                              & vlSelf->cpu__DOT__Instr);
    vlSelf->cpu__DOT__Decoder__DOT__branchcode = (7U 
                                                  & (vlSelf->cpu__DOT__Instr 
                                                     >> 0xcU));
    vlSelf->cpu__DOT__Decoder__DOT__ALUopcode = ((8U 
                                                  & (vlSelf->cpu__DOT__Instr 
                                                     >> 0x1bU)) 
                                                 | (7U 
                                                    & (vlSelf->cpu__DOT__Instr 
                                                       >> 0xcU)));
    if ((0x40U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
        if ((0x20U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
            if ((0x10U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                vlSelf->cpu__DOT__RA1 = 0U;
                vlSelf->cpu__DOT__RA2 = 0U;
                vlSelf->cpu__DOT__WA3 = 0U;
                vlSelf->cpu__DOT__WEn = 0U;
                vlSelf->cpu__DOT__ALUsrc = 1U;
                vlSelf->cpu__DOT__ALUctrl = 0U;
                vlSelf->cpu__DOT__Resultsrc = 0U;
                vlSelf->cpu__DOT__PCsrc = 0U;
                vlSelf->cpu__DOT__ImmOp = 0U;
                vlSelf->cpu__DOT__ImmSel = 0U;
                vlSelf->cpu__DOT__MemWrite = 0U;
                vlSelf->cpu__DOT__PC_to_Extend = 0U;
            } else if ((8U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                if ((4U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                    if ((2U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                        if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                            vlSelf->cpu__DOT__RA1 = vlSelf->cpu__DOT__Decoder__DOT__rs1;
                            vlSelf->cpu__DOT__RA2 = vlSelf->cpu__DOT__Decoder__DOT__rs2;
                            vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__rd;
                            vlSelf->cpu__DOT__WEn = 1U;
                            vlSelf->cpu__DOT__ALUsrc = 1U;
                            vlSelf->cpu__DOT__ALUctrl = 0U;
                            vlSelf->cpu__DOT__Resultsrc = 0U;
                            vlSelf->cpu__DOT__PCsrc = 1U;
                            vlSelf->cpu__DOT__ImmOp 
                                = vlSelf->cpu__DOT__Decoder__DOT__Imm;
                            vlSelf->cpu__DOT__ImmSel = 3U;
                            vlSelf->cpu__DOT__MemWrite = 0U;
                            vlSelf->cpu__DOT__PC_to_Extend = 0U;
                        } else {
                            vlSelf->cpu__DOT__RA1 = 0U;
                            vlSelf->cpu__DOT__RA2 = 0U;
                            vlSelf->cpu__DOT__WA3 = 0U;
                            vlSelf->cpu__DOT__WEn = 0U;
                            vlSelf->cpu__DOT__ALUsrc = 1U;
                            vlSelf->cpu__DOT__ALUctrl = 0U;
                            vlSelf->cpu__DOT__Resultsrc = 0U;
                            vlSelf->cpu__DOT__PCsrc = 0U;
                            vlSelf->cpu__DOT__ImmOp = 0U;
                            vlSelf->cpu__DOT__ImmSel = 0U;
                            vlSelf->cpu__DOT__MemWrite = 0U;
                            vlSelf->cpu__DOT__PC_to_Extend = 0U;
                        }
                    } else {
                        vlSelf->cpu__DOT__RA1 = 0U;
                        vlSelf->cpu__DOT__RA2 = 0U;
                        vlSelf->cpu__DOT__WA3 = 0U;
                        vlSelf->cpu__DOT__WEn = 0U;
                        vlSelf->cpu__DOT__ALUsrc = 1U;
                        vlSelf->cpu__DOT__ALUctrl = 0U;
                        vlSelf->cpu__DOT__Resultsrc = 0U;
                        vlSelf->cpu__DOT__PCsrc = 0U;
                        vlSelf->cpu__DOT__ImmOp = 0U;
                        vlSelf->cpu__DOT__ImmSel = 0U;
                        vlSelf->cpu__DOT__MemWrite = 0U;
                        vlSelf->cpu__DOT__PC_to_Extend = 0U;
                    }
                } else {
                    vlSelf->cpu__DOT__RA1 = 0U;
                    vlSelf->cpu__DOT__RA2 = 0U;
                    vlSelf->cpu__DOT__WA3 = 0U;
                    vlSelf->cpu__DOT__WEn = 0U;
                    vlSelf->cpu__DOT__ALUsrc = 1U;
                    vlSelf->cpu__DOT__ALUctrl = 0U;
                    vlSelf->cpu__DOT__Resultsrc = 0U;
                    vlSelf->cpu__DOT__PCsrc = 0U;
                    vlSelf->cpu__DOT__ImmOp = 0U;
                    vlSelf->cpu__DOT__ImmSel = 0U;
                    vlSelf->cpu__DOT__MemWrite = 0U;
                    vlSelf->cpu__DOT__PC_to_Extend = 0U;
                }
            } else if ((4U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                vlSelf->cpu__DOT__RA1 = 0U;
                vlSelf->cpu__DOT__RA2 = 0U;
                vlSelf->cpu__DOT__WA3 = 0U;
                vlSelf->cpu__DOT__WEn = 0U;
                vlSelf->cpu__DOT__ALUsrc = 1U;
                vlSelf->cpu__DOT__ALUctrl = 0U;
                vlSelf->cpu__DOT__Resultsrc = 0U;
                vlSelf->cpu__DOT__PCsrc = 0U;
                vlSelf->cpu__DOT__ImmOp = 0U;
                vlSelf->cpu__DOT__ImmSel = 0U;
                vlSelf->cpu__DOT__MemWrite = 0U;
                vlSelf->cpu__DOT__PC_to_Extend = 0U;
            } else if ((2U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                    if ((4U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__branchcode))) {
                        if ((2U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__branchcode))) {
                            if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__branchcode))) {
                                vlSelf->cpu__DOT__RA1 = 0U;
                                vlSelf->cpu__DOT__RA2 = 0U;
                                vlSelf->cpu__DOT__WA3 = 0U;
                                vlSelf->cpu__DOT__WEn = 0U;
                                vlSelf->cpu__DOT__ALUsrc = 1U;
                                vlSelf->cpu__DOT__ALUctrl = 0U;
                                vlSelf->cpu__DOT__Resultsrc = 0U;
                                vlSelf->cpu__DOT__PCsrc = 0U;
                                vlSelf->cpu__DOT__ImmOp = 0U;
                                vlSelf->cpu__DOT__ImmSel = 0U;
                                vlSelf->cpu__DOT__MemWrite = 0U;
                                vlSelf->cpu__DOT__PC_to_Extend = 0U;
                            } else {
                                vlSelf->cpu__DOT__RA1 
                                    = vlSelf->cpu__DOT__Decoder__DOT__rs1;
                                vlSelf->cpu__DOT__RA2 
                                    = vlSelf->cpu__DOT__Decoder__DOT__rs2;
                                vlSelf->cpu__DOT__WA3 
                                    = vlSelf->cpu__DOT__Decoder__DOT__r0;
                                vlSelf->cpu__DOT__WEn = 0U;
                                vlSelf->cpu__DOT__ALUsrc = 0U;
                                vlSelf->cpu__DOT__ALUctrl = 3U;
                                vlSelf->cpu__DOT__Resultsrc = 0U;
                                vlSelf->cpu__DOT__PCsrc 
                                    = vlSelf->cpu__DOT__zero;
                                vlSelf->cpu__DOT__ImmOp 
                                    = vlSelf->cpu__DOT__Decoder__DOT__Imm;
                                vlSelf->cpu__DOT__ImmSel = 7U;
                                vlSelf->cpu__DOT__MemWrite = 0U;
                                vlSelf->cpu__DOT__PC_to_Extend = 0U;
                            }
                        } else if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__branchcode))) {
                            vlSelf->cpu__DOT__RA1 = 0U;
                            vlSelf->cpu__DOT__RA2 = 0U;
                            vlSelf->cpu__DOT__WA3 = 0U;
                            vlSelf->cpu__DOT__WEn = 0U;
                            vlSelf->cpu__DOT__ALUsrc = 1U;
                            vlSelf->cpu__DOT__ALUctrl = 0U;
                            vlSelf->cpu__DOT__Resultsrc = 0U;
                            vlSelf->cpu__DOT__PCsrc = 0U;
                            vlSelf->cpu__DOT__ImmOp = 0U;
                            vlSelf->cpu__DOT__ImmSel = 0U;
                            vlSelf->cpu__DOT__MemWrite = 0U;
                            vlSelf->cpu__DOT__PC_to_Extend = 0U;
                        } else {
                            vlSelf->cpu__DOT__RA1 = vlSelf->cpu__DOT__Decoder__DOT__rs1;
                            vlSelf->cpu__DOT__RA2 = vlSelf->cpu__DOT__Decoder__DOT__rs2;
                            vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__r0;
                            vlSelf->cpu__DOT__WEn = 0U;
                            vlSelf->cpu__DOT__ALUsrc = 0U;
                            vlSelf->cpu__DOT__ALUctrl = 2U;
                            vlSelf->cpu__DOT__Resultsrc = 0U;
                            vlSelf->cpu__DOT__PCsrc 
                                = vlSelf->cpu__DOT__zero;
                            vlSelf->cpu__DOT__ImmOp 
                                = vlSelf->cpu__DOT__Decoder__DOT__Imm;
                            vlSelf->cpu__DOT__ImmSel = 7U;
                            vlSelf->cpu__DOT__MemWrite = 0U;
                            vlSelf->cpu__DOT__PC_to_Extend = 0U;
                        }
                    } else if ((2U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__branchcode))) {
                        vlSelf->cpu__DOT__RA1 = 0U;
                        vlSelf->cpu__DOT__RA2 = 0U;
                        vlSelf->cpu__DOT__WA3 = 0U;
                        vlSelf->cpu__DOT__WEn = 0U;
                        vlSelf->cpu__DOT__ALUsrc = 1U;
                        vlSelf->cpu__DOT__ALUctrl = 0U;
                        vlSelf->cpu__DOT__Resultsrc = 0U;
                        vlSelf->cpu__DOT__PCsrc = 0U;
                        vlSelf->cpu__DOT__ImmOp = 0U;
                        vlSelf->cpu__DOT__ImmSel = 0U;
                        vlSelf->cpu__DOT__MemWrite = 0U;
                        vlSelf->cpu__DOT__PC_to_Extend = 0U;
                    } else if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__branchcode))) {
                        vlSelf->cpu__DOT__RA1 = vlSelf->cpu__DOT__Decoder__DOT__rs1;
                        vlSelf->cpu__DOT__RA2 = vlSelf->cpu__DOT__Decoder__DOT__rs2;
                        vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__r0;
                        vlSelf->cpu__DOT__WEn = 0U;
                        vlSelf->cpu__DOT__ALUsrc = 0U;
                        vlSelf->cpu__DOT__ALUctrl = 8U;
                        vlSelf->cpu__DOT__Resultsrc = 0U;
                        vlSelf->cpu__DOT__PCsrc = (1U 
                                                   & (~ (IData)(vlSelf->cpu__DOT__zero)));
                        vlSelf->cpu__DOT__ImmOp = vlSelf->cpu__DOT__Decoder__DOT__Imm;
                        vlSelf->cpu__DOT__ImmSel = 7U;
                        vlSelf->cpu__DOT__MemWrite = 0U;
                        vlSelf->cpu__DOT__PC_to_Extend = 0U;
                    } else {
                        vlSelf->cpu__DOT__RA1 = vlSelf->cpu__DOT__Decoder__DOT__rs1;
                        vlSelf->cpu__DOT__RA2 = vlSelf->cpu__DOT__Decoder__DOT__rs2;
                        vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__r0;
                        vlSelf->cpu__DOT__WEn = 0U;
                        vlSelf->cpu__DOT__ALUsrc = 0U;
                        vlSelf->cpu__DOT__ALUctrl = 8U;
                        vlSelf->cpu__DOT__Resultsrc = 0U;
                        vlSelf->cpu__DOT__PCsrc = vlSelf->cpu__DOT__zero;
                        vlSelf->cpu__DOT__ImmOp = vlSelf->cpu__DOT__Decoder__DOT__Imm;
                        vlSelf->cpu__DOT__ImmSel = 7U;
                        vlSelf->cpu__DOT__MemWrite = 0U;
                        vlSelf->cpu__DOT__PC_to_Extend = 0U;
                    }
                } else {
                    vlSelf->cpu__DOT__RA1 = 0U;
                    vlSelf->cpu__DOT__RA2 = 0U;
                    vlSelf->cpu__DOT__WA3 = 0U;
                    vlSelf->cpu__DOT__WEn = 0U;
                    vlSelf->cpu__DOT__ALUsrc = 1U;
                    vlSelf->cpu__DOT__ALUctrl = 0U;
                    vlSelf->cpu__DOT__Resultsrc = 0U;
                    vlSelf->cpu__DOT__PCsrc = 0U;
                    vlSelf->cpu__DOT__ImmOp = 0U;
                    vlSelf->cpu__DOT__ImmSel = 0U;
                    vlSelf->cpu__DOT__MemWrite = 0U;
                    vlSelf->cpu__DOT__PC_to_Extend = 0U;
                }
            } else {
                vlSelf->cpu__DOT__RA1 = 0U;
                vlSelf->cpu__DOT__RA2 = 0U;
                vlSelf->cpu__DOT__WA3 = 0U;
                vlSelf->cpu__DOT__WEn = 0U;
                vlSelf->cpu__DOT__ALUsrc = 1U;
                vlSelf->cpu__DOT__ALUctrl = 0U;
                vlSelf->cpu__DOT__Resultsrc = 0U;
                vlSelf->cpu__DOT__PCsrc = 0U;
                vlSelf->cpu__DOT__ImmOp = 0U;
                vlSelf->cpu__DOT__ImmSel = 0U;
                vlSelf->cpu__DOT__MemWrite = 0U;
                vlSelf->cpu__DOT__PC_to_Extend = 0U;
            }
        } else {
            vlSelf->cpu__DOT__RA1 = 0U;
            vlSelf->cpu__DOT__RA2 = 0U;
            vlSelf->cpu__DOT__WA3 = 0U;
            vlSelf->cpu__DOT__WEn = 0U;
            vlSelf->cpu__DOT__ALUsrc = 1U;
            vlSelf->cpu__DOT__ALUctrl = 0U;
            vlSelf->cpu__DOT__Resultsrc = 0U;
            vlSelf->cpu__DOT__PCsrc = 0U;
            vlSelf->cpu__DOT__ImmOp = 0U;
            vlSelf->cpu__DOT__ImmSel = 0U;
            vlSelf->cpu__DOT__MemWrite = 0U;
            vlSelf->cpu__DOT__PC_to_Extend = 0U;
        }
    } else if ((0x20U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
        if ((0x10U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
            if ((8U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                vlSelf->cpu__DOT__RA1 = 0U;
                vlSelf->cpu__DOT__RA2 = 0U;
                vlSelf->cpu__DOT__WA3 = 0U;
                vlSelf->cpu__DOT__WEn = 0U;
                vlSelf->cpu__DOT__ALUsrc = 1U;
                vlSelf->cpu__DOT__ALUctrl = 0U;
                vlSelf->cpu__DOT__Resultsrc = 0U;
                vlSelf->cpu__DOT__PCsrc = 0U;
                vlSelf->cpu__DOT__ImmOp = 0U;
                vlSelf->cpu__DOT__ImmSel = 0U;
                vlSelf->cpu__DOT__MemWrite = 0U;
                vlSelf->cpu__DOT__PC_to_Extend = 0U;
            } else if ((4U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                if ((2U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                    if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                        vlSelf->cpu__DOT__RA1 = vlSelf->cpu__DOT__Decoder__DOT__r0;
                        vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__rd;
                        vlSelf->cpu__DOT__WEn = 1U;
                        vlSelf->cpu__DOT__ALUsrc = 1U;
                        vlSelf->cpu__DOT__ALUctrl = 0U;
                        vlSelf->cpu__DOT__Resultsrc = 0U;
                        vlSelf->cpu__DOT__PCsrc = 0U;
                        vlSelf->cpu__DOT__ImmOp = vlSelf->cpu__DOT__Decoder__DOT__Imm;
                        vlSelf->cpu__DOT__ImmSel = 1U;
                        vlSelf->cpu__DOT__MemWrite = 0U;
                        vlSelf->cpu__DOT__PC_to_Extend = 0U;
                        vlSelf->cpu__DOT__RA2 = vlSelf->cpu__DOT__Decoder__DOT__r0;
                    } else {
                        vlSelf->cpu__DOT__RA1 = 0U;
                        vlSelf->cpu__DOT__RA2 = 0U;
                        vlSelf->cpu__DOT__WA3 = 0U;
                        vlSelf->cpu__DOT__WEn = 0U;
                        vlSelf->cpu__DOT__ALUsrc = 1U;
                        vlSelf->cpu__DOT__ALUctrl = 0U;
                        vlSelf->cpu__DOT__Resultsrc = 0U;
                        vlSelf->cpu__DOT__PCsrc = 0U;
                        vlSelf->cpu__DOT__ImmOp = 0U;
                        vlSelf->cpu__DOT__ImmSel = 0U;
                        vlSelf->cpu__DOT__MemWrite = 0U;
                        vlSelf->cpu__DOT__PC_to_Extend = 0U;
                    }
                } else {
                    vlSelf->cpu__DOT__RA1 = 0U;
                    vlSelf->cpu__DOT__RA2 = 0U;
                    vlSelf->cpu__DOT__WA3 = 0U;
                    vlSelf->cpu__DOT__WEn = 0U;
                    vlSelf->cpu__DOT__ALUsrc = 1U;
                    vlSelf->cpu__DOT__ALUctrl = 0U;
                    vlSelf->cpu__DOT__Resultsrc = 0U;
                    vlSelf->cpu__DOT__PCsrc = 0U;
                    vlSelf->cpu__DOT__ImmOp = 0U;
                    vlSelf->cpu__DOT__ImmSel = 0U;
                    vlSelf->cpu__DOT__MemWrite = 0U;
                    vlSelf->cpu__DOT__PC_to_Extend = 0U;
                }
            } else if ((2U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                    vlSelf->cpu__DOT__RA1 = vlSelf->cpu__DOT__Decoder__DOT__rs1;
                    vlSelf->cpu__DOT__RA2 = vlSelf->cpu__DOT__Decoder__DOT__rs2;
                    vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__rd;
                    vlSelf->cpu__DOT__WEn = 1U;
                    vlSelf->cpu__DOT__ALUsrc = 0U;
                    vlSelf->cpu__DOT__ALUctrl = vlSelf->cpu__DOT__Decoder__DOT__ALUopcode;
                    vlSelf->cpu__DOT__Resultsrc = 0U;
                    vlSelf->cpu__DOT__PCsrc = 0U;
                    vlSelf->cpu__DOT__ImmOp = vlSelf->cpu__DOT__Decoder__DOT__Imm;
                    vlSelf->cpu__DOT__ImmSel = 0U;
                    vlSelf->cpu__DOT__MemWrite = 0U;
                    vlSelf->cpu__DOT__PC_to_Extend = 0U;
                } else {
                    vlSelf->cpu__DOT__RA1 = 0U;
                    vlSelf->cpu__DOT__RA2 = 0U;
                    vlSelf->cpu__DOT__WA3 = 0U;
                    vlSelf->cpu__DOT__WEn = 0U;
                    vlSelf->cpu__DOT__ALUsrc = 1U;
                    vlSelf->cpu__DOT__ALUctrl = 0U;
                    vlSelf->cpu__DOT__Resultsrc = 0U;
                    vlSelf->cpu__DOT__PCsrc = 0U;
                    vlSelf->cpu__DOT__ImmOp = 0U;
                    vlSelf->cpu__DOT__ImmSel = 0U;
                    vlSelf->cpu__DOT__MemWrite = 0U;
                    vlSelf->cpu__DOT__PC_to_Extend = 0U;
                }
            } else {
                vlSelf->cpu__DOT__RA1 = 0U;
                vlSelf->cpu__DOT__RA2 = 0U;
                vlSelf->cpu__DOT__WA3 = 0U;
                vlSelf->cpu__DOT__WEn = 0U;
                vlSelf->cpu__DOT__ALUsrc = 1U;
                vlSelf->cpu__DOT__ALUctrl = 0U;
                vlSelf->cpu__DOT__Resultsrc = 0U;
                vlSelf->cpu__DOT__PCsrc = 0U;
                vlSelf->cpu__DOT__ImmOp = 0U;
                vlSelf->cpu__DOT__ImmSel = 0U;
                vlSelf->cpu__DOT__MemWrite = 0U;
                vlSelf->cpu__DOT__PC_to_Extend = 0U;
            }
        } else if ((8U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
            vlSelf->cpu__DOT__RA1 = 0U;
            vlSelf->cpu__DOT__RA2 = 0U;
            vlSelf->cpu__DOT__WA3 = 0U;
            vlSelf->cpu__DOT__WEn = 0U;
            vlSelf->cpu__DOT__ALUsrc = 1U;
            vlSelf->cpu__DOT__ALUctrl = 0U;
            vlSelf->cpu__DOT__Resultsrc = 0U;
            vlSelf->cpu__DOT__PCsrc = 0U;
            vlSelf->cpu__DOT__ImmOp = 0U;
            vlSelf->cpu__DOT__ImmSel = 0U;
            vlSelf->cpu__DOT__MemWrite = 0U;
            vlSelf->cpu__DOT__PC_to_Extend = 0U;
        } else if ((4U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
            vlSelf->cpu__DOT__RA1 = 0U;
            vlSelf->cpu__DOT__RA2 = 0U;
            vlSelf->cpu__DOT__WA3 = 0U;
            vlSelf->cpu__DOT__WEn = 0U;
            vlSelf->cpu__DOT__ALUsrc = 1U;
            vlSelf->cpu__DOT__ALUctrl = 0U;
            vlSelf->cpu__DOT__Resultsrc = 0U;
            vlSelf->cpu__DOT__PCsrc = 0U;
            vlSelf->cpu__DOT__ImmOp = 0U;
            vlSelf->cpu__DOT__ImmSel = 0U;
            vlSelf->cpu__DOT__MemWrite = 0U;
            vlSelf->cpu__DOT__PC_to_Extend = 0U;
        } else if ((2U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
            if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                vlSelf->cpu__DOT__RA1 = vlSelf->cpu__DOT__Decoder__DOT__rs1;
                vlSelf->cpu__DOT__RA2 = vlSelf->cpu__DOT__Decoder__DOT__rs2;
                vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__r0;
                vlSelf->cpu__DOT__WEn = 0U;
                vlSelf->cpu__DOT__ALUsrc = 0U;
                vlSelf->cpu__DOT__ALUctrl = 0U;
                vlSelf->cpu__DOT__Resultsrc = 1U;
                vlSelf->cpu__DOT__PCsrc = 0U;
                vlSelf->cpu__DOT__ImmOp = vlSelf->cpu__DOT__Decoder__DOT__Imm;
                vlSelf->cpu__DOT__ImmSel = 2U;
                vlSelf->cpu__DOT__MemWrite = 1U;
                vlSelf->cpu__DOT__PC_to_Extend = 0U;
            } else {
                vlSelf->cpu__DOT__RA1 = 0U;
                vlSelf->cpu__DOT__RA2 = 0U;
                vlSelf->cpu__DOT__WA3 = 0U;
                vlSelf->cpu__DOT__WEn = 0U;
                vlSelf->cpu__DOT__ALUsrc = 1U;
                vlSelf->cpu__DOT__ALUctrl = 0U;
                vlSelf->cpu__DOT__Resultsrc = 0U;
                vlSelf->cpu__DOT__PCsrc = 0U;
                vlSelf->cpu__DOT__ImmOp = 0U;
                vlSelf->cpu__DOT__ImmSel = 0U;
                vlSelf->cpu__DOT__MemWrite = 0U;
                vlSelf->cpu__DOT__PC_to_Extend = 0U;
            }
        } else {
            vlSelf->cpu__DOT__RA1 = 0U;
            vlSelf->cpu__DOT__RA2 = 0U;
            vlSelf->cpu__DOT__WA3 = 0U;
            vlSelf->cpu__DOT__WEn = 0U;
            vlSelf->cpu__DOT__ALUsrc = 1U;
            vlSelf->cpu__DOT__ALUctrl = 0U;
            vlSelf->cpu__DOT__Resultsrc = 0U;
            vlSelf->cpu__DOT__PCsrc = 0U;
            vlSelf->cpu__DOT__ImmOp = 0U;
            vlSelf->cpu__DOT__ImmSel = 0U;
            vlSelf->cpu__DOT__MemWrite = 0U;
            vlSelf->cpu__DOT__PC_to_Extend = 0U;
        }
    } else if ((0x10U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
        if ((8U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
            vlSelf->cpu__DOT__RA1 = 0U;
            vlSelf->cpu__DOT__RA2 = 0U;
            vlSelf->cpu__DOT__WA3 = 0U;
            vlSelf->cpu__DOT__WEn = 0U;
            vlSelf->cpu__DOT__ALUsrc = 1U;
            vlSelf->cpu__DOT__ALUctrl = 0U;
            vlSelf->cpu__DOT__Resultsrc = 0U;
            vlSelf->cpu__DOT__PCsrc = 0U;
            vlSelf->cpu__DOT__ImmOp = 0U;
            vlSelf->cpu__DOT__ImmSel = 0U;
            vlSelf->cpu__DOT__MemWrite = 0U;
            vlSelf->cpu__DOT__PC_to_Extend = 0U;
        } else if ((4U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
            if ((2U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                    vlSelf->cpu__DOT__RA1 = vlSelf->cpu__DOT__Decoder__DOT__r0;
                    vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__rd;
                    vlSelf->cpu__DOT__WEn = 1U;
                    vlSelf->cpu__DOT__ALUsrc = 1U;
                    vlSelf->cpu__DOT__ALUctrl = 0U;
                    vlSelf->cpu__DOT__Resultsrc = 0U;
                    vlSelf->cpu__DOT__PCsrc = 0U;
                    vlSelf->cpu__DOT__ImmOp = vlSelf->cpu__DOT__Decoder__DOT__Imm;
                    vlSelf->cpu__DOT__ImmSel = 1U;
                    vlSelf->cpu__DOT__MemWrite = 0U;
                    vlSelf->cpu__DOT__PC_to_Extend 
                        = (0xffffU & ((IData)(vlSelf->cpu__DOT__PC_new) 
                                      - (IData)(4U)));
                    vlSelf->cpu__DOT__RA2 = vlSelf->cpu__DOT__Decoder__DOT__r0;
                } else {
                    vlSelf->cpu__DOT__RA1 = 0U;
                    vlSelf->cpu__DOT__RA2 = 0U;
                    vlSelf->cpu__DOT__WA3 = 0U;
                    vlSelf->cpu__DOT__WEn = 0U;
                    vlSelf->cpu__DOT__ALUsrc = 1U;
                    vlSelf->cpu__DOT__ALUctrl = 0U;
                    vlSelf->cpu__DOT__Resultsrc = 0U;
                    vlSelf->cpu__DOT__PCsrc = 0U;
                    vlSelf->cpu__DOT__ImmOp = 0U;
                    vlSelf->cpu__DOT__ImmSel = 0U;
                    vlSelf->cpu__DOT__MemWrite = 0U;
                    vlSelf->cpu__DOT__PC_to_Extend = 0U;
                }
            } else {
                vlSelf->cpu__DOT__RA1 = 0U;
                vlSelf->cpu__DOT__RA2 = 0U;
                vlSelf->cpu__DOT__WA3 = 0U;
                vlSelf->cpu__DOT__WEn = 0U;
                vlSelf->cpu__DOT__ALUsrc = 1U;
                vlSelf->cpu__DOT__ALUctrl = 0U;
                vlSelf->cpu__DOT__Resultsrc = 0U;
                vlSelf->cpu__DOT__PCsrc = 0U;
                vlSelf->cpu__DOT__ImmOp = 0U;
                vlSelf->cpu__DOT__ImmSel = 0U;
                vlSelf->cpu__DOT__MemWrite = 0U;
                vlSelf->cpu__DOT__PC_to_Extend = 0U;
            }
        } else if ((2U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
            if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                vlSelf->cpu__DOT__RA1 = vlSelf->cpu__DOT__Decoder__DOT__rs1;
                vlSelf->cpu__DOT__RA2 = vlSelf->cpu__DOT__Decoder__DOT__r0;
                vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__rd;
                vlSelf->cpu__DOT__WEn = 1U;
                vlSelf->cpu__DOT__ALUsrc = 1U;
                vlSelf->cpu__DOT__ALUctrl = vlSelf->cpu__DOT__Decoder__DOT__ALUopcode;
                vlSelf->cpu__DOT__Resultsrc = 0U;
                vlSelf->cpu__DOT__PCsrc = 0U;
                vlSelf->cpu__DOT__ImmOp = vlSelf->cpu__DOT__Decoder__DOT__Imm;
                vlSelf->cpu__DOT__ImmSel = 0U;
                vlSelf->cpu__DOT__MemWrite = 0U;
                vlSelf->cpu__DOT__PC_to_Extend = 0U;
            } else {
                vlSelf->cpu__DOT__RA1 = 0U;
                vlSelf->cpu__DOT__RA2 = 0U;
                vlSelf->cpu__DOT__WA3 = 0U;
                vlSelf->cpu__DOT__WEn = 0U;
                vlSelf->cpu__DOT__ALUsrc = 1U;
                vlSelf->cpu__DOT__ALUctrl = 0U;
                vlSelf->cpu__DOT__Resultsrc = 0U;
                vlSelf->cpu__DOT__PCsrc = 0U;
                vlSelf->cpu__DOT__ImmOp = 0U;
                vlSelf->cpu__DOT__ImmSel = 0U;
                vlSelf->cpu__DOT__MemWrite = 0U;
                vlSelf->cpu__DOT__PC_to_Extend = 0U;
            }
        } else {
            vlSelf->cpu__DOT__RA1 = 0U;
            vlSelf->cpu__DOT__RA2 = 0U;
            vlSelf->cpu__DOT__WA3 = 0U;
            vlSelf->cpu__DOT__WEn = 0U;
            vlSelf->cpu__DOT__ALUsrc = 1U;
            vlSelf->cpu__DOT__ALUctrl = 0U;
            vlSelf->cpu__DOT__Resultsrc = 0U;
            vlSelf->cpu__DOT__PCsrc = 0U;
            vlSelf->cpu__DOT__ImmOp = 0U;
            vlSelf->cpu__DOT__ImmSel = 0U;
            vlSelf->cpu__DOT__MemWrite = 0U;
            vlSelf->cpu__DOT__PC_to_Extend = 0U;
        }
    } else if ((8U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
        vlSelf->cpu__DOT__RA1 = 0U;
        vlSelf->cpu__DOT__RA2 = 0U;
        vlSelf->cpu__DOT__WA3 = 0U;
        vlSelf->cpu__DOT__WEn = 0U;
        vlSelf->cpu__DOT__ALUsrc = 1U;
        vlSelf->cpu__DOT__ALUctrl = 0U;
        vlSelf->cpu__DOT__Resultsrc = 0U;
        vlSelf->cpu__DOT__PCsrc = 0U;
        vlSelf->cpu__DOT__ImmOp = 0U;
        vlSelf->cpu__DOT__ImmSel = 0U;
        vlSelf->cpu__DOT__MemWrite = 0U;
        vlSelf->cpu__DOT__PC_to_Extend = 0U;
    } else if ((4U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
        vlSelf->cpu__DOT__RA1 = 0U;
        vlSelf->cpu__DOT__RA2 = 0U;
        vlSelf->cpu__DOT__WA3 = 0U;
        vlSelf->cpu__DOT__WEn = 0U;
        vlSelf->cpu__DOT__ALUsrc = 1U;
        vlSelf->cpu__DOT__ALUctrl = 0U;
        vlSelf->cpu__DOT__Resultsrc = 0U;
        vlSelf->cpu__DOT__PCsrc = 0U;
        vlSelf->cpu__DOT__ImmOp = 0U;
        vlSelf->cpu__DOT__ImmSel = 0U;
        vlSelf->cpu__DOT__MemWrite = 0U;
        vlSelf->cpu__DOT__PC_to_Extend = 0U;
    } else if ((2U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
        if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
            vlSelf->cpu__DOT__RA1 = vlSelf->cpu__DOT__Decoder__DOT__rs1;
            vlSelf->cpu__DOT__RA2 = vlSelf->cpu__DOT__Decoder__DOT__r0;
            vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__rs2;
            vlSelf->cpu__DOT__WEn = 1U;
            vlSelf->cpu__DOT__ALUsrc = 1U;
            vlSelf->cpu__DOT__ALUctrl = 0U;
            vlSelf->cpu__DOT__Resultsrc = 1U;
            vlSelf->cpu__DOT__PCsrc = 0U;
            vlSelf->cpu__DOT__ImmOp = vlSelf->cpu__DOT__Decoder__DOT__Imm;
            vlSelf->cpu__DOT__ImmSel = 4U;
            vlSelf->cpu__DOT__MemWrite = 1U;
            vlSelf->cpu__DOT__PC_to_Extend = 0U;
        } else {
            vlSelf->cpu__DOT__RA1 = 0U;
            vlSelf->cpu__DOT__RA2 = 0U;
            vlSelf->cpu__DOT__WA3 = 0U;
            vlSelf->cpu__DOT__WEn = 0U;
            vlSelf->cpu__DOT__ALUsrc = 1U;
            vlSelf->cpu__DOT__ALUctrl = 0U;
            vlSelf->cpu__DOT__Resultsrc = 0U;
            vlSelf->cpu__DOT__PCsrc = 0U;
            vlSelf->cpu__DOT__ImmOp = 0U;
            vlSelf->cpu__DOT__ImmSel = 0U;
            vlSelf->cpu__DOT__MemWrite = 0U;
            vlSelf->cpu__DOT__PC_to_Extend = 0U;
        }
    } else {
        vlSelf->cpu__DOT__RA1 = 0U;
        vlSelf->cpu__DOT__RA2 = 0U;
        vlSelf->cpu__DOT__WA3 = 0U;
        vlSelf->cpu__DOT__WEn = 0U;
        vlSelf->cpu__DOT__ALUsrc = 1U;
        vlSelf->cpu__DOT__ALUctrl = 0U;
        vlSelf->cpu__DOT__Resultsrc = 0U;
        vlSelf->cpu__DOT__PCsrc = 0U;
        vlSelf->cpu__DOT__ImmOp = 0U;
        vlSelf->cpu__DOT__ImmSel = 0U;
        vlSelf->cpu__DOT__MemWrite = 0U;
        vlSelf->cpu__DOT__PC_to_Extend = 0U;
    }
    vlSelf->WrAddr_Out = vlSelf->cpu__DOT__WA3;
    vlSelf->RegWrite_Out = vlSelf->cpu__DOT__WEn;
    vlSelf->MemWrite_Out = vlSelf->cpu__DOT__MemWrite;
    vlSelf->PCsrc_Out = vlSelf->cpu__DOT__PCsrc;
    vlSelf->Resultsrc_Out = vlSelf->cpu__DOT__Resultsrc;
    vlSelf->ALUctrl_Out = vlSelf->cpu__DOT__ALUctrl;
    vlSelf->ALUsrc_Out = vlSelf->cpu__DOT__ALUsrc;
    vlSelf->RA1_Out = vlSelf->cpu__DOT__RA1;
    vlSelf->cpu__DOT__RD1 = vlSelf->cpu__DOT__RegFile__DOT__rom_array
        [vlSelf->cpu__DOT__RA1];
    vlSelf->RA2_Out = vlSelf->cpu__DOT__RA2;
    vlSelf->cpu__DOT__RD2 = vlSelf->cpu__DOT__RegFile__DOT__rom_array
        [vlSelf->cpu__DOT__RA2];
    vlSelf->ImmOp_Out = vlSelf->cpu__DOT__ImmOp;
    vlSelf->Immsrc_Out = vlSelf->cpu__DOT__ImmSel;
    vlSelf->cpu__DOT__ImmExt = ((4U & (IData)(vlSelf->cpu__DOT__ImmSel))
                                 ? ((2U & (IData)(vlSelf->cpu__DOT__ImmSel))
                                     ? ((1U & (IData)(vlSelf->cpu__DOT__ImmSel))
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->cpu__DOT__ImmOp 
                                                            >> 0x18U)))) 
                                             << 0xcU) 
                                            | ((0x800U 
                                                & (vlSelf->cpu__DOT__ImmOp 
                                                   << 0xbU)) 
                                               | ((0x7e0U 
                                                   & (vlSelf->cpu__DOT__ImmOp 
                                                      >> 0xdU)) 
                                                  | (0x1eU 
                                                     & vlSelf->cpu__DOT__ImmOp))))
                                         : (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->cpu__DOT__ImmOp 
                                                            >> 0x18U)))) 
                                             << 0xcU) 
                                            | (0xfffU 
                                               & (vlSelf->cpu__DOT__ImmOp 
                                                  >> 0xdU))))
                                     : ((1U & (IData)(vlSelf->cpu__DOT__ImmSel))
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->cpu__DOT__ImmOp 
                                                            >> 0x18U)))) 
                                             << 0xcU) 
                                            | (0xfffU 
                                               & (vlSelf->cpu__DOT__ImmOp 
                                                  >> 0xdU)))
                                         : (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->cpu__DOT__ImmOp 
                                                            >> 0x18U)))) 
                                             << 0xcU) 
                                            | (0xfffU 
                                               & (vlSelf->cpu__DOT__ImmOp 
                                                  >> 0xdU)))))
                                 : ((2U & (IData)(vlSelf->cpu__DOT__ImmSel))
                                     ? ((1U & (IData)(vlSelf->cpu__DOT__ImmSel))
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->cpu__DOT__ImmOp 
                                                            >> 0x18U)))) 
                                             << 0x14U) 
                                            | ((0xff000U 
                                                & (vlSelf->cpu__DOT__ImmOp 
                                                   << 7U)) 
                                               | ((0x800U 
                                                   & (vlSelf->cpu__DOT__ImmOp 
                                                      >> 2U)) 
                                                  | (0x7feU 
                                                     & (vlSelf->cpu__DOT__ImmOp 
                                                        >> 0xdU)))))
                                         : (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->cpu__DOT__ImmOp 
                                                            >> 0x18U)))) 
                                             << 0xcU) 
                                            | ((0xfe0U 
                                                & (vlSelf->cpu__DOT__ImmOp 
                                                   >> 0xdU)) 
                                               | (0x1fU 
                                                  & vlSelf->cpu__DOT__ImmOp))))
                                     : ((1U & (IData)(vlSelf->cpu__DOT__ImmSel))
                                         ? (0xfffff000U 
                                            & (vlSelf->cpu__DOT__ImmOp 
                                               << 7U))
                                         : (((- (IData)(
                                                        (1U 
                                                         & (vlSelf->cpu__DOT__ImmOp 
                                                            >> 0x18U)))) 
                                             << 0xcU) 
                                            | (0xfffU 
                                               & (vlSelf->cpu__DOT__ImmOp 
                                                  >> 0xdU))))));
    vlSelf->RD1_Out = vlSelf->cpu__DOT__RD1;
    vlSelf->RD2_Out = vlSelf->cpu__DOT__RD2;
    vlSelf->ImmExt_Out = vlSelf->cpu__DOT__ImmExt;
    vlSelf->cpu__DOT__PC_Target = (0xffffU & ((IData)(vlSelf->cpu__DOT__PC) 
                                              + vlSelf->cpu__DOT__ImmExt));
    vlSelf->cpu__DOT__ALU_OP2 = ((IData)(vlSelf->cpu__DOT__ALUsrc)
                                  ? vlSelf->cpu__DOT__ImmExt
                                  : vlSelf->cpu__DOT__RD2);
    vlSelf->PC_Target_Out = vlSelf->cpu__DOT__PC_Target;
    vlSelf->cpu__DOT__ProgramCounter__DOT__next_PC 
        = (0xffffU & ((IData)(vlSelf->cpu__DOT__PCsrc)
                       ? ((IData)(vlSelf->cpu__DOT__PC_Next_Cycle) 
                          + (IData)(vlSelf->cpu__DOT__PC_Target))
                       : ((IData)(4U) + (IData)(vlSelf->cpu__DOT__PC_Next_Cycle))));
    vlSelf->cpu__DOT__ALU_Result = ((8U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                     ? ((4U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                         ? ((2U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                             ? 0U : 
                                            ((1U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                              ? (vlSelf->cpu__DOT__RD1 
                                                 >> 
                                                 (0x1fU 
                                                  & vlSelf->cpu__DOT__ALU_OP2))
                                              : 0U))
                                         : ((2U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                             ? 0U : 
                                            ((1U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                              ? 0U : 
                                             (vlSelf->cpu__DOT__RD1 
                                              - vlSelf->cpu__DOT__ALU_OP2))))
                                     : ((4U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                         ? ((2U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                             ? ((1U 
                                                 & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                                 ? 
                                                (vlSelf->cpu__DOT__RD1 
                                                 & vlSelf->cpu__DOT__ALU_OP2)
                                                 : 
                                                (vlSelf->cpu__DOT__RD1 
                                                 | vlSelf->cpu__DOT__ALU_OP2))
                                             : ((1U 
                                                 & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                                 ? 
                                                (vlSelf->cpu__DOT__RD1 
                                                 >> 
                                                 (0x1fU 
                                                  & vlSelf->cpu__DOT__ALU_OP2))
                                                 : 
                                                (vlSelf->cpu__DOT__RD1 
                                                 ^ vlSelf->cpu__DOT__ALU_OP2)))
                                         : ((2U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                             ? ((1U 
                                                 & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                                 ? 
                                                ((vlSelf->cpu__DOT__RD1 
                                                  < vlSelf->cpu__DOT__ALU_OP2)
                                                  ? 1U
                                                  : 0U)
                                                 : 
                                                (VL_LTS_III(32, vlSelf->cpu__DOT__RD1, vlSelf->cpu__DOT__ALU_OP2)
                                                  ? 1U
                                                  : 0U))
                                             : ((1U 
                                                 & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                                 ? 
                                                (vlSelf->cpu__DOT__RD1 
                                                 << 
                                                 (0x1fU 
                                                  & vlSelf->cpu__DOT__ALU_OP2))
                                                 : 
                                                (vlSelf->cpu__DOT__RD1 
                                                 + vlSelf->cpu__DOT__ALU_OP2)))));
    vlSelf->cpu__DOT__zero = (0U == vlSelf->cpu__DOT__ALU_Result);
    vlSelf->cpu__DOT__DOut = ((IData)(vlSelf->cpu__DOT__Resultsrc)
                               ? vlSelf->cpu__DOT__Memory_Read
                               : vlSelf->cpu__DOT__ALU_Result);
    vlSelf->Data_Out = vlSelf->cpu__DOT__DOut;
}

VL_ATTR_COLD void Vcpu___024root___eval_initial(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval_initial\n"); );
    // Body
    Vcpu___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vcpu___024root___eval_settle(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval_settle\n"); );
    // Body
    Vcpu___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    Vcpu___024root___settle__TOP__1(vlSelf);
}

VL_ATTR_COLD void Vcpu___024root___final(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___final\n"); );
}

VL_ATTR_COLD void Vcpu___024root___ctor_var_reset(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->ImmExt_Out = VL_RAND_RESET_I(32);
    vlSelf->PC_Out = VL_RAND_RESET_I(16);
    vlSelf->PC_Target_Out = VL_RAND_RESET_I(16);
    vlSelf->Instruction_Out = VL_RAND_RESET_I(32);
    vlSelf->PC_new_Out = VL_RAND_RESET_I(16);
    vlSelf->RD1_Out = VL_RAND_RESET_I(32);
    vlSelf->RD2_Out = VL_RAND_RESET_I(32);
    vlSelf->MemAddr_Out = VL_RAND_RESET_I(32);
    vlSelf->MemData_Out = VL_RAND_RESET_I(32);
    vlSelf->ZERO_Out = VL_RAND_RESET_I(1);
    vlSelf->RA1_Out = VL_RAND_RESET_I(5);
    vlSelf->RA2_Out = VL_RAND_RESET_I(5);
    vlSelf->PCsrc_Out = VL_RAND_RESET_I(1);
    vlSelf->Resultsrc_Out = VL_RAND_RESET_I(1);
    vlSelf->MemWrite_Out = VL_RAND_RESET_I(1);
    vlSelf->ALUctrl_Out = VL_RAND_RESET_I(4);
    vlSelf->ALUsrc_Out = VL_RAND_RESET_I(1);
    vlSelf->Immsrc_Out = VL_RAND_RESET_I(3);
    vlSelf->RegWrite_Out = VL_RAND_RESET_I(1);
    vlSelf->ImmOp_Out = VL_RAND_RESET_I(25);
    vlSelf->Decode_PC_Out = VL_RAND_RESET_I(16);
    vlSelf->WrAddr_Out = VL_RAND_RESET_I(5);
    vlSelf->Data_Out = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__PC = VL_RAND_RESET_I(16);
    vlSelf->cpu__DOT__PC_new = VL_RAND_RESET_I(16);
    vlSelf->cpu__DOT__PC_to_PCreg = VL_RAND_RESET_I(16);
    vlSelf->cpu__DOT__PC_Next_Cycle = VL_RAND_RESET_I(16);
    vlSelf->cpu__DOT__PC_Target = VL_RAND_RESET_I(16);
    vlSelf->cpu__DOT__PC_to_Extend = VL_RAND_RESET_I(16);
    vlSelf->cpu__DOT__PCsrc = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__zero = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__Resultsrc = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__MemWrite = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__WEn = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__MemWrAdd = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__RA1 = VL_RAND_RESET_I(5);
    vlSelf->cpu__DOT__RD1 = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__RA2 = VL_RAND_RESET_I(5);
    vlSelf->cpu__DOT__RD2 = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__WA3 = VL_RAND_RESET_I(5);
    vlSelf->cpu__DOT__Instr = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__ALUctrl = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__ALUsrc = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__ImmSel = VL_RAND_RESET_I(3);
    vlSelf->cpu__DOT__ImmOp = VL_RAND_RESET_I(25);
    vlSelf->cpu__DOT__ImmExt = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__ALU_OP2 = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__ALU_Result = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__DOut = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__Memory_Read = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__ProgramCounter__DOT__next_PC = VL_RAND_RESET_I(16);
    vlSelf->cpu__DOT__PCMem__DOT__instrByte1 = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__PCMem__DOT__instrByte2 = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__PCMem__DOT__instrByte3 = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__PCMem__DOT__instrByte4 = VL_RAND_RESET_I(8);
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        vlSelf->cpu__DOT__PCMem__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->cpu__DOT__Decoder__DOT__rd = VL_RAND_RESET_I(5);
    vlSelf->cpu__DOT__Decoder__DOT__rs1 = VL_RAND_RESET_I(5);
    vlSelf->cpu__DOT__Decoder__DOT__rs2 = VL_RAND_RESET_I(5);
    vlSelf->cpu__DOT__Decoder__DOT__Imm = VL_RAND_RESET_I(25);
    vlSelf->cpu__DOT__Decoder__DOT__UpperImm = VL_RAND_RESET_I(20);
    vlSelf->cpu__DOT__Decoder__DOT__ShortImm = VL_RAND_RESET_I(5);
    vlSelf->cpu__DOT__Decoder__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->cpu__DOT__Decoder__DOT__ALUopcode = VL_RAND_RESET_I(4);
    vlSelf->cpu__DOT__Decoder__DOT__r0 = VL_RAND_RESET_I(5);
    vlSelf->cpu__DOT__Decoder__DOT__branchcode = VL_RAND_RESET_I(3);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->cpu__DOT__RegFile__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        vlSelf->cpu__DOT__MemFile__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vchglast__TOP__cpu__DOT__zero = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
