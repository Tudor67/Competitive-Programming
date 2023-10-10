class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int N = nums.size();

        vector<int> candidates(2, INT_MAX);
        vector<int> freq(2, 0);

        for(int num: nums){
            if(candidates[0] == num){
                freq[0] += 1;
            }else if(candidates[1] == num){
                freq[1] += 1;
            }else if(freq[0] == 0){
                candidates[0] = num;
                freq[0] = 1;
            }else if(freq[1] == 0){
                candidates[1] = num;
                freq[1] = 1;
            }else{
                freq[0] -= 1;
                freq[1] -= 1;
            }
        }

        vector<int> res;
        for(int candidate: candidates){
            if(count(nums.begin(), nums.end(), candidate) > N / 3){
                res.push_back(candidate);
            }
        }

        return res;
    }
};