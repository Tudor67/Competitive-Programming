class Solution {
public:
    int minimumBoxes(int N) {
        vector<int> sum = {0}; // sum[i] = 1 + 2 + 3 + ... + i
        int prevTotalSum = 0;  // prevTotalSum = sum[1] + sum[2] + ... + sum[maxStep - 1]
        int totalSum = 0;      // totalSum = sum[1] + sum[2] + ... + sum[maxStep]
        int i = 1;
        while(totalSum < N){
            sum.push_back(sum.back() + i);
            prevTotalSum = totalSum;
            totalSum += sum.back();
            i += 1;
        }
        
        int answer = 0;
        int SUM_SIZE = sum.size();
        if(totalSum == N){
            answer = sum[SUM_SIZE - 1];
        }else{
            answer = sum[SUM_SIZE - 2] + lower_bound(sum.begin(), sum.end(), N - prevTotalSum) - sum.begin();
        }
        
        return answer;
    }
};