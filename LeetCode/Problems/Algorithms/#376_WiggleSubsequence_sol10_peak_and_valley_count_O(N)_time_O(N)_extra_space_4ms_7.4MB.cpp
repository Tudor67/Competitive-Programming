class Solution {
private:
    bool isPeak(vector<int>& v, int i){
        bool validLeft = (i == 0 || v[i - 1] < v[i]);
        bool validRight = (i == (int)v.size() - 1 || v[i] > v[i + 1]);
        return (validLeft && validRight);
    }
    
    bool isValley(vector<int>& v, int i){
        bool validLeft = (i == 0 || v[i - 1] > v[i]);
        bool validRight = (i == (int)v.size() - 1 || v[i] < v[i + 1]);
        return (validLeft && validRight);
    }
    
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> v = nums;
        v.resize(unique(v.begin(), v.end()) - v.begin());
        
        const int U = v.size();
        int maxLen = 0;
        for(int i = 0; i < U; ++i){
            if(isPeak(v, i) || isValley(v, i)){
                maxLen += 1;
            }
        }
        
        return maxLen;
    }
};