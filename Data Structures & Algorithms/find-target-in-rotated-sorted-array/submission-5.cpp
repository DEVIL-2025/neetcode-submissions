class Solution {
public:
    int binarySearch(vector<int> &nums, int s, int e, int target){
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        while(s < e){
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
    
        int b1 = binarySearch(nums, s, cut - 1, target);
        int b2 = binarySearch(nums, cut, e, target);
        
        if(b1 == -1){
            return b2;
        }
        else{
            return b1;
        }
        
    }
};
