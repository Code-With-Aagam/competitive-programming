int binpow(int x, int y) {
	int res = 1;
	while (y > 0) {
		if (y & 1) res = res * x;
		x *= x;
		y >>= 1;
	}
	return res;
}

int binpow(int x, int y, int mod) {
	x %= mod;
	int res = 1;
	while (y > 0) {
		if (y & 1) res = res * x;
		res %= mod;
		x *= x;
		x %= mod;
		y >>= 1;
	}
	return res;
}