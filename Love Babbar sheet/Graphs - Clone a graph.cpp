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
            return NULL;
        map<Node*, int>vis;
        queue<Node*>q;
        q.push(node);
        vis[node]=1;
        map<Node*, Node*>m;
        
        while(!q.empty()) {
            Node* curr = q.front();
            Node* n;
            if(m.find(curr) == m.end())
            {
                n = new Node(curr->val);
                m[curr]=n;
            }
            else
                n=m[curr];
            q.pop();
            
            for(Node* nw:curr->neighbors) {
                if(vis.find(nw) == vis.end())
                {
                    q.push(nw);
                    Node* p = new Node(nw->val);
                    vis[nw]=1;
                    m[nw]=p;
                }
                n->neighbors.push_back(m[nw]);
                // m[nw]->neighbors.push_back(n);
            }
        }

        return m[node];
    }
};
