#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Node;

typedef std::unordered_map<Node*, Node*> Map;

class Node 
{
public:
    Node() {}
    ~Node() {}

public:
    std::vector<Node*> neighbors;
};

static Node* graphCopy;
static Map map;

static void m_cleanup(Node* clone) 
{

}

Node* clone(Node* graph) 
{
    if (!graph) 
        return NULL;
 
    std::queue<Node*> q;
    q.push(graph);
 
    graphCopy = new Node();
    map[graph] = graphCopy;
 
    while (!q.empty()) 
    {
        Node* node = q.front();
        q.pop();
        int n = node->neighbors.size();
        for (int i = 0; i < n; i++) 
        {
            Node* neighbor = node->neighbors[i];
            // 没有该副本
            if (map.find(neighbor) == map.end()) 
            {
                Node* p = new Node();
                map[node]->neighbors.push_back(p);
                map[neighbor] = p;
                q.push(neighbor);
            } 
            else 
            {
                // 副本已经存在
                map[node]->neighbors.push_back(map[neighbor]);
            }
        }
    }
 
    return graphCopy;
}

int main(int argc, char* argv[]) 
{
    return 0;
}
