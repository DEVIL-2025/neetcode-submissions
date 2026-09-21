class Solution {
public:
    bool binarySearch(vector<int>& nums, int s, int e, int target){
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        while(s < e){
            while(s < e && nums[s] == nums[s + 1]){
                s++;
            }
            while(s < e && nums[e] == nums[e - 1]){
                e--;
            }
            int mid = s + (e - s) / 2;
            if(nums[mid] > nums[e]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }

        int cut = s;
        s = 0;
        e = n - 1;
        bool b1 = binarySearch(nums, s, cut - 1, target);
        bool b2 = binarySearch(nums, cut, e, target);

        if(b1){
            return true;
        }
        else if(b2){
            return true;
        }
        else{
            return false;
        }
    }
};