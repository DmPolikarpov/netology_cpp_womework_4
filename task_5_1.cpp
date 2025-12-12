#include <iostream>
#include <vector>


template <typename T>
T my_pow(T a)
{
	return a * a;
}

template <typename T1>
std::vector<T1> my_pow(std::vector<T1> a)
{
	std::vector<T1> newVector{};

	for (int i = 0; i < a.size(); i++)
	{
		newVector.push_back(a.at(i) * a.at(i));
	}
	return newVector;
}

template <typename T>
void printVector(std::vector<T> a)
{

	for (int i = 0; i < a.size(); i++)
	{
		std::cout << a.at(i) << "  ";
	}
	std::cout << std::endl;
}

int main()
{
	int a = my_pow(4);
	std::cout << a << std::endl;

	std::vector<int> b{ -1, 4, 8 };
	std::vector<int> c = my_pow(b);

	printVector(c);

	return EXIT_SUCCESS;
}
