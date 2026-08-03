class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            int diff = sum - k;
            count += mp[diff];
            mp[sum]++;
        }
        return count;
    }
};