class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        const int T = target.size();
        const int A = arr.size();
        
        unordered_map<int, vector<int>> posOf;
        for(int i = 0; i < T; ++i){
            posOf[target[i]] = {};
        }
        
        for(int i = 0; i < A; ++i){
            if(posOf.count(arr[i])){
                posOf[arr[i]].push_back(i);
            }
        }
        
        // Similar to LIS (longest increasing subsequence)
        //   v[i]: min position of the last element of a common subsequence of length (i + 1)
        //   v[0] < v[1] < v[2] < ... < v[i]
        vector<int> v;
        for(int i = 0; i < T; ++i){
            for(int j = (int)posOf[target[i]].size() - 1; j >= 0; --j){
                int pos = posOf[target[i]][j];
                int k = upper_bound(v.begin(), v.end(), pos) - v.begin();
                v.resize(max((int)v.size(), k + 1));
                v[k] = pos;
            }
        }
        
        return T - (int)v.size();
    }
};