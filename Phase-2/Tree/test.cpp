#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
        int data;
        Node *left = nullptr;
        Node *right = nullptr;

        // constructor
        Node(int data)
        {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter data ";
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }
    
    root = new Node(data);

    cout << "Enter left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter right of " << data << endl;
    root->right = buildTree(root->right);
}

int main()
{
    Node* root = nullptr;

    root = buildTree(root);

    return 0;
}