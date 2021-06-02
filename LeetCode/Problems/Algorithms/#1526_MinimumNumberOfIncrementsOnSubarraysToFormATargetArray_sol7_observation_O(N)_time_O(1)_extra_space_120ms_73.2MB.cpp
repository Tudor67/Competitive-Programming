class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        const int N = target.size();
        int answer = target[0];
        for(int i = 1; i < N; ++i){
            answer += max(0, target[i] - target[i - 1]);
        }
        return answer;
    }
};