class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        const int A_SUM = accumulate(a.begin(), a.end(), 0);
        const int B_SUM = accumulate(b.begin(), b.end(), 0);
        const int DIFF = A_SUM - B_SUM;
        
        unordered_set<int> bSet(b.begin(), b.end());
        
        for(int aElem: a){
            if(bSet.count(aElem - DIFF / 2)){
                return {aElem, aElem - DIFF / 2};
            }
        }
        
        return {-1, -1};
    }
};