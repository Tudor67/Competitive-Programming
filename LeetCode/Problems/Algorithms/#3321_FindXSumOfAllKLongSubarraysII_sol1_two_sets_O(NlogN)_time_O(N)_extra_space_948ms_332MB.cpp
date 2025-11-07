class Solution {
private:
    void update(int contribSign, int num, unordered_map<int, int>& freqOf, set<pair<int, int>>& s, long long& sum){
        s.erase({freqOf[num], num});
        sum -= freqOf[num] * (long long)num;
        freqOf[num] += contribSign;
        s.insert({freqOf[num], num});
        sum += freqOf[num] * (long long)num;
    }

    void balance(set<pair<int, int>>& leftSet, long long& leftSum,
                 set<pair<int, int>>& rightSet, long long& rightSum, int x){
        if((int)rightSet.size() >= x){
            long long s = rightSet.begin()->first * (long long)rightSet.begin()->second;
            rightSum -= s;
            leftSum += s;
            leftSet.insert(*rightSet.begin());
            rightSet.erase(rightSet.begin());
        }

        if(!leftSet.empty() && (int)rightSet.size() < x){
            long long s = prev(leftSet.end())->first * (long long)prev(leftSet.end())->second;
            leftSum -= s;
            rightSum += s;
            rightSet.insert(*prev(leftSet.end()));
            leftSet.erase(prev(leftSet.end()));
        }

        if(!leftSet.empty() && leftSet.begin()->first == 0){
            leftSet.erase(leftSet.begin());
        }
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        const int N = nums.size();

        vector<long long> res;
        unordered_map<int, int> freqOf;
        set<pair<int, int>> leftSet;
        set<pair<int, int>> rightSet;
        long long leftSum = 0;
        long long rightSum = 0;

        for(int i = 0; i < N; ++i){
            if(leftSet.count({freqOf[nums[i]], nums[i]})){
                update(1, nums[i], freqOf, leftSet, leftSum);
            }else{
                update(1, nums[i], freqOf, rightSet, rightSum);
            }
            balance(leftSet, leftSum, rightSet, rightSum, x);

            if(i >= k){
                if(leftSet.count({freqOf[nums[i - k]], nums[i - k]})){
                    update(-1, nums[i - k], freqOf, leftSet, leftSum);
                }else{
                    update(-1, nums[i - k], freqOf, rightSet, rightSum);
                }
                balance(leftSet, leftSum, rightSet, rightSum, x);
            }

            if(i >= k - 1){
                res.push_back(rightSum);
            }
        }

        return res;
    }
};