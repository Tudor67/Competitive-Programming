class Solution {
private:
    void generate(int n, int& code, vector<int>& grayCodes){
        if(n == 0){
            grayCodes.push_back(code);
        }else{
            generate(n - 1, code, grayCodes);
            code ^= (1 << (n - 1));
            generate(n - 1, code, grayCodes);
        }
    }
    
public:
    vector<int> grayCode(int n) {
        int code = 0;
        vector<int> grayCodes;
        generate(n, code, grayCodes);
        return grayCodes;
    }
};