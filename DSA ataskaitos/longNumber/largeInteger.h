#ifndef LARGE_INTEGER
#define LARGE_INTEGER
#include <string>
#include <vector>
class LargeInteger {
  private:
    std::vector<int> digits;
    LargeInteger(int size);

  public:
    LargeInteger(std::string initialString);
    void setValue(std::string initialString);
    LargeInteger operator+(const LargeInteger &n2);
    std::string toString();
};

#endif