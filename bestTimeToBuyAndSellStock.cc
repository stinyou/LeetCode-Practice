#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int length = prices.size();
        int smallestStock = prices[0];
        for (int i = 1; i < length; i++) {
            int curStock = prices[i];
            int profit = curStock - smallestStock;
            if (profit > maxProfit) maxProfit = profit;
            if (curStock < smallestStock) smallestStock = curStock;
        }
        return maxProfit;
    }
};

int main(void) {
    return 0;
}