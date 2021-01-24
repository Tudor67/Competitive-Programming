class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        vector<int> numFreq(MAX_NUM + 1, 0);
        for(int num: nums){
            numFreq[num] += 1;
        }
        
        vector<int> freq;
        for(int num = 0; num <= MAX_NUM; ++num){
            if(numFreq[num] > 0){
                freq.push_back(numFreq[num]);
            }
        }
        
        sort(freq.rbegin(), freq.rend());
        sort(quantity.rbegin(), quantity.rend());
        
        bool isPossible = false;
        do{
            int fIdx = 0;
            int sum = 0;
            bool ok = true;
            for(int q: quantity){
                sum += q;
                if(sum > freq[fIdx]){
                    sum = q;
                    fIdx += 1;
                    if(fIdx == freq.size() || sum > freq[fIdx]){
                        ok = false;
                        break;
                    }
                }
            }
            isPossible = isPossible | ok;
        }while(!isPossible && prev_permutation(quantity.begin(), quantity.end()));
        
        return isPossible;
    }
};