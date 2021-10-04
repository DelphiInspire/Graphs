#include "Graph_ver2.h"

Graph::Graph(std::string initialNode)
{
	graphNodes.resize(0);
	graphNodes.reserve(20);
	graphNodes.push_back(new Node(initialNode));
}

Graph::Graph(const Graph& other)
{
	*this = other;
}

Graph::Graph(Graph&& other)
{
	graphNodes = std::move(other.graphNodes);
}

Graph& Graph::operator=(const Graph& copyGraph)
{
	if (this != &copyGraph)
	{
		cleanData();
		copyData(copyGraph);

	}
	return *this;
}

Graph& Graph::operator=(Graph&& moveGraph)
{
	if (this != &moveGraph)
	{
		cleanData();
		graphNodes = std::move(moveGraph.graphNodes);
	}
	return *this;
}

void Graph::copyData(const Graph& copyGraph)
{
	for (size_t basePointsCounter = 0; basePointsCounter < copyGraph.graphNodes.size(); basePointsCounter++)
	{
		graphNodes.push_back(new Node(copyGraph.graphNodes.at(basePointsCounter)->getName()));
	}

	for (size_t outCounter = 0; outCounter < graphNodes.size(); outCounter++)
	{
		Node* copyNode{ copyGraph.graphNodes.at(outCounter) };
		size_t connectionsSize{ copyNode->connections.size() };

		for (size_t innerCounter = 0; innerCounter < connectionsSize; innerCounter++)
		{
			graphNodes.at(outCounter)->connections.push_back(getNode(copyNode->connections.at(innerCounter)->getName()));
		}
	}
}

void Graph::addConnection(std::string parentName, std::string childName)
{
	if (getNode(parentName) == nullptr)
	{
		if (getNode(childName) == nullptr)
		{
			return;
		}
		else
		{
			addConnection(childName, parentName);
		}
	}
	if (!getNode(parentName)->hasConnection(childName))
	{
		if (!isExist(childName))
		{
			graphNodes.push_back(new Node(childName));
		}
		getNode(parentName)->connections.push_back(getNode(childName));
		getNode(childName)->connections.push_back(getNode(parentName));
	}
	else
	{
		return;
	}
	
}

Node* Graph::getNode(std::string name) const
{
	for (size_t headCounter = 0; headCounter < graphNodes.size(); headCounter++)
	{
		if (graphNodes.at(headCounter)->getName() == name)
		{
			return graphNodes.at(headCounter);
		}
	}
	return nullptr;
}

bool Graph::isExist(std::string name) const
{
	size_t collectorSize{ graphNodes.size() };
	for (size_t counter = 0; counter < collectorSize; counter++)
	{
		if (graphNodes.at(counter)->getName() == name)
		{
			return true;
		}
	}
	return false;
}

void Graph::cleanData()
{
	
		for (std::vector<Node*>::iterator graphPointIterator = graphNodes.begin(); graphPointIterator != graphNodes.end(); graphPointIterator++)
		{
			delete* graphPointIterator;
		}
		graphNodes.clear();	
}

Graph::~Graph()
{
	cleanData();
}
