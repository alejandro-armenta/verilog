module counter (clk,
    en,
    rst,
    count);
 input clk;
 input en;
 input rst;
 output [7:0] count;

 wire _00_;
 wire _01_;
 wire _02_;
 wire _03_;
 wire _04_;
 wire _05_;
 wire _06_;
 wire _07_;
 wire _08_;
 wire _09_;
 wire _10_;
 wire _11_;
 wire _12_;
 wire _13_;
 wire _14_;
 wire _15_;
 wire _16_;
 wire _17_;
 wire _18_;
 wire _19_;
 wire _20_;
 wire _21_;
 wire _22_;
 wire net3;
 wire net4;
 wire net5;
 wire net6;
 wire net7;
 wire net8;
 wire net9;
 wire net10;
 wire net1;
 wire net2;
 wire clknet_0_clk;
 wire clknet_1_0__leaf_clk;
 wire clknet_1_1__leaf_clk;

 sky130_fd_sc_hd__clkinv_1 _23_ (.A(net2),
    .Y(_08_));
 sky130_fd_sc_hd__clkinv_1 _24_ (.A(net9),
    .Y(_09_));
 sky130_fd_sc_hd__a21oi_1 _25_ (.A1(_09_),
    .A2(_13_),
    .B1(_16_),
    .Y(_06_));
 sky130_fd_sc_hd__a21oi_1 _26_ (.A1(net6),
    .A2(_11_),
    .B1(net7),
    .Y(_17_));
 sky130_fd_sc_hd__nor3_1 _27_ (.A(_08_),
    .B(_12_),
    .C(_17_),
    .Y(_05_));
 sky130_fd_sc_hd__o21ai_0 _28_ (.A1(net3),
    .A2(net1),
    .B1(net2),
    .Y(_18_));
 sky130_fd_sc_hd__a21oi_1 _29_ (.A1(net3),
    .A2(net1),
    .B1(_18_),
    .Y(_04_));
 sky130_fd_sc_hd__o21ai_0 _30_ (.A1(net8),
    .A2(_12_),
    .B1(net2),
    .Y(_19_));
 sky130_fd_sc_hd__a21oi_1 _31_ (.A1(net8),
    .A2(_12_),
    .B1(_19_),
    .Y(_03_));
 sky130_fd_sc_hd__a21oi_1 _32_ (.A1(net3),
    .A2(net1),
    .B1(net4),
    .Y(_20_));
 sky130_fd_sc_hd__nor3_1 _33_ (.A(_08_),
    .B(_10_),
    .C(_20_),
    .Y(_02_));
 sky130_fd_sc_hd__o21ai_0 _34_ (.A1(net6),
    .A2(_11_),
    .B1(net2),
    .Y(_21_));
 sky130_fd_sc_hd__and3_1 _35_ (.A(net3),
    .B(net4),
    .C(net1),
    .X(_10_));
 sky130_fd_sc_hd__a21oi_1 _36_ (.A1(net6),
    .A2(_11_),
    .B1(_21_),
    .Y(_01_));
 sky130_fd_sc_hd__o21ai_0 _37_ (.A1(net5),
    .A2(_10_),
    .B1(net2),
    .Y(_22_));
 sky130_fd_sc_hd__nor2_1 _38_ (.A(_11_),
    .B(_22_),
    .Y(_00_));
 sky130_fd_sc_hd__and4_1 _39_ (.A(net5),
    .B(net3),
    .C(net4),
    .D(net1),
    .X(_11_));
 sky130_fd_sc_hd__and3_1 _40_ (.A(net7),
    .B(net6),
    .C(_11_),
    .X(_12_));
 sky130_fd_sc_hd__nand4_1 _41_ (.A(net8),
    .B(net7),
    .C(net6),
    .D(_11_),
    .Y(_13_));
 sky130_fd_sc_hd__o21ai_0 _42_ (.A1(_09_),
    .A2(_13_),
    .B1(net10),
    .Y(_14_));
 sky130_fd_sc_hd__or3_1 _43_ (.A(_09_),
    .B(net10),
    .C(_13_),
    .X(_15_));
 sky130_fd_sc_hd__a21oi_1 _44_ (.A1(_14_),
    .A2(_15_),
    .B1(_08_),
    .Y(_07_));
 sky130_fd_sc_hd__o21ai_0 _45_ (.A1(_09_),
    .A2(_13_),
    .B1(net2),
    .Y(_16_));
 sky130_fd_sc_hd__dfxtp_1 _46_ (.CLK(clknet_1_1__leaf_clk),
    .D(_04_),
    .Q(net3));
 sky130_fd_sc_hd__dfxtp_1 _47_ (.CLK(clknet_1_1__leaf_clk),
    .D(_02_),
    .Q(net4));
 sky130_fd_sc_hd__dfxtp_1 _48_ (.CLK(clknet_1_1__leaf_clk),
    .D(_00_),
    .Q(net5));
 sky130_fd_sc_hd__dfxtp_1 _49_ (.CLK(clknet_1_1__leaf_clk),
    .D(_01_),
    .Q(net6));
 sky130_fd_sc_hd__dfxtp_1 _50_ (.CLK(clknet_1_0__leaf_clk),
    .D(_05_),
    .Q(net7));
 sky130_fd_sc_hd__dfxtp_1 _51_ (.CLK(clknet_1_0__leaf_clk),
    .D(_03_),
    .Q(net8));
 sky130_fd_sc_hd__dfxtp_1 _52_ (.CLK(clknet_1_0__leaf_clk),
    .D(_06_),
    .Q(net9));
 sky130_fd_sc_hd__dfxtp_1 _53_ (.CLK(clknet_1_0__leaf_clk),
    .D(_07_),
    .Q(net10));
 sky130_fd_sc_hd__clkbuf_4 clkbuf_0_clk (.A(clk),
    .X(clknet_0_clk));
 sky130_fd_sc_hd__clkbuf_4 clkbuf_1_0__f_clk (.A(clknet_0_clk),
    .X(clknet_1_0__leaf_clk));
 sky130_fd_sc_hd__clkbuf_4 clkbuf_1_1__f_clk (.A(clknet_0_clk),
    .X(clknet_1_1__leaf_clk));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input1 (.A(en),
    .X(net1));
 sky130_fd_sc_hd__clkdlybuf4s50_1 input2 (.A(rst),
    .X(net2));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output10 (.A(net10),
    .X(count[7]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output3 (.A(net3),
    .X(count[0]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output4 (.A(net4),
    .X(count[1]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output5 (.A(net5),
    .X(count[2]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output6 (.A(net6),
    .X(count[3]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output7 (.A(net7),
    .X(count[4]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output8 (.A(net8),
    .X(count[5]));
 sky130_fd_sc_hd__clkdlybuf4s50_1 output9 (.A(net9),
    .X(count[6]));
endmodule
