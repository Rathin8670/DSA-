#include<stdio.h>
#include<stdlib.h>
struct Array{
    int *A;
    int size;
    int length;

};
void disply(struct Array arr){
    printf("elements are;\n");
     for(int i=0;i<arr.length;i++){
        printf("%d",arr.A[i]);

    }

}
int main(){
    struct Array arr;
    //for taking no. of elements
    int n,i;
    printf("ebter size of array;|\n");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    //arr.length=0;
    printf("enter number of elemnets \n");
    scanf("%d",&n);
    arr.length=n;
    printf("elements of the array :\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr.A[i]);

    }
    disply(arr);
      
    return 0;
}