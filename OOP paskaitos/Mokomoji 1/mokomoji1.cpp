#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class NameList {
  private:
    string initialString;
    vector<string> wordList;

  public:
    NameList(istream &is) {
        getline(is, initialString);
        findNames();
        sort(wordList.begin(), wordList.end());
    }

  private:
    void findNames() {
        int index = 0;
        while (index != (initialString.length() - 1)) {
            if (isupper(initialString[index]) && islower(initialString[index + 1])) {
                string tempString;
                tempString.push_back(initialString[index]);
                ++index;
                while (index != initialString.length() && islower(initialString[index])) {
                    tempString.push_back(initialString[index]);
                    ++index;
                }
                wordList.push_back(tempString);
            }
            ++index;
        }
    }

  public:
    string toString() {
        ostringstream ss;
        for (int i = 0; i < wordList.size(); ++i) {
            ss << wordList[i] << endl;
        }
        return ss.str();
    }
};
int main() {
    cout << "Enter a list of names.\n A name is a sequence of letters that starts with an uppercase." << endl;
    NameList list(cin);
    cout << list.toString();
}