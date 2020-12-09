class Solution {
public:
    bool hasAlternatingBits(int N) {
        uint num = N;
        num = num + (num >> 1) + 1;
        num = num & (num - 1);
        return (num == 0);
    }
};