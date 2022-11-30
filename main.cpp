#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct{
    ElemType *array;
    int length;
}OrderTable;

void InitTable(OrderTable &OT,int len){
    OT.length=len;
    OT.array=(ElemType*)malloc(sizeof(ElemType)*OT.length);
    srand(time(NULL));
    for(int i=0;i<OT.length;++i){
        OT.array[i]=rand()%100;
    }
}

void PrintTable(OrderTable OT){
    for(int i=0;i<OT.length;++i){
        printf("%3d",OT.array[i]);
    }
    printf("\n");
}

void swap(ElemType &a,ElemType &b){
    ElemType temp;
    temp=a;
    a=b;
    b=temp;
}

void BubbleSort(ElemType *arr,int len){
    for(int i=0;i<len-1;++i){
        for(int j=0;j<len-i-1;++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int Partition(ElemType *arr,int low,int high){
    ElemType pivot=arr[low];
    while(low<high){
        while(low<high&&arr[high]>=pivot){
            --high;
        }
        arr[low]=arr[high];
        while(low<high&&arr[low]<=pivot){
            ++low;
        }
        arr[high]=arr[low];
    }
    arr[low]=pivot;
    return low;
}

void QuickSort(ElemType *arr,int low,int high) {
    if (low<high) {
        int pivot_pos=Partition(arr,low,high);
        QuickSort(arr,low,pivot_pos-1);
        QuickSort(arr,pivot_pos+1,high);
    }
}

void InsertSort(ElemType *arr,int len){
    int i,j,insertVal;
    for(i=1;i<len;++i){
        insertVal=arr[i];
        for(j=i-1;j>=0&&arr[j]>insertVal;--j){
            arr[j+1]=arr[j];
        }
        arr[j+1]=insertVal;
    }
}

int main(){
    OrderTable OT;
    InitTable(OT,10);

    BubbleSort(OT.array,OT.length);
    PrintTable(OT);

    QuickSort(OT.array,0,OT.length-1);
    PrintTable(OT);

    InsertSort(OT.array,OT.length);
    PrintTable(OT);


    return 0;
}