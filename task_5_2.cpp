#include <iostream>
#include <utility>


template <typename T>
class Table
{
private:
	int cols{};
	int rows{};
	T** table;

public:
	Table(int a, int b) {
		cols = a;
		rows = b;
		table = new T* [rows];
		for (int i = 0; i < rows; i++)
		{
			table[i] = new T[cols] {};
		}
	};

	~Table()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] table[i];
		}
		delete[] table;
	};

	T* operator[](int a)
	{
		return table[a];
	};

	const T* operator[](int a) const
	{
		return table[a];
	};

	std::pair<int, int> Size() const {
		return { rows, cols };
	};
};


int main()
{
	auto test = Table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0];

	return EXIT_SUCCESS;
};
