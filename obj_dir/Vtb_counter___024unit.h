// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_counter.h for the primary calling header

#ifndef VERILATED_VTB_COUNTER___024UNIT_H_
#define VERILATED_VTB_COUNTER___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_counter__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_counter___024unit final {
  public:

    // DESIGN-SPECIFIC STATE
    CData/*0:0*/ __VmonitorOff;

    // INTERNAL VARIABLES
    Vtb_counter__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_counter___024unit();
    ~Vtb_counter___024unit();
    void ctor(Vtb_counter__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtb_counter___024unit);

    // INTERNAL METHODS
};


#endif  // guard
