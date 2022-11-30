class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        const int N = arr.size();
        
        unordered_map<int, int> countOf;
        for(int elem: arr){
            countOf[elem] += 1;
        }
        
        unordered_set<int> visCounts;
        for(const pair<int, int>& P: countOf){
            int elemCount = P.second;
            visCounts.insert(elemCount);
        }
        
        return (countOf.size() == visCounts.size());
    }
};