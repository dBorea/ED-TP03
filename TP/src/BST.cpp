#include "BST.hpp"

int max(int a, int b){
	return (a > b)? a : b;
}

TreeNode* BinarySearchTree::rotateRight(TreeNode* currentNode){
	TreeNode *XNode = currentNode->leftPtr;
	TreeNode *XYNode = XNode->rightPtr;
	XNode->rightPtr = currentNode;
	currentNode->leftPtr = XYNode;
	currentNode->setHeight(1 + max(height(currentNode->rightPtr), height(currentNode->leftPtr)));
	XNode->setHeight(1 + max(height(XNode->rightPtr), height(XNode->leftPtr)));
	return XNode;
}

TreeNode* BinarySearchTree::rotateLeft(TreeNode* currentNode){
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
	if(dataChave == currentNode->data)
		return currentNode;
	return nullptr;
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

TreeNode* BinarySearchTree::maxValueNode(TreeNode* origin){
	TreeNode* currentNode = origin;
	for(; currentNode->rightPtr != nullptr ;)
		currentNode = currentNode->rightPtr;
	return currentNode;
}

TreeNode* BinarySearchTree::delete_recursive(TreeNode* &currentNode, MsgContainer dataChave){
	if(currentNode == nullptr) return currentNode;
	else if(dataChave < currentNode->data) currentNode->leftPtr = delete_recursive(currentNode->leftPtr, dataChave);
	else if(dataChave > currentNode->data) currentNode->rightPtr = delete_recursive(currentNode->rightPtr, dataChave);	
	else if(dataChave == currentNode->data){
		if(currentNode->leftPtr == nullptr && currentNode->rightPtr == nullptr){
			delete currentNode;
			currentNode = nullptr;
		}
		else if(currentNode->leftPtr == nullptr){
			TreeNode *temp = currentNode;
			currentNode = currentNode->rightPtr;
			delete temp;
		}
		else if(currentNode->rightPtr == nullptr){
			TreeNode *temp = currentNode;
			currentNode = currentNode->leftPtr;
			delete temp;
		}
		else {
			TreeNode *temp = minValueNode(currentNode->rightPtr);
			currentNode->data = temp->data;
			currentNode->rightPtr = delete_recursive(currentNode->rightPtr, temp->data);
		}
	}
	else return currentNode;

	if(currentNode == nullptr)
		return nullptr;
	
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

void BinarySearchTree::destroy_recursive(TreeNode* currentNode){
	if(currentNode){
		destroy_recursive(currentNode->leftPtr);
		destroy_recursive(currentNode->rightPtr);
		delete currentNode;
	}
}

void BinarySearchTree::destroy(){
	destroy_recursive(raiz);
}