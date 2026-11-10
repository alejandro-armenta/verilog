// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_counter.h for the primary calling header

#ifndef VERILATED_VTB_COUNTER___024ROOT_H_
#define VERILATED_VTB_COUNTER___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtb_counter___024unit;


class Vtb_counter__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_counter___024root final {
  public:
    // CELLS
    Vtb_counter___024unit* __PVT____024unit;

    // DESIGN-SPECIFIC STATE
    CData/*0:0*/ tb_counter__DOT__clk;
    CData/*0:0*/ tb_counter__DOT__rst;
    CData/*0:0*/ tb_counter__DOT__en;
    CData/*7:0*/ tb_counter__DOT__dut__DOT__count;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___53___DOT__buf_Q;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___52___DOT__buf_Q;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___51___DOT__buf_Q;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___50___DOT__buf_Q;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___50___DOT__D_delayed;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___49___DOT__buf_Q;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___48___DOT__buf_Q;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___48___DOT__D_delayed;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___47___DOT__buf_Q;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___47___DOT__D_delayed;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___46___DOT__buf_Q;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___44___DOT__nor0_out_Y;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___36___DOT__nor0_out_Y;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___31___DOT__nor0_out_Y;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___29___DOT__nor0_out_Y;
    CData/*0:0*/ tb_counter__DOT__dut__DOT___25___DOT__nor0_out_Y;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_counter__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr_h292547da__0;
    CData/*7:0*/ __Vtrigprevexpr___TOP__tb_counter__DOT__dut__DOT__count__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_counter__DOT__en__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_counter__DOT__rst__0;
    IData/*31:0*/ __Vi;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hb59c593a__0;
    VlTriggerScheduler __VtrigSched_hb59c6a85__0;

    // INTERNAL VARIABLES
    Vtb_counter__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_counter___024root(Vtb_counter__Syms* symsp, const char* namep);
    ~Vtb_counter___024root();
    VL_UNCOPYABLE(Vtb_counter___024root);

    // INTERNAL METHODS
};


#endif  // guard
