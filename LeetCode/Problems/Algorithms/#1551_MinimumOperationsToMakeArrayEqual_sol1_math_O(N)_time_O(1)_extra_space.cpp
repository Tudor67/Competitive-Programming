class Solution {
public:
    int minOperations(int n) {
        int answer = 0;
        for(int i = 0; i < n; ++i){
            answer += abs(n - 2 * i - 1);
        }
        answer /= 2;
        return answer;
    }
};