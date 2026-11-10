// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_counter__Syms.h"


void Vtb_counter___024root__trace_chg_0_sub_0(Vtb_counter___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_counter___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root__trace_chg_0\n"); );
    // Body
    Vtb_counter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_counter___024root*>(voidSelf);
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_counter___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_counter___024root__trace_chg_0_sub_0(Vtb_counter___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root__trace_chg_0_sub_0\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.tb_counter__DOT__dut__DOT___46___DOT__buf_Q));
        bufp->chgBit(oldp+1,(vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__buf_Q));
        bufp->chgBit(oldp+2,(vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__buf_Q));
        bufp->chgBit(oldp+3,(vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q));
        bufp->chgBit(oldp+4,(vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__buf_Q));
        bufp->chgBit(oldp+5,(vlSelfRef.tb_counter__DOT__dut__DOT___51___DOT__buf_Q));
        bufp->chgBit(oldp+6,(vlSelfRef.tb_counter__DOT__dut__DOT___52___DOT__buf_Q));
        bufp->chgBit(oldp+7,(vlSelfRef.tb_counter__DOT__dut__DOT___53___DOT__buf_Q));
    }
    bufp->chgBit(oldp+8,(vlSelfRef.tb_counter__DOT__clk));
    bufp->chgBit(oldp+9,(vlSelfRef.tb_counter__DOT__rst));
    bufp->chgBit(oldp+10,(vlSelfRef.tb_counter__DOT__en));
    bufp->chgCData(oldp+11,(vlSelfRef.tb_counter__DOT__dut__DOT__count),8);
}

void Vtb_counter___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root__trace_cleanup\n"); );
    // Body
    Vtb_counter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_counter___024root*>(voidSelf);
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
