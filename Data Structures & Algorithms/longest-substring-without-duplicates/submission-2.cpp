class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int i = 0, j = 0;
        int maxCount = 0;

        while (j < s.length()) {

            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);
            maxCount = max(maxCount, j - i + 1);
            j++;
        }

        return maxCount;
    }
};