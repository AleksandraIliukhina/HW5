all: graph-tests bpq-tests dijkstra-tests

graph-tests:
	g++ Graph.cpp GraphTestsStarter.cpp -o graph-tests

bpq-tests:
		g++ Graph.cpp BetterPriorityQueue.cpp BPQTestsStarter.cpp -o bpq-tests

dijkstra-tests:
	g++ Graph.cpp BetterPriorityQueue.cpp Dijkstra.cpp DijkstraTestsStarter.cpp -o dijkstra-tests

clean:
	rm -f graph-tests bpq-tests dijkstra-tests