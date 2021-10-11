class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        set<vector<int>>s;
        for(int i=0;i<n-3;i++) {
            for(int j=i+1;j<n-2;j++) {
                int sum = k - (arr[i]+arr[j]);
                int l = j+1, r=n-1;
                while(l<r) {
                    // cout<<l<<" "<<r<<" "<<sum<<endl;
                    if(sum==arr[l]+arr[r])
                    {
                        s.insert({arr[i],arr[j],arr[l],arr[r]});
                        l++;
                        r--;
                    }
                    else if(sum<arr[l]+arr[r])
                        r--;
                    else l++;
                }
            }
        }
        vector<vector<int>>v;
        // cout<<s.size();
        auto it=s.begin();
        while(it!=s.end()) {
            auto k = *it;
            v.push_back({k[0], k[1], k[2], k[3]});
            it++;
        }
        return v;
    }
};
