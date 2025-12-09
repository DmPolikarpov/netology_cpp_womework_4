#include <iostream>
#include <vector>
#include <algorithm>

class CalcFunctor {
private:
    int sum;
    int count;
public:
 
    CalcFunctor() : sum(0), count(0) {};

    void operator()(int n) {
        if (n % 3 == 0) {
            sum += n;
            count++;
        }
    }

    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }
};

int main() {
    
    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };

    CalcFunctor calc;

    calc = std::for_each(numbers.begin(), numbers.end(), calc);

    std::cout << "get_sum(): " << calc.get_sum() << std::endl;
    std::cout << "get_count(): " << calc.get_count() << std::endl;

    return EXIT_SUCCESS;
}