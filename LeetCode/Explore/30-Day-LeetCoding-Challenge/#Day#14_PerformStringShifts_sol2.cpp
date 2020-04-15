class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.length();
        int shift_val = 0;
        for(const vector<int>& v: shift){
            shift_val += (v[0] == 0 ? -v[1] : v[1]);
        }
        
        string answer = s;
        if(shift_val > 0){
            shift_val = shift_val % n;
            answer = s.substr(n - shift_val) + s.substr(0, n - shift_val);
        }else if(shift_val < 0){
            shift_val = abs(shift_val) % n;
            answer = s.substr(shift_val) + s.substr(0, shift_val);
        }
        
        return answer;
    }
};