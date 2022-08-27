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
    Node* cloneGraph(Node* node) {
         if(node == NULL)
            return node;
        unordered_map<Node*, Node*> visited;
        queue<Node*> Q;
        Q.push(node);
        visited[node] = new Node(node->val);
        while(!Q.empty()){
            int n = Q.size();
            Node* curr = Q.front();
            Q.pop();
            for(auto nei: curr->neighbors){
                if(!visited[nei]){
                     visited[nei] = new Node(nei->val);
                     Q.push(nei);
                }
                visited[curr]->neighbors.push_back(visited[nei]);
            }
        }
        return visited[node];
    }
};