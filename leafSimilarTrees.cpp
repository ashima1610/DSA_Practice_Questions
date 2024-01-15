// Consider all the leaves of a binary tree, from left to right order, 
// the values of those leaves form a leaf value sequence.

// Check if two trees have the same leaf sequence.

//Leetcode ques no: 872.

#include<iostream>
#include<vector>

using namespace std;

class TreeNode{
  public:
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void leafSequence(TreeNode* root, vector<int>& v){
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
            return;
        }

        if(root->left!=NULL){
            leafSequence(root->left, v);
        }
        if(root->right!=NULL){
            leafSequence(root->right, v);
        }
        
    }

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> sequence1, sequence2;
        leafSequence(root1, sequence1);
        leafSequence(root2, sequence2);

        return sequence1==sequence2;
    }

int main() {
    // Example usage
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);

    cout << (leafSimilar(root1, root2) ? "Leaves are similar" : "Leaves are not similar") << endl;

    return 0;
}
