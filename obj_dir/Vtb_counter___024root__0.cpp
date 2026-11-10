// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter.h for the primary calling header

#include "Vtb_counter__pch.h"

VlCoroutine Vtb_counter___024root___eval_initial__TOP__Vtiming__0(Vtb_counter___024root* vlSelf);
VlCoroutine Vtb_counter___024root___eval_initial__TOP__Vtiming__1(Vtb_counter___024root* vlSelf);

void Vtb_counter___024root___eval_initial(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_initial\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_counter___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_counter___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vtb_counter___024root___eval_sample(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_sample\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_counter___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_counter___024root___eval_ico(Vtb_counter___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_ico\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_counter___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

void Vtb_counter___024root___timing_ready(Vtb_counter___024root* vlSelf);
void Vtb_counter___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_counter___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtb_counter___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vtb_counter___024root___timing_resume(Vtb_counter___024root* vlSelf);
void Vtb_counter___024root___eval_body__act(Vtb_counter___024root* vlSelf);

bool Vtb_counter___024root___eval_act(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_act\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        (((((((IData)(vlSelfRef.tb_counter__DOT__clk) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0))) 
                                                             << 3U) 
                                                            | (((~ (IData)(vlSelfRef.tb_counter__DOT__clk)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0)) 
                                                               << 2U)) 
                                                           | ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                               << 1U) 
                                                              | ((IData)(vlSelfRef.tb_counter__DOT__rst) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__rst__0)))) 
                                                          << 4U) 
                                                         | (((((IData)(vlSelfRef.tb_counter__DOT__en) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__en__0)) 
                                                              << 3U) 
                                                             | (((IData)(vlSelfRef.tb_counter__DOT__dut__DOT__count) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__dut__DOT__count__0)) 
                                                                << 2U)) 
                                                            | (((IData)(vlSelfRef.__Vtrigprevexpr_h292547da__0) 
                                                                << 1U) 
                                                               | ((IData)(vlSelfRef.tb_counter__DOT__clk) 
                                                                  ^ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0 
            = vlSelfRef.tb_counter__DOT__clk;
        vlSelfRef.__Vtrigprevexpr_h292547da__0 = 0U;
        vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__dut__DOT__count__0 
            = vlSelfRef.tb_counter__DOT__dut__DOT__count;
        vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__en__0 
            = vlSelfRef.tb_counter__DOT__en;
        vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__rst__0 
            = vlSelfRef.tb_counter__DOT__rst;
    }
    Vtb_counter___024root___timing_ready(vlSelf);
    Vtb_counter___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_counter___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_counter___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_counter___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_counter___024root___timing_resume(vlSelf);
        Vtb_counter___024root___eval_body__act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_counter___024root___eval_inact(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_inact\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb_counter.v", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_counter___024root___act_comb__TOP__1(Vtb_counter___024root* vlSelf);
void Vtb_counter___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vtb_counter___024root___eval_nba(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_nba\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_counter___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((0x000000000000001cULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    if (VL_UNLIKELY(((1U & (~ (IData)(vlSymsp->TOP____024unit.__VmonitorOff)))))) {
                        VL_WRITEF_NX("%0t reset: %1b enable: %1b count: %3d\n",5, 'T',-9
                                     , '#',64,VL_TIME_UNITED_Q(1000)
                                     , '#',1,(IData)(vlSelfRef.tb_counter__DOT__rst)
                                     , '#',1,vlSelfRef.tb_counter__DOT__en
                                     , '#',8,(IData)(vlSelfRef.tb_counter__DOT__dut__DOT__count));
                    }
                }
            }
            if ((0x00000000000000c0ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtb_counter___024root___act_comb__TOP__1(vlSelf);
            }
        }
        Vtb_counter___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vtb_counter___024root___eval_obs(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_obs\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtb_counter___024root___eval_react(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_react\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtb_counter___024root___eval_postponed(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_postponed\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VlCoroutine Vtb_counter___024root___eval_initial__TOP__Vtiming__0(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_counter__DOT__clk = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "tb_counter.v", 
                                             24);
        vlSelfRef.tb_counter__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_counter__DOT__clk)));
    }
    co_return;
}

void Vtb_counter___024root____VbeforeTrig_hb59c593a__0(Vtb_counter___024root* vlSelf, const char* __VeventDescription);
void Vtb_counter___024root____VbeforeTrig_hb59c6a85__0(Vtb_counter___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb_counter___024root___eval_initial__TOP__Vtiming__1(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_counter__DOT__unnamedblk1_1__DOT____Vrepeat0;
    tb_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile("post_layout_sim.vcd"s);
    vlSymsp->_traceDumpOpen();
    Vtb_counter___024root____VbeforeTrig_hb59c593a__0(vlSelf, 
                                                      "@(negedge tb_counter.clk)");
    co_await vlSelfRef.__VtrigSched_hb59c593a__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_counter.clk)", 
                                                         "tb_counter.v", 
                                                         43);
    vlSelfRef.tb_counter__DOT__rst = 0U;
    vlSelfRef.tb_counter__DOT__en = 1U;
    Vtb_counter___024root____VbeforeTrig_hb59c593a__0(vlSelf, 
                                                      "@(negedge tb_counter.clk)");
    co_await vlSelfRef.__VtrigSched_hb59c593a__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_counter.clk)", 
                                                         "tb_counter.v", 
                                                         47);
    vlSelfRef.tb_counter__DOT__rst = 1U;
    tb_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0x0000000aU;
    while (VL_LTS_III(32, 0U, tb_counter__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_counter___024root____VbeforeTrig_hb59c6a85__0(vlSelf, 
                                                          "@(posedge tb_counter.clk)");
        co_await vlSelfRef.__VtrigSched_hb59c6a85__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_counter.clk)", 
                                                             "tb_counter.v", 
                                                             50);
        tb_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (tb_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    VL_FINISH_MT("tb_counter.v", 52, "");
    co_return;
}

