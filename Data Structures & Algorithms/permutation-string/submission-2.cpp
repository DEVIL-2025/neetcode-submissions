class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char &ch : s1){
            freq1[ch - 'a']++;
        }

        int l = 0;
        int r = 0;
        while(r < m){
            freq2[s2[r] - 'a']++;
            if(r - l + 1 > n){
                freq2[s2[l] - 'a']--;
                l++;
            }
            if(freq1 == freq2){
                return true;
            }
            r++;
        }

        return false;
    }
};
