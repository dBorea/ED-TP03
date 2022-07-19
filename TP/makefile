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

perfAll: perfMsgSize perfUsers perfVarianca

perfInput: $(EXE)
	$(EXE) -p $(REGPERF)/input_var100k.out -i $(TEMP)/entradas/out_1.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/input_var200k.out -i $(TEMP)/entradas/out_2.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/input_var300k.out -i $(TEMP)/entradas/out_3.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/input_var400k.out -i $(TEMP)/entradas/out_4.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/input_var500k.out -i $(TEMP)/entradas/out_5.txt -o $(TEMP)/saidas/saida_temp.txt

perfUsers: $(EXE)
	$(EXE) -p $(REGPERF)/numusers_var1.out -i $(TEMP)/entradas/out_numusers_1.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/numusers_var2.out -i $(TEMP)/entradas/out_numusers_2.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/numusers_var3.out -i $(TEMP)/entradas/out_numusers_3.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/numusers_var4.out -i $(TEMP)/entradas/out_numusers_4.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/numusers_var5.out -i $(TEMP)/entradas/out_numusers_5.txt -o $(TEMP)/saidas/saida_temp.txt

perfMsgSize: $(EXE)
	$(EXE) -p $(REGPERF)/msgsize_var1.out -i $(TEMP)/entradas/out_msgsize_1.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/msgsize_var2.out -i $(TEMP)/entradas/out_msgsize_2.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/msgsize_var3.out -i $(TEMP)/entradas/out_msgsize_3.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/msgsize_var4.out -i $(TEMP)/entradas/out_msgsize_4.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/msgsize_var5.out -i $(TEMP)/entradas/out_msgsize_5.txt -o $(TEMP)/saidas/saida_temp.txt

perfVarianca: $(EXE)
	$(EXE) -p $(REGPERF)/varianca10-10_var1.out -i $(TEMP)/entradas/out_variancia_10-10_1.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca10-10_var2.out -i $(TEMP)/entradas/out_variancia_10-10_2.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca10-10_var3.out -i $(TEMP)/entradas/out_variancia_10-10_3.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca10-10_var4.out -i $(TEMP)/entradas/out_variancia_10-10_4.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca10-10_var5.out -i $(TEMP)/entradas/out_variancia_10-10_5.txt -o $(TEMP)/saidas/saida_temp.txt

	$(EXE) -p $(REGPERF)/varianca100-0_var1.out -i $(TEMP)/entradas/out_variancia_100-0_1.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca100-0_var2.out -i $(TEMP)/entradas/out_variancia_100-0_2.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca100-0_var3.out -i $(TEMP)/entradas/out_variancia_100-0_3.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca100-0_var4.out -i $(TEMP)/entradas/out_variancia_100-0_4.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca100-0_var5.out -i $(TEMP)/entradas/out_variancia_100-0_5.txt -o $(TEMP)/saidas/saida_temp.txt

	$(EXE) -p $(REGPERF)/varianca0-100_var1.out -i $(TEMP)/entradas/out_variancia_0-100_1.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca0-100_var2.out -i $(TEMP)/entradas/out_variancia_0-100_2.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca0-100_var3.out -i $(TEMP)/entradas/out_variancia_0-100_3.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca0-100_var4.out -i $(TEMP)/entradas/out_variancia_0-100_4.txt -o $(TEMP)/saidas/saida_temp.txt
	$(EXE) -p $(REGPERF)/varianca0-100_var5.out -i $(TEMP)/entradas/out_variancia_0-100_5.txt -o $(TEMP)/saidas/saida_temp.txt

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