class Solution {
public:
    // void output(long long n, long long &ans, long long mod){
    //     if(n<=0) return;
    //     ans= (ans*20)%mod;
    //     output(n-2, ans, mod);
    // }
    long long mod= 1e9+7;
    long long power(long long mid, int x){
        if(mid==0) return 1;
        long long res= power(mid/2, x);
        if(mid&1){
            return (x*(res*res)%mod)%mod;
        }
        else{
            return (res*res)%mod;
        }
        
    }
    int countGoodNumbers(long long n) {
        
        if(n==1){
            return 5;
        }
        long long ans=1;
        // while(n>0){
        //     if(n%2==0) {
        //         ans*=4;
        //         ans%=mod;
        //     }
        //     else{
        //         ans*=5;
        //         ans%=mod;
        //     }
        //     n--;
        // }
        // if(n%2!=0){
        //     n--;
        //     ans*= 5;
        // }
        // output(n, ans, mod);
        
        if(n%2==0){
            long long mid= n/2;
            ans= (ans*(power(mid, 5))%mod)%mod;
            // cout<<ans<<" ";
            ans= (ans*(power(mid, 4))%mod)%mod;
            // cout<<ans<<endl;
        }
        else{
            long long mid= n/2;
            ans= (ans*(power(mid, 5))%mod)%mod;
            ans= (ans*(power(mid, 4))%mod)%mod;
            ans= (ans*5)%mod;
        }

        return ans;
    }
};