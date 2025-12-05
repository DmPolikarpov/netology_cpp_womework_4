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
		if (currIndex + 1 == size) throw std::runtime_error("The array is full!");
		arr[currIndex] = a;
		currIndex++;
	}

	int get_element(int index)
	{
		if (index >= size) throw std::runtime_error("Incorrect index!");
		return arr[index];
	}
};

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
