class Solution {
public:
    string breakPalindrome(string palindrome) {
        const int N = palindrome.length();
        
        // Case 1: (palindrome length == 1) => return empty string
        if(N <= 1){
            return "";
        }
        
        // Case 2: * odd or even length palindrome with all chars equal to a
        //           "aaaa...aaaa" => return "aaaa...aaab"
        //         * odd length palindrome with all chars equal to a, except middle char x (x != a, x is middle char)
        //           "aa...x...aa" => return "aa...x...ab"
        int aCount = count(palindrome.begin(), palindrome.end(), 'a');
        if((aCount == N) ||
           (aCount == N - 1 && N % 2 == 1 && palindrome[N / 2] != 'a')){
            palindrome.back() = 'b';
            return palindrome;
        }
        
        // Case 3: * palindrome with at least one char x (x != a, x is not middle char)
        //           "aaxfk..kfxaa" => return "aaafk..kfxaa"
        int nonAPos = 0;
        while(palindrome[nonAPos] == 'a'){
            nonAPos += 1;
        }
        palindrome[nonAPos] = 'a';
        return palindrome;
    }
};