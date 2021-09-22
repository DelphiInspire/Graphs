#include <string>
#include <vector>

class Node
{
private:
	std::string name;
	void cleanConnections()
	{
		if (connections != nullptr)
		{
			connections->clear();
			delete connections;
			connections = nullptr;
			name.clear();
		}
	}
public:
	Node(std::string name) : name{ name }, connections{nullptr} 
	{
		connections = new std::vector<Node*>;
	};

	std::vector<Node*>* connections;
	std::string getName() const { return name; };
	bool isHasConnection(std::string checkNode) const
	{
		size_t connectionsSize{ connections->size() };
		for (size_t counter = 0; counter < connectionsSize; counter++)
		{
			if (connections->at(counter)->getName() == checkNode)
			{
				return true;
			}
		}
		return false;
	}

	~Node() 
	{ 
		cleanConnections();
	};
};



class Graph
{
private:
	std::vector<Node*>* graphNodes;
	Node* getNode(std::string name) const;
	bool isExist(std::string name) const;
	void copyData(const Graph& copyGraph);
	void cleanData();
public:
	Graph(std::string initialNode);
	Graph(const Graph& copyGraph);
	Graph(Graph&& moveGraph);
	Graph& operator=(const Graph& other);
	Graph& operator=(Graph&& other);
	void addConnection(std::string parentName, std::string childName);
	~Graph();
};

