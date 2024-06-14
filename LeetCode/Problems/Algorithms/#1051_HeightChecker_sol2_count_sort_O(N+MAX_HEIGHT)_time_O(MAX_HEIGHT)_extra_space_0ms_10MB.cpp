class Solution {
public:
    int heightChecker(vector<int>& heights) {
        const int N = heights.size();
        const int MAX_HEIGHT = *max_element(heights.begin(), heights.end());

        vector<int> freq(MAX_HEIGHT + 1);
        for(int h: heights){
            freq[h] += 1;
        }

        int badIndices = 0;
        int i = 0;
        for(int h = 0; h <= MAX_HEIGHT; ++h){
            while(freq[h] >= 1){
                badIndices += (int)(h != heights[i]);
                i += 1;
                freq[h] -= 1;
            }
        }

        return badIndices;
    }
};