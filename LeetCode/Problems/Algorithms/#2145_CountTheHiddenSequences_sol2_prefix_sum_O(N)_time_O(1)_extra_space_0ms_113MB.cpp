class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        const int N = differences.size();

        long long num = 0;
        long long minNum = 0;
        long long maxNum = 0;
        for(int i = 0; i < N; ++i){
            num += differences[i];
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }

        return max((long long)0, (upper - lower + 1) - (maxNum - minNum + 1) + 1);
    }
};