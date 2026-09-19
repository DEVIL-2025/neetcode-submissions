class Solution {
public:
    int findMin(vector<int> &nums) {
        int n  = nums.size();
        int s = 0;
        int e = n - 1;
        int ans = nums[s];
        while(s <= e){
            if(nums[s] < nums[e]){
                ans = min(ans, nums[s]);
                break;
            }
            int mid = s + (e - s) / 2;
            ans = min(ans, nums[mid]);

            if(nums[mid] >= nums[s]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return ans;
    }
};
