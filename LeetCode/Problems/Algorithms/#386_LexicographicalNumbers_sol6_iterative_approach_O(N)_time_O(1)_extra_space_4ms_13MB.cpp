class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res = {1};

        while((int)res.size() < n){
            int num = res.back();
            if(num * 10 <= n){
                res.push_back(num * 10);
            }else if(num % 10 != 9 && num + 1 <= n){
                res.push_back(num + 1);
            }else{
                num /= 10;
                while(num % 10 == 9){
                    num /= 10;
                }
                num += 1;
                res.push_back(num);
            }
        }

        return res;
    }
};