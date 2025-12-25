#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class big_integer {
private:
    std::vector<int> digits;

public:
   
    big_integer(std::string str) {
        for (int i = str.length() - 1; i >= 0; --i) {
            digits.push_back(str[i] - '0');
        }
    };

    big_integer(big_integer&& bigInt) noexcept: digits(std::move(bigInt.digits)) {};

    
    big_integer& operator=(big_integer&& bigInt) noexcept
    {
        digits = std::move(bigInt.digits);
        return *this;
    }

    big_integer operator+(const big_integer& bigInt) const {
        big_integer result("");

        int carry = 0;
        int n = std::max(digits.size(), bigInt.digits.size());

        for (int i = 0; i < n || carry; ++i) {
            int sum = carry + (i < digits.size() ? digits[i] : 0) + (i < bigInt.digits.size() ? bigInt.digits[i] : 0);
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        return result;
    }

    big_integer operator*(int multiplier) const {
        if (multiplier == 0) return big_integer("0");

        big_integer result("");

        long long carry = 0;
        for (int i = 0; i < digits.size() || carry; ++i) {
            long long current = carry + (i < digits.size() ? digits[i] : 0) * 1LL * multiplier;
            result.digits.push_back(current % 10);
            carry = current / 10;
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& bi) {
        if (bi.digits.empty()) {
            os << "0";
        }
        else {
            for (int i = bi.digits.size() - 1; i >= 0; --i) {
                os << bi.digits[i];
            }
        }
        return os;
    }
};

int main() {
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");

    auto result = number1 + number2;

    std::cout << result;

    return 0;
}