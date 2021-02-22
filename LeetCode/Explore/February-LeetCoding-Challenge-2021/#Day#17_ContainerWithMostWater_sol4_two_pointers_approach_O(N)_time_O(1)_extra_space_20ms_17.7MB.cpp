class Solution {
public:
    int maxArea(vector<int>& heights) {
        int answer = 0;
        int i = 0;
        int j = (int)heights.size() - 1;
        while(i < j){
            int w = j - i;
            int h = min(heights[i], heights[j]);
            answer = max(w * h, answer);
            if(heights[i] <= heights[j]){
                i += 1;
            }else{
                j -= 1;
            }
        }
        return answer;
    }
};