#include<stdio.h>
struct Array {
    int a[100];
    int s;
    int l;
};
struct Array* Merge(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *merge=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->l && j<arr2->l){
        if(arr1->a[i]<arr2->a[j])
        merge->a[k++]=arr1->a[i++];
        else
        merge->a[k++]=arr2->a[j++];

    }
    for(;i<arr1->l;i++)
    merge->a[k++]=arr1->a[i];
    for(;j<arr2->l;j++)
    merge->a[k++]=arr2->a[j];
    return merge;

}
void Display(struct Array arr){
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.l;i++)
 printf("%d ",arr.a[i]);
 printf("jh");
 }
int main(){
    struct Array arr1={{2,3,6,8,9},10,5};
    struct Array arr2={{1,4,5,10,7},10,5};
    struct Array *merge;
    merge=Merge(&arr1,&arr2);
    Display(*merge);
    return 0;

}