// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> vo;
        int k;
        for(int q=0;q<n;q++){
            cin>>k;
            vo.push_back(k);
        }
        if(n==1){
            cout<<"Bark"<<endl;
            cout<<vo[0]<<" "<<vo[0]<<endl;
            continue;
        }
        sort(vo.begin(),vo.end());
        vector<int> vi;
        for(int q=0;q<n;q++){
            vi.push_back(vo[q]);
        }
        vector<int>::iterator it;
        it=unique(vi.begin(),vi.end());
        vi.resize(it-vi.begin());
        vector<int> vf;
        vf.resize(n);
        for(int q=0;q<n;q++){
            vf[q]=lower_bound(vi.begin(),vi.end(),vo[q])-vi.begin();
        }
        long long sum=0;
        for(int q=0;q<n;q++){
            sum+=vf[q];
        }
        int imin,imax;
        imin=sum/n;
        imax=imin+1;
        int omin,omax;
        omin=vi[imin];
        omax=vi[imax];
        long long smin=0,smax=0;
        k=0;
        while(vf[k]<imin){
            smin+=vf[k];
            k++;
        }
        smin=imin*k-smin;
        k=n-1;
        while(vf[k]>imax){
            smax+=vf[k];
            k--;
        }
        smax-=imax*(n-k-1);
        if(smin<=smax)cout<<"Bark"<<endl;
        else cout<<"Meow"<<endl;
        cout<<omin<<" "<<omax<<endl;
    }
}
