class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.length();
        int left_shift = 0;
        int right_shift = 0;
        for(vector<int> op: shift){
            if(op[0] == 0){
                left_shift += op[1];
            }else{
                right_shift += op[1];
            }
        }
        
        left_shift %= n;
        right_shift %= n;
        
        int shift_val;
        if(left_shift == right_shift){
            return s;
        }else if(left_shift < right_shift){
            shift_val = right_shift - left_shift;
            return s.substr(n - shift_val) + s.substr(0, n - shift_val);
        }else{
            shift_val = left_shift - right_shift;
            return s.substr(shift_val) + s.substr(0, shift_val);
        }
    }
};