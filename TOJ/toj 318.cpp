#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
double doublemod(double a,double b){
    return a-(int)(a/b)*b;
}
double get_w(double w,double x){
//    cout<<"get_w "<<w<<" "<<x<<" "<<abs(w/2-doublemod(x,w))<<endl;
    return abs(w/2-doublemod(x,w));
}
double get_k(double w,double x,double y){
    // y=k(x-w)(x+w)
//    cout<<"get_k "<<w<<" "<<x<<" "<<y<<" "<<y/(x-w)/(x+w)<<endl;
    return y/(x-w)/(x+w);
}
double get_y(double k,double w,double x){
    // y=k(x-w)(x+w)
//    cout<<"get_y "<<k<<" "<<w<<" "<<x<<" "<<k*(x-w)*(x+w)<<endl;
    return k*(x-w)*(x+w);
}
double get_v(double w,double h){
    double t=sqrt(2*h); // h=a*t^2 / 2 => t=sqrt(2h)
//    cout<<"get_v "<<w<<" "<<h<<" "<<t<<" "<<hypot(t,w/t)<<endl;
    return hypot(t,w/t); // Vy=at Vx=w/t
}
double deg45_y(double w){
    // t=W/V=V/a a=1
    // W=V^2  V=sqrt(W)=t
    // h=vt+at^2/2 =w/2
    double k=get_k(w,0,w/2);
//    cout<<"deg45_y "<<w<<" "<<k<<" "<<get_y(k,w,0)<<endl;
    return get_y(k,w,0);
}
double getans(double w,double x,double y){
    double deg45h=deg45_y(w);
    
    double k=get_k(w,x,y); // y=k(x-w)(x+w)
    double h=get_y(k,w,0); // y=k(x-w)(x+w)
//    cout<<"getans "<<w<<" "<<x<<" "<<y<<" "<<k<<" "<<h<<" "<<deg45h<<" "<<get_v(w,max(h,deg45h))<<endl;
    return get_v(w,max(h,deg45h)); // Vy=at Vx=w/t
}
bool check_same(double a,double b){
    if(abs(a-b)<1e-10)return true;
    return false;
}
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    double D;
    int N,B;
    cin>>D>>N>>B;
    double v[N][2];
    for(int q=0;q<N;q++){
        cin>>v[q][0]>>v[q][1];
    }
    double ans=1e100;
    for(int q=1;q<=B+1;q++){
//        cout<<"B="<<q<<endl;
        double sub_w=D/q;
        double temp_ans=0;
        bool valid_w=true;
        for(int w=0;w<N;w++){
            if(check_same(sub_w/2,get_w(sub_w,v[w][0]))){
                valid_w=false;
//                cout<<"same"<<endl;
                break;
            }
            temp_ans=max(temp_ans,getans(sub_w/2,get_w(sub_w,v[w][0]),v[w][1]));
//            cout<<"-----------"<<endl;
        }
//        cout<<sub_w<<" "<<temp_ans<<endl;
        if(valid_w)ans=min(ans,temp_ans);
    }
    cout<<fixed<<setprecision(3)<<ans<<endl;
}