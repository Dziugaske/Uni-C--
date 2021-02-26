#include "largeInteger.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

LargeInteger::LargeInteger(int size) {
    std::vector<int> temp(size, 0);
    digits = temp;
}
LargeInteger::LargeInteger(std::string initialString) {
    setValue(initialString);
}
void LargeInteger::setValue(std::string initialString) {
    for (int i = 0; i < initialString.length(); ++i) {
        if (initialString[i] >= '0' && initialString[i] <= '9') {
            digits.push_back(initialString[i] - 48);
        } else {
            throw 1;
        }
    }
    std::reverse(digits.begin(), digits.end());
}
LargeInteger LargeInteger::operator+(const LargeInteger &n2) {
    if (digits.size() >= n2.digits.size()) {
        LargeInteger n(digits.size() + 1);
        int remainder = 0;
        for (int i = 0; i < n2.digits.size(); ++i) {
            n.digits[i] = digits[i] + n2.digits[i] + remainder;
            if (n.digits[i] / 10 == 1) {
                n.digits[i] %= 10;
                remainder = 1;
            } else {
                remainder = 0;
            }
        }
        for (int i = n2.digits.size(); i < digits.size(); ++i) {
            n.digits[i] = n.digits[i] + digits[i] + remainder;
            if (n.digits[i] / 10 == 1) {
                n.digits[i] %= 10;
                remainder = 1;
            } else {
                remainder = 0;
            }
        }
        if (n.digits[n.digits.size() - 1] == 0) {
            n.digits.pop_back();
        }
        return n;
    } else {
        LargeInteger n(n2.digits.size() + 1);
        int remainder = 0;
        for (int i = 0; i < digits.size(); ++i) {
            n.digits[i] = digits[i] + n2.digits[i] + remainder;
            if (n.digits[i] / 10 == 1) {
                n.digits[i] %= 10;
                remainder = 1;
            } else {
                remainder = 0;
            }
        }
        for (int i = digits.size(); i < n2.digits.size(); ++i) {
            n.digits[i] = n.digits[i] + n2.digits[i] + remainder;
            if (n.digits[i] / 10 == 1) {
                n.digits[i] %= 10;
                remainder = 1;
            } else {
                remainder = 0;
            }
        }
        if (n.digits[n.digits.size() - 1] == 0) {
            n.digits.pop_back();
        }
        return n;
    }
}
std::string LargeInteger::toString() {
    std::ostringstream ss;
    std::reverse(digits.begin(), digits.end());
    for (int i = 0; i < digits.size(); ++i) {
        ss << digits[i];
    }
    return ss.str();
}
