#include <iostream>
#include <algorithm>

template <typename T>
class SimpleVector
{
private:
	T* startPoint;
	int currentSize;
	int currentCapacity;

	void reSize(int newCapacity)
	{
		T* newData = new T[newCapacity];
		std::copy(startPoint, startPoint + currentSize, newData);
		delete[] startPoint;
		startPoint = newData;
		currentCapacity = newCapacity;
	}

public:
	SimpleVector(int size = 10) : startPoint(new T[size]), currentSize(0), currentCapacity(size) {}

	SimpleVector(const SimpleVector& other) : startPoint(nullptr), currentSize(other.currentSize), currentCapacity(other.currentCapacity)
	{
		this->startPoint = new T[other.currentCapacity];
		std::copy(other.startPoint, other.startPoint + other.currentSize, this->startPoint);
	}

	~SimpleVector()
	{
		// ���� �迭 �޸� ����
		delete[] startPoint;
	}

	void push_back(const T& value)
	{
		// �迭�� ���� á���� Ȯ��
		if (currentSize == currentCapacity)
		{
			int newCapacity = currentCapacity + 5;
			reSize(newCapacity);
		}

		// �迭�� �������� �� ���� �� ������ ����
		startPoint[currentSize++] = value;

		// ���Ե� �� ���
		std::cout << "push_back : " << startPoint[currentSize - 1] << std::endl;
	}

	void pop_back()
	{
		// �迭�� ���� �ִ��� Ȯ��
		if (currentSize <= 0)
		{
			return;
		}

		T deleteValue = startPoint[currentSize - 1];

		// �迭�� ũ�� ����
		--currentSize;

		// ������ �� ���
		std::cout << "pop_back : " << deleteValue << std::endl;
	}

	int size() const { return currentSize; }

	int capacity() const { return currentCapacity; }

	void sortData()
	{
		std::sort(startPoint, startPoint + currentSize);
	}
};

int main()
{
	SimpleVector<int>test;

	for (int i = 0; i < 15; ++i)
	{
		test.push_back(i);
	}

	SimpleVector<int>test2(test);

	test2.pop_back();

	std::cout << test2.size() << std::endl;
	std::cout << test2.capacity() << std::endl;
}