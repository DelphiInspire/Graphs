#include "Graph_ver2.h"


Graph buildGraph(std::string startNode)
{
	Graph res(startNode);
	return res;
}

int main()
{
	Graph test("A");
	test.addConnection("A", "B");
	test.addConnection("A", "C");
	test.addConnection("C", "B");
	Graph test2(test);
	Graph test3 = (buildGraph("A"));
	test.~Graph();

	return 0;
}
