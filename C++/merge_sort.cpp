#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void merge(int s,int mid, int n,int a[]){
	int c[20],i = s,k=s,j=mid+1;
	while(i<=mid && j<=n){
		if(a[i]<a[j]){
			c[k++] = a[i++];
		}
		else{
			c[k++] = a[j++];
		}
	}
	while(i<= mid){
		c[k++] = a[i++];
	}
	while(j<=n){
		c[k++] = a[j++];
	}
	for(int m=s;m<k;m++){
		a[m] = c[m];
	}
}

void mergeSort(int a[],int s,int n){

	if(s<n){
	int mid = (s+n)/2;
	mergeSort(a,s,mid);
	mergeSort(a,mid+1,n);
	merge(s,mid,n,a);
	}
	return;

}

int main(){
	int n;
	cin>>n;cout<<endl;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	cout<<endl;
    mergeSort(a,0,n-1);
	for(int j=0;j<n;j++)	cout<<a[j]<<"\t";
	return 0;
}
