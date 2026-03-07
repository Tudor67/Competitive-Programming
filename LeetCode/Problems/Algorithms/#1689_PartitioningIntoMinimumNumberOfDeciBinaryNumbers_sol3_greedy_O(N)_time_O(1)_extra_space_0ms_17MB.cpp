class Solution {
public:
    int minPartitions(string str) {
        return *max_element(str.begin(), str.end()) - '0';
    }
};