class Solution {
public:
    string generate(string &word){
    
        int arr[26] = {0};
        for(char ch : word){
            arr[ch - 'a']++;
        }

        string s = "";
        for(int i = 0 ; i < 26 ; i++){
            int freq = arr[i];
            if(freq > 0){
                s += string(freq, i + 'a');
            }
        }

        return s;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(int i = 0 ; i < strs.size() ; i++){
            string word = strs[i];
            string new_word = generate(word);
            mp[new_word].push_back(strs[i]);
        }

        for(auto i : mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};
