class Solution {
private:
    vector<pair<int, int>> memo;
    
    void initMemo(const int& SIZE, const pair<int, int>& VAL){
        memo.resize(SIZE);
        fill(memo.begin(), memo.end(), VAL);
    }
    
    pair<int, int> minPersonsTime(vector<int>& jobs, int jobsMask, const int& TIME_LIMIT){
        // return the minimum {`personsNum`, `time`} to complete all jobs from `jobsMask` in a `time` <= `TIME_LIMIT`
        if(memo[jobsMask] == pair<int, int>{INT_MAX, INT_MAX}){
            if(jobsMask == 0){
                memo[jobsMask] = {1, 0};
            }else{
                pair<int, int> answer = {INT_MAX, INT_MAX};
                for(int bit = 0; bit < jobs.size(); ++bit){
                    if((jobsMask >> bit) & 1){
                        pair<int, int> submaskAnswer = minPersonsTime(jobs, jobsMask ^ (1 << bit), TIME_LIMIT);
                        int submaskPersons = submaskAnswer.first;
                        int submaskTime = submaskAnswer.second;
                        bool newPersonNeeded = (submaskTime + jobs[bit] > TIME_LIMIT);
                        answer = min(pair<int, int>{submaskPersons + newPersonNeeded, submaskTime * !newPersonNeeded + jobs[bit]}, answer);
                    }
                }
                memo[jobsMask] = answer;
            }
        }
        return memo[jobsMask];
    }
    
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        const int N = jobs.size();
        const int FULL_JOBS_MASK = (1 << N) - 1;
        const int MIN_POSSIBLE_TIME = *max_element(jobs.begin(), jobs.end());
        const int MAX_POSSIBLE_TIME = accumulate(jobs.begin(), jobs.end(), 0);
        int l = MIN_POSSIBLE_TIME;
        int r = MAX_POSSIBLE_TIME;
        while(l != r){
            int mid = (l + r) / 2;
            initMemo(FULL_JOBS_MASK + 1, {INT_MAX, INT_MAX});
            if(minPersonsTime(jobs, FULL_JOBS_MASK, mid).first <= k){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};