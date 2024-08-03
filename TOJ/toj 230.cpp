// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Order{
    int x,y,dis;
};
bool cmp(Order a,Order b){
    return a.dis<b.dis;
}
vector<Order> disorder;
int R,C;
int x,y;
bool v[510][510];
bool checkn(int n,int max){
    if(n>0&&n<=max)return true;
    return false;
}
bool check2(int x,int y){
    if(checkn(x,R)&&checkn(y,C)&&v[x][y])return true;
    return false;
}
bool check(int i){
    if(check2(x+disorder[i].x,y+disorder[i].y))return true;
    if(check2(x+disorder[i].y,y+disorder[i].x))return true;
    if(check2(x-disorder[i].x,y+disorder[i].y))return true;
    if(check2(x-disorder[i].y,y+disorder[i].x))return true;
    if(check2(x-disorder[i].x,y-disorder[i].y))return true;
    if(check2(x-disorder[i].y,y-disorder[i].x))return true;
    if(check2(x+disorder[i].x,y-disorder[i].y))return true;
    if(check2(x+disorder[i].y,y-disorder[i].x))return true;
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int q=0;q<=500;q++){
        for(int w=q;w<=500;w++){
            disorder.push_back({q,w,q*q+w*w});
        }
    }
    sort(disorder.begin(),disorder.end(),cmp);
    int s=disorder.size();
    int T;cin>>T;
    char c;
    while(T--){
        cin>>R>>C;
        memset(v,0,sizeof(0));
        for(int q=1;q<=R;q++){
            for(int w=1;w<=C;w++){
                cin>>c;
                v[q][w]=(c=='x');
            }
        }
        int N;cin>>N;
        while(N--){
            cin>>x>>y;
            for(int q=0;q<s;q++){
                if(check(q)){
                    cout<<disorder[q].dis<<endl;
                    break;
                }
            }
            v[x][y]=true;
        }
    }
}
