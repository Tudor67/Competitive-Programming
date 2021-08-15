class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int answer = 0;
        int prefOnes = 0;
        for(char c: s){
            if(c == '1'){
                // '1' can be appended to previous solution => answer remains the same;
                prefOnes += 1;
            }else{
                // '0' can be appended only after zeros => flip previous prefOnes => cost0 = prefOnes;
                // '0' can be flipped to '1' and appended to previous solution => cost1 = answer + 1;
                // answer is the minimum of cost0 and cost1
                answer = min(answer + 1, prefOnes);
            }
        }
        return answer;
    }
};