#include<iostream>
#include<queue>
using namespace std;

class Node {
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

// level order traversal
void printBinaryTree(Node* root) {
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

// bst is building in O(logn) since we are dividing the tree while traversing
Node* buildBST(Node* root, int data) {
    // base case
    if(!root) {
        root = new Node(data);
        return root;
    }

    if(data < root->data) {
        root->left = buildBST(root->left, data);
    }
    else {
        root->right = buildBST(root->right, data);  
    }

    return root;
}

// data input is taking constant time
Node* createBST() {
    int data;
    cout << "Enter node data " << endl;
    cin >> data;

    Node* root = nullptr;

    while(data != -1) {
        root = buildBST(root, data);
        cout << "Enter node data " << endl;
        cin >> data;
    }

    return root;
}

int main()
{
    // input 100 50 200 70 20 250 150 -1
    Node* root = createBST();

    printBinaryTree(root);
    
    return 0;
}