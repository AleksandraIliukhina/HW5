#include "Dijkstra.h"
#include "BetterPriorityQueue.h"
#include <map>
#include <climits>

// With this Graph implementation, getting outgoing edges scans all edges
// Contains() and Update() scan the priority queue.
// Therefore, the worst-case time complexity is O(VE + V^2), where V is the number of nodes and E is the number of edges.
int dijkstra(nodekey_t start, nodekey_t end, const Graph *g){
    if(g == nullptr || !g->IsPresent(start) || !g->IsPresent(end)){
        return -1;
    }

    BetterPriorityQueue queue;
    map<nodekey_t, int> distances;

    // Initially, all distances are infinite except the start node.
    for(nodekey_t key : g->GetNodes()){
        distances[key] = INT_MAX;
        BPQNode node;
        node.gnode = key;
        queue.push(node);
    }

    distances[start] = 0;

    BPQNode startNode;
    startNode.gnode = start;
    startNode.pri = 0;
    queue.Update(startNode);

    while(!queue.empty()){
        BPQNode current = queue.top();
        queue.pop();
        // An infinite priority means the remaining nodes are unreachable.
        if(current.pri == INT_MAX){
            break;
        }
        if(current.gnode == end){
            return current.pri;
        }

        set<const GraphEdge*> edges = g->GetOutwardEdgesFrom(current.gnode);

        for(const GraphEdge* edge : edges){
            if(edge->weight > static_cast<unsigned int>(INT_MAX - current.pri)){
                continue;
            }
            int newDistance =
                current.pri + static_cast<int>(edge->weight);
            // Update only when this path is shorter than the known one.
            if(newDistance < distances[edge->to]){
                distances[edge->to] = newDistance;
                BPQNode neighbor;
                neighbor.gnode = edge->to;
                neighbor.pri = newDistance;

                queue.Update(neighbor);
            }
        }
    }
    return INT_MAX;
}