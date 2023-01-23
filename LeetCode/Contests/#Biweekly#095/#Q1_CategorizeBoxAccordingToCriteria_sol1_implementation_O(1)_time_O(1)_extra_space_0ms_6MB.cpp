class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool isBulky = (max({length, width, height}) >= 1e4 ||
                        length * 1LL * width * 1LL * height >= 1e9);
        bool isHeavy = (mass >= 100);
        
        if(isBulky && isHeavy){
            return "Both";
        }
        if(!isBulky && !isHeavy){
            return "Neither";
        }
        if(isBulky){
            return "Bulky";
        }
        return "Heavy";
    }
};