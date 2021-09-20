#include <string>
#include <vector>

class Node
{
private:
	std::string name;
	Node* next;
public:
	Node(std::string name) : name{ name }, next{nullptr} {};
	std::string getName() const { return name; };
	Node* getNext() { return next; };
	void setNext(Node* nextNode) { next = nextNode; };
	~Node() 
	{ 
		name.clear(); 
	};
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
	void cleanConnections()
	{	
		while (head != nullptr)
		{
			Node* connectDestroyer{ head->getNext() };
			delete head;
			head = connectDestroyer;
		} 
	}
public:
	LinkedList(std::string name) : head{ nullptr }, tail{nullptr}
	{
		addNode(name);
	};

	LinkedList& operator=(const LinkedList& copyList)
	{
		if (this != &copyList)
		{
			head = nullptr;
			tail = nullptr;
			
			addNode(copyList.head->getName());
			Node* copyNode{ copyList.head->getNext() };
			while (copyNode != nullptr)
			{
				addNode(copyNode->getName());
				copyNode = copyNode->getNext();
			}
		}
		return *this;
	}

	LinkedList(const LinkedList& copyList)
	{
		*this = copyList;
	}

	Node* getHead() { return head; };

	void addNode(std::string name)
	{
		Node* bufferNode{ new Node(name) };
		bufferNode->setNext(nullptr);

		if (head == nullptr)
		{
			head = bufferNode;
			tail = bufferNode;
		}
		else
		{
			tail->setNext(bufferNode);
			tail = tail->getNext();
		}
	}

	bool hasEqual(std::string comparisonMember)
	{
		Node* member;
		member = head;
		while (member->getNext() != nullptr)
		{
			if (member->getName() == comparisonMember)
			{
				return true;
			}
			member = member->getNext();
		}
		return false;
	}

	~LinkedList() 
	{
		cleanConnections();
	};

};

class Graph_link
{
private:
	std::vector<LinkedList*>* collector;
	bool isExist(std::string name) const;
	LinkedList* getNodeCommunity(std::string name);
	void copyData(const Graph_link& copyGraph);
	void cleanData();
public:
	Graph_link(std::string initialNode);
	Graph_link(const Graph_link& copyGraph);
	Graph_link(Graph_link&& moveGraph);
	Graph_link& operator=(const Graph_link& copyGraph);
	Graph_link& operator=(Graph_link&& moveGraph);
	void newConnection(std::string parentName, std::string childName);
	~Graph_link();
};

