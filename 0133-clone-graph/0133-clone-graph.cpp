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
    unordered_map <Node*, Node*> mp;
    
    void dfs(Node* cur){
        Node* copy = new Node(cur->val);
        mp[cur] = copy;
        for(auto it : cur->neighbors){
            if(mp.find(it) != mp.end()){
                copy->neighbors.push_back(mp[it]);
            }
            else{
                dfs(it);
                copy->neighbors.push_back(mp[it]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        dfs(node);
        return mp[node];
    }
};