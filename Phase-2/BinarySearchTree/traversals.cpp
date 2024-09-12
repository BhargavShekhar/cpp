#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        // constructor
        Node(int data) {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
};

Node* buildTree(Node* root, int data) {
    if(!root) {
        root = new Node(data);
        return root;
    }

    if(data < root->data) {
        root->left = buildTree(root->left, data);
    }
    if(data > root->data) {
        root->right = buildTree(root->right, data);
    }

    return root;
}

Node* createTree() {
    int data;
    cout << "Enter node data " << endl;
    cin >> data;

    Node* root = nullptr;

    while(data != -1) {
        root = buildTree(root, data);
        cout << "Enter node data " << endl;
        cin >> data;
    }

    return root;
}

// NLR
void preOrderTraversal(Node* root) {
    // base case
    if(!root) return;

    cout << root->data << " ";
    if(root->left) preOrderTraversal(root->left);
    if(root->right) preOrderTraversal(root->right);
}

// LNR
void inOrderTraversal(Node* root) {
    // base case
    if(!root) return;

    if(root->left) inOrderTraversal(root->left);
    cout << root->data << " ";
    if(root->right) inOrderTraversal(root->right);
}

// LRN
void postOrderTraversal(Node* root) {
    // base case
    if(!root) return;

    if(root->left) postOrderTraversal(root->left);
    if(root->right) postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    // 100 50 200 70 20 250 150 -1
    Node* root = createTree();  

    cout << endl;

    cout << "PreOrder Traversal: " << endl;
    preOrderTraversal(root);

    cout << endl;

    cout << "InOrder Traversal: " << endl;
    inOrderTraversal(root);

    cout << endl;

    cout << "PostOrder Traversal: " << endl;
    postOrderTraversal(root);
    
    return 0;
}