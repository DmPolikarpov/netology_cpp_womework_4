#include <iostream>
#include <stdexcept>

class smart_array
{
private:
	int* arr;
	int size;
	int currIndex{};

public:
	smart_array(int number)
	{
		arr = new int[number];
		size = number;
	}

	~smart_array()
	{
		delete[] arr;
	}

	void add_element(int a)
	{
		if (currIndex == size) throw std::runtime_error("The array is full!");
		arr[currIndex] = a;
		currIndex++;
	}

	int get_element(int index)
	{
		if (index >= size) throw std::runtime_error("Incorrect index!");
		return arr[index];
	}

	int* getArrPointer()
	{
		return arr;
	}

	int getSize()
	{
		return size;
	}

	int getCurrIndex()
	{
		return currIndex;
	}

	smart_array& operator = (smart_array& smartArray)
	{
		int* temp = new int[smartArray.getSize()];
		int* smArr = smartArray.getArrPointer();
		for (int i = 0; i < smartArray.getSize(); i++) {
			temp[i] = smArr[i];
		}
		delete[] arr;
		this->arr = temp;
		this->size = smartArray.getSize();
		this->currIndex = smartArray.getCurrIndex();
		return *this;
	}
};

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		std::cout << arr.get_element(1) << std::endl;

		arr = new_array;

		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
