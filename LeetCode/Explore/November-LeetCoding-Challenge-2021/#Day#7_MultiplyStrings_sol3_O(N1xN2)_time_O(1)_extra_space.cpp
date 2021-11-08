class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        
        const int N1 = num1.length();
        const int N2 = num2.length();
        
        string numProd(N1 + N2, '0');
        for(int i2 = N2 - 1; i2 >= 0; --i2){
            for(int i1 = N1 - 1; i1 >= 0; --i1){
                int digitProd = (num1[i1] - '0') * (num2[i2] - '0') + (numProd[i1 + i2 + 1] - '0');
                numProd[i1 + i2 + 1] = char('0' + digitProd % 10);
                numProd[i1 + i2] += digitProd / 10;
            }
        }
        
        if((int)numProd.size() >= 2 && numProd[0] == '0'){
            numProd.erase(numProd.begin());
        }
        
        return numProd;
    }
};