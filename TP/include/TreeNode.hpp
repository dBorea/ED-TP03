#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "MsgContainer.hpp"

class AVLTree;

class TreeNode{
	private:
		MsgContainer data;
		TreeNode* leftPtr;
		TreeNode* rightPtr;
		int height;
	public:
		TreeNode(MsgContainer dataInput) : data(dataInput), leftPtr(nullptr), rightPtr(nullptr), height(1) {
			escreveMemLog((long int)(this), sizeof(TreeNode*), 0);
		}
		MsgContainer getData() { return data; leMemLog((long int)(this), sizeof(TreeNode*), 0); }
		void setData(MsgContainer newData) { data = newData; escreveMemLog((long int)(this), sizeof(TreeNode*), 0); }
		void setHeight(int H) { height = H; }
	friend class AVLTree;
};

#endif