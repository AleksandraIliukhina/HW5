This project implements a graph, a priority queue, and Dijkstra's algorithm in C++.

The Graph class stores nodes and directed edges. It supports adding nodes and edges, checking whether a node exists, and getting the edges connected to a node.
The BetterPriorityQueue class is a priority queue that stores graph nodes with priorities. It checks whether a node is in the queue and updates a node's priority when the new priority is smaller.
The Dijkstra class uses the graph and priority queue to find the shortest distance from a starting node to other nodes.

To compile and run the tests, use the following commands in the terminal:
make

Run the Graph tests: 
./graph-tests

Run the BetterPriorityQueue tests:
./bpq-tests

Run the Dijkstra tests:
./dijkstra-tests
