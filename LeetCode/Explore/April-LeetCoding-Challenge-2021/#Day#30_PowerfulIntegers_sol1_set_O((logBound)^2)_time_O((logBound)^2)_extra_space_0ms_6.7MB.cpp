class Solution {
private:
    vector<int> getPows(int base, int bound){
        vector<int> pows;
        if(base == 1){
            if(1 <= bound){
                pows = {1};
            }
        }else{
            for(int p = 1; p <= bound; p *= base){
                pows.push_back(p);
            }
        }
        return pows;
    }
    
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> xPows = getPows(x, bound);
        vector<int> yPows = getPows(y, bound);
        set<int> powSums;
        for(int xPow: xPows){
            for(int yPow: yPows){
                if(xPow + yPow <= bound){
                    powSums.insert(xPow + yPow);
                }
            }
        }
        vector<int> answer(powSums.begin(), powSums.end());
        return answer;
    }
};