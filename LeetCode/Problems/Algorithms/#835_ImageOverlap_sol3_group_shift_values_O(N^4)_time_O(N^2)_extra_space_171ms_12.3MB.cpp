class Solution {
private:
    void storeOnes(vector<vector<int>>& img, vector<pair<int, int>>& imgOnes){
        const int N = img.size();
        imgOnes.clear();
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(img[row][col] == 1){
                    imgOnes.push_back({row, col});
                }
            }
        }
    }
    
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int N = img1.size();
        
        vector<pair<int, int>> img1Ones;
        vector<pair<int, int>> img2Ones;
        
        storeOnes(img1, img1Ones);
        storeOnes(img2, img2Ones);
        
        int maxOverlaps = 0;
        unordered_map<int, int> overlapsFor;
        for(const pair<int, int>& P1: img1Ones){
            for(const pair<int, int>& P2: img2Ones){
                int shift = (P1.first - P2.first) * (2 * N + 5) + (P1.second - P2.second);
                overlapsFor[shift] += 1;
                maxOverlaps = max(maxOverlaps, overlapsFor[shift]);
            }
        }
        
        return maxOverlaps;
    }
};