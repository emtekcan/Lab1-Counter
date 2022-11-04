// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter.h for the primary calling header

#include "verilated.h"

#include "Vcounter___024root.h"

VL_INLINE_OPT void Vcounter___024root___sequent__TOP__0(Vcounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__count;
    IData/*31:0*/ __Vdly__counter__DOT__stopcounter;
    // Body
    __Vdly__count = vlSelf->count;
    __Vdly__counter__DOT__stopcounter = vlSelf->counter__DOT__stopcounter;
    if (vlSelf->rst) {
        __Vdly__count = 0U;
        __Vdly__counter__DOT__stopcounter = 0U;
    } else if (VL_LTS_III(32, 0U, vlSelf->counter__DOT__stopcounter)) {
        __Vdly__counter__DOT__stopcounter = (vlSelf->counter__DOT__stopcounter 
                                             - (IData)(1U));
    } else if ((9U == (IData)(vlSelf->count))) {
        __Vdly__counter__DOT__stopcounter = 2U;
        __Vdly__count = 0U;
    } else {
        __Vdly__count = (0xffU & ((IData)(vlSelf->count) 
                                  + (IData)(vlSelf->en)));
    }
    vlSelf->count = __Vdly__count;
    vlSelf->counter__DOT__stopcounter = __Vdly__counter__DOT__stopcounter;
}

void Vcounter___024root___eval(Vcounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vcounter___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vcounter___024root___eval_debug_assertions(Vcounter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