bool Vtb_counter___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___trigger_anySet__ico\n"); );
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

bool Vtb_counter___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___trigger_anySet__act\n"); );
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

void Vtb_counter___024root___act_comb__TOP__1(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___act_comb__TOP__1\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ tb_counter__DOT__dut__DOT___29___DOT__and0_out;
    tb_counter__DOT__dut__DOT___29___DOT__and0_out = 0;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___26___DOT__and0_out;
    tb_counter__DOT__dut__DOT___26___DOT__and0_out = 0;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___42___DOT__or0_out;
    tb_counter__DOT__dut__DOT___42___DOT__or0_out = 0;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___40___DOT__and0_out_X;
    tb_counter__DOT__dut__DOT___40___DOT__and0_out_X = 0;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___35___DOT__and0_out_X;
    tb_counter__DOT__dut__DOT___35___DOT__and0_out_X = 0;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y;
    tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y = 0;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___39___DOT__and0_out_X;
    tb_counter__DOT__dut__DOT___39___DOT__and0_out_X = 0;
    // Body
    tb_counter__DOT__dut__DOT___29___DOT__and0_out 
        = ((IData)(vlSelfRef.tb_counter__DOT__en) & (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___46___DOT__buf_Q));
    vlSelfRef.tb_counter__DOT__dut__DOT___29___DOT__nor0_out_Y 
        = (1U & (~ ((~ ((IData)(vlSelfRef.tb_counter__DOT__rst) 
                        & ((IData)(vlSelfRef.tb_counter__DOT__en) 
                           | (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___46___DOT__buf_Q)))) 
                    | (IData)(tb_counter__DOT__dut__DOT___29___DOT__and0_out))));
    tb_counter__DOT__dut__DOT___35___DOT__and0_out_X 
        = ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__buf_Q) 
           & (IData)(tb_counter__DOT__dut__DOT___29___DOT__and0_out));
    vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__D_delayed 
        = (1U & (~ ((~ (IData)(vlSelfRef.tb_counter__DOT__rst)) 
                    | ((~ ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__buf_Q) 
                           | (IData)(tb_counter__DOT__dut__DOT___29___DOT__and0_out))) 
                       | (IData)(tb_counter__DOT__dut__DOT___35___DOT__and0_out_X)))));
    tb_counter__DOT__dut__DOT___39___DOT__and0_out_X 
        = ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__buf_Q) 
           & (IData)(tb_counter__DOT__dut__DOT___35___DOT__and0_out_X));
    vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__D_delayed 
        = (1U & (~ ((~ ((IData)(vlSelfRef.tb_counter__DOT__rst) 
                        & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__buf_Q) 
                           | (IData)(tb_counter__DOT__dut__DOT___35___DOT__and0_out_X)))) 
                    | (IData)(tb_counter__DOT__dut__DOT___39___DOT__and0_out_X))));
    tb_counter__DOT__dut__DOT___26___DOT__and0_out 
        = ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q) 
           & (IData)(tb_counter__DOT__dut__DOT___39___DOT__and0_out_X));
    tb_counter__DOT__dut__DOT___40___DOT__and0_out_X 
        = ((IData)(tb_counter__DOT__dut__DOT___39___DOT__and0_out_X) 
           & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__buf_Q) 
              & (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q)));
    tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y 
        = (1U & (~ ((IData)(tb_counter__DOT__dut__DOT___39___DOT__and0_out_X) 
                    & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q) 
                       & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___51___DOT__buf_Q) 
                          & (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__buf_Q))))));
    vlSelfRef.tb_counter__DOT__dut__DOT___36___DOT__nor0_out_Y 
        = (1U & (~ ((~ ((IData)(vlSelfRef.tb_counter__DOT__rst) 
                        & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q) 
                           | (IData)(tb_counter__DOT__dut__DOT___39___DOT__and0_out_X)))) 
                    | (IData)(tb_counter__DOT__dut__DOT___26___DOT__and0_out))));
    vlSelfRef.tb_counter__DOT__dut__DOT___31___DOT__nor0_out_Y 
        = (1U & (~ ((~ ((IData)(vlSelfRef.tb_counter__DOT__rst) 
                        & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___51___DOT__buf_Q) 
                           | (IData)(tb_counter__DOT__dut__DOT___40___DOT__and0_out_X)))) 
                    | ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___51___DOT__buf_Q) 
                       & (IData)(tb_counter__DOT__dut__DOT___40___DOT__and0_out_X)))));
    vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__D_delayed 
        = (1U & (~ ((~ (IData)(vlSelfRef.tb_counter__DOT__rst)) 
                    | ((~ ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__buf_Q) 
                           | (IData)(tb_counter__DOT__dut__DOT___26___DOT__and0_out))) 
                       | (IData)(tb_counter__DOT__dut__DOT___40___DOT__and0_out_X)))));
    tb_counter__DOT__dut__DOT___42___DOT__or0_out = 
        (1U & ((IData)(tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y) 
               | (~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___52___DOT__buf_Q))));
    vlSelfRef.tb_counter__DOT__dut__DOT___25___DOT__nor0_out_Y 
        = (1U & (~ ((~ ((IData)(vlSelfRef.tb_counter__DOT__rst) 
                        & (IData)(tb_counter__DOT__dut__DOT___42___DOT__or0_out))) 
                    | ((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___52___DOT__buf_Q)) 
                       & (IData)(tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y)))));
    vlSelfRef.tb_counter__DOT__dut__DOT___44___DOT__nor0_out_Y 
        = (1U & (~ ((~ (IData)(vlSelfRef.tb_counter__DOT__rst)) 
                    | ((~ ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___53___DOT__buf_Q) 
                           & (IData)(tb_counter__DOT__dut__DOT___42___DOT__or0_out))) 
                       & ((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___53___DOT__buf_Q) 
                          | ((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___52___DOT__buf_Q)) 
                             | (IData)(tb_counter__DOT__dut__DOT___41___DOT__nand0_out_Y)))))));
}

