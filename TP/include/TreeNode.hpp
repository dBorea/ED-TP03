#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "MsgContainer.hpp"

class BinarySearchTree;

class TreeNode{
	private:
		MsgContainer data;
		TreeNode* leftPtr;
		TreeNode* rightPtr;
		TreeNode* parentPtr;
		int height;
	public:
		TreeNode(MsgContainer dataInput) : data(dataInput), leftPtr(nullptr), rightPtr(nullptr), height(0) {}
		MsgContainer getData() { return data; }
		void setHeight(int H) { height = H; }
	friend class BinarySearchTree;
};

#endif