#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
	std::string str = "Hello world!!";

	// count elemtns and put them to the map
	std::map<char, int> elsMap;
	for (size_t i = 0; i < str.size(); i++)
	{
		elsMap[str[i]]++;
	};

	// put them into the vector to sort
	std::vector<std::pair<char, int>> elsVector(elsMap.begin(), elsMap.end());

	// create a function to sort vector items
	auto cb = [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
		return a.second > b.second;
		};

	// sort the vector
	std::sort(elsVector.begin(), elsVector.end(), cb);

	// print result
	for (const std::pair<char, int>& item : elsVector)
	{
		std::cout << item.first << " : " << item.second << std::endl;
	}

	return EXIT_SUCCESS;
}