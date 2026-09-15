class Solution {
public:

    int binarySearch(vector<int>& nums, int target, int s, int e){
        int mid = s + (e - s) / 2;
        if(s > e){
            return -1;
        }

        if(nums[mid] == target){
            return mid;
        }

        if(nums[mid] < target){
            return binarySearch(nums, target, mid + 1, e);
        }
        else if(nums[mid] > target){
            return binarySearch(nums, target, s, mid - 1);
        }

    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        
        return binarySearch(nums, target, s, e);
    }
};
