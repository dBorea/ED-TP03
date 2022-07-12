#ifndef HASH_H
#define HASH_H

#include "BST.hpp"

class Hash{
	private:
		int lenghtOfTable;
		BinarySearchTree* table;

		int hashFunction(int U) { return (U % lenghtOfTable); }
	public:
		Hash(int L) : lenghtOfTable(L), table(new BinarySearchTree[L]) {}
		~Hash() { delete[] table; }

		void insert(MsgContainer);
		bool remove(MsgContainer);
		MsgContainer consult(MsgContainer);
};

void Hash::insert(MsgContainer dataInput){
	table[hashFunction(dataInput.getDestinatario())].insertNewNode(dataInput);
}

bool Hash::remove(MsgContainer dataInput){
	if(table[hashFunction(dataInput.getDestinatario())].deleteNode(dataInput))
		return true;
	return false;
}

MsgContainer Hash::consult(MsgContainer dataInput){
	TreeNode *temp = table[hashFunction(dataInput.getDestinatario())].searchNode(dataInput);
	if(temp != nullptr)
		return temp->getData();
	return MsgContainer(dataInput.getDestinatario(), dataInput.getMessageID(), 0, "MENSAGEM INEXISTENTE");
}

#endif