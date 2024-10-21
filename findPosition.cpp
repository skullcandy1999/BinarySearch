#Time Complexity: O(log N)

class Solution {
public:
    vector<int> findPos(int left, int mid, int right, vector<int>& nums){
        while(left<=mid){
            if(nums[left]==nums[mid]){
                break;
            }
            else{
                left++;
            }
        }

        while(right>=mid){
            if(nums[right]==nums[mid]){
                break;
            }
            else{
                right--;
            }
        }

        return {left, right};
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target){
                return findPos(left, mid, right, nums);
            }
            if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return {-1, -1};
    }
};
