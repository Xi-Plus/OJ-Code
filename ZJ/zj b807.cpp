// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
#define Debug(A)
const double PI=acos(-1);
const double eps=10e-6;
using namespace std;
struct Point{
	double x,y;
};
bool operator == (Point a,Point b){
	return abs(a.x-b.x)<eps&&abs(a.y-b.y)<eps;
}
bool operator != (Point a,Point b){
	return abs(a.x-b.x)>=eps||abs(a.y-b.y)>=eps;
}
double get_angle(Point p){
	if(p.x<0)return atan(p.y/p.x)/PI*180+180;
	if(p.x>=0&&p.y<0)return atan(p.y/p.x)/PI*180+360;
	return atan(p.y/p.x)/PI*180;
}
struct PointList{
	Point point;
	double angle;
	int type;
};
bool cmp_point(PointList a,PointList b){
	if(abs(a.angle-b.angle)<eps) return a.type>b.type;
	return a.angle<b.angle;
}
struct Side{
	Point p1,p2;
};
struct Multiple{
	double x,y;
};
Point get_vector(Point a,Point b){
	return {b.x-a.x,b.y-a.y};
}
Multiple Cramer(double a,double b,double c,double d,double e,double f){
	// ax+by=e
	// cx+dy=f
	// https://zh.wikipedia.org/wiki/%E5%85%8B%E8%90%8A%E5%A7%86%E6%B3%95%E5%89%87#.E4.BE.8B.E5.AD.90
	if(a*d==b*c)return {NAN,NAN};
	return {(e*d-b*f)/(a*d-b*c),(a*f-e*c)/(a*d-b*c)};
}
Point Intersection(Point a1,Point a2,Point b1,Point b2){
	// v1=a2-a1 v2=b2-b1
	Point Va=get_vector(a1,a2),Vb=get_vector(b1,b2);
	Point A=a1,B=b1;
	// Ax+m*Vax=Bx+n*Vbx
	// Ay+m*Vay=By*n*Vby
	// Vax*m+(-Vbx)*n=Bx-Ax
	// Vay*m+(-Vby)*n=By-Ay
	Multiple k=Cramer(Va.x,-Vb.x,Va.y,-Vb.y,B.x-A.x,B.y-A.y);
	if(std::isnan(k.x))return {NAN,NAN};
	Point ans={A.x+k.x*Va.x,A.y+k.x*Va.y};
	if(min(a1.x,a2.x)-eps<=ans.x&&ans.x<=max(a1.x,a2.x)+eps&&
		min(a1.y,a2.y)-eps<=ans.y&&ans.y<=max(a1.y,a2.y)+eps&&
		min(b1.x,b2.x)-eps<=ans.x&&ans.x<=max(b1.x,b2.x)+eps&&
		min(b1.y,b2.y)-eps<=ans.y&&ans.y<=max(b1.y,b2.y)+eps
		)return ans;
	return {NAN,NAN};
}
int get_side(double xl,double yt,double xr,double yb,double R){
	if(xr<=-R)return 0;
	if(xl>=+R)return 0;
	if(yb>=+R)return 0;
	if(yt<=-R)return 0;
	int ans=1;
	if(xr>=0)ans++;
	if(xl>0)ans++;
	if(yb<=0)ans+=3;
	if(yt<0)ans+=3;
	return ans;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int T,N;
	double R,px,py;
	cin>>T;
	Debug(FILE *ggb;
	ggb=fopen("zj b807-ggb.txt","w");
	fprintf(ggb,"var a = ggbApplet; \n");)
	Debug(int testcount=0;)
	while(T--){
		Debug(testcount++;)
		Debug(cout<<"#"<<testcount<<endl;)
		cin>>R>>px>>py>>N;
		Debug(printf("%lf %lf %lf %d \n",R,px,py,N);)
		Debug(fprintf(ggb,"a.evalCommand('Polygon[(%lf,%lf), (%lf,%lf), (%lf,%lf), (%lf,%lf)]'); \n",px-R,py+R,px-R,py-R,px+R,py-R,px+R,py+R);)
		vector<PointList>pointlist;
		pointlist.push_back({-R,+R,0,2});
		pointlist.push_back({+R,+R,0,2});
		pointlist.push_back({-R,-R,0,2});
		pointlist.push_back({+R,-R,0,2});
		vector<Side>sidelist;
		sidelist.push_back({{-R-1,+R},{+R+1,+R}});
		sidelist.push_back({{-R-1,-R},{+R+1,-R}});
		sidelist.push_back({{-R,+R+1},{-R,-R-1}});
		sidelist.push_back({{+R,+R+1},{+R,-R-1}});
		double obstacle_ans=0;
		for(int q=0;q<N;q++){
			double xl,yt,xr,yb;
			cin>>xl>>yt>>xr>>yb;
			Debug(printf("%lf %lf %lf %lf \n",xl,yt,xr,yb);)
			xl-=px;xr-=px;
			yt-=py;yb-=py;
			if(xl>xr) swap(xl,xr);
			if(yt<yb) swap(yt,yb);
			Debug(fprintf(ggb,"a.evalCommand('Polygon[(%lf,%lf), (%lf,%lf), (%lf,%lf), (%lf,%lf)]'); \n",xl,yt,xl,yb,xr,yb,xr,yt);)
			int side=get_side(xl,yt,xr,yb,R);
			if(side==0)continue;
			if(xl==xr&&yt==yb)continue;
			obstacle_ans+=(min(xr,R)-max(xl,-R))*(min(yt,R)-max(yb,-R));
			if(yt!=yb){
				if(side%3==1) sidelist.push_back({{xr,yt},{xr,yb}});
				else if(side%3==0) sidelist.push_back({{xl,yt},{xl,yb}});
			}
			if(xl!=xr){
				if(side<=3) sidelist.push_back({{xl,yb},{xr,yb}});
				else if(side>=7) sidelist.push_back({{xl,yt},{xr,yt}});
			}
			Debug(printf("inputside: %lf %lf %lf %lf %d \n",xl,yt,xr,yb,side);)
			switch(side){
				case 1:
					pointlist.push_back({xr,min(yt,R),0,0});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xr,min(yt,R));)
					pointlist.push_back({max(xl,-R),yb,0,1});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",max(xl,-R),yb);)
					if(xl!=xr&&yt!=yb)pointlist.push_back({xr,yb,0,2});
					break;
				case 2:
					pointlist.push_back({xr,yb,0,0});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xr,yb);)
					pointlist.push_back({xl,yb,0,1});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xl,yb);)
					break;
				case 3:
					pointlist.push_back({min(xr,R),yb,0,0});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",min(xr,R),yb);)
					pointlist.push_back({xl,min(yt,R),0,1});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xl,min(yt,R));)
					if(xl!=xr&&yt!=yb)pointlist.push_back({xl,yb,0,2});
					break;
				case 4:
					pointlist.push_back({xr,yt,0,0});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xr,yt);)
					pointlist.push_back({xr,yb,0,1});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xr,yb);)
					break;
				case 6:
					pointlist.push_back({xl,yb,0,0});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xl,yb);)
					pointlist.push_back({xl,yt,0,1});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xl,yt);)
					break;
				case 7:
					pointlist.push_back({max(xl,-R),yt,0,0});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",max(xl,-R),yt);)
					pointlist.push_back({xr,max(yb,-R),0,1});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xr,max(yb,-R));)
					if(xl!=xr&&yt!=yb)pointlist.push_back({xr,yt,0,2});
					break;
				case 8:
					pointlist.push_back({xl,yt,0,0});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xl,yt);)
					pointlist.push_back({xr,yt,0,1});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xr,yt);)
					break;
				case 9:
					pointlist.push_back({xl,max(yb,-R),0,0});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",xl,max(yb,-R));)
					pointlist.push_back({min(xr,R),yt,0,1});
					Debug(fprintf(ggb,"a.evalCommand('Ray[(0,0), (%lf,%lf)]'); \n",min(xr,R),yt);)
					if(xl!=xr&&yt!=yb)pointlist.push_back({xl,yt,0,2});
					break;
			}
		}
		Debug(
		for(auto i:pointlist){
			printf("point: %lf %lf %d \n",i.point.x,i.point.y,i.type);
		}
		for(auto i:sidelist){
			printf("side: %lf %lf %lf %lf \n",i.p1.x,i.p1.y,i.p2.x,i.p2.y);
		}
		)

		vector<PointList>point_ans;
		for(auto p:pointlist){
			Debug(printf(" point: %lf %lf\n",p.point.x,p.point.y);)
			bool vaild=true;
			double min_dis=10000;
			double k;
			if(abs(p.point.x)<eps){
				k=(R+10)/abs(p.point.y);
			}else if(abs(p.point.y)<eps){
				k=(R+10)/abs(p.point.x);
			}else {
				k=(R+10)/min(abs(p.point.x),abs(p.point.y));
			}
			Point far_p={p.point.x*k,p.point.y*k};
			Debug(printf(" far_p: %lf %lf\n",far_p.x,far_p.y);)
			Point far_inter={NAN,NAN};;
			for(auto s:sidelist){
				Point inter=Intersection({0,0},p.point,s.p1,s.p2);
				Debug(printf("  side: %lf %lf %lf %lf \n",s.p1.x,s.p1.y,s.p2.x,s.p2.y);)
				Debug(printf("  inter: %lf %lf \n",inter.x,inter.y);)
				if(inter!=p.point&&!std::isnan(inter.x)){
					vaild=false;
					Debug(printf("  unvaild \n");)
					break;
				}
				inter=Intersection({0,0},far_p,s.p1,s.p2);
				Debug(printf("  inter2: %lf %lf \n",inter.x,inter.y);	)
				if(p.type!=2&&!std::isnan(inter.x)&&inter!=s.p1&&inter!=s.p2){
					if(hypot(inter.x,inter.y)<min_dis){
						min_dis=hypot(inter.x,inter.y);
						Debug(printf(" far_int: %lf %lf %lf\n",inter.x,inter.y,min_dis);)
						far_inter=inter;
					}
				}
			}
			if(vaild){
				point_ans.push_back({p.point,get_angle(p.point),p.type});
				if(p.type!=2) point_ans.push_back({far_inter,get_angle(far_inter),1-p.type});
				Debug(printf(" far_point: %lf %lf\n",far_inter.x,far_inter.y);)
			}
		}
		sort(point_ans.begin(),point_ans.end(),cmp_point);
		Debug(fprintf(ggb,"----------------- \nvar a = ggbApplet; \na.evalCommand('Polygon[");)
		Debug(for(auto p:point_ans){
			printf("point_ans: %lf %lf %lf %d\n",p.point.x,p.point.y,p.angle,p.type);
			fprintf(ggb,"(%lf,%lf), ",p.point.x,p.point.y);
		})
		Debug(fprintf(ggb,"]'); \n");)
		int sz=point_ans.size();
		double ans=0;
		for(int q=0;q<sz-1;q++){
			ans+=point_ans[q].point.x*point_ans[q+1].point.y;
			ans-=point_ans[q+1].point.x*point_ans[q].point.y;
		}
		ans+=point_ans[sz-1].point.x*point_ans[0].point.y;
		ans-=point_ans[0].point.x*point_ans[sz-1].point.y;
		Debug(cout<<fixed<<R*R*4<<endl<<abs(ans)/2<<endl<<obstacle_ans<<endl;)
		cout<<fixed<<setprecision(2)<<R*R*4-abs(ans)/2-obstacle_ans<<endl;
	}
}
