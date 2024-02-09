#include<stdio.h>
void merge(int a[],int l, int m, int h){
    int i=l;
    int j=m+1;
    int k=l;
    int c[50];
    while(i<=m && j<=h){
        if(a[i]<=a[j]){
            c[k++]=a[i++];
        }else{
            c[k++]=a[j++];
        }
    }while(i<=m)
        c[k++]=a[i++];
        while(j<=h)
        c[k++]=a[j++];
        for(i=l;i<=h;i++)
            a[i]=c[i];
}
void merge_sort(int a[], int l, int h){
    if (l<h){
        int m=(l+h)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,h);
        merge(a,l,m,h);
    }
}
int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];

    printf("\nEnter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    merge_sort(a, 0, n - 1);

    printf("\nSorted array is : \n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}