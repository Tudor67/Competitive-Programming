class Solution {
private:
    int countFrontOneBits(int num){
        int frontOneBits = 0;
        while(frontOneBits <= 7 && ((num >> (7 - frontOneBits)) & 1)){
            frontOneBits += 1;
        }
        return frontOneBits;
    }
    
    bool containsOnlyBytesWithPrefix10(vector<int>& data, int firstPos, int lastPos){
        for(int i = firstPos; i <= lastPos; ++i){
            if(countFrontOneBits(data[i]) != 1){
                return false;
            }
        }
        return true;
    }
    
    bool isTypeXData(vector<int>& data, int i, int x){
        const int N = data.size();
        if(x == 1){
            return (countFrontOneBits(data[i]) == 0);
        }
        if(2 <= x && x <= 4){
            return (i + x - 1 <= N - 1 && countFrontOneBits(data[i]) == x && containsOnlyBytesWithPrefix10(data, i + 1, i + x - 1));
        }
        return false;
    }
    
public:
    bool validUtf8(vector<int>& data) {
        const int N = data.size();
        
        int i = 0;
        while(i < N){
            if(isTypeXData(data, i, 1)){
                i += 1;
            }else if(isTypeXData(data, i, 2)){
                i += 2;
            }else if(isTypeXData(data, i, 3)){
                i += 3;
            }else if(isTypeXData(data, i, 4)){
                i += 4;
            }else{
                return false;
            }
        }
        
        return true;
    }
};