class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();

        map<int, int> f;
        for(int num: nums){
            f[num] += 1;
        }

        int totalOps = 0;
        for(const pair<const int, int>& P: f){
            int numFreq = P.second;
            if(numFreq == 1){
                return -1;
            }else if(numFreq % 3 == 0){
                totalOps += numFreq / 3;
            }else if(numFreq % 3 == 1){
                totalOps += 2 + (numFreq - 4) / 3;
            }else{
                totalOps += 1 + (numFreq - 2) / 3;
            }
        }

        return totalOps;
    }
};