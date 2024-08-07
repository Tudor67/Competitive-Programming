class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        const int N = arr.size();

        unordered_map<int, int> freqBalance;
        for(int i = 0; i < N; ++i){
            freqBalance[target[i]] += 1;
            freqBalance[arr[i]] -= 1;
        }

        for(const pair<const int, int>& P: freqBalance){
            int balance = P.second;
            if(balance != 0){
                return false;
            }
        }

        return true;
    }
};