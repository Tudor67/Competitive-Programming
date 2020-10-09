class Solution {
private:
    const int MIN_COLOR = 1001;
    
    int getNextPos(const vector<int>& NUMS, const int& N, const int& POS){
        return ((POS + NUMS[POS]) % N + N) % N;
    }
    
    bool sameDirection(const int& A, const int& B){
        return (A < 0 && B < 0) || (A > 0 && B > 0);
    }
    
    bool isValidColor(const vector<int>& NUMS, const int& POS, const int& CURRENT_COLOR){
        return (abs(NUMS[POS]) < MIN_COLOR) || (NUMS[POS] == CURRENT_COLOR);
    }
    
public:
    bool circularArrayLoop(vector<int>& nums) {
        const int N = nums.size();
        bool cycleFound = false;
        
        int currentColor = MIN_COLOR;
        for(int i = 0; i < N; ++i){
            if(abs(nums[i]) < MIN_COLOR){
                int pos = i;
                int nextPos = getNextPos(nums, N, pos);
                int fixedDirection = (nums[i] < 0 ? -1 : 1);
                
                currentColor = abs(currentColor) + 1;
                currentColor *= fixedDirection;
                
                while(!cycleFound){
                    if(pos == nextPos){
                        break;
                    }
                    if(sameDirection(fixedDirection, nums[nextPos]) &&
                       isValidColor(nums, nextPos, currentColor)){
                        if(nums[nextPos] == currentColor){
                            cycleFound = true;
                            break;
                        }else{
                            nums[pos] = currentColor;
                            pos = nextPos;
                            nextPos = getNextPos(nums, N, pos);
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