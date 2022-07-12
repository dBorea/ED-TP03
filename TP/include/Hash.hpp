#ifndef HASH_H
#define HASH_H

#include "BST.hpp"

class Hash{
	private:
		int lenghtOfTable;
		BinarySearchTree* table;

	public:
		Hash(int L) : lenghtOfTable(L), table(new BinarySearchTree[L]) {}
		~Hash() { delete[] table; }

		int hashFunction(int U) { return (U % lenghtOfTable); }
		void insert(MsgContainer);
		bool remove(MsgContainer);
		MsgContainer consult(MsgContainer);
};

#endif