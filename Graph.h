#ifndef GRAPH_H
#define GRAPH_H

#include <climits>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>

using namespace std;

#define nodekey_t unsigned long long int

// This represents an invalid node key. It is the largest value that nodekey_t can store.
#define INVALID_NODE_KEY ULLONG_MAX

struct GraphEdge{
    nodekey_t from;
    nodekey_t to;
    unsigned int weight;
};

// Stores nodes and the edges between them.
class Graph{
public:
    Graph();
    ~Graph();
    void AddNode(nodekey_t key);

    // Adds a directed edge from one existing node to another.
    // The weight is 0 if the caller does not provide one.
    // Returns a pointer to the newly created edge.
    const GraphEdge* AddEdge(nodekey_t fromNodeKey, nodekey_t toNodeKey, unsigned int weight = 0);

    bool IsPresent(nodekey_t key) const;
    string NodesToString() const;
    string EdgesToString() const;
    // Returns the edges that start at the specified node.
    // These are called outward edges.
    set<const GraphEdge*> GetOutwardEdgesFrom(nodekey_t nodeKey) const;

    set<nodekey_t> GetNodes() const;

    // Returns the number of edges in the graph
    size_t Size() const;

    // Returns the number of nodes in the graph
    size_t Order() const;

private:
    // Stores node keys in the order they were added.
    vector<nodekey_t> nodes;

    // Stores pointers to dynamically allocated edges
    // The Graph class is responsible for deleting these edges.
    vector<GraphEdge*> edges;
};

#endif