class Solution {
private:
    int getVowelIdx(char c){
        if(c == 'a'){
            return 0;
        }else if(c == 'e'){
            return 1;
        }else if(c == 'i'){
            return 2;
        }else if(c == 'o'){
            return 3;
        }else if(c == 'u'){
            return 4;
        }
        return -1;
    }
    
public:
    int findTheLongestSubstring(string s) {
        const int N = s.length();
        
        int maxLength = 0;
        int prefixMask = 0;
        unordered_map<int, int> firstPosOf;
        firstPosOf[0] = -1;
        for(int i = 0; i < N; ++i){
            int idx = getVowelIdx(s[i]);
            if(idx != -1){
                prefixMask ^= (1 << idx);
            }
            if(firstPosOf.find(prefixMask) == firstPosOf.end()){
                firstPosOf[prefixMask] = i;
            }else{
                maxLength = max(maxLength, i - firstPosOf[prefixMask]);
            }
        }
        
        return maxLength;
    }
};