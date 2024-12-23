#include <iostream>
using namespace std;
template <typename T>
class Vector
{
	T* data;
	int capacity;
	int size;
public:
	Vector(int cap)
	{
		if (cap <= 0)
		{
			cout << "capacity is invalid\n";
		}
		else
		{
			capacity = cap;
			size = 0;
			data = new T[capacity];
		}
	}
	Vector(const Vector& ref)
	{
		capacity = ref.capacity;
		size = ref.size;
		data = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			data[i] = ref.data[i];
		}
	}
	void resize(int newCap)
	{
		T* temp = new T[newCap];
		int smallerCap = (capacity < newCap)?capacity : newCap;
		for (int i = 0; i < smallerCap; i++)
		{
			temp[i] = data[i];
		}
		delete[]data;
		data = temp;
		capacity = newCap;
		temp = nullptr;
	}
	void insert(int index, const T& value)
	{
		if (index > size)
		{
			cout << "out of bounds\n";
			return;
		}
		if (size == capacity)
		{
			cout << "resized\n";
			resize(2 * capacity);
		}
		for (int i = size; i > index; i--)
		{
			data[i] = data[i - 1];
		}
		data[index] = value;
		size++;
	}
	void pushBack(const T& value)
	{
		if (size == capacity)
		{
			resize(2 * capacity);
		}
		data[size++] = value;
	}
	void print()const
	{
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << '\n';
	}
};
int main()
{
	Vector<int>vec{ 3 };
	vec.insert(1, 1);
	//vec.insert(1, 2);
	//vec.insert(2, 3);
	vec.print();
}