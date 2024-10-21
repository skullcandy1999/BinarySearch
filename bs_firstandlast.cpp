#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findPosition(nums, target, true), findPosition(nums, target, false)};
    }

private:
    int findPosition(vector<int>& nums, int target, bool findFirst) {
        int lo = 0, hi = nums.size() - 1, position = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                position = mid;
                if (findFirst) hi = mid - 1; // Search left half
                else lo = mid + 1; // Search right half
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return position;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = solution.searchRange(nums, target);
    
    cout << "First and last position of " << target << ": [" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
//Time complexity -O(log  n)
//Space complexity -O(1)