CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O0 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11


program.exe: program.o Hospital.o Doctor.o Pacient.o Visita.o Data.o
	$(LINK.cc) -o $@ $^
	
program.o: program.cpp Hospital.hpp Doctor.hpp Pacient.hpp Visita.hpp Data.hpp BST.hpp PriorityQueue.hpp

Hospital.o: Hospital.cpp Hospital.hpp Doctor.hpp Pacient.hpp Visita.hpp BST.hpp PriorityQueue.hpp

Doctor.o: Doctor.cpp Doctor.hpp Visita.hpp

Pacient.o: Pacient.cpp Pacient.hpp

Visita.o: Visita.cpp Visita.hpp Data.hpp Pacient.hpp

Data.o: Data.cpp Data.hpp


.PHONY: clean
clean:
	rm -vf program.o Hospital.o Doctor.o Pacient.o Visita.o Data.o BST.o PriorityQueue.o program.exe

.PHONY: test
test1: 
	./program.exe < sample1.inp | diff - sample1.cor
	
test:
#	Descomenteu les següents línies si voleu executar tots
#	els jocs de proves.
# 	./program.exe < sample1.inp | diff - sample1.cor 
# 	./program.exe < sample2.inp | diff - sample2.cor
# 	./program.exe < sample3.inp | diff - sample3.cor