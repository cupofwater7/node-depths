#include <vector>
#include <iostream>
using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};
void nodeDepthsCalcu(BinaryTree* root, int count, int& sums);
int nodeDepths(BinaryTree* root);

int main()
{
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->left->left = new BinaryTree(4);
    root->left->left->left = new BinaryTree(8);
    root->left->left->right = new BinaryTree(9);
    root->left->right = new BinaryTree(5);
    root->right = new BinaryTree(3);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);
    int actual = nodeDepths(root);
    cout << actual << " ";
    return 0;
}


int nodeDepths(BinaryTree* root) {
    // Write your code here.
    int sums = 0;
    nodeDepthsCalcu(root, 0, sums);
    return sums;
}

void nodeDepthsCalcu(BinaryTree* root, int count, int& sums)
{
    if (root == nullptr)return;

    sums += count;
    int curSums = count + 1;


    nodeDepthsCalcu(root->left, curSums, sums);
    nodeDepthsCalcu(root->right, curSums, sums);
}