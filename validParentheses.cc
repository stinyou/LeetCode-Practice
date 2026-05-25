// INCORRECT FIRST ATTEMPT, fails for strings like '(()())'

// #include <string>
// using namespace std;

// class Solution {
// public:
//     bool isValid(string s) {
//         if (s.length() <= 0) return true;
//         char head = s[0];
//         if (head == '{') {
//             for (int i = 1; i < s.length(); i++) {
//                 if (s[i] == '}') {
//                     return (isValid(s.substr(1, i-1)) && isValid(s.substr(i+1)));
//                 }
//             }
//         } else if (head == '[') {
//             for (int i = 1; i < s.length(); i++) {
//                 if (s[i] == ']') {
//                     return (isValid(s.substr(1, i-1)) && isValid(s.substr(i+1)));
//                 }
//             }
//         } else if (head == '(') {
//             for (int i = 1; i < s.length(); i++) {
//                 if (s[i] == ')') {
//                     return (isValid(s.substr(1, i-1)) && isValid(s.substr(i+1)));
//                 }
//             }
//         } else {
//             return false;
//         }
//         return false;
//     }
// };

// TRY USING STACK ADT
#include <string>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> braces{};
        for (int i = 0; i < s.length(); i++) {
            char curChar = s[i];
            if (curChar == '(' || curChar == '[' || curChar == '{') {
                braces.push(curChar);
            } else if (curChar == ')' || curChar == ']' || curChar == '}') {
                if (braces.empty()) return false;
                if (!(
                    curChar == ')' && braces.top() == '(' || 
                    curChar == ']' && braces.top() == '[' ||
                    curChar == '}' && braces.top() == '{'
                )) return false;
                braces.pop();
            } else {
                assert(0);
            }
        }
        if (braces.empty()) return true;
        return false;
    }
};

int main(void) {
    return 0;
}