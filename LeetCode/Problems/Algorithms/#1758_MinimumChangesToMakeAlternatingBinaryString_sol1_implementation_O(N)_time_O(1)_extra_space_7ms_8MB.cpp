class Solution {
public:
    int minOperations(string s) {
        const int N = s.length();

        int minOps = N;
        for(char startChar: {'0', '1'}){
            int ops = 0;
            char targetChar = startChar;
            for(char c: s){
                if(c != targetChar){
                    ops += 1;
                }
                targetChar ^= 1;
            }
            minOps = min(minOps, ops);
        }

        return minOps;
    }
};