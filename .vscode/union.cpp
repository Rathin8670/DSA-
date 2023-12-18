
#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(Array arr)
{
    cout << "Elements are: " << endl;
    for (int i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
    cout << endl;
}
/*IN sorted list*/
Array* Union(Array* arr1, Array* arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array* arr3 = new Array;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else/*if two elements are same then assign anyone and also increment another*/
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    //for the last element==>
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}
bool elementPresentOrNot(int arr[],  int x)
{
    int l=sizeof(arr)/sizeof(int);
    for(int i=0; i<l; i++)
    {
        if(arr[i]==x)
            return true;
    }
    return false;
}

Array* UnionOnUnsortedList(Array* arr1,Array* arr2){
    int i,j,k;
    i=j=k=0;
    Array* arr3=new Array;
    for(i;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
        arr3->length++;

    }
    for(j;j<arr2->length;j++){
        if(!elementPresentOrNot(arr3->A,arr2->A[j])){
        arr3->A[k++]=arr2->A[j];
          arr3->length++;

        }
    }
    return arr3;
}

Array* Intersection(Array* arr1, Array* arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array* arr3 = new Array;
/*  In intersection only the duplicate value will be copied in 3rd array*/
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];   
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

Array* Difference(Array* arr1, Array* arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array* arr3 = new Array;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main()
{
    Array arr1 = { {2,91,29,28,35}, 10, 5 };
    Array arr2 = { {2,33,19,18,28}, 10, 5 };
    Array* arr3;
Display(arr1);Display(arr2);
//cout<<"union is"<<endl;
 //   arr3 = UnionOnUnsortedList(&arr1, &arr2);
    arr3=Difference(&arr1,&arr2);
    Display(*arr3);

    delete arr3;

    return 0;
}
