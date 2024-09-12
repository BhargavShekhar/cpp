#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
    public:
        char data;
        unordered_map<int, TrieNode*> children;  // Ascii Value:Trie
        bool isTerminal;

        // ctor
        TrieNode(char data) {
            this->data = data;
            isTerminal = false;
        }
};

void insertIntoTrie(TrieNode* root, string word) {
    // base case
    if(word.size() == 0) {
        root->isTerminal = true;
        return;
    }

    char letter = word[0];
    TrieNode* child;

    // visit if present
    if(root->children.count(letter) == 1) child = root->children[letter];
    // create if not present
    else {
        child = new TrieNode(letter);
        root->children[letter] = child;
    }

    insertIntoTrie(child, word.substr(1));
}

bool searchInTrie(TrieNode* root, string word) {
    // base case
    if(word.size() == 0) {
        if(root->isTerminal) return true;
        else return false;
    }
    
    char letter = word[0];
    TrieNode* child;

    // visit if present
    if(root->children.find(letter) != root->children.end()) child = root->children[letter];
    else return false;

    return searchInTrie(child, word.substr(1));
}

// search helper function
void searchFromTrie(TrieNode* root, string word) {
    bool search = searchInTrie(root, word);

    if(search) cout << word << " is present" << endl;
    else cout << word << " is not" << endl;
}

void deleteFromTrie(TrieNode* root, string word) {
    // base case
    if(word.size() == 0) {
        root->isTerminal = false;
        return;
    }

    char letter = word[0];
    TrieNode* child;

    // search if present
    if(root->children.find(letter) != root->children.end()) child = root->children[letter];
    else return;

    deleteFromTrie(child, word.substr(1));
}

int main()
{
    TrieNode* root = new TrieNode('-');

    insertIntoTrie(root, "cover");
    insertIntoTrie(root, "car");
    insertIntoTrie(root, "care");
    insertIntoTrie(root, "snake");
    insertIntoTrie(root, "fivefoot");
    insertIntoTrie(root, "extremlyWell");
    insertIntoTrie(root, "selfObsessed");
    insertIntoTrie(root, "tag");
    insertIntoTrie(root, "take");
    insertIntoTrie(root, "took");
    insertIntoTrie(root, "hate");
    insertIntoTrie(root, "is");
    insertIntoTrie(root, "love");

    searchFromTrie(root, "hate");

    deleteFromTrie(root, "love");

    searchFromTrie(root, "love");
    
    return 0;
}