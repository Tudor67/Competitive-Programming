class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0;
        
        for(int reversed = 0; reversed <= 1; ++ reversed){
            for(int i = 0, j = 1; j < height.size(); ++j){
                if(height[i] <= height[j]){
                    for(int k = i + 1; k < j; ++k){
                        answer += (height[i] - height[k]);
                        height[k] = height[i];
                    }
                    i = j;
                }
            }
            reverse(height.begin(), height.end());
        }
        
        return answer;
    }
};