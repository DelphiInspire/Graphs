#include "Graph_ver2.h"


Graph buildGraph(std::string startNode)
{
	return Graph(startNode);
}

int main()
{
	Graph test("A");
	test.addConnection("A", "B");
	test.addConnection("A", "C");
	test.addConnection("C", "B");
	Graph test2(test);
	test.~Graph();

	return 0;
}
