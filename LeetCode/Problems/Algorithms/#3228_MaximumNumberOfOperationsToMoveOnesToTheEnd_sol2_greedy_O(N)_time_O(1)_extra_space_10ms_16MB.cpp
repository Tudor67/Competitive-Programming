class Solution {
public:
    int maxOperations(string s) {
        const int N = s.length();

        int totalOps = 0;
        int prefOnes = 0;
        int i = 0;
        while(i < N){
            if(s[i] == '0'){
                totalOps += prefOnes;
                while(i < N && s[i] == '0'){
                    i += 1;
                }
            }else{
                prefOnes += 1;
                i += 1;
            }
        }

        return totalOps;
    }
};