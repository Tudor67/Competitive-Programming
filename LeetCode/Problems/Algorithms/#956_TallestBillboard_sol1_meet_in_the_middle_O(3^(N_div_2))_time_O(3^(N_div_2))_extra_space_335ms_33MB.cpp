class Solution {
private:
    void generateSums(int index, int endIndex, int sum1, int sum2, vector<int>& rods,
                      unordered_map<int, int>& diffToMaxSum1){
        if(index == endIndex){
            int diff = sum1 - sum2;
            diffToMaxSum1[diff] = max(diffToMaxSum1[diff], sum1);
        }else{
            generateSums(index + 1, endIndex, sum1, sum2, rods, diffToMaxSum1);
            generateSums(index + 1, endIndex, sum1 + rods[index], sum2, rods, diffToMaxSum1);
            generateSums(index + 1, endIndex, sum1, sum2 + rods[index], rods, diffToMaxSum1);
        }
    }

public:
    int tallestBillboard(vector<int>& rods) {
        const int N = rods.size();

        unordered_map<int, int> firstHalfSums;
        generateSums(0, N / 2, 0, 0, rods, firstHalfSums);

        unordered_map<int, int> secondHalfSums;
        generateSums(N / 2, N, 0, 0, rods, secondHalfSums);

        int res = 0;
        for(const pair<int, int>& P: firstHalfSums){
            int diff = P.first;
            int sum1 = P.second;
            if(secondHalfSums.count(-diff)){
                res = max(res, sum1 + secondHalfSums[-diff]);
            }
        }

        return res;
    }
};