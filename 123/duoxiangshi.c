#include<stdio.h>
#include<math.h>

#include<time.h>
clock_t start,stop;
double duration; //记录被测函数的运行时间
#define RE 10000000//重复次数

#define N 10//最大次数

double f1(int n,double a[],double x);
double f2(int n,double a[],double x);

int main(){
	//输入
	int i;
	double x,a[N+1],p1,p2;
	for(i=0;i<=N;i++){
		a[i]=(double)i;
		
	}//多项式系数赋值
	scanf("%lf",&x);//变量值
	
	start=clock(); 
	
	//输出
	for(i=1;i<=RE;i++)
	p1=f1(N,a,x);

	stop=clock();
	duration=(double)(stop-start)/CLK_TCK/RE;
	printf("ticks1=%f\n",(double)(stop-start));
	printf("duration1=%6.2e\n",duration);
	
	start=clock(); 
	//输出
	for(i=1;i<=RE;i++)
	p2=f2(N,a,x);
	stop=clock();
	duration=(double)(stop-start)/CLK_TCK/RE;
	printf("ticks2=%f\n",(double)(stop-start));
	printf("duration2=%6.2e\n",duration);
	
	// printf("p1=%f\np2=%f\n",p1,p2);
	
	return 0;
	
	
}

double f1(int n,double a[],double x){
	int j;
	double f=a[0];
	for(j=1;j<=n;j++){
		f+=a[j]*pow(x,j);
		
	}
	
	return f;
	
}

double f2(int n,double a[],double x){
	int j;
	double f=a[n];
	for(j=n;j>0;j--){
		f=a[j-1]+f*x;
		
	}
	
	return f;
	
}
