class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string s = to_string(N);
        sort(s.begin(), s.end());
        
        do{
            if(s[0] != '0'){
                int num = stoi(s);
                if((num & (num - 1)) == 0){
                    return true;
                }
            }
        }while(next_permutation(s.begin(), s.end()));
        
        return false;
    }
};