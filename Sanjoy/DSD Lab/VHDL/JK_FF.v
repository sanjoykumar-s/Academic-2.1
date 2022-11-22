module JK_FF(q,qbar,J,K,clr,clk);

input J,K,clr,clk;
output q,qbar;
wire a,b,c,d,y,ybar,clkbar;

not (clkbar,clk);
nand (a,J,clk,clr,qbar);
nand (b,K,clk,q);
nand (y,a,ybar);
nand (ybar,b,y,clr);
nand (c,y,clkbar);
nand (d,clkbar,ybar);
nand (q,c,qbar);
nand (qbar,d,clr,q);

endmodule
