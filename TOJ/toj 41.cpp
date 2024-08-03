// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int v[1010];
int find(int p){
    if(v[p]==p)return p;
    return v[p]=find(v[p]);
}
bool check(int a,int b){
    int ta=find(a),tb=find(b);
    if(ta==tb)return false;
    v[ta]=tb;
    return true;
}
struct Road{
    int a,b,d;
};
bool cmp(Road a,Road b){
    return a.d<b.d;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k,r;cin>>k>>r;
    for(int q=0;q<k;q++)v[q]=q;
    vector<Road> road;
    int ta,tb,td;
    for(int q=0;q<r;q++){
        cin>>ta>>tb>>td;
        road.push_back({ta,tb,td});
    }
    sort(road.begin(),road.end(),cmp);
    int add=0,ans=0;
    for(int q=0;q<r;q++){
        if(check(road[q].a,road[q].b)){
            add++;
            ans+=road[q].d;
            if(add==k-1){
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
