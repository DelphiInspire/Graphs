#include <string>
#include <vector>
#include <iterator>

class Node
{
private:
	std::string name;
public:
	std::vector<Node*> connections;


public:
	Node(const std::string& name) : name{ name } 
	{
		connections.reserve(20);
		connections.resize(0);
	};
	~Node(){};

	std::string getName() const { return name; };
	bool hasConnection(const std::string& searchNode) const
	{
		const size_t connectionsSize{ connections.size() };
		for (size_t counter = 0; counter < connectionsSize; counter++)
		{
			if (connections.at(counter)->getName() == searchNode)
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

	void addConnection(const std::string& firstParticipant, const std::string& secondParticipant);
	void deleteConnection(const std::string& deleteNode);
};

