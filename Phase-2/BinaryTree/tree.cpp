#include <iostream>
#include<queue>
using namespace std;

class Node {
    public:
        Node* left;
        Node* right;
        int data;
        // constructor
        Node(int data) {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
};

Node* buildTree(int data) {
    // base case
    if(data == -1) return nullptr;
    
    Node* head = new Node(data);
    
    cout << "Enter left node of " << data << endl;
    int left;
    cin >> left;
    head->left = buildTree(left);
    
    cout << "Enter rigth node of " << data << endl;
    int right;
    cin >> right;
    head->right = buildTree(right);
    
    return head;
}

void preorderTraversal(Node* head) {
    // base case
    if(!head) return;
    
    cout << head->data << " ";
    
    preorderTraversal(head->left);
    preorderTraversal(head->right);
}

void inorderTraversal(Node* head) {
    // base case
    if(!head) return;
    
    inorderTraversal(head->left);
    cout << head->data << " ";
    inorderTraversal(head->right);
}

void postorderTraversal(Node* head) {
    // base case
    if(!head) return;
    
    postorderTraversal(head->left);
    postorderTraversal(head->right);
    
    cout << head->data << " ";
}

void levelOrderTraversal(Node* head) {
    queue<Node*> level;
    
    level.push(head);
    level.push(nullptr);
    
    while(!level.empty()) {
        Node* temp = level.front();
        level.pop();
        
        if(temp == nullptr) {
            cout << endl;
            if(!level.empty()) level.push(nullptr);
        }
        else {
            cout << temp->data << " ";
            if(temp->left) level.push(temp->left);
            if(temp->right) level.push(temp->right);
        }
    }
}

int main() {
    // input 1 12 -1 -1 2 -1 -1 4 -1 -1
    Node* head = buildTree(5);
    cout << "Tree Build Successfully" << endl;
    
    cout << endl;
    
    cout << "Preorder traversal of tree is " << endl;
    preorderTraversal(head);
    
    cout << endl;
    
    cout << "Inorder traversal of the tree is " << endl;
    inorderTraversal(head);
    
    cout << endl;
    
    cout << "Postorder traversal traversal of the tree is " << endl;
    postorderTraversal(head);
    
    cout << endl;
    
    cout << "Levelorder traversal of the tree is " << endl;
    levelOrderTraversal(head);
    
    return 0;
}