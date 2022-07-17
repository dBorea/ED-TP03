#ifndef HASH_H
#define HASH_H

#include "AVL.hpp"

class Hash{
	private:
		int lenghtOfTable;
		AVLTree* table;

	public:
		Hash(int L) : lenghtOfTable(L), table(new AVLTree[L]) {}
		~Hash() { delete[] table; }

		int hashFunction(int U) { return (U % lenghtOfTable); }
		void insert(MsgContainer);
		void remove(MsgContainer);
		bool hasElement(MsgContainer);
		MsgContainer consult(MsgContainer);
};

#endif