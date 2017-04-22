#include "stdio.h"  
#include "stdlib.h"
#include "conio.h"
#include "time.h"
void show(int* A){
	int s,i;
	s=sizeof(A)/sizeof(A[0]);
	for(i=0;i<s;i++){
		printf("%d  ",A[i]);
	}
}
int LISdt(int A[],int s){//动态规划
	int max,i;
	int b[s];
	max=A[0];
	b[0]=A[0];
	for(i=1;i<s;i++){
		if(b[i-1]>0){
			b[i]=b[i-1]+A[i];
		}else{
			b[i]=A[i];
		}
		if(b[i]>max)
			max=b[i];
	}
	return max;
}
int LISfz(int b,int e,int A[]){//分治法
	if(b<e){
		int max1,max2,max,left_m,right_m,mid,i,c;
		mid=b+(e-b)/2;
		max1=LISfz(b,mid,A);
		max2=LISfz(mid+1,e,A);
		c=A[mid];
		left_m=c;
		for(i=mid-1;i>=b;--i){
			c+=A[i];
			if(c>left_m)
				left_m=c;
		}
		c=A[mid+1];
		right_m=c;
		for(i=mid+2;i<=e;++i){
			c+=A[i];
			if(c>right_m)
				right_m=c;
		}
		max=left_m+right_m;
		if(max1>max){
			max=max1;
		}
		if(max2>max){
			max=max2;
		}
		return max;
	}else{
		return A[b];
	}
}
void generandomarray(int *a)
{
    int i;
    for(i=0;i<10000;i++)
    {
    srand(i*time(0));
    a[i]=(rand() % (50))-10;
    }
}
int main()  
{
    int a[10000];
    int b[10000];
    int i, size;
    size = sizeof(int);  
    generandomarray(&a[0]);
    FILE *fp1;
    if( (fp1=fopen("lis.txt", "rb+")) == NULL ){
        printf("Cannot open file, press any key to exit!\n");
        getch();
        exit(1);
    }
    fwrite(a, size, 10000, fp1);
    rewind(fp1);
    fread(b, size, 10000, fp1);
    int maxa;
    int maxb;
    maxb=LISfz(0,9999,b);
    maxa=LISdt(b,10000);
    printf("max a:%d\n",maxa);
    printf("max b:%d\n",maxb);
    return 1;
}  