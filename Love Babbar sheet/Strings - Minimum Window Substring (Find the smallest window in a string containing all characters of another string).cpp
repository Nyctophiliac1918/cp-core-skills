class Solution {
public:
    string minWindow(string s, string p) {
        int n = p.size(), t = s.size();

		if (n > t)
			return "";

		unordered_map<char, int>m, q;
		for (char c : p) m[c]++;

		int l = 0, r = 0, c = 0, mx = INT_MAX, ans = -1;

		while (r <= t) {
			if (c == n) {
				if (m.find(s[l]) != m.end())
				{
					q[s[l]]--;
					if (q[s[l]] < m[s[l]])
						c--;
				}
				// cout << "l: " << l << " " << c << endl;
				l++;
				if (mx > r - l + 1) {
					mx = r - l + 1;
					ans = l - 1;
					// cout << mx << " " << ans << endl;
				}
			}
			else {
				if (m.find(s[r]) != m.end()) {
					q[s[r]]++;
					if (q[s[r]] <= m[s[r]])
						c++;
				}
				// cout << "r: " << r << " " << c << endl;
				r++;
			}
		}
    
        if(ans==-1) return "";
		return s.substr(ans, mx);
    }
};
