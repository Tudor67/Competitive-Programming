class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        const int N1 = arr1.size();
        const int N2 = arr2.size();

        unordered_map<int, int> pos;
        for(int i = 0; i < N2; ++i){
            pos[arr2[i]] = i;
        }

        for(int i = 0; i < N1; ++i){
            if(!pos.count(arr1[i])){
                pos[arr1[i]] = N2;
            }
        }

        vector<int> res = arr1;
        sort(res.begin(), res.end(),
             [&](int lhs, int rhs){
                return pair<int, int>{pos[lhs], lhs} <
                       pair<int, int>{pos[rhs], rhs};
             });

        return res;
    }
};