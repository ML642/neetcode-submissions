/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> copy_map;

   Node* cloning(Node* node){
if(!node)return nullptr;

if(copy_map.contains(node)){
	return copy_map[node];
}

Node* new_node = new Node(node->val);
copy_map[node] = new_node;

for(auto n : node->neighbors) {
	new_node->neighbors.push_back(cloning(n));
}


return new_node;
    }  

    Node* cloneGraph(Node* node) {
        return cloning(node);
    }
};
