class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = INT_MIN;
        int i = 0;
        int j = n - 1;
        while(i < j){
            int w = j - i;
            int h = min(heights[i], heights[j]);
            int area = w * h;
            maxi = max(area, maxi);
            if(heights[i] > heights[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxi;
    }
};
