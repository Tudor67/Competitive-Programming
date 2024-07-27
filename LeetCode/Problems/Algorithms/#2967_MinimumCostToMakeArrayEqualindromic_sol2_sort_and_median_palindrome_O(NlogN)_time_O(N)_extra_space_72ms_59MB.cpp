class Solution {
private:
    long long computeCost(vector<int>& nums, int candidate){
        long long cost = 0;
        for(int num: nums){
            cost += abs(num - candidate);
        }
        return cost;
    }

    bool isPowOf10(int num){
        while(num % 10 == 0){
            num /= 10;
        }
        return (num == 1);
    }

    void mirror(string& s){
        copy(s.begin(), s.end(), s.rbegin());
    }

    int getPrevPalindrome(string& s){
        int len = s.length();
        int prefix = stoi(s.substr(0, (len + 1) / 2));

        if(isPowOf10(prefix) && len >= 2){
            return stoi(string(len - 1, '9'));
        }

        string resStr = to_string(prefix - 1);
        resStr.resize(len);
        mirror(resStr);
        return stoi(resStr);
    }

    int getNextPalindrome(string& s){
        int len = s.length();
        int prefix = stoi(s.substr(0, (len + 1) / 2));

        if(isPowOf10(prefix + 1)){
            return stoi(string(1, '1') + string(len - 1, '0') + string(1, '1'));
        }

        string resStr = to_string(prefix + 1);
        resStr.resize(len);
        mirror(resStr);
        return stoi(resStr);
    }

    void generateCandidatesFromNum(int num, set<int>& candidates){
        string s = to_string(num);
        mirror(s);
        candidates.insert(getPrevPalindrome(s));
        candidates.insert(stoi(s));
        candidates.insert(getNextPalindrome(s));
    }

public:
    long long minimumCost(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> medians = {sortedNums[(N - 1) / 2], sortedNums[N / 2]};

        set<int> candidates;
        generateCandidatesFromNum(medians.front(), candidates);
        generateCandidatesFromNum(medians.back(), candidates);

        long long minCost = 1e18;
        for(int candidate: candidates){
            minCost = min(minCost, computeCost(nums, candidate));
        }

        return minCost;
    }
};