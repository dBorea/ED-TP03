#include "Hash.hpp"

void Hash::insert(MsgContainer dataInput){
	int index = hashFunction(dataInput.getDestinatario());
	table[index].insertNewNode(dataInput);
}

bool Hash::remove(MsgContainer dataInput){
	int index = hashFunction(dataInput.getDestinatario());
	if(table[index].deleteNode(dataInput))
		return true;
	return false;
}

MsgContainer Hash::consult(MsgContainer dataInput){
	int index = hashFunction(dataInput.getDestinatario());
	TreeNode *temp = table[index].searchNode(dataInput);
	if(temp != nullptr)
		return temp->getData();
	return MsgContainer(dataInput.getDestinatario(), dataInput.getMessageID(), 0, "MENSAGEM INEXISTENTE");
}

bool Hash::hasElement(MsgContainer dataInput){
	int index = hashFunction(dataInput.getDestinatario());
	if(table[index].searchNode(dataInput))
		return true;
	return false;
}