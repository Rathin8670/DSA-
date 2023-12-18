 #include<stdio.h>
int main(){
    int arr[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
   
int index=2;
for(int i=n;i>index;i--){           //for shifting the elements
    arr[i]=arr[i-1];

}
arr[index]=10;              //copy the value at index 
n++;

//print the elements
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}
return 0;

}