/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<UndirectedGraphNode*,UndirectedGraphNode*> old2new;
        return cloneGraph(node,old2new);
    }
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node,map<UndirectedGraphNode*,UndirectedGraphNode*> &old2new){
        if(!node)
            return NULL;
        else if(old2new.find(node)!=old2new.end())
            return old2new[node];
        else{
            UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
            old2new[node] = newnode;
            vector<UndirectedGraphNode*> neighbors = node->neighbors;
            for(int i=0;i<neighbors.size();i++){
                newnode->neighbors.push_back(cloneGraph(neighbors[i],old2new));
            }
            return newnode;
        }
    }
};