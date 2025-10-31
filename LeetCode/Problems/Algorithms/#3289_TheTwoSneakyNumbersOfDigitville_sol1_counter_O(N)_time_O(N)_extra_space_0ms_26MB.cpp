class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        const int N = (int)nums.size() - 2;

        vector<int> freqOf(N);
        for(int num: nums){
            freqOf[num] += 1;
        }

        vector<int> res;
        for(int num = 0; num < N; ++num){
            if(freqOf[num] == 2){
                res.push_back(num);
            }
        }
        
        return res;
    }
};