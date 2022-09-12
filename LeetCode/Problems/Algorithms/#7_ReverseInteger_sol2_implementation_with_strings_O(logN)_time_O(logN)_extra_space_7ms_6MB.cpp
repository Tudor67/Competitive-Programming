class Solution {
public:
    int reverse(int x) {
        // Case 1: special case
        if(x == INT_MIN){
            return 0;
        }
        
        // Case 2: reverse the absolute value of x (using strings)
        int sign = (x < 0 ? -1 : 1);
        int xAbs = (x < 0 ? -x : x);
        string xAbsStr = to_string(xAbs);
        string xAbsRevStr(xAbsStr.rbegin(), xAbsStr.rend());
        
        string intMaxStr = to_string(INT_MAX);
        if(xAbsRevStr.length() == intMaxStr.length() && xAbsRevStr > intMaxStr){
            return 0;
        }
        return sign * stoi(xAbsRevStr);
    }
};