class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        int zeroIndex = -1;
        int zeroCount = 0;

        int ans = 1;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                zeroCount++;
                zeroIndex = i;
            }
            else{
                ans = ans * nums[i];
            }
        }

        if(zeroCount > 1){
            return res;
        }

        if(zeroCount == 1){
            res[zeroIndex] = ans;
            return res;
        }

        for(int i = 0 ; i < n ; i++){
            res[i] = ans / nums[i];
        }

        return res;
    }
};
