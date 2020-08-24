class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;
        for(int i = 0, j = (int)height.size() - 1; i < j;){
            int area = (j - i) * min(height[i], height[j]);
            answer = max(area, answer);
            if(height[i] < height[j]){
                ++i;
            }else{
                --j;
            }
        }
        return answer;
    }
};