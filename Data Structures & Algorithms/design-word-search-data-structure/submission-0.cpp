class WordDictionary {
public:

    struct Node{
        Node* children[26] = {};
        bool isEnd = false;
    };

    Node* root;

    WordDictionary() {
        this->root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;

        for(char c : word){
            if(!node->children[c-'a']){
                node->children[c-'a'] = new Node();
                node = node->children[c-'a'];
            }
            else{
                node = node->children[c-'a'];
            }
        }

        node->isEnd = true; 
    }
    
     bool dfs(string& word, int index, Node* node) {
        if (index == word.size()) {
            return node->isEnd;
        }

        char c = word[index];

        if (c == '.') {
            for (Node* child : node->children) {
                if (child && dfs(word, index + 1, child)) {
                    return true;
                }
            }

            return false;
        }

        Node* next = node->children[c - 'a'];

        if (!next) {
            return false;
        }

        return dfs(word, index + 1, next);
    }


    bool search(string word) {
        return dfs(word,0,root);
    }
};
