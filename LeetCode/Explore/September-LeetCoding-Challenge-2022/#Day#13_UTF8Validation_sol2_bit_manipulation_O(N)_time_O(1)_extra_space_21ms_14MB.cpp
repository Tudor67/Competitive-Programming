class Solution {
private:
    int getKthBit(int num, int k){
        return ((num >> k) & 1);
    }
    
    int countFrontOneBits(int num){
        int frontOneBits = 0;
        while(frontOneBits <= 7 && getKthBit(num, 7 - frontOneBits) == 1){
            frontOneBits += 1;
        }
        return frontOneBits;
    }
    
public:
    bool validUtf8(vector<int>& data) {
        const int N = data.size();
        
        bool isValid = true;
        int i = 0;
        while(i < N && isValid){
            if(getKthBit(data[i], 7) == 0){
                // Number of Bytes: 1
                i += 1;
            }else{
                int frontOneBits = countFrontOneBits(data[i]);
                if(2 <= frontOneBits && frontOneBits <= 4 && i + frontOneBits - 1 < N){
                    // Number of Bytes: 2 or 3 or 4
                    for(int j = i + 1; j <= i + frontOneBits - 1; ++j){
                        if(countFrontOneBits(data[j]) != 1){
                            isValid = false;
                        }
                    }
                    i += frontOneBits;
                }else{
                    isValid = false;
                }
            }
        }
        
        return isValid;
    }
};