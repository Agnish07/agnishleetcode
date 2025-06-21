class Solution {
public:
    const int mod = 1e9 + 7;
    // int isprime(long long n){
    //     int cnt = 0;
    //     for(int i = 0; i*i <= nl; i++){
    //         if(n%i != 0){
    //             cnt++;
    //             if(n%i != i){P
    //                 cnt++;
    //             }
    //         }
    //         if(cnt == 2) return true;
    //         return false;
    //     }
    // }
    long long modpow(long long base, long long exp, int mod){
        if(exp == 0) return 1;
        long long half = modpow(base, exp/2, mod);
        long long result = (half * half) % mod;
        if(exp%2 == 1) result = (result * base) % mod;
        return result;
    }

    int countGoodNumbers(long long n) {
        long long half = n/2;
        long long evencount = (n+1)/2;
        
        long long ans = modpow(5, evencount, mod) * modpow(4, half, mod) % mod;
        return (int)ans;
    }
};