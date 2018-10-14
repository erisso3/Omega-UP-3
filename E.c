#include <stdio.h>
#define op_io ios_base:
#define sync_with_stdio();cin.tie();
void mezclar(long long int A[],int l,int m,int r){
	int n1 = m - l + 1;
	int n2 = r-m;
	long long int L[n1];
	long long int R[n1];
	for(int i=0;i<n1;i++){
		L[i] = A[l+i];
	}
	for(int i=0;i<n2;i++){
		R[i] = A[m+1+i];
	}
	int a = 0;
	int b = n2-1;
	int k = l;
	
	while(a <n1 && b>=0){
		if(L[a] <= R[b]){
			A[k] = L[a];
			a++;
		}
		else{
			A[k] = R[b];
			b--;
		}
		k++;
	}
	while(a<n1){
		A[k] = L[a];
		a++;
		k++;
	}
	while(b>=0){
		A[k] = R[b];
		b--;
		k++;
	}
}
void ordenar(long long int A[],int lo,int hi){
	if(lo<hi){
		int m = lo + (hi-lo)/2;
		ordenar(A,lo,m);
		ordenar(A,m+1,hi);
		mezclar(A,lo,m,hi);
	}
}
int main(){
	long int n;
	scanf("%d",&n);
	long long int A[n];
	for(int i=0;i<n;i++)scanf("%d",&A[i]);
	ordenar(A,0,n-1);
	
	for(int i=0;i<n;i++)printf("%d ",A[i]);
	return 0;
}
