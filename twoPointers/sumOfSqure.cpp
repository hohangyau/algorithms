class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 1, j = floor(sqrt(c));
        if(j * j  == c) return true;
        while(i <= j) {
            if( i * i + j * j == c) return true;
            else if(  i * i + j * j > c){
                --j;
            }else {
                ++i;
            }
        }
            return false;
    }

};