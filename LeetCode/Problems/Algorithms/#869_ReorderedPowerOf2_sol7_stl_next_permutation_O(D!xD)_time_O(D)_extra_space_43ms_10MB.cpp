class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);

        sort(s.begin(), s.end());
        do{
            int num = stoi(s);
            if(s[0] != '0' && (num & (num - 1)) == 0){
                return true;
            }
        }while(next_permutation(s.begin(), s.end()));

        return false;
    }
};