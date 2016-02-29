// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int F[1003][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,r,s;
    char c;
    cin>>t;
    while(t--){
        cin>>r>>s;
        int ans=0;
        for(int q=r;q>=1;q--){
            F[q][0]=2000;
            F[q][1]=0;
            for(int w=1;w<=s;w++){
                cin>>c;
                if(c=='F'||c=='S'){
                    F[q][0]=min(w,F[q][0]);
                    F[q][1]=max(w,F[q][1]);
                }
            }
            if(F[q][0]==2000)F[q][0]=0;
//            cout<<F[q][0]<<" "<<F[q][1]<<" add "<<F[q][1]-F[q][0]<<endl;
            ans+=F[q][1]-F[q][0];
        }
        if(F[1][1]==0){
            F[1][1]=1;
        }
        F[1][0]=1;
//        for(int q=r;q>=1;q--){
//            cout<<F[q][0]<<" "<<F[q][1]<<endl;
//        }
        int q=1,w=1;
        for(;q<=r&&w<=r;){
            for(w=q+1;w<=r;w++){
                if(F[w][0]!=0&&F[w][1]!=0){
//                    cout<<q<<" "<<w<<" ";
                    if(q&1&&w&1){
                        ans+=abs(F[q][1]-F[w][0]);
//                        cout<<"add "<<F[q][1]<<" "<<F[w][0]<<endl;
                    }else if(q&1&&!(w&1)){
                        ans+=abs(F[q][1]-F[w][1]);
//                        cout<<"add "<<F[q][1]<<" "<<F[w][1]<<endl;
                    }else if(!(q&1)&&w&1){
                        ans+=abs(F[q][0]-F[w][0]);
//                        cout<<"add "<<F[q][0]<<" "<<F[w][0]<<endl;
                    }else {
                        ans+=abs(F[q][0]-F[w][1]);
//                        cout<<"add "<<F[q][0]<<" "<<F[w][1]<<endl;
                    }
                    ans+=w-q;
                    q=w;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}