class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string nStr = to_string(n);
        sort(nStr.begin(), nStr.end());
        
        do{
            int num = stoi(nStr);
            if(nStr[0] != '0' && (num & (num - 1)) == 0){
                return true;
            }
        }while(next_permutation(nStr.begin(), nStr.end()));
        
        return false;
    }
};