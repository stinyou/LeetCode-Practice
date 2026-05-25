#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		int s_len = s.size();
		int t_len = t.size();
		if (s_len != t_len) return false;
		unordered_map<char, int> s_chars{};
		for (int i = 0; i < s_len; i++) {
			s_chars[s[i]]++;
		}
		for (int i = 0; i < t_len; i++) {
			char curChar = t[i];
			if (s_chars.find(curChar) != s_chars.end()) {
                if (s_chars[curChar] == 0) return false;
                s_chars[curChar]--;
            }
		    else {
                return false;
            }
        }
        // DO NOT NEED THE FOLLOWING SINCE LENGTH CHECK HELPS DETECT ALL CASES ALREADY
		// int s_chars_len = s_chars.size();
		// for (const auto& [key, value] : s_chars) {
		// 	if (value != 0) return false;
		// }
		return true;
	}
};

int main(void) {
    return 0;
}