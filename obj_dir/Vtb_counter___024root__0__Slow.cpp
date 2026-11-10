// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter.h for the primary calling header

#include "Vtb_counter__pch.h"

void Vtb_counter___024root___timing_ready(Vtb_counter___024root* vlSelf);

VL_ATTR_COLD void Vtb_counter___024root___eval_static(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_static\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (4ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (8ULL | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__VactTriggered[0U] = (0x0000000000000010ULL 
                                     | vlSelfRef.__VactTriggered[0U]);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0 
        = vlSelfRef.tb_counter__DOT__clk;
    vlSelfRef.__Vtrigprevexpr_h292547da__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__dut__DOT__count__0 
        = vlSelfRef.tb_counter__DOT__dut__DOT__count;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__en__0 
        = vlSelfRef.tb_counter__DOT__en;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__rst__0 
        = vlSelfRef.tb_counter__DOT__rst;
    Vtb_counter___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_counter___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_counter___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vtb_counter___024root___eval_body__stl(Vtb_counter___024root* vlSelf);

VL_ATTR_COLD bool Vtb_counter___024root___eval_stl(Vtb_counter___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_stl\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_counter___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_counter___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_counter___024root___eval_body__stl(vlSelf);
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vtb_counter___024root___eval_dump_triggers__stl(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_dump_triggers__stl\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_counter___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_counter___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_counter___024root___eval_dump_triggers__ico(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_dump_triggers__ico\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_counter___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_counter___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_counter___024root___eval_dump_triggers__act(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_dump_triggers__act\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_counter___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vtb_counter___024root___eval_dump_triggers__nba(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_dump_triggers__nba\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtb_counter___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vtb_counter___024root___eval_dump_triggers__obs(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_dump_triggers__obs\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_counter___024root___eval_dump_triggers__react(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_dump_triggers__react\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_counter___024root___eval_final(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_final\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_counter___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_counter___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_counter___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vtb_counter___024root___eval_body__stl(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_body__stl\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        {
            // Inlined CFunc: _stl_sequent__TOP__0
            CData/*0:0*/ __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___29___DOT__and0_out;
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___29___DOT__and0_out = 0;
            CData/*0:0*/ __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___26___DOT__and0_out;
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___26___DOT__and0_out = 0;
            CData/*0:0*/ __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___42___DOT__or0_out;
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___42___DOT__or0_out = 0;
            CData/*0:0*/ __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___40___DOT__and0_out_X;
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___40___DOT__and0_out_X = 0;
            CData/*0:0*/ __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___35___DOT__and0_out_X;
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___35___DOT__and0_out_X = 0;
            CData/*0:0*/ __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y;
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y = 0;
            CData/*0:0*/ __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___39___DOT__and0_out_X;
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___39___DOT__and0_out_X = 0;
            vlSelfRef.tb_counter__DOT__dut__DOT__count 
                = ((((((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___53___DOT__buf_Q) 
                       << 3U) | ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___52___DOT__buf_Q) 
                                 << 2U)) | (((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___51___DOT__buf_Q) 
                                             << 1U) 
                                            | (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__buf_Q))) 
                    << 4U) | ((((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q) 
                                << 3U) | ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__buf_Q) 
                                          << 2U)) | 
                              (((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__buf_Q) 
                                << 1U) | (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___46___DOT__buf_Q))));
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___29___DOT__and0_out 
                = ((IData)(vlSelfRef.tb_counter__DOT__en) 
                   & (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___46___DOT__buf_Q));
            vlSelfRef.tb_counter__DOT__dut__DOT___29___DOT__nor0_out_Y 
                = (1U & (~ ((~ ((IData)(vlSelfRef.tb_counter__DOT__rst) 
                                & ((IData)(vlSelfRef.tb_counter__DOT__en) 
                                   | (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___46___DOT__buf_Q)))) 
                            | __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___29___DOT__and0_out)));
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___35___DOT__and0_out_X 
                = ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__buf_Q) 
                   & __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___29___DOT__and0_out);
            vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__D_delayed 
                = (1U & (~ ((~ (IData)(vlSelfRef.tb_counter__DOT__rst)) 
                            | ((~ ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__buf_Q) 
                                   | __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___29___DOT__and0_out)) 
                               | __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___35___DOT__and0_out_X))));
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___39___DOT__and0_out_X 
                = ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__buf_Q) 
                   & __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___35___DOT__and0_out_X);
            vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__D_delayed 
                = (1U & (~ ((~ ((IData)(vlSelfRef.tb_counter__DOT__rst) 
                                & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__buf_Q) 
                                   | __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___35___DOT__and0_out_X))) 
                            | __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___39___DOT__and0_out_X)));
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___26___DOT__and0_out 
                = ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q) 
                   & __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___39___DOT__and0_out_X);
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___40___DOT__and0_out_X 
                = (__Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___39___DOT__and0_out_X 
                   & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__buf_Q) 
                      & (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q)));
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y 
                = (1U & (~ (__Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___39___DOT__and0_out_X 
                            & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q) 
                               & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___51___DOT__buf_Q) 
                                  & (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__buf_Q))))));
            vlSelfRef.tb_counter__DOT__dut__DOT___36___DOT__nor0_out_Y 
                = (1U & (~ ((~ ((IData)(vlSelfRef.tb_counter__DOT__rst) 
                                & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q) 
                                   | __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___39___DOT__and0_out_X))) 
                            | __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___26___DOT__and0_out)));
            vlSelfRef.tb_counter__DOT__dut__DOT___31___DOT__nor0_out_Y 
                = (1U & (~ ((~ ((IData)(vlSelfRef.tb_counter__DOT__rst) 
                                & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___51___DOT__buf_Q) 
                                   | __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___40___DOT__and0_out_X))) 
                            | ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___51___DOT__buf_Q) 
                               & __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___40___DOT__and0_out_X))));
            vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__D_delayed 
                = (1U & (~ ((~ (IData)(vlSelfRef.tb_counter__DOT__rst)) 
                            | ((~ ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__buf_Q) 
                                   | __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___26___DOT__and0_out)) 
                               | __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___40___DOT__and0_out_X))));
            __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___42___DOT__or0_out 
                = (1U & (__Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y 
                         | (~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___52___DOT__buf_Q))));
            vlSelfRef.tb_counter__DOT__dut__DOT___25___DOT__nor0_out_Y 
                = (1U & (~ ((~ ((IData)(vlSelfRef.tb_counter__DOT__rst) 
                                & __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___42___DOT__or0_out)) 
                            | ((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___52___DOT__buf_Q)) 
                               & __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y))));
            vlSelfRef.tb_counter__DOT__dut__DOT___44___DOT__nor0_out_Y 
                = (1U & (~ ((~ (IData)(vlSelfRef.tb_counter__DOT__rst)) 
                            | ((~ ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___53___DOT__buf_Q) 
                                   & __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___42___DOT__or0_out)) 
                               & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___53___DOT__buf_Q) 
                                  | ((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___52___DOT__buf_Q)) 
                                     | __Vinline_0__stl_sequent__TOP__0_tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y))))));
        }
    }
}

