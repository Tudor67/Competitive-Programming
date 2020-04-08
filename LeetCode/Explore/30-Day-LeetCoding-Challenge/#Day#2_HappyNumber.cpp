class Solution {
private:
    int get_next_n(int n){
        int s = 0;
        int digit;
        while(n > 0){
            digit = n % 10;
            s += digit * digit;
            n /= 10;
        }
        return s;
    }
    
public:
    bool isHappy(int n) {
        set<int> vis;
        
        do{
            vis.insert(n);
            n = get_next_n(n);
        }while(!vis.count(1) && !vis.count(n));
        
        return vis.count(1);
    }
};