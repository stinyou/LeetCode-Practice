// #include <algorithm>
// #include <vector>

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int length = nums.size();
//         vector<int> sortedNums = nums;
//         std::sort(sortedNums.begin(), sortedNums.end());
//         int slowPtr = 0;
//         int fastPtr = length - 1;
//         int sum;
//         while (slowPtr < fastPtr) {
//             sum = sortedNums[slowPtr] + sortedNums[fastPtr];
//             if (sum == target) {
//                 int ptr1 = -1, ptr2 = -1;
//                 for (int i = 0; i < length; i++) {
//                     if (sortedNums[slowPtr] == nums[i] && ptr1 == -1) ptr1 = i;
//                     if (sortedNums[fastPtr] == nums[i] && ptr2 == -1 && ptr1 != i) ptr2 = i;
//                 }
//                 return vector<int>{ptr1, ptr2};
//             } else if (sum > target) {
//                 fastPtr--;
//             } else {
//                 slowPtr++;
//             }
//         }
//         return vector<int>{-1, -1};
//     }
// };

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> valueIndices{};
        int curIndex = 0;
        int length = nums.size();
        // add first value -> index to Hash Table
        valueIndices[nums[curIndex]] = curIndex;
        curIndex++;
        while (curIndex < length) {
            int curValue = nums[curIndex];
            int lookingFor = target - curValue;
            if (valueIndices.find(lookingFor) != valueIndices.end()) return {valueIndices[lookingFor], curIndex};
            valueIndices[curValue] = curIndex;
            curIndex++;
        }
        return {-1, -1};
    }
};

int main(void) {
    return 0;
}