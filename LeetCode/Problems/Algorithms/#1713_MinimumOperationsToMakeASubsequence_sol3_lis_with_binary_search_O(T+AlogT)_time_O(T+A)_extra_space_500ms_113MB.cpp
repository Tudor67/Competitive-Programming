class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        const int T = target.size();
        const int A = arr.size();
        
        unordered_map<int, int> idxOf;
        for(int i = 0; i < T; ++i){
            idxOf[target[i]] = i;
        }
        
        vector<int> indices;
        for(int i = 0; i < A; ++i){
            if(idxOf.count(arr[i])){
                indices.push_back(idxOf[arr[i]]);
            }
        }
        
        vector<int> v;
        for(int elem: indices){
            int k = lower_bound(v.begin(), v.end(), elem) - v.begin();
            v.resize(max((int)v.size(), k + 1));
            v[k] = elem;
        }
        
        return T - (int)v.size();
    }
};