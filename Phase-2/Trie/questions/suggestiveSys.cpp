#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class TrieNode{
    public:
        char data;
        unordered_map<char, TrieNode*> children;
        bool isTerminal;

        TrieNode(char data) {
            this->data = data;
            this->isTerminal = false;
        }

        void insert(TrieNode* root, string word) {
            if(word.size() == 0) {
                root->isTerminal = true;
                return;
            }

            char letter = word[0];
            TrieNode* child;

            if(root->children.find(letter) != root->children.end()) child = root->children[letter];
            else {
                child = new TrieNode(letter);
                root->children[letter] = child;
            }

            insert(child, word.substr(1));
        }
};

void addSuggestions(TrieNode* root, vector<string> &suggestions, string temp = "") {
    // no need to return since there can be more words further
    if(root->isTerminal) suggestions.push_back(temp);

    for(auto it:root->children) {
        char letter = it.first;
        TrieNode* child = it.second;

        temp.push_back(letter);
        addSuggestions(child, suggestions, temp);
        temp.pop_back();
    }
}

void findSuggestions(TrieNode* root, string prefix, vector<string> &suggestions) {
    // base case
    if(prefix.size() == 0) {
        addSuggestions(root, suggestions);
        return;
    }

    char letter = prefix[0];
    TrieNode* child;

    if(root->children.find(letter) != root->children.end()) child = root->children[letter];
    else return;

    findSuggestions(child, prefix.substr(1), suggestions);
}

int main()
{
    TrieNode* root = new TrieNode('-');

    root->insert(root, "heater");
    root->insert(root, "cooler");
    root->insert(root, "fan");
    root->insert(root, "fanta");
    root->insert(root, "colddrink");
    root->insert(root, "fasttrack");
    root->insert(root, "camp");

    string prefix;
    cout << "Enter Word to Search " << endl;
    cin >> prefix;

    vector<string> suggestions;

    findSuggestions(root, prefix, suggestions);

    for(const auto str:suggestions) cout << prefix + str << " ";

    if(suggestions.empty()) cout << "No Words to Suggest... Please Add more words" << endl;
    
    return 0;
}