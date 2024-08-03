// By xiplus
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
    g[from].push_back({to,cost});
    g[to].push_back({from,cost});
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
    int MAX_P;
    double tc;
    cin>>MAX_P>>n>>a>>b;
    vector<int> v;
    for(int q=0;q<n;q++){
        cin>>ta>>tb>>tc;
        insert_edge(ta,tb,tc);
        l.push_back({ta,tb,tc});
    }
    pointd temp;
    ppq.push({a,0});
    p[a].costa=0;
    while(!ppq.empty()){
        temp=ppq.top();
        ppq.pop();
        for(int q=0;q<g[temp.p].size();q++){
            if(temp.cost+g[temp.p][q].cost<p[g[temp.p][q].to].costa){
                p[g[temp.p][q].to].costa=temp.cost+g[temp.p][q].cost;
                ppq.push({g[temp.p][q].to,p[g[temp.p][q].to].costa});
            }
        }
    }
    ppq.push({b,0});
    p[b].costb=0;
    while(!ppq.empty()){
        temp=ppq.top();
        ppq.pop();
        for(int q=0;q<g[temp.p].size();q++){
            if(temp.cost+g[temp.p][q].cost<p[g[temp.p][q].to].costb){
                p[g[temp.p][q].to].costb=temp.cost+g[temp.p][q].cost;
                ppq.push({g[temp.p][q].to,p[g[temp.p][q].to].costb});
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
        if(p[q].costa==p[q].costb){
            ans.push_back({q,q,0});
        }
    }
    for(int q=0;q<ans.size();q++){
        cout<<fixed<<setprecision(0)<<ans[q].e<<" "<<ans[q].f<<" "<<ans[q].p<<endl;
    }
}
