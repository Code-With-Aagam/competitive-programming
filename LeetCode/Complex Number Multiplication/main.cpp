class Solution {
   public:
    pair<int, int> complex(string& s) {
        int i = 0, p, q, count1 = 0, count2 = 0;
        while (s[i++] != '+') count1++;
        p = stoi(s.substr(0, count1));
        int j = i;
        while (s[i++] != 'i') count2++;
        q = stoi(s.substr(j, count2));
        cout << p << ',' << q << endl;
        return {p, q};
    }

    string complexNumberMultiply(string a, string b) {
        int a1, a2, b1, b2;
        string res = "";
        a1 = complex(a).first;
        b1 = complex(a).second;
        a2 = complex(b).first;
        b2 = complex(b).second;
        res += to_string(a1 * a2 - b1 * b2) + '+' + to_string(a1 * b2 + b1 * a2) + 'i';
        return res;
    }
};