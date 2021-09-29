class Solution {
public:
    string breakPalindrome(string palindrome) {
        const int N = palindrome.length();
        
        // Case 1: N <= 1 => return empty string
        if(N <= 1){
            return "";
        }
        
        // Case 2: change the first non 'a' char to an 'a' char and return the modified string
        //         for odd N ignore the middle char
        for(int i = 0; i < N; ++i){
            if(i == N / 2 && N % 2 == 1){
                continue;
            }
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        // Case 3: "aaa...aaa" (only 'a', except middle char (for odd N) which can be any char) => return "aaa...aab"
        palindrome[N - 1] = 'b';
        return palindrome;
    }
};