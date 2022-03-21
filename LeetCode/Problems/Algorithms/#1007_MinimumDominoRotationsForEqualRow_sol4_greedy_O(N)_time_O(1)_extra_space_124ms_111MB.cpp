class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        const int N = tops.size();
        
        bool isValidTopValue = true;
        bool isValidBottomValue = true;
        for(int i = 0; i < N; ++i){
            if(tops[0] != tops[i] && tops[0] != bottoms[i]){
                isValidTopValue = false;
            }
            if(bottoms[0] != tops[i] && bottoms[0] != bottoms[i]){
                isValidBottomValue = false;
            }
        }
        
        int top1 = 0;
        int top2 = 0;
        int bottom1 = 0;
        int bottom2 = 0;
        for(int i = 0; i < N; ++i){
            top1 += (int)(tops[0] == tops[i]);
            top2 += (int)(tops[0] == bottoms[i]);
            bottom1 += (int)(bottoms[0] == tops[i]);
            bottom2 += (int)(bottoms[0] == bottoms[i]);
        }
        
        int rotationsForTopValue = N - ((int)isValidTopValue) * max(top1, top2);
        int rotationsForBottomValue = N - ((int)isValidBottomValue) * max(bottom1, bottom2);
        
        int answer = min(rotationsForTopValue, rotationsForBottomValue);
        if(answer == N){
            answer = -1;
        }
        
        return answer;
    }
};