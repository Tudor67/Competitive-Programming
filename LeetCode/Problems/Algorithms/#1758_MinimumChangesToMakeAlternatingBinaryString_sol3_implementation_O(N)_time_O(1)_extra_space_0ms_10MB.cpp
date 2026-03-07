class Solution {
private:
    int computeMinCost(string& s, char targetStartChar){
        int minCost = 0;
        char targetChar = targetStartChar;
        for(char c: s){
            minCost += (c ^ targetChar);
            targetChar ^= 1;
        }
        return minCost;
    }

public:
    int minOperations(string s) {
        return min(computeMinCost(s, '0'),
                   computeMinCost(s, '1'));
    }
};