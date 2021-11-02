class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        string ss = s + s;
        if(ss.find(goal) != string::npos){
            return true;
        }
        return false;
    }
};