class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        const int N = arr.size();

        map<int, int> freqOf;
        for(int num: arr){
            freqOf[num] += 1;
        }

        vector<int> f;
        for(const pair<const int, int>& P: freqOf){
            f.push_back(P.second);
        }

        sort(f.begin(), f.end());

        int res = f.size();
        for(int i = 0; i < (int)f.size(); ++i){
            if(f[i] <= k){
                res -= 1;
                k -= f[i];
            }
        }

        return res;
    }
};