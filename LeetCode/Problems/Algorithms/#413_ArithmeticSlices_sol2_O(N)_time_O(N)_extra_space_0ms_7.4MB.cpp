class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> diffs;
        for(int i = 1; i < (int)A.size(); ++i){
            diffs.push_back(A[i] - A[i - 1]);
        }
        
        int answer = 0;
        for(int i = 1, count = 1; i < (int)diffs.size(); ++i){
            if(diffs[i] == diffs[i - 1]){
                count += 1;
            }
            if(diffs[i] != diffs[i - 1] || i + 1 == (int)diffs.size()){
                answer += (count * (count - 1) / 2);
                count = 1;
            }
        }
        
        return answer;
    }
};