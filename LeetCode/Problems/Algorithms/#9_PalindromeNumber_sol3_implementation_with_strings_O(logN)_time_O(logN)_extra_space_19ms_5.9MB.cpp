class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        string xStr = to_string(x);
        return equal(xStr.begin(), xStr.end(), xStr.rbegin());
    }
};