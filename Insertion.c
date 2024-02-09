#include<stdio.h>
void insertion(int a[], int n){
    int i,j,temp;
    
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        
        while(j>=0 && a[j]>temp){
        a[j+1]=a[j];
        j=j-1;
        }
        a[j+1]=temp;
    }
}
void print(int a[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
int main(){
    int a[]={2,4,12,6,34,23,43,35,65,43,25,76,24,5,3};
    int n= sizeof(a) / sizeof (a[0]);
    insertion(a,n);
    print(a,n);
    return 0;
}