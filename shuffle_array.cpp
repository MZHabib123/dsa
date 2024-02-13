#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> num1, num2, num3;

        // Fill num1 and num2
        for (int i = 0; i < n ; i++) {
            num1.push_back(nums[i]);
        }
        for (int i = n ; i < 2*n; i++) {
            num2.push_back(nums[i]);
        }

        // Shuffle and merge num1 and num2 into num3
        for (int i = 0; i < n ; i++) {
            num3.push_back(num1[i]);
            num3.push_back(num2[i]);
        }

        return num3;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int n = 3;
    vector<int> result = sol.shuffle(nums, n);

    for (int i = 0; i < 2 * n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
