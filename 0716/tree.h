#ifndef TREE__H___
#define TREE__H___
#include<iostream>
using namespace std;

class TreeNode {
	private:
		int data;
	public:
		TreeNode(int data) {
			this->data = data;
		}

		int getData() {
			return this->data;
		}

		void setData(int data) {
			this->data = data;
		}
};

class Tree {
	public:
		virtual void pushTreeNode(TreeNode *newNode) = 0;
		virtual TreeNode* popTreeNode() = 0;
		virtual void printAllNode() = 0;
};
/*
class ListTreeNode : public TreeNode {
	private:
		ListTreeNode *leftchild;
		ListTreeNode *rightchild;

	public:
		//getter, setter, constructor, distruc....
};
*/
#endif
