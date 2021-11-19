class Solution {
public:
    int minTimeToType(string word) {
        int cost = 0;
        char prevChar = 'a';
        for(char c: word){
            cost += min(abs(c - prevChar), 26 - abs(c - prevChar));
            cost += 1;
            prevChar = c;
        }
        return cost;
    }
};