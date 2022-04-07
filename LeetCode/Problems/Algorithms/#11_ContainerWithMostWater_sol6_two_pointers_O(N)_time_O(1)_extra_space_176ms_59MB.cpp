class Solution {
public:
    int maxArea(vector<int>& height) {
        const int N = height.size();
        
        int res = 0;
        int i = 0;
        int j = N - 1;
        while(i < j){
            int area = min(height[i], height[j]) * (j - i);
            res = max(res, area);
            if(height[i] <= height[j]){
                ++i;
            }else{
                --j;
            }
        }
        
        return res;
    }
};