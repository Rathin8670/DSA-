#include<stdio.h>
struct Array {
    int a[10];
    int size;
    int length;
};

void Display(struct Array arr){
    printf("Elements are:\n");
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.a[i]);
    }
}

void delete(struct Array *arr,int index){
    int x=0;
    if(index>=0 && index<arr->length){
        x=arr->a[index];
        for(int i=index;i<arr->length-1;i++){
            arr->a[i]=arr->a[i+1];
            
        }
        arr->length--;
      }
}
int main(){
    struct Array arr={{1,2,3,45,5},10,5};
   
    delete(&arr,1);
    Display(arr);
    return 0;
}