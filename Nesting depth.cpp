#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    char a[100];
    cin>>a;
    int len=strlen(a);
    for(int i=0;i<len;i++){
        int howmany;
        if(i==0){
            howmany=a[i]-'0';
            for(int j=0;j<howmany;j++){
                cout<<'(';
            }
        }
        else{
            if(a[i]>a[i-1]){
                howmany=a[i]-a[i-1];
                for(int j=0;j<howmany;j++){
                    cout<<'(';
                }
            }
            else if(a[i-1]>a[i]){
                howmany=a[i-1]-a[i];
                for(int j=0;j<howmany;j++){
                    cout<<')';
                }
            }
        }
        cout<<a[i];
        if(i==len-1){
            howmany=a[i]-'0';
            for(int j=0;j<howmany;j++){
                cout<<')';
            }
        }
    }
    cout<<endl;
}
int main()
{
    int t, i=1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<i<<": ";
        solve();
        i++;
    }
    return 0;
}
