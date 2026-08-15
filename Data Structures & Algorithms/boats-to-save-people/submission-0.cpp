class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int i = 0;
        int j = n - 1;
        int count = 0;
        while(i <= j){
            int rem = limit - people[j];
            j--;
            count++;
            if(i <= j && rem >= people[i]){
                i++;
            }
        }
        return count;
    }
};