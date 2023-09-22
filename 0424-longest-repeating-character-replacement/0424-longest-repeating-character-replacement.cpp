class Solution {
public:
    int characterReplacement(string s, int k) {
         unordered_map<int,vector<int>> m;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            m[s[i]].push_back(i);
        }
        int ans=0;
        for(auto it:m)
        {
            
            int sz=it.second.size();
            int i=0,j=0;
            while(j<sz)
            {

                while(it.second[j]-it.second[i]-(j-i)>k) i++;
                int extra=k-(it.second[j]-it.second[i]-(j-i));
                // cout<<extra<<" ";
                int curr=it.second[j]-it.second[i]+1;

                if(it.second[i]>0)
                {
                    curr+=min(it.second[i],extra);
                    extra-=min(it.second[i],extra);
                }
                if(it.second[j]<n)
                {
                    curr+=min(n-it.second[j]-1,extra);
                    extra-=min(n-it.second[j]-1,extra);
                }
                // cout<<it.second[i]<<"->"<<it.second[j]<<" "<<endl;
                ans=max(ans,curr);
                j++;
            }
            
        }
        return ans;
    }
};