bool Vtb_counter___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_counter___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_counter___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtb_counter___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_counter___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_counter___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(edge tb_counter.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(edge 1'h0)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( tb_counter.dut.count)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( tb_counter.en)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @( tb_counter.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(negedge tb_counter.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(posedge tb_counter.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_counter___024root___ctor_var_reset(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___ctor_var_reset\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_counter__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9420731110383679103ull);
    vlSelf->tb_counter__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15285361603058899672ull);
    vlSelf->tb_counter__DOT__en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11687070073348605764ull);
    vlSelf->tb_counter__DOT__dut__DOT__count = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13910424255298589887ull);
    vlSelf->tb_counter__DOT__dut__DOT___53___DOT__buf_Q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11433780877575894006ull);
    vlSelf->tb_counter__DOT__dut__DOT___52___DOT__buf_Q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3619384211908453974ull);
    vlSelf->tb_counter__DOT__dut__DOT___51___DOT__buf_Q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5947366923198670351ull);
    vlSelf->tb_counter__DOT__dut__DOT___50___DOT__buf_Q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16429933601546486676ull);
    vlSelf->tb_counter__DOT__dut__DOT___50___DOT__D_delayed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15722381570905269832ull);
    vlSelf->tb_counter__DOT__dut__DOT___49___DOT__buf_Q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1520955770436815949ull);
    vlSelf->tb_counter__DOT__dut__DOT___48___DOT__buf_Q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13712462051734914005ull);
    vlSelf->tb_counter__DOT__dut__DOT___48___DOT__D_delayed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14557524687459293713ull);
    vlSelf->tb_counter__DOT__dut__DOT___47___DOT__buf_Q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10119091993879162967ull);
    vlSelf->tb_counter__DOT__dut__DOT___47___DOT__D_delayed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1134694624267903145ull);
    vlSelf->tb_counter__DOT__dut__DOT___46___DOT__buf_Q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18032343505896597068ull);
    vlSelf->tb_counter__DOT__dut__DOT___44___DOT__nor0_out_Y = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5988367854418425551ull);
    vlSelf->tb_counter__DOT__dut__DOT___36___DOT__nor0_out_Y = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6188079007175689868ull);
    vlSelf->tb_counter__DOT__dut__DOT___31___DOT__nor0_out_Y = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15231573329961092086ull);
    vlSelf->tb_counter__DOT__dut__DOT___29___DOT__nor0_out_Y = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 98151452786195017ull);
    vlSelf->tb_counter__DOT__dut__DOT___25___DOT__nor0_out_Y = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12575712712584176919ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr_h292547da__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_counter__DOT__dut__DOT__count__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_counter__DOT__en__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_counter__DOT__rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