void Vtb_counter___024root___eval_body__act(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_body__act\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        {
            // Inlined CFunc: _act_sequent__TOP__0
            vlSelfRef.tb_counter__DOT__dut__DOT___53___DOT__buf_Q = 0U;
            vlSelfRef.tb_counter__DOT__dut__DOT___52___DOT__buf_Q = 0U;
            vlSelfRef.tb_counter__DOT__dut__DOT___51___DOT__buf_Q = 0U;
            vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__buf_Q = 0U;
            vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q = 0U;
            vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__buf_Q = 0U;
            vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__buf_Q = 0U;
            vlSelfRef.tb_counter__DOT__dut__DOT___46___DOT__buf_Q = 0U;
        }
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        {
            // Inlined CFunc: _act_sequent__TOP__1
            if (((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___44___DOT__nor0_out_Y) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___53___DOT__buf_Q = 1U;
            }
            if (((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___44___DOT__nor0_out_Y)) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___53___DOT__buf_Q = 0U;
            }
            if (((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___25___DOT__nor0_out_Y) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___52___DOT__buf_Q = 1U;
            }
            if (((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___25___DOT__nor0_out_Y)) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___52___DOT__buf_Q = 0U;
            }
            if (((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___31___DOT__nor0_out_Y) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___51___DOT__buf_Q = 1U;
            }
            if (((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___31___DOT__nor0_out_Y)) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___51___DOT__buf_Q = 0U;
            }
            if (((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__D_delayed) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__buf_Q = 1U;
            }
            if (((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__D_delayed)) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___50___DOT__buf_Q = 0U;
            }
            if (((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___36___DOT__nor0_out_Y) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q = 1U;
            }
            if (((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___36___DOT__nor0_out_Y)) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___49___DOT__buf_Q = 0U;
            }
            if (((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__D_delayed) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__buf_Q = 1U;
            }
            if (((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__D_delayed)) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___48___DOT__buf_Q = 0U;
            }
            if (((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__D_delayed) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__buf_Q = 1U;
            }
            if (((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__D_delayed)) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___47___DOT__buf_Q = 0U;
            }
            if (((IData)(vlSelfRef.tb_counter__DOT__dut__DOT___29___DOT__nor0_out_Y) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___46___DOT__buf_Q = 1U;
            }
            if (((~ (IData)(vlSelfRef.tb_counter__DOT__dut__DOT___29___DOT__nor0_out_Y)) 
                 & (IData)(vlSelfRef.tb_counter__DOT__clk))) {
                vlSelfRef.tb_counter__DOT__dut__DOT___46___DOT__buf_Q = 0U;
            }
        }
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VactTriggered[0U])) {
        {
            // Inlined CFunc: _act_comb__TOP__0
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
        }
    }
    if ((0x00000000000000c3ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_counter___024root___act_comb__TOP__1(vlSelf);
    }
}

void Vtb_counter___024root___timing_ready(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___timing_ready\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000000000040ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hb59c593a__0.ready("@(negedge tb_counter.clk)");
    }
    if ((0x0000000000000080ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_hb59c6a85__0.ready("@(posedge tb_counter.clk)");
    }
}

void Vtb_counter___024root___timing_resume(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___timing_resume\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_hb59c593a__0.moveToResumeQueue(
                                                          "@(negedge tb_counter.clk)");
    vlSelfRef.__VtrigSched_hb59c6a85__0.moveToResumeQueue(
                                                          "@(posedge tb_counter.clk)");
    vlSelfRef.__VtrigSched_hb59c593a__0.resume("@(negedge tb_counter.clk)");
    vlSelfRef.__VtrigSched_hb59c6a85__0.resume("@(posedge tb_counter.clk)");
    if ((0x0000000000000020ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_counter___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vtb_counter___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

void Vtb_counter___024root____VbeforeTrig_hb59c593a__0(Vtb_counter___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root____VbeforeTrig_hb59c593a__0\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((IData)(vlSelfRef.tb_counter__DOT__clk) 
                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0))) 
                                   << 7U) | (((~ (IData)(vlSelfRef.tb_counter__DOT__clk)) 
                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0)) 
                                             << 6U))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0 
        = vlSelfRef.tb_counter__DOT__clk;
    if ((0x0000000000000040ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hb59c593a__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb59c593a__0.ready(__VeventDescription);
    }
    if ((0x0000000000000080ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hb59c6a85__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vtb_counter___024root____VbeforeTrig_hb59c6a85__0(Vtb_counter___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root____VbeforeTrig_hb59c6a85__0\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((IData)(vlSelfRef.tb_counter__DOT__clk) 
                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0))) 
                                   << 7U) | (((~ (IData)(vlSelfRef.tb_counter__DOT__clk)) 
                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0)) 
                                             << 6U))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_counter__DOT__clk__0 
        = vlSelfRef.tb_counter__DOT__clk;
    if ((0x0000000000000040ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hb59c593a__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_hb59c593a__0.ready(__VeventDescription);
    }
    if ((0x0000000000000080ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_hb59c6a85__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb_counter___024root___eval_debug_assertions(Vtb_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_counter___024root___eval_debug_assertions\n"); );
    Vtb_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
