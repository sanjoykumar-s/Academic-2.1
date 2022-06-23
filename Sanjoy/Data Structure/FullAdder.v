module FullAdder(s,cout,a,b,cin);
	input a,b,cin;
	output s,cout;
	wire c1,c2,s1;
	HalfAddder ha1(s1,c1,a,b);
	HalfAddder ha2(s1,c2,s1,cin);
	or(cout,c1,c2);
endmodule
