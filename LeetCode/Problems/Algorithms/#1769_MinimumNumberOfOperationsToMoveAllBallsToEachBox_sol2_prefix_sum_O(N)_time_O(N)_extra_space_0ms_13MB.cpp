class Solution {
private:
    int getRangeSum(vector<int>& prefixSum, int l, int r){
        if(l > r) return 0;
        if(l == 0) return prefixSum[r];
        return prefixSum[r] - prefixSum[l - 1];
    }
    
public:
    vector<int> minOperations(string boxes) {
        const int N = boxes.size();

        vector<int> prefixSum(N);
        vector<int> prefixCount(N);
        for(int i = 0; i < N; ++i){
            if(i >= 1){
                prefixSum[i] = prefixSum[i - 1];
                prefixCount[i] = prefixCount[i - 1];
            }
            if(boxes[i] == '1'){
                prefixSum[i] += i;
                prefixCount[i] += 1;
            }
        }

        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            int leftContrib = i * getRangeSum(prefixCount, 0, i - 1) - getRangeSum(prefixSum, 0, i - 1);
            int rightContrib = getRangeSum(prefixSum, i + 1, N - 1) - i * getRangeSum(prefixCount, i + 1, N - 1);
            res[i] = leftContrib + rightContrib;
        }

        return res;
    }
};