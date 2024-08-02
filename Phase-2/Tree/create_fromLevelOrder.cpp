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
        left = nullptr;
        right = nullptr;
    }
};

void create_LevelOrderTraversal(Node* &root) {
    queue<Node*> q;

    int data;
    cout << "Enter Root data: ";
    cin >> data;

    root = new Node(data);

    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter left for " << temp->data << " : ";
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int RightData;
        cout << "Enter right for " << temp->data << " : ";
        cin >> RightData;
        if (RightData != -1)
        {
            temp->right = new Node(RightData);
            q.push(temp->right);
        }
        
    }
    
}

void levelOrderTraversel(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(nullptr);
            }
            
        }

        else
        { 
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node* root = nullptr;

    create_LevelOrderTraversal(root);
    // Input String 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    levelOrderTraversel(root);
    
    return 0;
}