class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int N = nums.size();
        const int K = 3;

        unordered_map<int, int> freq;
        for(int num: nums){
            freq[num] += 1;
            if((int)freq.size() == K){
                unordered_map<int, int>::iterator it = freq.begin();
                while(it != freq.end()){
                    it->second -= 1;
                    if(it->second == 0){
                        it = freq.erase(it);
                    }else{
                        it = next(it);
                    }
                }
            }
        }

        vector<int> res;
        for(const pair<int, int>& P: freq){
            int candidate = P.first;
            if(count(nums.begin(), nums.end(), candidate) > N / K){
                res.push_back(candidate);
            }
        }

        return res;
    }
};