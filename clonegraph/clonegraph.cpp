// Copyright (C) 2013 Leslie Zhai <xiangzhai83@gmail.com>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

template<typename T> class graph_node;

typedef graph_node<int> Node;
typedef std::unordered_map<Node*, Node*> Map;
typedef std::unordered_map<Node*, Node*>::iterator MapIter;

template<typename T> class graph_node 
{
public:
    graph_node() {}
    graph_node(T data) :m_data(data) {}
    ~graph_node() {}

public:
    std::vector<graph_node<T>*> neighbors;
    T get_data() { return m_data; }

private:
    T m_data;
};

static Node* graphCopy = NULL;
static Map map;

static void m_cleanup() 
{
    MapIter iter;
    int i;

    for (iter = map.begin(); iter != map.end(); iter++) 
    {
        for (i = 0; i < (*iter).second->neighbors.size(); i++) 
        {
            delete (*iter).second->neighbors[i];
            (*iter).second->neighbors[i] = NULL;
        }
    }

    if (graphCopy) 
    {
        delete graphCopy;
        graphCopy = NULL;
    }
}

Node* clone(Node* graph) 
{
    if (!graph) 
        return NULL;
    else 
        std::cout << "DEBUG: origin graph node " << graph->get_data() << std::endl;
 
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
            std::cout << "DEBUG: neighbor " << neighbor->get_data() << std::endl;
            // 没有该副本
            if (map.find(neighbor) == map.end()) 
            {
                Node* p = new Node();
                std::cout << "DEBUG: new clone" << std::endl;
                map[node]->neighbors.push_back(p);
                map[neighbor] = p;
                q.push(neighbor);
            } 
            else 
            {
                // 副本已经存在
                std::cout << "DEBUG: cloned exist " << map[neighbor]->get_data() << std::endl;
                map[node]->neighbors.push_back(map[neighbor]);
            }
        }
    }
 
    return graphCopy;
}

int main(int argc, char* argv[]) 
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n3);

    clone(n1);

    m_cleanup();

    return 0;
}
