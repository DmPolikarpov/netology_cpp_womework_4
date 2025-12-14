#include <iostream>
#include <vector>
#include <set>
#include <list>

template <typename T>
void print_container(T container)
{
	for (auto dataIt{ container.begin() }; container.end() != dataIt; ++dataIt)
	{
		std::cout << *dataIt << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set);

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list);

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector);

	
	return EXIT_SUCCESS;
}