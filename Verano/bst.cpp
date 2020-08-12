#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <climits>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

class TreeNode {
	public:
		int val = -1;
		TreeNode* right = nullptr;
		TreeNode* left = nullptr;

		TreeNode(int def) : val(def){};
		TreeNode(){};
};

class BinarySearchTree{
	private:
		TreeNode* root;

		// Returns the position of the item with such value or the node 
		// that should host such value as a child
		//  nullptr if an error occurs (The pointer given isn't valid)
		TreeNode* binSearch(TreeNode* root, int val){
			if(root == nullptr) return nullptr;
			else if(val == root->val) return root;
			
			if(root->left != nullptr && val < root->val) {
				return binSearch(root->left, val);
			}
			if(root->right != nullptr && val > root->val){
				return binSearch(root->right, val);
			}
			return root;
		}
		
	public:
		BinarySearchTree (int defVal = -1) {
			root = new TreeNode;
			root->val = defVal;
		}

		bool find(int val) {
			return binSearch(root, val) != nullptr; 
		}

		TreeNode* succesor(TreeNode* node, int leftOne = true) {
			if(node == nullptr) return nullptr;

			if(leftOne) {
				return node->left;
			}
			else {
				return node->right;
			}
		}

		TreeNode* findMax(TreeNode* node) {
			if(node != nullptr && node->right != nullptr) return findMax(node->right);
			else return node;
		}
		int findMaxVal(TreeNode* node) {
			return findMax(node)->val;
		}

		TreeNode* findMin(TreeNode* node) {
			if(node != nullptr && node->left != nullptr) return findMax(node->left);
			else return node;
		}
		int findMinVal(TreeNode* node) {
			return findMin(node)->val;
		}

		void insert(int val) {
			TreeNode* parent = binSearch(root, val);
			if(parent == nullptr || parent->val == val) return;

			TreeNode* newNode = new TreeNode(val);
			if(val < parent->val)
				parent->left = newNode;
			if(val > parent->val)
				parent->right = newNode;
		}

};

bool isBST(TreeNode* root) {
	if(root != nullptr) {
		if(root->left !=nullptr && root->left->val > root->val) return false;
		else if(root->right != nullptr && root->right->val < root->val) return false;
		else return isBST(root->left) && isBST(root->right);
	}
	else return true;
}

void resuelveCaso() {
	
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


