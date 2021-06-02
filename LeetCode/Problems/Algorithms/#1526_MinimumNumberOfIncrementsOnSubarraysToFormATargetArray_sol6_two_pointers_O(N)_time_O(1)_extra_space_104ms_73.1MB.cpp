class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        const int N = target.size();
        int answer = 0;
        int i = 0;
        int j = 0;
        while(i < N){
            j = i;
            while(j + 1 < N && target[j] >= target[j + 1]){
                j += 1;
            }
            if(i == 0){
                answer += target[i];
            }else{
                answer += target[i] - target[i - 1];
            }
            i = j + 1;
        }
        return answer;
    }
};