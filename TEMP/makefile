CXX = g++
SAIDAS = saidas

EXE = comparator
GENLOAD = genload

all: $(GENLOAD) $(EXE)

$(GENLOAD): genLoad.cpp
	$(CXX) genLoad.cpp -o $(GENLOAD)

$(EXE): fileComparator.cpp
	$(CXX) fileComparator.cpp -o $(EXE)

compare: $(EXE)
	./$(EXE) -1 $(SAIDAS)/saida_1.txt -2 $(SAIDAS)/minha_saida_1.txt
	./$(EXE) -1 $(SAIDAS)/saida_2.txt -2 $(SAIDAS)/minha_saida_2.txt
	./$(EXE) -1 $(SAIDAS)/saida_3.txt -2 $(SAIDAS)/minha_saida_3.txt
	./$(EXE) -1 $(SAIDAS)/saida_4.txt -2 $(SAIDAS)/minha_saida_4.txt