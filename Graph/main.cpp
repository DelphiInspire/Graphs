#include "Graph_ver2.h"

int main()
{
	Graph* A = new Graph("A");
	Graph* B = new Graph(*A);
	delete A;
	Graph* C = new Graph("C");
	*C = *B;
	A = new Graph("P");
	*A = std::move(*C);
	A->addConnection("A", "K");
	A->deleteConnection("K");
	delete A;
	delete B;
	delete C;
	return 0;
}
