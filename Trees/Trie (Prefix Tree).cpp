#include <iostream>
#include <unordered_map>
using namespace std;

// Trie Node Structure
struct TrieNode {
    unordered_map<char, TrieNode*> children; // Child nodes map (each character points to a TrieNode)
    bool isEndOfWord; // Flag to mark the end of a word

    TrieNode() {
        isEndOfWord = false;
    }
};

// Trie Class
class Trie {
private:
    TrieNode* root;

public:
    // Constructor to initialize the Trie
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true; // Mark the end of the word
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false; // Word does not exist
            }
            currentNode = currentNode->children[ch];
        }
        return currentNode->isEndOfWord; // True if the word exists, false otherwise
    }

    // Check if there is any word starting with the given prefix
    bool startsWith(string prefix) {
        TrieNode* currentNode = root;
        for (char ch : prefix) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false; // No word with this prefix
            }
            currentNode = currentNode->children[ch];
        }
        return true; // Prefix exists
    }
};

int main() {
    Trie trie;

    int choice;
    string word;

    do {
        cout << "\nTrie Operations Menu:\n";
        cout << "1. Insert Word\n";
        cout << "2. Search Word\n";
        cout << "3. Check Prefix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter word to insert: ";
            cin >> word;
            trie.insert(word);
            cout << "Word '" << word << "' inserted into the Trie.\n";
            break;

        case 2:
            cout << "Enter word to search: ";
            cin >> word;
            if (trie.search(word)) {
                cout << "Word '" << word << "' found in the Trie.\n";
            } else {
                cout << "Word '" << word << "' not found in the Trie.\n";
            }
            break;

        case 3:
            cout << "Enter prefix to check: ";
            cin >> word;
            if (trie.startsWith(word)) {
                cout << "Prefix '" << word << "' exists in the Trie.\n";
            } else {
                cout << "Prefix '" << word << "' does not exist in the Trie.\n";
            }
            break;

        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
