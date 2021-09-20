
#include <string>
#include <vector>



class Node
{

public:
	Node(std::string name) : ownerName{name}{};
	std::string getName() const { return ownerName; };
	~Node() 
	{
		ownerName.clear();
	};
private:
	std::string ownerName;
};

class Edge
{
public:
	Edge(Node* target, int tripWeight) : child{ target }, weight{tripWeight} {};
	Node* getChild() const { return child; };
	int getWeight() const { return weight; };
	~Edge() { };
private:
	Node* child;
	int weight;
};


class Graph
{
private:
	std::vector<std::pair<Node*, std::vector<Edge*>*>>* collector;
	std::pair<Node*, std::vector<Edge*>*> getNode(Node* searchNode);
	void cleanData();
	void copyData(const Graph* copyGraph);
	bool isConnected(Node* inqyiryNode, std::vector<Edge*>* nodeEdges) const;
public:
	Graph(Node* startNode);
	Graph(const Graph& copyGraph);
	Graph& operator=(const Graph& copyGraph);
	Graph(Graph&& moveGraph);
	Graph& operator=(Graph&& moveGraph);
	void makeConnection(Node* parentNode, Node* childNode, int weight);
	//void outNodeEdges(Node* showMember);
	//void outAllEdges();
	~Graph();
};