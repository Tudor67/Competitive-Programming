class Solution {
private:
    vector<int> beautifulNums;

    void generateBeautifulNums(){
        if(!beautifulNums.empty()){
            return;
        }
        
        for(int mask = 1; mask < (1 << 6); ++mask){
            string s;
            for(int bit = 0; bit < 6; ++bit){
                if((mask >> bit) & 1){
                    s.append(bit + 1, char('0' + bit + 1));
                }
            }

            if((int)s.length() <= 7){
                do{
                    beautifulNums.push_back(stoi(s));
                }while(next_permutation(s.begin(), s.end()));
            }
        }

        sort(beautifulNums.begin(), beautifulNums.end());
    }

public:
    int nextBeautifulNumber(int n) {
        generateBeautifulNums();
        return *upper_bound(beautifulNums.begin(), beautifulNums.end(), n);
    }
};