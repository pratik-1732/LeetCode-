class Solution {
public:
    double myPow(double x, int n) {
        long temp=n;
        double ans= 1.0;
        if(temp<0) temp*= -1;
        while(temp>0){
            if(temp%2==0){
                x*= x;
                temp/=2;
            }
            else{
                ans*= x;
                temp--;
            }
        }
        if(n<0) ans= 1/ans;

        return ans;
    }
};