// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_counter.h for the primary calling header

#include "Vtb_counter__pch.h"

void Vtb_counter___024unit___ctor_var_reset(Vtb_counter___024unit* vlSelf);

Vtb_counter___024unit::Vtb_counter___024unit() = default;
Vtb_counter___024unit::~Vtb_counter___024unit() = default;

void Vtb_counter___024unit::ctor(Vtb_counter__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtb_counter___024unit___ctor_var_reset(this);
}

void Vtb_counter___024unit::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
