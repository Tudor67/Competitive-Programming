class Solution {
public:
    int xorOperation(int n, int start) {
        // O(1) time and O(1) space solution
        // Observations:
        // (1) start ^ (start + 2) ^ (start + 4) ^ (start + 6) ^ ... ^ (start + 2 * (n - 1))
        //       =
        //      2 * (start/2 ^ (start/2 + 1) ^ (start/2 + 2) ^ (start/2 + 3) ^ ... ^ (start/2 + n - 1)) + (start % 2 == 1) * (n % 2 == 1)
        //      
        // (2) 
        //      x ^ (x + 1) ^ (x + 2) ^ (x + 3) = 0, if x is even
        //      
        // (3) 
        // 
        //                                                            |-> 0, if(x % 2 == 0 && n % 4 == 0)
        //                                                            |-> (x + n - 1), if(x % 2 == 0 && n % 4 == 1)
        //                                                            |-> (x + n - 2) ^ (x + n - 1), if(x % 2 == 0 && n % 4 == 2)
        //                                                            |-> (x + n - 3) ^ (x + n - 2) ^ (x + n - 1), if(x % 2 == 0 && n % 4 == 3)
        //      x ^ (x + 1) ^ (x + 2) ^ (x + 3) ^ ... ^ (x + n - 1) = |
        //                                                            |-> x ^ (x + n - 3) ^ (x + n - 2) ^ (x + n - 1), if(x % 2 == 1 && n % 4 == 0)
        //                                                            |-> x, if(x % 2 == 1 && n % 4 == 1)
        //                                                            |-> x ^ (x + n - 1), if(x % 2 == 1 && n % 4 == 2)
        //                                                            |-> x ^ (x + n - 2) ^ (x + n - 1), if(x % 2 == 1 && n % 4 == 3)
        
        int answer = 0;
        int x = start / 2;
        if(x % 2 == 0){
            if(n % 4 == 0){
                answer = 0;
            }else if(n % 4 == 1){
                answer = x + n - 1;
            }else if(n % 4 == 2){
                answer = (x + n - 2) ^ (x + n - 1);
            }else if(n % 4 == 3){
                answer = (x + n - 3) ^ (x + n - 2) ^ (x + n - 1);
            }
        }else{
            if(n % 4 == 0){
                answer = x ^ (x + n - 3) ^ (x + n - 2) ^ (x + n - 1);
            }else if(n % 4 == 1){
                answer = x;
            }else if(n % 4 == 2){
                answer = x ^ (x + n - 1);
            }else if(n % 4 == 3){
                answer = x ^ (x + n - 2) ^ (x + n - 1);
            }
        }
        
        answer = 2 * answer + (start % 2) * (n % 2);
        
        return answer;
    }
};