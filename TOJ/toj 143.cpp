#include <cstdio> 
using namespace std;
int main(){
    int n,m,a,b;
    while(~scanf("%d%d",&n,&m)){
        int v[n];
        bool x=0;
        for(int q=0;q<n;q++)v[q]=0;
        while(m--){
            //¿é¤J¼Ä¤HÃö«Y 
            scanf("%d%d",&a,&b);
            //¦pªGA¸òB³£¨S¦³¼Ä¤H¡A¨º¥L­Ì´N¤¬¬°¼Ä¤H 
            if(v[a]+v[b]==0){
                v[a]=b;
                v[b]=a;
            }
            //¦pªGA¨S¦³¼Ä¤H B¦³¼Ä¤H¡A¨ºAªº¼Ä¤H´N¬OBªº¼Ä¤Hªº¼Ä¤H(=BªºªB¤Í) 
            //¸ÑÄÀ °²³]²{¦b¬°(1,3)¼Ä¹ï(2,4) ¼Ä¤HÃö«Y¬°
            //1 2 3 4 ªº¼Ä¤H¹ïÀ³¬O¤U­± 
            //2 1 2 1 
            //´ú¸ê¿é¤J 3 ¸ò6¼Ä¹ï  =>(1,3)¼Ä¹ï(2,4,6)
            //«h6ªº¼Ä¤H¬O 3 ªº¼Ä¤Hªº¼Ä¤H=1  
            //ÁöµM 3¤]¬O6ªº¼Ä¤H   ¦ý¬O§Ú­Ì­n¼Ä¤H³Ì¤p¤Æ (½s¸¹³Ì¤pªº§@¬°»â³S) 
            else if(v[a]==0){
                v[a]=v[v[b]];
            }
            else if(v[b]==0){
                v[b]=v[v[a]];
            }
            //¦pªG2¤H¼Ä¹ï¦ý¬O¼Ä¤H«o¬O¤@¼Ëªº=>Âù­±¿Ò 
            else if(v[a]==v[b]){
                x=1;
                goto BREAK;
            } 
            //¥H¤U§PÂ_¦n¹³¨S¦³¥²­n ¤£ºÞ¥L ¥i¥HAC 
            /*else {
                if(a>b)a^=b^=a^=b;
                v[b]=a;
            }*/ 
            /*for(int q=0;q<n;q++)cout<<v[q];
            cout<<endl;*/
        }
        //¥H¤U¦n¹³¨S¦³¥²­n ¤£ºÞ¥L ¥i¥HAC ¥\¯à¬O ½T»{©Ò¦³¤Hªº¼Ä¤H³£¬O"»â³S "
        /* 
        for(int q=0;q<n;q++){
            if(v[v[q]]!=v[q])v[q]=v[v[v[q]]];
            /*for(int w=0;w<n;w++)cout<<v[w];
            cout<<endl;
        }
        */ 
        goto End;
        BREAK:
        //Àu¤Æ ¤Ï¥¿¦³µª®×´N¥i¥H¿é¥X¤F  ¥u­n§â³Ñ¤U´ú¸êÅª§¹´N¦n 
        while(m--)scanf("%d%d",&a,&b);
        End:
        if(!x)printf("YES\n");
        else printf("NO\n");
    }
}