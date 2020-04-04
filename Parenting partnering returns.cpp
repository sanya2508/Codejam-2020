#include<bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   int k=0;
   while(t--)
   {
       k++;
       int n;
       cin>>n;
       vector<pair<pair<int,int>,int>> v(n);
       for(int i=0;i<n;i++)
       {
           int a,b;
           cin>>a>>b;
            v[i]={{a,b},i};
       }
       sort(v.begin(),v.end());
       string s="C";
       string ans(n,'C');
       ans[v[0].second]='C';
       if(v[0].first.second>v[1].first.first)
        s+='J',ans[v[1].second]='J';
        else
            s+='C',ans[v[1].second]='C';
       for(int i=2;i<n;i++)
       {
           int pc=0,pj=0;
            if(s[s.length()-1]=='C')
            {
                for(int j=0;j<s.length();j++)
                    {
                        if(s[j]=='J')
                            pj=j;
                        if(s[j]=='C')
                            pc=j;
                    }
                if(v[i].first.first>=v[i-1].first.second)
                    s+='C',ans[v[i].second]='C';
                else
                {
                    if(pj==0)
                        s+='J',ans[v[i].second]='J';
                    else
                    {
                        if(v[pj].first.second<=v[i].first.first)
                            s+='J',ans[v[i].second]='J';
                        else if(v[pc].first.second<=v[i].first.first)
                            s+='C',ans[v[i].second]='C';
                        else
                        {
                            //cout<<s<<endl;
                            ans="IMPOSSIBLE";
                            goto answer;
                        }
                    }
                }
                    
            }
            else if(s[s.length()-1]=='J')
            {
                for(int j=0;j<s.length();j++)
                    {
                        if(s[j]=='J')
                            pj=j;
                        if(s[j]=='C')
                            pc=j;
                    }
                if(v[i].first.first>=v[i-1].first.second)
                    s+='J',ans[v[i].second]='J';
                else
                {
                        if(v[pc].first.second<=v[i].first.first)
                            s+='C',ans[v[i].second]='C';
                        else if(v[pj].first.second<=v[i].first.first)
                            s+='J',ans[v[i].second]='J';
                        else
                        {
                          //cout<<s<<endl;
                            ans="IMPOSSIBLE";
                            //cout<<v[pc].second<<" "<<v[pj].second<<" "<<v[i].first;
                           // cout<<"hoi";
                            goto answer;
                        }
                }
                    
            }
       }
      answer:
                cout<<"Case #"<<k<<":"<<" "<<ans<<endl;
   }
}
