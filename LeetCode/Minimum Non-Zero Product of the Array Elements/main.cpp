class Solution {
private:
    const long long mod = 1e9 + 7;

    long long binpow(long long x, long long y) {
        if (y == 0) return 1LL;
        if (y == 1) return x;
        long long ans = binpow(x, y / 2) % mod;
        ans = (ans * ans) % mod;
        return (y % 2 == 0 ? ans : ((ans % mod) * (x % mod)) % mod);
    }
public:
    int minNonZeroProduct(int p) {
        long long n = (1LL << p);
        long long ans = binpow(n - 2, 1 + (n - 4) / 2);
        return ((ans % mod) * ((n - 1) % mod)) % mod;
    }
};