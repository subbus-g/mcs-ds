#include <iostream>
#include <assert.h>
using namespace std;

class Vector
{
private:
	int *arr = nullptr;
	int size, capacity;
	void expand_capacity()
	{
		capacity *= 2;
		int *temp = arr;
		arr = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}
		delete[] temp;
	}

public:
	Vector() : size(0), capacity(0)
	{
	}
	Vector(int size) : size(size), capacity(size)
	{

		if (size < 1)
		{
			size = 1;
		}
		arr = new int[size];
	}
	int get(int idx)
	{
		assert(idx >= 0 && idx <= size);
		return arr[idx];
	}
	void set(int idx, int val)
	{
		assert(idx >= 0 && idx <= size);
		arr[idx] = val;
	}
	int find(int value)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == value)
			{
				return i;
			}
		}
		return -1;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int get_front()
	{
		return arr[0];
	}
	int get_back()
	{
		return arr[size - 1];
	}
	// highly unoptimal approach
	// takes O(size) space but O(1) amortized time for 1 push back operation
	void push_back(int value)
	{
		// if block is executed less often now
		if (size == capacity)
		{
			expand_capacity();
		}
		arr[size++] = value;
	}
	void insert(int idx, int value)
	{
		if (size == capacity)
		{
			expand_capacity();
		}
		size++;
		// create a hole at idx
		for (int i = size - 1; i >= idx; i--)
		{
			swap(arr[i], arr[i + 1]);
		}
		// fill the hole with given value
		arr[idx] = value;
	}
	~Vector()
	{
		delete[] arr;
		arr = nullptr; // resetting
	}
};
int main()
{
	// comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	int n = 5;
	Vector v(n);
	v.set(0, 10);
	v.set(1, 8);
	v.set(2, 7);
	v.set(3, 5);
	v.set(4, 3);

	v.print();
	v.insert(2, 17);
	v.print();
	return 0;
}
