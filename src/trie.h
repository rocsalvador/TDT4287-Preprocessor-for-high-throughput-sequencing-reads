#include <unordered_map>
#include <string>

class Trie {
private:
    struct Node {
        std::unordered_map<char, Node*> childs;
    };

    Node* root;

public:
    Trie();

    void addText(const std::string& s, Node* node);

    bool search(const std::string& s, Node* node);

    bool searchWithMissmatch(const std::string& s, int errors, int maxErrors, Node* node);

    Node* getRoot();
};