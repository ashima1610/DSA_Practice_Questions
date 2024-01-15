#include<iostream>

using namespace std;

class TreeNode{
    public: 
     int val;
     TreeNode* left;
     TreeNode* right;

     TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
     }
};

bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //base case
        if(p==NULL && q==NULL) return true;

        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)){
            return false;
        }

        if(p->val!=q->val){
            return false;
        }

        bool leftEqual = isSameTree(p->left, q->left);
        bool rightEqual = isSameTree(p->right, q->right);

        return (leftEqual && rightEqual);

    }

int main(){
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
    root2->left->right = new TreeNode(2);
    root2->right->left = new TreeNode(9);
    root2->right->right = new TreeNode(8);
    root2->left->right->left = new TreeNode(7);
    root2->left->right->right = new TreeNode(4);


    // TreeNode* root2 = new TreeNode(3);
    // root2->left = new TreeNode(5);
    // root2->right = new TreeNode(1);
    // root2->left->left = new TreeNode(6);
    // root2->left->right = new TreeNode(7);
    // root2->right->left = new TreeNode(4);
    // root2->right->right = new TreeNode(2);
    // root2->right->right->left = new TreeNode(9);
    // root2->right->right->right = new TreeNode(8);

    if(isSameTree(root1, root2)){
        cout<<"Both trees are same";
    }
    else{
        cout<<"Both trees are different";
    }
}