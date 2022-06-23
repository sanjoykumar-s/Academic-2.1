module HalfAdder(s,c,a,b);
		input a, b;
	        output s,c;
	xor xrl(s,a,b);
	and carry(c,a,b);
endmodule