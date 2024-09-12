// level order traversal left to right
// zig zag is in leetcode

#include<iostream>
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

Node* buildTree(Node* root) {
    int data;
    cout << "Enter root data ";
    cin >> data;

    root = new Node(data);

    if(root->data == -1) return nullptr;

    cout << "Enter left of " << root->data << endl;
    root->left = buildTree(root->left);

    cout << "Enter right of " << root->data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> levels;
    levels.push(root);
    levels.push(nullptr);

    while(!levels.empty()) {
        Node* temp = levels.front();
        levels.pop();

        if(!temp) {
            cout << endl;
            if(!levels.empty()) levels.push(nullptr);
        }

        else {
            cout << temp->data << " ";
            if(temp->left) levels.push(temp->left);
            if(temp->right) levels.push(temp->right);
        }
    }
}

void rightTOLeft_levelOrdertraersal(Node* root) {
    queue<Node*> levels;
    levels.push(root);
    levels.push(nullptr);

    while(!levels.empty()) {
        Node* temp = levels.front();
        levels.pop();

        if(!temp && !levels.empty()) {
            cout << endl;
            if(!levels.empty()) levels.push(nullptr);
        }

        else {
            cout << temp->data << " ";
            if(temp->right) levels.push(temp->right);
            if(temp->left) levels.push(temp->left);
        }
    }
}

int main()
{
    // input -> 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    // input -> 5 4 11 7 -1 -1  2 -1 -1 -1 8 13 -1 -1 4 -1 1 -1 -1
    Node* root = nullptr;
    root = buildTree(root);

    cout << "Tree created !!" << endl;

    cout << endl;

    cout << "Level order traversal of the tree is " << endl;
    levelOrderTraversal(root);

    cout << endl;

    cout << "Right to left Level order traversal of the tree is " << endl;
    rightTOLeft_levelOrdertraersal(root);
    
    return 0;
}