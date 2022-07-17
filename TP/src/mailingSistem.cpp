#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <getopt.h>
#include "Hash.hpp"

using std::istringstream;

void parseArgs(int argc, char *argv[], char inputName[], char outputName[], char logName[], bool &regMem, bool &optReg){
	extern char *optarg;
	logName[0] = 0;
	inputName[0] = 0;
	outputName[0] = 0;

	for(int opt; (opt=getopt(argc, argv, "i:I:o:O:p:l")) != EOF;){
		switch(opt){
			case 'i':
			case 'I':
				strcpy(inputName, optarg);
				erroAssert(strlen(inputName)>0, "Arquivo de entrada não foi informado corretamente.");
				break;

			case 'o':
			case 'O':
				strcpy(outputName, optarg);
				erroAssert(strlen(outputName)>0, "Arquivo de saída não foi informado corretamente.");
				break;

			case 'p':
				strcpy(logName, optarg);
				erroAssert(strlen(logName)>0, "Com a opção -p, o nome do arquivo de registro deve ser informado.");
				optReg = true;
				break;
				
			case 'l':
				regMem = true;
				break;
		}
	}

	if(regMem)
		regMem = optReg;

	erroAssert(strlen(inputName)>0, "Arquivo de entrada não foi informado.");
	erroAssert(strlen(outputName)>0, "Arquivo de saída não foi informado.");
}

void readMailLogFile(std::ifstream& inputFile, std::ofstream& outputFile){
	int tempInt;
	inputFile >> tempInt;
	Hash hashTree(tempInt);

	int destiny, msgID, numberOfWords;
	string tempString, inputString, tempMessage;

	for(; getline(inputFile, inputString) ;){
		if(inputString=="") getline(inputFile, inputString);
		istringstream linhaAtual(inputString);

		linhaAtual >> tempString;
		if(tempString == "ENTREGA"){
			linhaAtual >> destiny >> msgID >> numberOfWords;
			tempMessage = "";
			for(int i=0; i<numberOfWords; i++){
				linhaAtual >> tempString;
				tempMessage.append(tempString);
				if(i<numberOfWords-1) tempMessage.append(" ");
			}
			hashTree.insert(MsgContainer(destiny, msgID, numberOfWords, tempMessage));
			outputFile << "OK: MENSAGEM " << msgID << " PARA " << destiny << " ARMAZENADA EM " << hashTree.hashFunction(destiny) << endl;
		}
		else if(tempString == "CONSULTA"){
			linhaAtual >> destiny >> msgID;
			outputFile << "CONSULTA " << hashTree.consult(MsgContainer(destiny, msgID));
		}
		else if(tempString == "APAGA"){
			linhaAtual >> destiny >> msgID;
			if(hashTree.hasElement(MsgContainer(destiny, msgID))){
				hashTree.remove(MsgContainer(destiny, msgID));
				outputFile << "OK: MENSAGEM APAGADA" << endl;
			}
			else
				outputFile << "ERRO: MENSAGEM INEXISTENTE" << endl;
		}
		else erroAssert(false, "Comando inválido introduzido. Por favor, use apenas os comandos ENTREGA, CONSULTA e APAGA.");
	}
}

int main(int argc, char *argv[]){
	char logName[100], inputName[100], outputName[100];
	bool optReg = false, regMem = false;

	parseArgs(argc, argv, inputName, outputName, logName, regMem, optReg);
	std::string arqEntrada(inputName), arqSaida(outputName);
	std::ifstream inputFile(arqEntrada); erroAssert(!inputFile.fail(), "Arquivo de entrada não pôde ser aberto");
	std::ofstream outputFile(arqSaida);

	if(optReg)
		iniciaMemLog(logName);
	if(regMem)
		ativaMemLog();
	else
		desativaMemLog();

	readMailLogFile(inputFile, outputFile);

	return (optReg)? finalizaMemLog() : 0;
}