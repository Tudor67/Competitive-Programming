class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        const int A_SUM = accumulate(a.begin(), a.end(), 0);
        const int B_SUM = accumulate(b.begin(), b.end(), 0);
        const int DIFF = A_SUM - B_SUM;
        
        sort(b.begin(), b.end());
        
        for(int aElem: a){
            auto it = lower_bound(b.begin(), b.end(), aElem - DIFF / 2);
            if(it != b.end() && *it == aElem - DIFF / 2){
                return {aElem, *it};
            }
        }
        
        return {-1, -1};
    }
};