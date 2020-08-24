class Solution {
public:
    int maxArea(vector<int>& height) {
        const int N = height.size();
        
        int answer = 0;
        int prev_p1 = -1, p1 = 0;
        int prev_p2 = -1, p2 = N - 1;
        
        while(p1 < p2 && !(prev_p1 == p1 && prev_p2 == p2)){
            //update answer
            int area = (p2 - p1) * min(height[p1], height[p2]);
            answer = max(area, answer);
            
            // use prev values to avoid cycling
            prev_p1 = p1;
            prev_p2 = p2;
            
            // move pointer with minimum height to a larger height
            if(height[p1] < height[p2]){
                for(int i = p1 + 1; i <= p2; ++i){
                    if(height[i] > height[p1]){
                        p1 = i;
                        break;
                    }
                }
            }else{
                for(int i = p2 - 1; i >= p1; --i){
                    if(height[i] > height[p2]){
                        p2 = i;
                        break;
                    }
                }
            }
        }
        
        return answer;
    }
};