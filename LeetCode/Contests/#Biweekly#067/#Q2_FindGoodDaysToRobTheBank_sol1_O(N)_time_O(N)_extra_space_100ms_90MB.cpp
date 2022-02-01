class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        const int N = security.size();
        
        vector<int> leftDec(N, 1);
        for(int i = 1; i < N; ++i){
            if(security[i - 1] >= security[i]){
                leftDec[i] = leftDec[i - 1] + 1;
            }
        }
        
        vector<int> rightDec(N, 1);
        for(int i = N - 2; i >= 0; --i){
            if(security[i] <= security[i + 1]){
                rightDec[i] = 1 + rightDec[i + 1];
            }
        }
        
        vector<int> answer;
        for(int i = time; i + time < N; ++i){
            if(leftDec[i] >= time + 1 && rightDec[i] >= time + 1){
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};