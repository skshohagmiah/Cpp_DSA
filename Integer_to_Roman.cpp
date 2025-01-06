#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Define Roman numeral values and their symbols
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";

        // Iterate through the value-symbol pairs
        for (auto &[value, symbol] : roman) {
            // Append the symbol while the value fits into num
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }

        return result;
    }
};
