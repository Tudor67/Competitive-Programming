class Solution {
private:
    int max_area(const vector<int>& HEIGHTS, const int& H){
        int x1 = 0;
        for(int i = 0; i < HEIGHTS.size(); ++i){
            if(HEIGHTS[i] >= H){
                x1 = i;
                break;
            }
        }
        int x2 = 0;
        for(int i = (int)HEIGHTS.size() - 1; i >= 0; --i){
            if(HEIGHTS[i] >= H){
                x2 = i;
                break;
            }
        }
        return (H * max(0, x2 - x1));
    }
    
public:
    int maxArea(vector<int>& heights) {
        int answer = 0;
        int min_height = *min_element(heights.begin(), heights.end());
        int max_height = *max_element(heights.begin(), heights.end());
        for(int h = min_height; h <= max_height; ++h){
            int area = max_area(heights, h);
            answer = max(area, answer);
        }
        return answer;
    }
};