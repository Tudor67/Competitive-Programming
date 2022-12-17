class Solution {
private:
    int computeVal(const string& S){
        int val = 0;
        for(char c: S){
            if(isdigit(c)){
                val = val * 10 + (c - '0');
            }else{
                return S.length();
            }
        }
        return val;
    }
    
public:
    int maximumValue(vector<string>& strs) {
        int maxVal = 0;
        for(const string& S: strs){
            maxVal = max(maxVal, computeVal(S));
        }
        return maxVal;
    }
};