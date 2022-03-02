class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int s = flowerbed.size();
        if (n == 0 ) return true;    
        if (s == 1) return flowerbed[0] == 0 ?  true :  false;
        
        if(flowerbed[0] == 0 && flowerbed[1] == 0) {
            --n;
            if (n == 0 ) return true;    
            flowerbed[0] = 1;
        }
        
        
        if(flowerbed[s - 1] == 0 && flowerbed[s - 2] == 0) {
            --n;
            if (n == 0 ) return true;    
            flowerbed[s - 1] = 1;
        }
            
        for(int i = 0; i < s - 1; ++i) {
            if (n == 0 ) return true;    
            if(flowerbed[i] == 0 && flowerbed[i + 1 ] == 0 && flowerbed[i - 1 ] == 0 ) {
               flowerbed[i] = 1;
                --n;
            }
        }
        
        return n <= 0 ? true : false;
    }
};