
module UpDown_Counter(q,M,clk,clr);

output [2:0]q;
input M,clk,clr;
wire [2:0]qbar;

assign J1 = 1'b1;
assign K1 = J1;
JK_FF JK1(q[0],qbar[0],J1,K1,clr,clk);
xor (J2,M,q[0]);
assign K2 = J2;
JK_FF JK2(q[1],qbar[1],J2,K2,clr,clk);
and (c,M,qbar[0],qbar[1]);
not (Mbar,M);
and (d,Mbar,q[0],q[1]);
or (J3,c,d);
assign K3=J3;
JK_FF JK3(q[2],qbar[2],J3,K3,clr,clk);

endmodule