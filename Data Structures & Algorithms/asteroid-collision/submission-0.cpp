class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(int i : asteroids){
            if(s.empty() || i > 0){
                s.push(i);
            }
            else{
                while(!s.empty() && s.top() > 0 && abs(i) > s.top()){
                    s.pop();
                }
                if(s.empty() || s.top() < 0){
                    s.push(i);
                }
                else if(abs(i) == s.top()){
                    s.pop();
                }
            }
        }

        vector<int> res;

        while(!s.empty()){
            int top = s.top();
            s.pop();
            res.push_back(top);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};