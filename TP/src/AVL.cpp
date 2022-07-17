#include "AVL.hpp"

int max(int a, int b){
	return (a > b)? a : b;
}

TreeNode* AVLTree::rotateRight(TreeNode* currentNode){
	TreeNode *newHead = currentNode->leftPtr;
	currentNode->leftPtr = newHead->rightPtr;
	newHead->rightPtr = currentNode;
	currentNode->setHeight(1 + max(height(currentNode->rightPtr), height(currentNode->leftPtr)));
	newHead->setHeight(1 + max(height(newHead->rightPtr), height(newHead->leftPtr)));
	return newHead;
}

TreeNode* AVLTree::rotateLeft(TreeNode* currentNode){
	TreeNode *newHead = currentNode->rightPtr;
	currentNode->rightPtr = newHead->leftPtr;
	newHead->leftPtr = currentNode;
	currentNode->setHeight(1 + max(height(currentNode->leftPtr), height(currentNode->rightPtr)));
	newHead->setHeight(1 + max(height(newHead->leftPtr), height(newHead->rightPtr)));
	return newHead;
}

void AVLTree::insertNewNode(MsgContainer dataInput){
	raiz = insert_recursive(raiz, dataInput);
}

TreeNode* AVLTree::insert_recursive(TreeNode* currentNode, MsgContainer dataInput){
	if(currentNode == nullptr){
		// cout << "NOVO ELEMENTO:";
		// dataInput.printMsg();
		TreeNode* newNode = new TreeNode(dataInput);
		return newNode;
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
	if(balance > 1 && dataInput <= currentNode->leftPtr->data)
		return rotateRight(currentNode);
	
	// Caso esquerda->direita
	if(balance > 1 && dataInput > currentNode->leftPtr->data){
		currentNode->leftPtr = rotateLeft(currentNode->leftPtr);
		return rotateRight(currentNode);
	}

	// Caso direita->direita
	else if(balance < -1 && dataInput >= currentNode->rightPtr->data)
		return rotateLeft(currentNode);
	
	// Caso direita->esquerda
	else if(balance < -1 && dataInput < currentNode->rightPtr->data){
		currentNode->rightPtr = rotateRight(currentNode->rightPtr);
		return rotateLeft(currentNode);
	}
	
	return currentNode;
}

TreeNode* AVLTree::searchNode(MsgContainer dataChave){
	return search_recursive(raiz, dataChave);
}

TreeNode* AVLTree::search_recursive(TreeNode* currentNode, MsgContainer dataChave){
	if(currentNode == nullptr)
		return nullptr;
	
	if(dataChave < currentNode->data)
		return search_recursive(currentNode->leftPtr, dataChave);
	if(dataChave > currentNode->data)
		return search_recursive(currentNode->rightPtr, dataChave);
	if(dataChave == currentNode->data)
		return currentNode;
	return nullptr;
}

void AVLTree::deleteNode(MsgContainer dataChave){
	raiz = delete_recursive(raiz, dataChave);
}

TreeNode* AVLTree::minValueNode(TreeNode* origin){
	TreeNode* currentNode = origin;
	for(; currentNode->leftPtr != nullptr ;)
		currentNode = currentNode->leftPtr;
	return currentNode;
}

TreeNode* AVLTree::maxValueNode(TreeNode* origin){
	TreeNode* currentNode = origin;
	for(; currentNode->rightPtr != nullptr ;)
		currentNode = currentNode->rightPtr;
	return currentNode;
}

TreeNode* AVLTree::delete_recursive(TreeNode* &currentNode, MsgContainer dataChave){
	if(currentNode == nullptr) return nullptr;
		 if(dataChave < currentNode->data) currentNode->leftPtr = delete_recursive(currentNode->leftPtr, dataChave);
	else if(dataChave > currentNode->data) currentNode->rightPtr = delete_recursive(currentNode->rightPtr, dataChave);	
	else {
		TreeNode *tempRight = currentNode->rightPtr;
		if(currentNode->rightPtr == nullptr){
			TreeNode *tempLeft = currentNode->leftPtr;
			delete currentNode;
			currentNode = tempLeft;
		}
		else if(currentNode->leftPtr == nullptr){
			delete currentNode;
			currentNode = tempRight;
		}
		else {
			tempRight = minValueNode(tempRight);
			currentNode->data = tempRight->data;
			currentNode->rightPtr = delete_recursive(currentNode->rightPtr, tempRight->data);
		}
	}

	if(currentNode == nullptr) return nullptr;
	
	currentNode->setHeight(1 + max(height(currentNode->rightPtr), height(currentNode->leftPtr)));
	int balance = getBalance(currentNode);

	// Caso esquerda->esquerda
	if(balance > 1 && getBalance(currentNode->leftPtr) >= 0)
		return rotateRight(currentNode);
	
	// Caso esquerda->direita
	if(balance > 1 && getBalance(currentNode->leftPtr) < 0){
		currentNode->leftPtr = rotateLeft(currentNode->leftPtr);
		return rotateRight(currentNode);
	}

	// Caso direita->direita
	else if(balance < -1 && getBalance(currentNode->leftPtr) <= 0)
		return rotateLeft(currentNode);
	
	// Caso direita->esquerda
	else if(balance < -1 && getBalance(currentNode->leftPtr) > 0){
		currentNode->rightPtr = rotateRight(currentNode->rightPtr);
		return rotateLeft(currentNode);
	}
	
	return currentNode;
}

void AVLTree::destroy_recursive(TreeNode* currentNode){
	if(currentNode){
		destroy_recursive(currentNode->leftPtr);
		destroy_recursive(currentNode->rightPtr);
		// cout << "DELETANDO ELEMENTO:";
		// currentNode->data.printMsg();
		delete currentNode;
	}
}

void AVLTree::destroy(){
	destroy_recursive(raiz);
}