#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "TreeNode.hpp"

class Hash;

class AVLTree{
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
		AVLTree() : raiz(nullptr) {}
		~AVLTree() { destroy(); }
		void insertNewNode(MsgContainer);
		void deleteNode(MsgContainer);
		TreeNode* searchNode(MsgContainer);

	friend class Hash;
};

#endif