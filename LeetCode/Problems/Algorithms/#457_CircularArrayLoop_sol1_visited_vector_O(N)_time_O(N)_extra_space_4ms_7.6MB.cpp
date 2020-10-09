class Solution {
private:
    bool sameDirection(const int& A, const int& B){
        return (A > 0 && B > 0) || (A < 0 && B < 0);
    }
    
    bool isValidColor(const vector<int>& COLORS, const int& CURRENT_COLOR, const int& NEXT_POS){
        return (COLORS[NEXT_POS] == 0) || (COLORS[NEXT_POS] == CURRENT_COLOR);
    }
    
public:
    bool circularArrayLoop(vector<int>& nums) {
        const int N = nums.size();
        bool cycleFound = false;
        
        vector<int> colors(N);
        int currentColor = 0;
        for(int i = 0; i < N; ++i){
            if(colors[i] == 0){
                currentColor += 1;
                colors[i] = currentColor;
                int currentPos = i;
                int nextPos = ((i + nums[i]) % N + N) % N;
                while(!cycleFound){
                    if(sameDirection(nums[currentPos], nums[nextPos]) && isValidColor(colors, currentColor, nextPos)){
                        if(colors[nextPos] == currentColor){
                            cycleFound = (currentPos != nextPos);
                            break;
                        }else{
                            colors[nextPos] = currentColor;
                            currentPos = nextPos;
                            nextPos = ((currentPos + nums[currentPos]) % N + N) % N;
                        }
                    }else{
                        break;
                    }
                }
            }
        }
        
        return cycleFound;
    }
};