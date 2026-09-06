class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int res = 0;
        for(auto op : operations){
            if(op == "+"){
                int top = s.top();
                s.pop();
                int newTop = top + s.top();
                s.push(top);
                s.push(newTop);
                res += newTop;
            }
            else if(op == "D"){
                s.push(2 * s.top());
                res += s.top();
            }
            else if(op == "C"){
                res -= s.top();
                s.pop();
            }
            else{
                s.push(stoi(op));
                res += s.top();
            }
        }
        return res;
    }
};