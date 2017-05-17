#include<iostream>
using namespace std;
struct node{
    int l,w,h;
};
node s1[1001];
int main()
{
    int t,n,ml,mw,mh;
    cin>>t;
    while(t--){
        cin>>n;
        ml=mh=0; mw=1000000;
        for(int i=0;i<n;i++){
            cin>>s1[i].l>>s1[i].w>>s1[i].h;
            if(ml<s1[i].l) ml=s1[i].l;
        }
        int j=0;
        for(int i=0;i<n;i++){//得到最长
            if(ml==s1[i].l){
                s1[j++]=s1[i];
                if(mw>s1[i].w) mw=s1[i].w;
            }
        }
        int k=0;
        for(int i=0;i<j;i++){
            if(mw==s1[i].w){
                if(mh<s1[i].h) mh=s1[i].h;
            }
        }
        cout<<mh<<endl;
    }
    return 0;
}

