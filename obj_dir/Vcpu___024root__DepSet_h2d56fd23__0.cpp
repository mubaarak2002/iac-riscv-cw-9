// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu.h for the primary calling header

#include "verilated.h"

#include "Vcpu___024root.h"

VL_INLINE_OPT void Vcpu___024root___combo__TOP__0(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->ZERO_Out = vlSelf->cpu__DOT__zero;
}

VL_INLINE_OPT void Vcpu___024root___sequent__TOP__0(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__cpu__DOT__RegFile__DOT__rom_array__v0;
    IData/*31:0*/ __Vdlyvval__cpu__DOT__RegFile__DOT__rom_array__v0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__RegFile__DOT__rom_array__v0;
    IData/*19:0*/ __Vdlyvdim0__cpu__DOT__MemFile__DOT__ram_array__v0;
    IData/*31:0*/ __Vdlyvval__cpu__DOT__MemFile__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__MemFile__DOT__ram_array__v0;
    // Body
    __Vdlyvset__cpu__DOT__MemFile__DOT__ram_array__v0 = 0U;
    __Vdlyvset__cpu__DOT__RegFile__DOT__rom_array__v0 = 0U;
    if (vlSelf->cpu__DOT__MemWrite) {
        __Vdlyvval__cpu__DOT__MemFile__DOT__ram_array__v0 
            = vlSelf->cpu__DOT__RD2;
        __Vdlyvset__cpu__DOT__MemFile__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__cpu__DOT__MemFile__DOT__ram_array__v0 
            = vlSelf->cpu__DOT__MemFile__DOT__addr;
    }
    if (vlSelf->cpu__DOT__WEn) {
        __Vdlyvval__cpu__DOT__RegFile__DOT__rom_array__v0 
            = vlSelf->cpu__DOT__DOut;
        __Vdlyvset__cpu__DOT__RegFile__DOT__rom_array__v0 = 1U;
        __Vdlyvdim0__cpu__DOT__RegFile__DOT__rom_array__v0 
            = vlSelf->cpu__DOT__WA3;
    }
    if (__Vdlyvset__cpu__DOT__MemFile__DOT__ram_array__v0) {
        vlSelf->cpu__DOT__MemFile__DOT__ram_array[__Vdlyvdim0__cpu__DOT__MemFile__DOT__ram_array__v0] 
            = __Vdlyvval__cpu__DOT__MemFile__DOT__ram_array__v0;
    }
    if (__Vdlyvset__cpu__DOT__RegFile__DOT__rom_array__v0) {
        vlSelf->cpu__DOT__RegFile__DOT__rom_array[__Vdlyvdim0__cpu__DOT__RegFile__DOT__rom_array__v0] 
            = __Vdlyvval__cpu__DOT__RegFile__DOT__rom_array__v0;
    }
}

VL_INLINE_OPT void Vcpu___024root___sequent__TOP__1(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->cpu__DOT__PC_Next_Cycle = ((IData)(vlSelf->rst)
                                        ? 0U : (IData)(vlSelf->cpu__DOT__ProgramCounter__DOT__next_PC));
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
}

VL_INLINE_OPT void Vcpu___024root___combo__TOP__1(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___combo__TOP__1\n"); );
    // Body
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
    vlSelf->cpu__DOT__isJALR = (0x67U == (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode));
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
                if ((2U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                    if ((1U & (IData)(vlSelf->cpu__DOT__Decoder__DOT__opcode))) {
                        vlSelf->cpu__DOT__RA1 = vlSelf->cpu__DOT__Decoder__DOT__rs1;
                        vlSelf->cpu__DOT__RA2 = vlSelf->cpu__DOT__Decoder__DOT__rs2;
                        vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__rd;
                        vlSelf->cpu__DOT__WEn = 0U;
                        vlSelf->cpu__DOT__ALUsrc = 0U;
                        vlSelf->cpu__DOT__ALUctrl = 0U;
                        vlSelf->cpu__DOT__Resultsrc = 0U;
                        vlSelf->cpu__DOT__PCsrc = 1U;
                        vlSelf->cpu__DOT__ImmOp = vlSelf->cpu__DOT__Decoder__DOT__Imm;
                        vlSelf->cpu__DOT__ImmSel = 4U;
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
                vlSelf->cpu__DOT__ALUsrc = 1U;
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
                vlSelf->cpu__DOT__ALUctrl = vlSelf->cpu__DOT__Decoder__DOT__branchcode;
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
            vlSelf->cpu__DOT__WA3 = vlSelf->cpu__DOT__Decoder__DOT__rd;
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
    vlSelf->cpu__DOT__PC_Target = (0xffffU & (((IData)(vlSelf->cpu__DOT__isJALR)
                                                ? vlSelf->cpu__DOT__RD1
                                                : (IData)(vlSelf->cpu__DOT__PC_Next_Cycle)) 
                                              + vlSelf->cpu__DOT__ImmExt));
    vlSelf->cpu__DOT__ALU_OP2 = ((IData)(vlSelf->cpu__DOT__ALUsrc)
                                  ? vlSelf->cpu__DOT__ImmExt
                                  : vlSelf->cpu__DOT__RD2);
    vlSelf->PC_Target_Out = vlSelf->cpu__DOT__PC_Target;
    vlSelf->cpu__DOT__ProgramCounter__DOT__next_PC 
        = (0xffffU & ((IData)(vlSelf->cpu__DOT__PCsrc)
                       ? (IData)(vlSelf->cpu__DOT__PC_Target)
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
    vlSelf->cpu__DOT__MemFile__DOT__addr = (0xfffffU 
                                            & vlSelf->cpu__DOT__ALU_Result);
    vlSelf->cpu__DOT__Memory_Read = vlSelf->cpu__DOT__MemFile__DOT__ram_array
        [vlSelf->cpu__DOT__MemFile__DOT__addr];
    vlSelf->MemData_Out = vlSelf->cpu__DOT__Memory_Read;
    vlSelf->cpu__DOT__DOut = ((IData)(vlSelf->cpu__DOT__Resultsrc)
                               ? vlSelf->cpu__DOT__Memory_Read
                               : vlSelf->cpu__DOT__ALU_Result);
    vlSelf->Data_Out = vlSelf->cpu__DOT__DOut;
}

void Vcpu___024root___eval(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval\n"); );
    // Body
    Vcpu___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vcpu___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vcpu___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    Vcpu___024root___combo__TOP__1(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

QData Vcpu___024root___change_request_1(Vcpu___024root* vlSelf);

VL_INLINE_OPT QData Vcpu___024root___change_request(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___change_request\n"); );
    // Body
    return (Vcpu___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vcpu___024root___change_request_1(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSelf->cpu__DOT__zero ^ vlSelf->__Vchglast__TOP__cpu__DOT__zero));
    VL_DEBUG_IF( if(__req && ((vlSelf->cpu__DOT__zero ^ vlSelf->__Vchglast__TOP__cpu__DOT__zero))) VL_DBG_MSGF("        CHANGE: cpu.sv:71: cpu.zero\n"); );
    // Final
    vlSelf->__Vchglast__TOP__cpu__DOT__zero = vlSelf->cpu__DOT__zero;
    return __req;
}

#ifdef VL_DEBUG
void Vcpu___024root___eval_debug_assertions(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
