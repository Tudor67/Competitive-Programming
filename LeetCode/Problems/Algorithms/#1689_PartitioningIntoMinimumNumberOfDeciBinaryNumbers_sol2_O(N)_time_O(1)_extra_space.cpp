class Solution {
public:
    int minPartitions(string s) {
        int maxDigit = *max_element(s.begin(), s.end()) - '0';
        return maxDigit;
    }
};