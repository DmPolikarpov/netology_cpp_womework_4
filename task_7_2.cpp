#include <iostream>
#include <Windows.h>
#include <set>


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int size;

	std::cout << "¬ведите количество элементов: ";
	std::cin >> size;

	std::set<int> numbers;

	std::cout << "¬ведите " << size << " чисел:" << std::endl;
	for (int i = 0; i < size; ++i) {
		int number;
		std::cin >> number;
		numbers.insert(number);
	}

	std::cout << std::endl;

	std::cout << "”никальные числа в пор€дке убывани€:" << std::endl;
	for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
		std::cout << *it << std::endl;
	}

	return EXIT_SUCCESS;
}