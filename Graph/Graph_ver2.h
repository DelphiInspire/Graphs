#include <string>
#include <vector>

class Node
{
private:
	std::string name;

	void cleanConnections()
	{
		connections.clear();
		name.clear();
	}
public:
	std::vector<Node*> connections;

	Node(std::string name) : name{ name } 
	{
		connections.reserve(20);
		connections.resize(0);
	};
	~Node()
	{
		cleanConnections();
	};

	std::string getName() const { return name; };
	bool hasConnection(std::string checkNode) const
	{
		size_t connectionsSize{ connections.size() };
		for (size_t counter = 0; counter < connectionsSize; counter++)
		{
			if (connections.at(counter)->getName() == checkNode)
			{
				return true;
			}
		}
		return false;
	}	
};



class Graph
{
private:
	std::vector<Node*> graphNodes;

	Node* getNode(std::string name) const;
	bool isExist(std::string name) const;
	void copyData(const Graph& copyGraph);
	void cleanData();
public:
	Graph() {};
	Graph(std::string initialNode);
	~Graph();

	Graph(const Graph& copyGraph);
	Graph(Graph&& moveGraph);
	Graph& operator=(const Graph& other);
	Graph& operator=(Graph&& other);

	void addConnection(std::string parentName, std::string childName);
};

