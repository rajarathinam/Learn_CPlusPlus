#include "stub.h"

namespace BinaryTree {
typedef struct Node
{

    Node* left;
    Node* right;
    int data;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }

}Node;

}

bool hasPath(BinaryTree::Node * root, std::vector<int>& arr, int key)
{
    if(!root) {
        return false;
    }

    arr.push_back(root->data);
    if( root->data == key) {
        return  true;
    }
    if( hasPath(root->left,arr,key) || hasPath(root->right, arr, key))
    {
        return true;
    }

    arr.pop_back();
    return  false;



}
 void printPath(BinaryTree::Node *root, int key)
 {
     std::vector<int> arr;
     if(hasPath(root, arr, key))
     {
         int vSize = static_cast<int>(arr.size());
         for (auto i  = 0; i < vSize; ++i) {
             std::cout << arr[i] << " ";

         }
     } else {
         std::cout << "No Path\n";
     }
 }

int anjan()
{
    using namespace BinaryTree;

    BinaryTree::Node* root = new BinaryTree::Node(1);
    root ->left = new BinaryTree::Node(2);
    root ->right = new BinaryTree::Node(3);
    root ->left->left = new BinaryTree::Node(4);
    root ->left->right = new BinaryTree::Node(5);
    root ->left->right->left = new BinaryTree::Node(6);
    printPath(root, 6);



    return 0;
}
