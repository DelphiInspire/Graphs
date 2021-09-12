#include <cassert>

class Vector
{
private:
	const static unsigned int supply{ 10 };
	unsigned int size;
	unsigned int capacity;
	int* data;
	using iterator = int*;
	void reserve(unsigned int newCapacity);
public:
	explicit Vector(unsigned int size = 0);
	~Vector();
	Vector(const Vector& copyVector);

	Vector& operator=(const Vector& copyVector);
	const int& operator[](unsigned int index) const;
	void resize(unsigned int newSize);

	void push_back(int newMember);
	void pop_back();
	unsigned int getSize() const { return size; };
	inline bool isLegalIndex(unsigned int index) const
	{
		if (index > size - 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	};
	iterator begin() { return &data[0]; };
	iterator end() { return &data[size]; }

};
