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
		// 동적 배열 메모리 해제
		delete[] startPoint;
	}

	void push_back(const T& value)
	{
		// 배열이 가득 찼는지 확인
		if (currentSize == currentCapacity)
		{
			int newCapacity = currentCapacity + 5;
			reSize(newCapacity);
		}

		// 배열의 마지막에 값 대입 및 사이즈 변경
		startPoint[currentSize++] = value;

		// 대입된 값 출력
		std::cout << "push_back : " << startPoint[currentSize - 1] << std::endl;
	}

	void pop_back()
	{
		// 배열에 값이 있는지 확인
		if (currentSize <= 0)
		{
			return;
		}

		T deleteValue = startPoint[currentSize - 1];

		// 배열의 크기 감소
		--currentSize;

		// 삭제된 값 출력
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