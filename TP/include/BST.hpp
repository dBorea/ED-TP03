#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "TreeNode.hpp"

class Hash;

class BinarySearchTree{
	private:
		TreeNode *raiz;

		TreeNode* minValueNode(TreeNode*);
		TreeNode* maxValueNode(TreeNode*);
		TreeNode* rotateRight(TreeNode*);
		TreeNode* rotateLeft(TreeNode*);
		TreeNode* insert_recursive(TreeNode*, MsgContainer);
		TreeNode* search_recursive(TreeNode*, MsgContainer);
		TreeNode* delete_recursive(TreeNode*&, MsgContainer);
		void destroy_recursive(TreeNode*);
		void destroy();

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
		~BinarySearchTree() { destroy(); }
		void insertNewNode(MsgContainer);
		TreeNode* searchNode(MsgContainer);
		TreeNode* deleteNode(MsgContainer);

	friend class Hash;
};

#endif