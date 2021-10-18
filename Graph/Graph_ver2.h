#include <string>
#include <vector>
#include <iterator>

class Node
{
private:
	std::string name;
	std::vector<Node*> connections;
	const size_t capacityConnections;
public:
	Node(const std::string& name); 
	~Node(){};

	std::string getName() const { return name; };
	std::vector<Node*>& getConnections() { return connections; }

	void addConnection(Node* newConnection);

	void removeConnection(Node* deletingConnection);

	bool hasConnection(const std::string& searchNode) const;
};



class Graph
{
private:
	const size_t capacity;
	std::vector<Node*> graphNodes;
private:
	Node* getNode(const std::string& name);
	bool isExist(const std::string& name) const;
	void copyData(const Graph& copyGraph);
	void cleanData();
public:
	Graph(const std::string& initialNode);
	~Graph();

	Graph(const Graph& copyGraph);
	Graph(Graph&& moveGraph);

	Graph& operator=(const Graph& other);
	Graph& operator=(Graph&& other);

	void makeConnection(const std::string& firstParticipant, const std::string& secondParticipant);
	void deleteConnection(const std::string& deleteNode);
};

