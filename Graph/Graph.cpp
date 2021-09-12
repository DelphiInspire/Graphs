#include "Graph.h"

Graph::Graph(Node* startNode)
{
	collector = new std::vector<std::pair<Node*, std::vector<Edge*>*>>;
	collector->push_back(std::make_pair(startNode, new std::vector<Edge*>));
}

Graph::Graph(const Graph& copyGraph)
{
	collector = new std::vector<std::pair<Node*, std::vector<Edge*>*>>;
	copyData(&copyGraph);
}

Graph::Graph(Graph&& moveGraph)
{
	collector = moveGraph.collector;
	moveGraph.collector = nullptr;
}

Graph& Graph::operator=(const Graph& copyGraph)
{
	if (this != &copyGraph)
	{
		cleanData();
		copyData(&copyGraph);
	}
	return *this;
}

Graph& Graph::operator=(Graph&& moveGraph)
{
	if (this != &moveGraph)
	{
		cleanData();
		collector = moveGraph.collector;
		moveGraph.collector = nullptr;
	}
	return *this;
}



void Graph::copyData(const Graph* const copyGraph)
{
	for (std::vector<std::pair<Node*, std::vector<Edge*>*>>::iterator it = copyGraph->collector->begin();
		it != copyGraph->collector->end(); it++)
	{
		collector->push_back(std::make_pair(it->first, new std::vector<Edge*>(*it->second)));
	}
}

void Graph::makeConnection(Node* parentNode, Node* childNode, int weight)
{
	if (getNode(childNode).first == nullptr)
	{           
		collector->push_back(std::make_pair(childNode, new std::vector<Edge*>));
		getNode(parentNode).second->push_back(new Edge(childNode, weight));
		getNode(childNode).second->push_back(new Edge(parentNode, weight));

	}
	else
	{
		getNode(parentNode).second->push_back(new Edge(childNode, weight));
		getNode(childNode).second->push_back(new Edge(parentNode, weight));
	}
}

void Graph::outNodeEdges(Node* showMember)
{
	std::cout << "Owner: " << showMember->getName() << "has connection`s: ";
	std::vector<Edge*>* buffer;
	buffer = getNode(showMember).second;
	if (buffer != nullptr)
	{
		for (std::vector<Edge*>::iterator it = buffer->begin(); it != buffer->end(); it++)
		{
			std::cout << static_cast<Edge*>(*it)->getChild()->getName() << " ";
		}
	}
	std::cout << std::endl;
}

void Graph::outAllEdges()
{
	if (collector != nullptr)
	{
		for (size_t out_counter = 0; out_counter < collector->size(); out_counter++)
		{
			std::cout << "Owner  " << collector->at(out_counter).first->getName() << ":" << "  ";
			for (size_t inner_counter = 0; inner_counter < collector->at(out_counter).second->size(); inner_counter++)
			{
				std::cout << collector->at(out_counter).second->at(inner_counter)->getChild()->getName() << " with weight " << 
				collector->at(out_counter).second->at(inner_counter)->getWeight() << " ; ";
			}
			std::cout << std::endl;
		}
	}
	
}

std::pair<Node*, std::vector<Edge*>*> Graph::getNode(Node* searchNode)
{
	if (collector != nullptr)
	{
		for (std::vector<std::pair<Node*, std::vector<Edge*>*>>::iterator it = collector->begin(); it != collector->end(); it++)
		{
			if (it->first == searchNode)
			{
				return *it;
			}
		}
	}
	return std::make_pair(nullptr, nullptr);
}

void Graph::cleanData()
{
	for (std::vector<std::pair<Node*, std::vector<Edge*>*>>::iterator outIt = collector->begin(); outIt != collector->end(); outIt++)
	{
		outIt->second->clear();
		delete outIt->second;
	}
	collector->clear();
	delete collector;
}

Graph::~Graph()
{
	if (collector != nullptr)
	{
		cleanData();
		collector = nullptr;
	}
	
}


//void Graph::removeNode(Node* removingNode)
//{
//	std::vector<Edge*>* connections{ getNode(removingNode).second };
//	for (std::vector<Edge*>::iterator it = connections->begin(); it != connections->end(); it++)
//	{
//		Edge* partner;
//		partner = *it;
//		removeNode(partner->getChild());
//		 
//
//	}
//	std::pair<Node*, std::vector<Edge*>*> buffer{ getNode(removingNode) };
//	buffer.first->~Node();
//	for (std::vector<Edge*>::iterator it = buffer.second->begin(); it != buffer.second->end(); it++)
//	{
//		Edge* cleaning{ *it };
//		getNode(cleaning->getChild()).second->
//	}
//
//}
