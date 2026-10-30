#include "Graph.h"

#include <stdexcept>
#include <string>

// Creates an empty graph.
Graph::Graph(){}

// Destructor, runs automatically when a Graph object is destroyed.
// Each edge was created with new, so it must be deleted.
Graph::~Graph(){
    for(GraphEdge* edge : edges){
        delete edge;
    }
    // The vector itself cleans up its stored pointers automatically, 
    // but the pointers do not delete the objects they point to
}

// Adds a new node to the graph.
void Graph::AddNode(nodekey_t key){
    // Do not allow two nodes with the same key.
    if(IsPresent(key)){
        throw invalid_argument("Node already exists");
    }
    // Store the new node key.
    nodes.push_back(key);
}

// Adds a directed edge from fromNodeKey to toNodeKey.
const GraphEdge* Graph::AddEdge(nodekey_t fromNodeKey, nodekey_t toNodeKey, unsigned int weight){
    if(!IsPresent(fromNodeKey) || !IsPresent(toNodeKey)){
        throw invalid_argument("Node does not exist");
    }

    for (const GraphEdge* edge : edges) {
        if(edge->from == fromNodeKey &&edge->to == toNodeKey){
            throw invalid_argument("Edge already exists");
        }
    }

    // Create a new edge dynamically. Its fields are initialized with the supplied values.
    GraphEdge* edge = new GraphEdge{
        fromNodeKey,
        toNodeKey,
        weight
    };

    // Save the pointer so the graph can find and eventually delete it.
    edges.push_back(edge);

    // Return a pointer to the newly created edge.
    return edge;
}

// Checks whether a node key is present.
bool Graph::IsPresent(nodekey_t key) const{
    for(nodekey_t node : nodes){
        if(node == key){
            return true;
        }
    }
    return false;
}

// Converts the list of nodes into a readable string.
string Graph::NodesToString() const{
    string result = "[";
    for(size_t i = 0; i < nodes.size(); ++i){
        if(i > 0){
            result += ", ";
        }
        result += "(" + to_string(nodes[i]) + ")";
    }
    result += "]";
    return result;
}

// Converts all edges into a readable string.
string Graph::EdgesToString() const{
    string result = "[";
    for(size_t i = 0; i < edges.size(); ++i){
        if(i > 0){
            result += ", ";
        }
        const GraphEdge* edge = edges[i];
        // Display the start node, end node, and weight.
        result += "((" + to_string(edge->from) + ")->(" +
                  to_string(edge->to) + ") w:" +
                  to_string(edge->weight) + ")";
    }
    result += "]";
    return result;
}

// Finds all edges that start at nodeKey.
set<const GraphEdge*> Graph::GetOutwardEdgesFrom(nodekey_t nodeKey) const{
    if(!IsPresent(nodeKey)){
        throw invalid_argument("Node does not exist");
    }
    // Store pointers to the edges that start at this node.
    set<const GraphEdge*> result;

    // Examine every edge in the graph.
    for(const GraphEdge* edge : edges){
        // Keep only edges whose starting node matches nodeKey.
        if(edge->from == nodeKey){
            result.insert(edge);
        }
    }
    return result;
}

// Returns all node keys as a set.
set<nodekey_t> Graph::GetNodes() const{
    set<nodekey_t> result;
    for(nodekey_t node : nodes){
        result.insert(node);
    }
    return result;
}

// REturns the number of edges.
size_t Graph::Size() const{
    return edges.size();
}

// Returns the number of nodes.
size_t Graph::Order() const{
    return nodes.size();
}