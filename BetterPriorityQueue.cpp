#include "BetterPriorityQueue.h"
#include <algorithm>
#include <utility>

// Checks whether the queue contains a node with the same key.
bool BetterPriorityQueue::Contains(BPQNode node) const{
    for(const BPQNode& item : this->c){
        if(item == node){
            return true;
        }
    }
    return false;
}

// Updates an existing node only when its priority decreases.
bool BetterPriorityQueue::Update(BPQNode node){
    // Find the existing node by its graph key.
    for(size_t i = 0; i < this->c.size(); ++i){
        if(this->c[i] == node){
            if(node.pri >= this->c[i].pri){
                return false;
            }
            // Save the new information in the existing entry.
            this->c[i] = node;

            // Move the node up if its priority is smaller than its parent's.
            size_t child = i;
            while (child > 0){
                size_t parent = (child - 1) / 2;
                if(this->c[parent].pri <= this->c[child].pri){
                    break;
                }
                std::swap(this->c[parent], this->c[child]);
                child = parent;
            }
            return true;
        }
    }
    return false;
}

// Converts one queue node to the text format.
string BetterPriorityQueue::BPQNodeToString(BPQNode node){
    return "(" + to_string(node.gnode) +
           ", pri: " + to_string(node.pri) + ")";
}

// Converts the queue's internal heap array to a string.
string BetterPriorityQueue::ToString() const{
    string result = "[";
    for(size_t i = 0; i < this->c.size(); ++i){
        if(i > 0){
            result += ", ";
        }
        result += BPQNodeToString(this->c[i]);
    }
    result += "]";
    return result;
}