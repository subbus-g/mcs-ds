#include <iostream>
#include <assert.h>
using namespace std;

class Vector
{
private:
	int *arr = nullptr;
	int size = 0;

public:
	Vector(int size) : size(size)
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
		for (int i = 0; i < size;i++)
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
		for (int i = 0; i < size;i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~Vector()
	{
		delete[] arr;
		arr = nullptr; // resetting
	}
};
int main()
{
	//comment these 2 lines for console I/O rather than file I/O
	freopen("..\\00-in.txt", "r", stdin);
	freopen("..\\00-out.txt", "w", stdout);

	Vector v(10);
	for (int i = 0; i < 10;i++)
	{
		v.set(i, i);
	}
	v.print();
	cout << v.find(5) << " " << v.find(55);

	return 0;
}
