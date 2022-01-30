constexpr int N = 1e8;
vector<bool> isPrime(N + 1, true);
vector<int> primeNumbers;

void sieveOfEratosthenes() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            primeNumbers.push_back(i);
            for (int j = 2 * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}