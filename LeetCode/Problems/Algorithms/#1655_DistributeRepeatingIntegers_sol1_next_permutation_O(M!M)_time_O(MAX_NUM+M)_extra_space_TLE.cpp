class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int M = quantity.size();
        
        vector<int> count(MAX_NUM + 1, 0);
        for(int num: nums){
            count[num] += 1;
        }
        
        vector<int> freqs;
        for(int num = 0; num <= MAX_NUM; ++num){
            if(count[num] > 0){
                freqs.push_back(count[num]);
            }
        }
        
        sort(freqs.rbegin(), freqs.rend());
        
        bool isPossible = false;
        vector<int> p(M);
        iota(p.begin(), p.end(), 0);
        do{
            int i = 0;
            int sum = 0;
            for(int j = 0; j < M; ++j){
                sum += quantity[p[j]];
                if(sum > freqs[i]){
                    i += 1;
                    if(i < freqs.size() && quantity[p[j]] <= freqs[i]){
                        sum = quantity[p[j]];
                    }else{
                        break;
                    }
                }
                isPossible = isPossible || (j == M - 1);
            }
        }while(!isPossible && next_permutation(p.begin(), p.end()));
        
        return isPossible;
    }
};