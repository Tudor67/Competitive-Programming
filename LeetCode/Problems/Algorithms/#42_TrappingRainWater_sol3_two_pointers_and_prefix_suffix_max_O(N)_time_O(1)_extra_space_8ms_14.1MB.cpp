class Solution {
public:
    int trap(vector<int>& h) {
        if(h.empty()){
            return 0;
        }
        
        const int N = h.size();
        int totalWater = 0;
        int prefMax = h[0];
        int suffMax = h[N - 1];
        int i = 0;
        int j = N - 1;
        while(i < j){
            if(prefMax <= suffMax){
                totalWater += (prefMax - h[i]);
                i += 1;
            }else{
                totalWater += (suffMax - h[j]);
                j -= 1;
            }
            prefMax = max(prefMax, h[i]);
            suffMax = max(suffMax, h[j]);
        }
        
        return totalWater;
    }
};