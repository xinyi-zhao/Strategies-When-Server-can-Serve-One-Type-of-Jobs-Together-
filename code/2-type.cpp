#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<cmath>
using namespace std;
int la,lb,sa,sb;
int q[10000005];
double tm[10000005];
int q2[1000005];
double tm2[1000005];
int ge;
double ans;
int renshu;
double get_next(double lambda){
    double pV = 0.0;
    while(true)
    {
        pV = (double)rand()/(double)RAND_MAX;
        if (pV != 1)
        {
            break;
        }
    }
    pV = (-1.0/lambda)*log(1-pV);
    return pV;
}
void did1(){
	double na=get_next(la),nb=get_next(lb);
	int ci=1000000;
	ge=0;
	double now=0;
	ans=0;renshu=0;
	while(ci--){
		if(ge==0){
			if(na<nb){
				q[++ge]=1;tm[ge]=na;
				na+=get_next(la);
				now=na;
			}
			else{
				q[++ge]=2;tm[ge]=nb;
				now=nb;
				nb+=get_next(lb);
			}
			continue;
		}
		int type=q[1];
		int tmp=0;
		for(int i=1;i<=ge;i++){
			if(q[i]==type){
				ans+=now-tm[i];
				renshu++;
			}
			else{
				tmp++;
				q2[tmp]=q[i];tm2[tmp]=tm[i];
			}
		}
		for(int i=1;i<=tmp;i++){
			q[i]=q2[i];
			tm[i]=tm2[i];
		}
		ge=tmp;
		if(type==1)now+=sa;else now+=sb;
		while(na<=now || nb<=now){
			if(na<nb){
				q[++ge]=1;tm[ge]=na;
				na+=get_next(la);
			}
			else{
				q[++ge]=2;tm[ge]=nb;
				nb+=get_next(lb);
			}
		}
	}
	ans=ans/renshu;
	cout<<ans<<",";
}
void did2(){
	double na=get_next(la),nb=get_next(lb);
	int ci=1000000;
	ge=0;
	double now=0;
	int type=2;
	ans=0;
	renshu=0;
	while(ci--){
		//now=max(now,shi);
		if(type==2)type=1;
		else type=2;
		int tmp=0;
		for(int i=1;i<=ge;i++){
			if(q[i]==type){
				ans+=now-tm[i];
				renshu++;
			}
			else{
				tmp++;
				q2[tmp]=q[i];tm2[tmp]=tm[i];
			}
		}
		for(int i=1;i<=tmp;i++){
			q[i]=q2[i];
			tm[i]=tm2[i];
		}
		ge=tmp;
		if(type==1)now+=sa;else now+=sb;
		while(na<=now || nb<=now){
			if(na<nb){
				q[++ge]=1;tm[ge]=na;
				na+=get_next(la);
			}
			else{
				q[++ge]=2;tm[ge]=nb;
				nb+=get_next(lb);
			}
		}
	}
	ans=ans/renshu;
	cout<<ans<<",";
}
void did3(){
	double na=get_next(la),nb=get_next(lb);
	int ci=1000000;
	ge=0;
	double now=0;
	ans=0;renshu=0;
	while(ci--){
		if(ge==0){
			if(na<nb){
				q[++ge]=1;tm[ge]=na;
				na+=get_next(la);
				now=na;
			}
			else{
				q[++ge]=2;tm[ge]=nb;
				now=nb;
				nb+=get_next(lb);
			}
			continue;
		}
		int type;
		int pp=0,qq=0;
		for(int i=1;i<=ge;i++){
			if(q[i]==1)pp++;else qq++;
		}
		if(1.0*sa*qq<1.0*sb*pp)type=1;
		else type=2;
		int tmp=0;
		for(int i=1;i<=ge;i++){
			if(q[i]==type){
				ans+=now-tm[i];
				renshu++;
			}
			else{
				tmp++;
				q2[tmp]=q[i];tm2[tmp]=tm[i];
			}
		}
		for(int i=1;i<=tmp;i++){
			q[i]=q2[i];
			tm[i]=tm2[i];
		}
		ge=tmp;
		if(type==1)now+=sa;else now+=sb;
		while(na<=now || nb<=now){
			if(na<nb){
				q[++ge]=1;tm[ge]=na;
				na+=get_next(la);
			}
			else{
				q[++ge]=2;tm[ge]=nb;
				nb+=get_next(lb);
			}
		}
	}
	ans=ans/renshu;
	cout<<ans<<",";
	if(tm[1]<1000)printf("!!!");
}
void did4(){
	double na=get_next(la),nb=get_next(lb);
	int ci=1000000;
	ge=0;
	double now=0;
	ans=0;renshu=0;
	while(ci--){
		int type=rand()%2;
		type=type+1;
		int tmp=0;
		for(int i=1;i<=ge;i++){
			if(q[i]==type){
				ans+=now-tm[i];
				renshu++;
			}
			else{
				tmp++;
				q2[tmp]=q[i];tm2[tmp]=tm[i];
			}
		}
		for(int i=1;i<=tmp;i++){
			q[i]=q2[i];
			tm[i]=tm2[i];
		}
		ge=tmp;
		if(type==1)now+=sa;else now+=sb;
		while(na<=now || nb<=now){
			if(na<nb){
				q[++ge]=1;tm[ge]=na;
				na+=get_next(la);
			}
			else{
				q[++ge]=2;tm[ge]=nb;
				nb+=get_next(lb);
			}
		}
	}
	ans=ans/renshu;
	cout<<ans<<",";
	if(tm[1]<1000)printf("!!!");
}

int main(){
	srand(time(0));
	freopen("2-type-00.out","w",stdout);
	//scanf("%d%d%d%d",&la,&lb,&sa,&sb);
	int strategy;
	//scanf("%d",&strategy);
	//did1();
	//return 0;
	
		for(int i1=1;i1<=1;i1++){
			for(int i2=1;i2<=1;i2++){
				for(int i3=1;i3<=50;i3++){
					for(int i4=1;i4<=1;i4++){
						la=i1;lb=i2;sa=i3;sb=i3;
					//	cout<<la<<" "<<lb<<" "<<sa<<" "<<sb<<" ";
						did1();
					}
				}
			}
		}
	fclose(stdin);
freopen("2-type-11.out","w",stdout);
		for(int i1=1;i1<=1;i1++){
			for(int i2=1;i2<=1;i2++){
				for(int i3=1;i3<=50;i3++){
					for(int i4=1;i4<=1;i4++){
						la=i1;lb=i2;sa=i3;sb=i3;
					//	cout<<la<<" "<<lb<<" "<<sa<<" "<<sb<<" ";
						did2();
					}
				}
			}
		}
fclose(stdin);
freopen("2-type-22.out","w",stdout);
		for(int i1=1;i1<=1;i1++){
			for(int i2=1;i2<=1;i2++){
				for(int i3=1;i3<=50;i3++){
					for(int i4=1;i4<=1;i4++){
						la=i1;lb=i2;sa=i3;sb=i3;
					//	cout<<la<<" "<<lb<<" "<<sa<<" "<<sb<<" ";
						did3();
					}
				}
			}
		}
	fclose(stdin);

	return 0;
}