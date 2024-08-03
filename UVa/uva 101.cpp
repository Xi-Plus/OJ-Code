// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Node{
	int now;
	int parent;
	int son;
}node[25];
void init(int n){
	for(int q=0;q<n;q++){
		node[q]={q,-1,-1};
	}
}
void reset(int a){
	if(a!=-1){
//		cout<<"reset "<<a<<endl;
		reset(node[a].son);
		node[a]={a,-1,-1};
	}
}
int getleave(int a){
	if(node[a].son==-1)return a;
	return getleave(node[a].son);
}
void merge(int a,int b){
//	cout<<"merge "<<a<<" "<<b<<endl;
	if(node[a].parent!=-1){
		node[node[a].parent].son=-1;
//		cout<<"set "<<node[a].parent<<" son -1"<<endl;
	}
	int bleave=getleave(b);
//	cout<<"b leave is "<<bleave<<endl;
	node[bleave].son=a;
//	cout<<"set "<<bleave<<" son "<<a<<endl;
	node[a].parent=bleave;
//	cout<<"set "<<a<<" parent "<<bleave<<endl;
	int anow=a;
	while(anow!=-1){
//		cout<<"set "<<anow<<" now "<<node[b].now<<endl;
		node[anow].now=node[b].now;
		anow=node[anow].son;
	}
}
void show(int n){
	for(int q=0;q<n;q++){
		cout<<q<<":";
		if(node[q].now==q){
			int anow=q;
			while(anow!=-1){
				cout<<" "<<anow;
//				cout<<"("<<node[anow].parent<<","<<anow<<","<<node[anow].son<<")";
				anow=node[anow].son;
			}
		}
		cout<<endl;
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	string s1,s2;
	int a,b;
	while(cin>>n){
		init(n);
		while(cin>>s1,s1!="quit"){
			cin>>a>>s2>>b;
//			cout<<s1<<" "<<a<<" "<<s2<<" "<<b<<endl;
			if(node[a].now==node[b].now){
//				cout<<"error ignore"<<endl;
				continue;
			}
			if(s1=="move"){
				reset(node[a].son);
				node[a].son=-1;
			}
			if(s2=="onto"){
				reset(node[b].son);
				node[b].son=-1;
			}
			merge(a,b);
//			show(n);
//			cout<<endl;
//			cout<<endl;
		}
		show(n);
	}
}

