//Tree traversal in C++
#include <iostream>
#include <malloc.h>
#include <conio.h>
#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node* left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void Postorder(struct Node* node)
{
    if (node == NULL)
        return;
    Postorder(node->left);
    Postorder(node->right);
    cout << node->data << " ";
}
void Inorder(struct Node* node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
}
void Preorder(struct Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    Preorder(node->left);
    Preorder(node->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->left             = new Node(2);
    root->right         = new Node(3);
    root->left->left     = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    Preorder(root);
    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);
    cout << "\nPostorder traversal of binary tree is \n";
    Postorder(root);

    return 0;
}
