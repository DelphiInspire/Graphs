#include "Graph.h"
#include "Vector.h"


Graph buildGraph(Node* startNode)
{
	return Graph(startNode);
}

int main()
{
	Node* A = new Node("A");
	Node* B = new Node("B");
	Node* C = new Node("C");
	Node* D = new Node("D");
	Node* E = new Node("E");
	Node* F = new Node("F");

	Graph test(B);
	test = buildGraph(A);
	test.makeConnection(A, B, 1);
	test.makeConnection(A, C, 2);
	test.makeConnection(B, C, 3);
	test.makeConnection(C, D, 4);
	test.makeConnection(A, E, 5);
	test.makeConnection(E, F, 6);

	Graph test2(test);
	test.~Graph();
	test2.outAllEdges();

	Vector mytest;

	mytest.push_back(3);
	mytest.push_back(2);
	Vector check(mytest);

	return 0;
}
