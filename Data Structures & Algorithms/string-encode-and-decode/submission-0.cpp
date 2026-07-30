class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0 ; i < strs.size() ; i++){
            s += to_string(strs[i].length()) + '#' + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

            // Length of next string
            int len = stoi(s.substr(i, j - i));

            // Move after '#'
            j++;

            // Extract the string
            ans.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return ans;
    }
};
