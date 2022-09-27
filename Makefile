symbol_res.out: symbol_res.cc
	g++ symbol_res.cc -o symbol_res.out

clean:
	rm *.out