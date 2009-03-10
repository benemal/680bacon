bacon : bacontree.o Movie.o movieProcessor.o parser_nix.o baconmain.cpp
	g++ -o bacon baconmain.cpp bacontree.o Movie.o movieProcessor.o parser_nix.o

bacontree.o : p3.h
	g++ -c bacontree.cpp

Movie.o : p3.h
	g++ -c Movie.cpp

movieProcessor.o : p3.h
	g++ -c movieProcessor.cpp

parser_nix.o : p3.h
	g++ -c parser_nix.cpp

clean :
	-rm bacontree.o Movie.o movieProcessor.o parser_nix.o bacon
