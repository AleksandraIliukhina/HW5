#ifndef BETTER_PRIORITY_QUEUE_H
#define BETTER_PRIORITY_QUEUE_H

#include "Graph.h"
#include <queue>
#include <vector>
#include <climits>
#include <string>

// A BPQNode represents one graph node inside the priority queue.
struct BPQNode{
    // A priority of this node. INT_MAX means that we do not yet know a path to this node.
    int pri = INT_MAX;

    bool visited = false;

    // Key of the corresponding graph node. INVALID_NODE_KEY means that no valid key has been assigned yet.
    nodekey_t gnode = INVALID_NODE_KEY;

    bool operator<(const BPQNode& other) const{
        return pri < other.pri;
    }

    bool operator>(const BPQNode& other) const{
        return pri > other.pri;
    }

    bool operator==(const BPQNode& other) const{
        return gnode == other.gnode;
    }
};

// Inherit from the standard priority_queue. The template arguments specify:
// The type of each element: BPQNode
// The internal container: vector<BPQNode>
// The comparison rule: greater<BPQNode>
// Using greater<BPQNode> makes the smallest priority appear at top()
class BetterPriorityQueue :
    public priority_queue<BPQNode, vector<BPQNode>, greater<BPQNode>> {
public:
    // Returns true if a node with the same gnode is in the queue.
    bool Contains(BPQNode node) const;

    // Finds an existing node and updates its information. Returns true if an existing entry was changed.
    bool Update(BPQNode node);

    // Returns a readable representation of the queue.
    string ToString() const;

    // Converts one BPQNode into a readable string.
    static string BPQNodeToString(BPQNode node);
};

#endif