#include "Graph_ver2.h"

Graph::Graph(const std::string& initialNode) : capacity{20}
{
	graphNodes.resize(0);
	graphNodes.reserve(capacity);
	graphNodes.push_back(new Node(initialNode));
}

Graph::Graph(const Graph& other) : capacity{ other.capacity } 
{
	*this = other;
}

Graph::Graph(Graph&& other) : capacity{ other.capacity }
{

	*this = std::move(other);

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
		const size_t connectionsSize{ copyNode->connections.size() };

		for (size_t innerCounter = 0; innerCounter < connectionsSize; innerCounter++)
		{
			graphNodes.at(outCounter)->connections.push_back(getNode(copyNode->connections.at(innerCounter)->getName()));
		}
	}
}

void Graph::addConnection(const std::string& firstParticipant, const std::string& secondParticipant)
{
	if (getNode(firstParticipant) == nullptr)
	{
		if (getNode(secondParticipant) == nullptr)
		{
			return;
		}
		else
		{
			addConnection(secondParticipant, firstParticipant);
		}
	}
	if (!getNode(firstParticipant)->hasConnection(secondParticipant))
	{
		if (!isExist(secondParticipant))
		{
			graphNodes.push_back(new Node(secondParticipant));
		}
		getNode(firstParticipant)->connections.push_back(getNode(secondParticipant));
		getNode(secondParticipant)->connections.push_back(getNode(firstParticipant));
	}
	else
	{
		return;
	}
	
}

void Graph::deleteConnection(const std::string& deleteNode)
{
	Node* outNode{ getNode(deleteNode) };
	const size_t numNodeConnections{ outNode->connections.size() };
	//search Node for deleting 
	for (std::vector<Node*>::iterator mainIt = graphNodes.begin(); mainIt != graphNodes.end();)
	{
		if (*mainIt == outNode)
		{
			//go through deleting Node connections and remove this Node from neighbours connections
			for (size_t counter = 0; counter < numNodeConnections; counter++)
			{
				Node* memberNode(outNode->connections.at(counter));
				for (std::vector<Node*>::iterator memberIt = memberNode->connections.begin(); memberIt != memberNode->connections.end();)
				{
					if (*memberIt == outNode)
					{
						memberIt = memberNode->connections.erase(memberIt);
					}
					else
					{
						++memberIt;
					}
				}
			}
			mainIt = graphNodes.erase(mainIt);
		}
		else
		{
			++mainIt;
		}	
	}
	delete outNode;
}

Node* Graph::getNode(const std::string& name)
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

bool Graph::isExist(const std::string& name) const
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
	if (graphNodes.size() != 0)
	{
		for (std::vector<Node*>::iterator graphPointIterator = graphNodes.begin(); graphPointIterator != graphNodes.end(); graphPointIterator++)
		{
			delete* graphPointIterator;
		}
		graphNodes.clear();
	}
}

Graph::~Graph()
{
	cleanData();
}
