class Solution {
   public:
    string addStrings(string x, string y) {
        if (x.size() > y.size()) return addStrings(y, x);
        while (x.size() != y.size()) x = "0" + x;
        string z = "";
        int c = 0;
        for (int i = y.size() - 1; i >= 0; --i) {
            int a = x[i] - '0', b = y[i] - '0';
            z += to_string((a + b + c) % 10);
            c = (a + b + c) / 10;
        }
        if (c > 0) z += to_string(c);
        reverse(begin(z), end(z));
        return z;
    }
};