class Solution {
private:
    int countFrontBits(int byte){
        int cnt = 0;
        for(int bit = 7; bit >= 0 && ((byte >> bit) & 1); --bit){
            cnt += 1;
        }
        return cnt;
    }
    
public:
    bool validUtf8(vector<int>& data) {
        const int BYTE_MASK = 255;
        bool isValid = true;
        bool isFrontByte = true;
        int n = 0;
        for(int i = 0; i < data.size(); ++i){
            int byte = (data[i] & BYTE_MASK);
            int frontBitsCount = countFrontBits(byte);
            if(frontBitsCount > 4){
                isValid = false;
                break;
            }
            if(isFrontByte){
                if(frontBitsCount == 0){
                    continue;
                }else if(frontBitsCount == 1){
                    isValid = false;
                    break;
                }else{
                    n = frontBitsCount - 1;
                    isFrontByte = false;
                }
            }else{
                if(frontBitsCount == 1 && n >= 1){
                    n -= 1;
                    isFrontByte = (n == 0);
                }else{
                    isValid = false;
                    break;
                }
            }
        }
        isValid = isValid && isFrontByte;
        return isValid;
    }
};