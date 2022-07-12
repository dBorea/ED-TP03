#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "TreeNode.hpp"

int max(int a, int b){
	return (a > b)? a : b;
}

class BinarySearchTree{
	private:
		TreeNode *raiz;
		bool isEmpty();

		TreeNode* rotateLeft(TreeNode*);
		TreeNode* rotateRight(TreeNode*);
		TreeNode* insert_recursive(TreeNode*, MsgContainer);
		TreeNode* search_recursive(TreeNode*, MsgContainer);
		TreeNode* minValueNode(TreeNode*);
		TreeNode* delete_recursive(TreeNode*, MsgContainer);

		int height(TreeNode* N){
			if(N == nullptr) return 0;
			return N->height;
		}
		int getBalance(TreeNode* N){
			if(N == nullptr) return 0;
			return height(N->leftPtr) - height(N->rightPtr);
		}

	public:
		BinarySearchTree() : raiz(nullptr) {}
		void insertNewNode(MsgContainer);
		TreeNode* searchNode(MsgContainer);
		TreeNode* deleteNode(MsgContainer);
};

TreeNode* BinarySearchTree::rotateLeft(TreeNode* currentNode){
	TreeNode *XNode = currentNode->leftPtr;
	TreeNode *XYNode = XNode->rightPtr;
	XNode->rightPtr = currentNode;
	currentNode->leftPtr = XYNode;
	currentNode->setHeight(1 + max(height(currentNode->rightPtr), height(currentNode->leftPtr)));
	XNode->setHeight(1 + max(height(XNode->rightPtr), height(XNode->leftPtr)));
	return XNode;
}

TreeNode* BinarySearchTree::rotateRight(TreeNode* currentNode){
	TreeNode *YNode = currentNode->rightPtr;
	TreeNode *YXNode = YNode->leftPtr;
	YNode->leftPtr = currentNode;
	currentNode->rightPtr = YXNode;
	currentNode->setHeight(1 + max(height(currentNode->rightPtr), height(currentNode->leftPtr)));
	YNode->setHeight(1 + max(height(YNode->rightPtr), height(YNode->leftPtr)));
	return YNode;
}


void BinarySearchTree::insertNewNode(MsgContainer dataInput){
	raiz = insert_recursive(raiz, dataInput);
}

TreeNode* BinarySearchTree::insert_recursive(TreeNode* currentNode, MsgContainer dataInput){
	if(currentNode == nullptr){
		TreeNode newNode(dataInput);
		return &newNode;
	}
	else {
		if(dataInput < currentNode->data)
			currentNode->leftPtr = insert_recursive(currentNode->leftPtr, dataInput);
		else if(dataInput > currentNode->data)
			currentNode->rightPtr = insert_recursive(currentNode->rightPtr, dataInput);
		else
			erroAssert(false, "Tentativa de inserir duplicata de elemento já existente.");
	}

	currentNode->setHeight(1 + max(height(currentNode->rightPtr), height(currentNode->leftPtr)));
	int balance = getBalance(currentNode);

	// Caso esquerda->esquerda
	if(balance > 1 && dataInput < currentNode->leftPtr->data)
		return rotateRight(currentNode);
	
	// Caso esquerda->direita
	if(balance > 1 && dataInput > currentNode->leftPtr->data){
		currentNode->leftPtr = rotateLeft(currentNode->leftPtr);
		return rotateRight(currentNode);
	}

	// Caso direita->direita
	else if(balance < -1 && dataInput > currentNode->rightPtr->data)
		return rotateLeft(currentNode);
	
	// Caso direita->esquerda
	else if(balance < -1 && dataInput < currentNode->rightPtr->data){
		currentNode->rightPtr = rotateRight(currentNode->rightPtr);
		return rotateLeft(currentNode);
	}
	
	return currentNode;
}

TreeNode* BinarySearchTree::searchNode(MsgContainer dataChave){
	return search_recursive(raiz, dataChave);
}

TreeNode* BinarySearchTree::search_recursive(TreeNode* currentNode, MsgContainer dataChave){
	if(currentNode == nullptr)
		return nullptr;
	
	if(dataChave < currentNode->data)
		return search_recursive(currentNode->leftPtr, dataChave);
	if(dataChave > currentNode->data)
		return search_recursive(currentNode->rightPtr, dataChave);
	
	return currentNode;
}

TreeNode* BinarySearchTree::deleteNode(MsgContainer dataChave){
	return delete_recursive(raiz, dataChave);
}

TreeNode* BinarySearchTree::minValueNode(TreeNode* origin){
	TreeNode* currentNode = origin;
	for(; currentNode->leftPtr != nullptr ;)
		currentNode = currentNode->leftPtr;
	return currentNode;
}

TreeNode* BinarySearchTree::delete_recursive(TreeNode* currentNode, MsgContainer dataChave){
	TreeNode *foundNode = search_recursive(currentNode, dataChave);
	if(foundNode == nullptr)
		return nullptr;
	
	if(foundNode->leftPtr == nullptr || foundNode->rightPtr == nullptr){
		TreeNode *temp = (foundNode->leftPtr) ? foundNode->leftPtr : foundNode->rightPtr;
		if(temp == nullptr){
			temp = foundNode;
			foundNode = nullptr;
		}
		else {
			*foundNode = *temp;
		}
		delete temp;
	}
	else {
		TreeNode *temp = minValueNode(foundNode->rightPtr);
		foundNode->data = temp->data;
		foundNode->rightPtr = delete_recursive(foundNode->rightPtr, temp->data);
	}

	if(foundNode == nullptr)
		return nullptr;
	
	foundNode->setHeight(1 + max(height(foundNode->rightPtr), height(foundNode->leftPtr)));
	int balance = getBalance(foundNode);

	// Caso esquerda->esquerda
	if(balance > 1 && getBalance(foundNode->leftPtr) >= 0)
		return rotateRight(foundNode);
	
	// Caso esquerda->direita
	if(balance > 1 && getBalance(foundNode->leftPtr) < 0){
		foundNode->leftPtr = rotateLeft(foundNode->leftPtr);
		return rotateRight(foundNode);
	}

	// Caso direita->direita
	else if(balance < -1 && getBalance(foundNode->leftPtr) <= 0)
		return rotateLeft(foundNode);
	
	// Caso direita->esquerda
	else if(balance < -1 && getBalance(foundNode->leftPtr) > 0){
		foundNode->rightPtr = rotateRight(foundNode->rightPtr);
		return rotateLeft(foundNode);
	}
	
	return foundNode;
}

#endif