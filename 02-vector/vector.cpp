#include <iostream>
#include <assert.h>
using namespace std;

class Vector
{
private:
	int *arr = nullptr;
	int size = 0;
	int capacity = 0;

public:
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
	// takes O(size) space and time for 1 push back operation
	void push_back(int value)
	{
		if (size < capacity)
		{
			arr[size] = value;
			size++;
			return;
		}
		cout << "new memory allocatied"
			 << "size:" << size<<"  capacity:"<<capacity<<endl;
		capacity = 2 * size;
		int *temp = arr;
		arr = new int[capacity];
		for (int i = 0; i < size;i++)
		{
			arr[i] = temp[i];
		}
		arr[size] = value;
		size++;
		delete[] temp;
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

	Vector v(1);
	v.set(0,0);
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
	}
	v.print();
	v.push_back(100);
	v.print();
	return 0;
}
