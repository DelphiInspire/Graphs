//#include "Graph.h"
#include "Graph_ver2.h"


Graph_link buildGraph(std::string startNode)
{
	return Graph_link(startNode);
}

int main()
{
	/*Node* A = new Node("A");
	Node* B = new Node("B");
	Node* C = new Node("C");
	Node* D = new Node("D");
	Node* E = new Node("E");
	Node* F = new Node("F");

	Graph test(B);
	test = buildGraph(A);
	test.makeConnection(B, A, 1);
	test.makeConnection(B, A, 1);
	test.makeConnection(B, C, 3);
	test.makeConnection(C, D, 4);
	test.makeConnection(A, E, 5);
	test.makeConnection(E, F, 6);

	Graph test2(test);
	test.~Graph();*/

	Graph_link test("A");
	test.newConnection("A", "B");
	test.newConnection("A", "C");
	test.newConnection("C", "B");
	Graph_link test2(test);
	test.~Graph_link();

	return 0;
}
