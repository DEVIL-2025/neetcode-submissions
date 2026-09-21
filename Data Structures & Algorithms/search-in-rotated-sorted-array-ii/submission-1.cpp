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
        set<int> st(nums.begin(), nums.end());
        vector<int> ans(st.begin(), st.end());

        return binarySearch(ans, 0, ans.size() - 1, target);
    }
};