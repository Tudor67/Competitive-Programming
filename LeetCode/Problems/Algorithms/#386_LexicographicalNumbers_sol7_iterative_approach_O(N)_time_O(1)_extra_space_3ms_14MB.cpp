class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        v.reserve(n);

        v.push_back(1);
        while((int)v.size() < n){
            int lastNum = v.back();
            if(lastNum * 10 <= n){
                v.push_back(lastNum * 10);
            }else if(lastNum + 1 <= n && lastNum % 10 <= 8){
                v.push_back(lastNum + 1);
            }else{
                int num = lastNum / 10 + 1;
                while(num % 10 == 0){
                    num /= 10;
                }
                v.push_back(num);
            }
        }

        return v;
    }
};