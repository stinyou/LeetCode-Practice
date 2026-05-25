#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int leftIndex = 0;
		int rightIndex = s.size()-1;
		while (rightIndex > leftIndex) {
			char leftChar = s[leftIndex];
			if (
                !(leftChar >= 48 && leftChar <= 57) &&
				!(leftChar >= 65 && leftChar <= 90) &&
				!(leftChar >= 97 && leftChar <= 122)
			) {
				leftIndex++;
				continue;
			}
			char rightChar = s[rightIndex];
			if (
                !(rightChar >= 48 && rightChar <= 57) &&
				!(rightChar >= 65 && rightChar <= 90) &&
				!(rightChar >= 97 && rightChar <= 122)
			) {
				rightIndex--;
                continue;
            }
            if (tolower(leftChar) != tolower(rightChar)) {
                return false;
            }
            leftIndex++;
            rightIndex--;
        }
        return true;
    }
};

int main(void) {
    return 0;
}