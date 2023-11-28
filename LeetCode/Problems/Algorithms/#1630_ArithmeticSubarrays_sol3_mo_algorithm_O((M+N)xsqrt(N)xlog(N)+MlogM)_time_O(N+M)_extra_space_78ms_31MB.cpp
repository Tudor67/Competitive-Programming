class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        const int N = nums.size();
        const int M = l.size();
        const int BLOCK_SIZE = sqrt(N);

        // Mo's Algorithm        
        multiset<int> ms;
        unordered_map<int, int> freq;

        auto incFreq = [&](int diff){
            freq[diff] += 1;
        };

        auto decFreq = [&](int diff){
            unordered_map<int, int>::iterator it = freq.find(diff);
            it->second -= 1;
            if(it->second == 0){
                freq.erase(it);
            }
        };
        
        auto add = [&](int i){
            if((int)ms.size() == 1){
                incFreq(abs(*ms.begin() - nums[i]));
            }else if((int)ms.size() >= 2){
                multiset<int>::iterator it = ms.lower_bound(nums[i]);
                if(it == ms.end()){
                    incFreq(nums[i] - *prev(it));
                }else if(it == ms.begin()){
                    incFreq(*it - nums[i]);
                }else{
                    decFreq(*it - *prev(it));
                    incFreq(*it - nums[i]);
                    incFreq(nums[i] - *prev(it));
                }
            }
            ms.insert(nums[i]);
        };

        auto remove = [&](int i){
            if((int)ms.size() == 1){
                ms.clear();
                freq.clear();
            }else if((int)ms.size() >= 2){
                multiset<int>::iterator it = ms.lower_bound(nums[i]);
                if(it == ms.begin()){
                    decFreq(*next(it) - nums[i]);
                }else if(next(it) == ms.end()){
                    decFreq(*it - *prev(it));
                }else{
                    decFreq(*next(it) - nums[i]);
                    decFreq(nums[i] - *prev(it));
                    incFreq(*next(it) - *prev(it));
                }
                ms.erase(ms.find(nums[i]));
            }
        };

        auto getAnswer = [&](){
            return ((int)freq.size() == 1);
        };

        vector<int> p(M);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return pair<int, int>{l[lhs] / BLOCK_SIZE, r[lhs]} <
                        pair<int, int>{l[rhs] / BLOCK_SIZE, r[rhs]};
             });

        vector<bool> answer(M, false);
        int curL = 0;
        int curR = -1;
        for(int i: p){
            const int Q_L = l[i];
            const int Q_R = r[i];
            
            while(curR + 1 <= Q_R){
                add(curR + 1);
                curR += 1;
            }
            while(curL < Q_L){
                remove(curL);
                curL += 1;
            }
            while(Q_R < curR){
                remove(curR);
                curR -= 1;
            }
            while(Q_L <= curL - 1){
                add(curL - 1);
                curL -= 1;
            }

            answer[i] = getAnswer();
        }

        return answer;
    }
};