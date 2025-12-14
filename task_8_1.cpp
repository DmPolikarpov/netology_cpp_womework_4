#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> vect)
{
	std::vector<int>::iterator i = vect.begin();
	while (i != vect.end())
	{
		std::cout << *i << " ";
		i++;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vect = { 1, 1, 2, 5, 6, 1, 2, 4 };

	std::cout << "[in]:\t";
	print(vect);

	std::sort(vect.begin(), vect.end());

	auto it = std::unique(vect.begin(), vect.end());
	vect.erase(it, vect.end());

	std::cout << "[Out]:\t";
	print(vect);

	return EXIT_SUCCESS;
}