#include "Graph.h"


Graph buildGraph(Node* startNode)
{
	return Graph(startNode);
}

std::vector<int> quickSort(std::vector<int>& sortingArray)
{
	std::vector<int> less;
	std::vector<int> greater;
	if (sortingArray.size() < 2)
	{
		return sortingArray;
	}
	else
	{
		int pivot{ sortingArray.at[0] };
		for (size_t i = 1; i < sortingArray.size(); i++)
		{
			if (sortingArray.at[i] <= pivot)
			{
				less.push_back(sortingArray.at[i]);
			}
			else
			{
				greater.push_back(sortingArray.at[i]);
			}
		}

	}
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
	/*test.makeConnection(A, B, 1);
	test.makeConnection(A, C, 2);
	test.makeConnection(B, C, 3);
	test.makeConnection(C, D, 4);
	test.makeConnection(A, E, 5);
	test.makeConnection(E, F, 6);*/

	/*Graph test2(test);
	test.~Graph();
	test.outAllEdges();*/
	return 0;
}
