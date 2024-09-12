#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    public:
    int data;
    Node* left;
    Node* right;

    // constructor
    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildtree(Node* root) {
    // build root tree node
    int data;
    cout << "Enter data: ";
    cin >> data;

    root = new Node(data);

    // Base case
    if(data == -1) return nullptr;

    // left child node
    cout << "Enter Left child node of " << data << endl;
    root->left = buildtree(root);

    // right child node
    cout << "Enter right child node of " << data << endl;
    root->right = buildtree(root);
}

// LNR
void inorderTraversal(Node* root) {
    // base case
    if(root == nullptr) {
        return;
    }

    inorderTraversal(root->left);

    cout << root->data << " ";

    inorderTraversal(root->right);
}

// NLR
void preorderTraversal(Node* root) {
    // base case
    if(root == nullptr) {
        return;
    }

    cout << root->data << " ";

    preorderTraversal(root->left);

    preorderTraversal(root->right);
}

// LRN
void postorderTraversal(Node* root) {
    // base case
    if(root == nullptr) {
        return;
    }

    postorderTraversal(root->left);

    postorderTraversal(root->right);

    cout << root->data << " ";
}

int main()
{
    Node* root = nullptr;

    root = buildtree(root);
    cout << endl;
    // input string -> 1 3 7 -1-1 11 -1 -1 5 17 -1 -1 -1

    cout << "Inorder Traversal is ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal is ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal is ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}