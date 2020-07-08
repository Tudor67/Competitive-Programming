class Solution {
public:
    int arrangeCoins(int n) {
        int answer = 0;
        while(1LL * answer * (answer + 1) / 2 <= n){
            answer += 1;
        }
        return answer - 1;
    }
};