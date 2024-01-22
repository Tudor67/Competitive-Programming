class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        const int N = arr.size();

        unordered_map<int, int> freq;
        for(int elem: arr){
            freq[elem] += 1;
        }

        unordered_set<int> vis;
        for(const pair<const int, int>& P: freq){
            int elemFreq = P.second;
            if(vis.count(elemFreq)){
                return false;
            }
            vis.insert(elemFreq);
        }

        return true;
    }
};