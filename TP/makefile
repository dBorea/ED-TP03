CXX = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
TEMP = ../TEMP
REGMEM = $(TEMP)/regmem
REGPERF = $(TEMP)/regperf

OBJS = $(OBJ)/memlog.o $(OBJ)/mailingSistem.o $(OBJ)/Hash.o $(OBJ)/AVL.o
HDRS = $(INC)/msgassert.hpp $(INC)/memlog.hpp $(INC)/MsgContainer.hpp $(INC)/TreeNode.hpp $(INC)/AVL.hpp $(INC)/Hash.hpp

SANITIZE = -fsanitize=undefined,address -static-libasan
LDFLAGS =  -pg -O3
CXXFLAGS = -Wall -c -I$(INC) $(LDFLAGS) 

CMP = make -C $(TEMP) compare -s
ANALISAMEM = ../analisamem/bin/analisamem
EXE = $(BIN)/tp3.exe

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(EXE) $(OBJS)

$(OBJ)/mailingSistem.o: $(HDRS) $(SRC)/mailingSistem.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/mailingSistem.o $(SRC)/mailingSistem.cpp 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp

$(OBJ)/Hash.o: $(HDRS) $(SRC)/Hash.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/Hash.o $(SRC)/Hash.cpp

$(OBJ)/AVL.o: $(HDRS) $(SRC)/AVL.cpp
	$(CXX) $(CXXFLAGS) -o $(OBJ)/AVL.o $(SRC)/AVL.cpp

execute: $(EXE)
	$(EXE) -i $(TEMP)/entradas/entrada_1.txt -o $(TEMP)/saidas/minha_saida_1.txt
	$(EXE) -i $(TEMP)/entradas/entrada_2.txt -o $(TEMP)/saidas/minha_saida_2.txt
	$(EXE) -i $(TEMP)/entradas/entrada_3.txt -o $(TEMP)/saidas/minha_saida_3.txt
	$(EXE) -i $(TEMP)/entradas/entrada_4.txt -o $(TEMP)/saidas/minha_saida_4.txt
	$(CMP)

mem: $(EXE)
	rm -f $(REGMEM)/mail_log.out dataSorterText.out
	$(EXE) -p $(REGMEM)/mail_log.out -l -i $(TEMP)/entradas/entrada_regmem.txt -o $(TEMP)/saidas/saida_regmem.txt
	$(ANALISAMEM) -i $(REGMEM)/mail_log.out -p $(REGMEM)/mail_regmem
	gnuplot $(REGMEM)/*.gp

gprof: $(EXE)
	$(EXE) -i $(TEMP)/entradas/entrada_gprof.txt -o $(TEMP)/saidas/saida_gprof.txt
	gprof $(EXE) gmon.out > $(REGPERF)/bigInputGPROF.txt

clean:
	rm -f $(EXE) $(OBJS) gmon.out