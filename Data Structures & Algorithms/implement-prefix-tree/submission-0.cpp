class PrefixTree {

public:
    struct TrieNode{
        TrieNode* children[26] = {};
        bool isEnd = false;
    };

    TrieNode* root;

    PrefixTree() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;

        for(char cr : word){
            if(!node->children[cr-'a']){
                node->children[cr-'a'] = new TrieNode();
                node = node->children[cr-'a'];
            }
            else{
                node = node->children[cr-'a'];
            }
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;

        for(char c: word){
            if(!node->children[c-'a']){
                return false;
            }
            else{
                node = node->children[c-'a'];
            }
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for(char cr: prefix){
            if(!node->children[cr-'a']){
                return false;
            }
            else{
                node = node->children[cr-'a'];
            }
        }

        return true;
    }
};
