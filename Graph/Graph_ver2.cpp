#include "Graph_ver2.h"

Graph_link::Graph_link(std::string initialNode) : collector{nullptr}
{
	collector = new std::vector<LinkedList*>;
	collector->push_back(new LinkedList(initialNode));
}

Graph_link::Graph_link(const Graph_link& copyGraph)
{
	*this = copyGraph;
}

Graph_link::Graph_link(Graph_link&& moveGraph)
{
	collector = moveGraph.collector;
	moveGraph.collector = nullptr;
}

Graph_link& Graph_link::operator=(const Graph_link& copyGraph)
{
	if (this != &copyGraph)
	{
		cleanData();
		collector = new std::vector<LinkedList*>;
		copyData(copyGraph);

	}
	return *this;
}

Graph_link& Graph_link::operator=(Graph_link&& moveGraph)
{
	if (this != &moveGraph)
	{
		cleanData();
		collector = moveGraph.collector;
		moveGraph.collector = nullptr;
	}
	return *this;
}

void Graph_link::copyData(const Graph_link& copyGraph)
{
	for (size_t counter = 0; counter < copyGraph.collector->size(); counter++)
	{
		collector->push_back(new LinkedList(*copyGraph.collector->at(counter)));
	}
}

void Graph_link::newConnection(std::string parentName, std::string childName)
{
	if (getNodeCommunity(parentName) == nullptr)
	{
		if (getNodeCommunity(childName) == nullptr)
		{
			return;
		}
		else
		{
			newConnection(childName, parentName);
		}
	}
	if (!getNodeCommunity(parentName)->hasEqual(childName))
	{
		if (!isExist(childName))
		{
			collector->push_back(new LinkedList(childName));
		}
		getNodeCommunity(parentName)->addNode(childName);
		getNodeCommunity(childName)->addNode(parentName);
	}
	else
	{
		return;
	}
	
}

LinkedList* Graph_link::getNodeCommunity(std::string name)
{
	for (size_t headCounter = 0; headCounter < collector->size(); headCounter++)
	{
		if (collector->at(headCounter)->getHead()->getName() == name)
		{
			return collector->at(headCounter);
		}
	}
	return nullptr;
}

bool Graph_link::isExist(std::string name) const
{
	for (size_t counter = 0; counter < collector->size(); counter++)
	{
		Node* variantNode{ collector->at(counter)->getHead() };
		if (variantNode->getName() == name)
		{
			return true;
		}
	}
	return false;
}

void Graph_link::cleanData()
{
	if (collector != nullptr)
	{
		for (std::vector<LinkedList*>::iterator listIterator = collector->begin(); listIterator != collector->end(); listIterator++)
		{
			delete* listIterator;
		}
		collector->clear();
		delete collector;
		collector = nullptr;
	}
}

Graph_link::~Graph_link()
{
	cleanData();
}
