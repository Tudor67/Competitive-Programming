class Solution {
public:
    int largestVariance(string s) {
        const int N = s.length();
        
        vector<bool> contains(130, false);
        for(char c: s){
            contains[c] = true;
        }
        
        int maxVariance = 0;
        for(int a = 'a'; a <= 'z'; ++a){
            for(int b = 'a'; b <= 'z'; ++b){
                if(a == b || !contains[a] || !contains[b]){
                    continue;
                }
                
                int balance = 0;
                bool visitedA = false;
                bool startsWithA = false;
                for(char c: s){
                    if(c == a){
                        if(startsWithA && balance >= 0){
                            // balance of a*** == balance of ***a, with * != a
                            startsWithA = false;
                        }else{
                            balance = max(-1, balance - 1);
                            startsWithA |= (balance == -1);
                        }
                        visitedA = true;
                    }else if(c == b){
                        balance += 1;
                    }
                    
                    if(visitedA){
                        maxVariance = max(maxVariance, balance);
                    }
                }
            }
        }
        
        return maxVariance;
    }
};