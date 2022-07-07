class Solution {
public:
    int largestVariance(string s) {
        const int N = s.length();
        
        vector<bool> contains(130, false);
        for(char c: s){
            contains[c] = true;
        }
        
        int maxVariance = 0;
        vector<int> balance(N);
        for(int a = 'a'; a <= 'z'; ++a){
            for(int b = 'a'; b <= 'z'; ++b){
                if(a == b || !contains[a] || !contains[b]){
                    continue;
                }
                
                int minBalance = 0;
                int k = 0;
                bool visitedA = false;
                bool visitedB = false;
                for(int i = 0; i < N; ++i){
                    if(i > 0){
                        balance[i] = balance[i - 1];
                    }else{
                        balance[i] = 0;
                    }
                    
                    if(s[i] == a){
                        visitedA = true;
                        balance[i] -= 1;
                    }else if(s[i] == b){
                        visitedB = true;
                        balance[i] += 1;
                    }
                    
                    if(s[i] == a){
                        while(k < i){
                            minBalance = min(minBalance, balance[k]);
                            k += 1;
                        }
                    }
                    
                    if(visitedA && visitedB){
                        maxVariance = max(maxVariance, balance[i] - minBalance);
                    }
                }
            }
        }
        
        return maxVariance;
    }
};