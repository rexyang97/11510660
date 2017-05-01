#include "stdio.h"  
int Liss(int A[],int len,int result[]){
	int i,j,k,max;
	int liss[len];//以当前元素结尾的最长递增子序列
	int pre[len];//当前元素结尾的最长递增子序列的前驱节点
	for(i=0;i<len;++i){
		liss[i]=1;
		pre[i]=1;
	}
	max=1;
	k=0;
	for(i=1;i<len;++i){
		for(j=0;j<i;++j){
			if(A[j]<A[i]&&liss[j]+1>liss[i]){
				liss[i]=liss[j]+1;
				pre[i]=j;
				if(max<liss[i]){
					max=liss[i];
					k=i;
				}
			}
		}
	}
	i=max-1;
	while(pre[k]!=k){
		result[i--]=A[k];
		k=pre[k];
	}
	result[i]=A[k];
	return max;
}