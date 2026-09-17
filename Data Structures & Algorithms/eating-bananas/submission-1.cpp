class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int minTime = e;
        while(s <= e){
            int mid = s + (e - s) / 2;
            int time = 0;
            for(int i = 0 ; i < n ; i++){
                time += (piles[i] + mid - 1) / mid;
            }
            if(time <= h){
                minTime = min(mid, minTime);
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return minTime;
    }
};
