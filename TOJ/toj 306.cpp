// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAX_V=100010;
struct line{
    int a,b;
    double cost;
};
vector<line> l;
struct edge{
    int to;
    double cost;
};
vector<edge> g[MAX_V];
void insert_edge(int from,int to,double cost){
//    cout<<from<<" "<<to<<" "<<cost<<endl;
    g[from].push_back({to,cost});  
    g[to].push_back({from,cost}); /*if bidirected*/
}
struct pointd{
    int p;
    double cost;
    bool operator<(const pointd& rhs) const {
        return cost > rhs.cost;
    }
};
priority_queue<pointd> ppq;
struct point{
    double costa=1e10,costb=1e10;
};
struct answer{
    int e,f;
    double p;
    
};
vector<answer> ans;
bool cmp(answer a,answer b){
    if(a.e==b.e) return a.f<b.f;
    return a.e<b.e;
}
point p[MAX_V];
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int a,b,n,ta,tb;
    double tc;
    cin>>a>>b>>n;
    vector<int> v;
    for(int q=0;q<n;q++){
        cin>>ta>>tb>>tc;
        v.push_back(ta);
        v.push_back(tb);
        l.push_back({ta,tb,tc});
    }
    sort(v.begin(),v.end());
//    for(int q=0;q<v.size();q++){
//        cout<<q<<" "<<v[q]<<endl;
//    }
//    cout<<endl;
    vector<int>::iterator it;
    it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    int MAX_P=v.size();
//    for(int q=0;q<v.size();q++){
//        cout<<q<<" "<<v[q]<<endl;
//    }
    a=lower_bound(v.begin(),v.end(),a)-v.begin()+1;
    b=lower_bound(v.begin(),v.end(),b)-v.begin()+1;
    for(int q=0;q<n;q++){
        insert_edge(
            lower_bound(v.begin(),v.end(),l[q].a)-v.begin()+1,
            lower_bound(v.begin(),v.end(),l[q].b)-v.begin()+1,
            l[q].cost
        );
    }
    pointd temp;
    ppq.push({a,0});
    p[a].costa=0;
//    bool update=true;
    while(!ppq.empty()){
        temp=ppq.top();
        ppq.pop();
//        cout<<"find "<<temp.p<<" "<<temp.cost<<endl;
//        update=false;
        for(int q=0;q<g[temp.p].size();q++){
//            cout<<"check "<<g[temp.p][q].to<<" "<<g[temp.p][q].cost<<endl;
            if(temp.cost+g[temp.p][q].cost<p[g[temp.p][q].to].costa){
                p[g[temp.p][q].to].costa=temp.cost+g[temp.p][q].cost;
//                cout<<"update "<<g[temp.p][q].to<<" "<<p[g[temp.p][q].to].costa<<endl;
                ppq.push({g[temp.p][q].to,p[g[temp.p][q].to].costa});
//                update=true;
            }
        }
    }
    ppq.push({b,0});
    p[b].costb=0;
//    bool update=true;
    while(!ppq.empty()){
        temp=ppq.top();
        ppq.pop();
//        cout<<"find "<<temp.p<<" "<<temp.cost<<endl;
//        update=false;
        for(int q=0;q<g[temp.p].size();q++){
//            cout<<"check "<<g[temp.p][q].to<<" "<<g[temp.p][q].cost<<endl;
            if(temp.cost+g[temp.p][q].cost<p[g[temp.p][q].to].costb){
                p[g[temp.p][q].to].costb=temp.cost+g[temp.p][q].cost;
//                cout<<"update "<<g[temp.p][q].to<<" "<<p[g[temp.p][q].to].costa<<endl;
                ppq.push({g[temp.p][q].to,p[g[temp.p][q].to].costb});
//                update=true;
            }
        }
    }
    double d;
    int pta,ptb;
    for(int q=0;q<l.size();q++){
        pta=l[q].a;
        ptb=l[q].b;
        d=p[pta].costa-p[ptb].costb;
        if(abs(d)<l[q].cost&&p[pta].costa<p[ptb].costa&&p[ptb].costb<p[pta].costb){
            double p=100/2*(l[q].cost-d)/l[q].cost;
            if(p>0){
                if(pta>ptb){
                    swap(pta,ptb);
                    p=100-p;
                }
                ans.push_back({pta,ptb,p});
            }
        }
        pta=l[q].b;
        ptb=l[q].a;
        d=p[pta].costa-p[ptb].costb;
        if(abs(d)<l[q].cost&&p[pta].costa<p[ptb].costa&&p[ptb].costb<p[pta].costb){
            double p=100/2*(l[q].cost-d)/l[q].cost;
            if(p>0){
                if(pta>ptb){
                    swap(pta,ptb);
                    p=100-p;
                }
                ans.push_back({pta,ptb,p});
            }
        }
    }
    for(int q=1;q<=MAX_P;q++){
//        cout<<q<<" "<<p[q].costa<<" "<<p[q].costb<<endl;
        if(p[q].costa==p[q].costb){
            ans.push_back({q,q,0});
        }
    }
    for(int q=0;q<ans.size();q++){
        cout<<ans[q].e<<" "<<ans[q].f<<" "<<ans[q].p<<endl;
    }
}
