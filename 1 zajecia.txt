#include <iostream>
#include <stdio.h>

int main(){
#define size 10;
int numbers[10]={10,20,32, 40 ,-23, 23,-76,-9,20, 0};
for(int i=0;i<10;i++){
    printf("numbers[%d]=%d\n",i,numbers[i]);}
printf("///////////////////////////////\n");
    int minimum = numbers[0];
for(int i=0;i<10;i++){
   if(numbers[i]<minimum){
       minimum=numbers[i];}}
    printf("minimum%d\n",minimum);
    printf("///////////////////////////////\n");
    int max = numbers[0];
    for(int i=0;i<10;i++){
        if(numbers[i]>max){
            max=numbers[i];}}
    printf("max%d\n",max);
    printf("///////////////////////////////\n");
    { int sum=0;
    for(int i=0;i<10;i++)
        sum+=numbers[i];
    printf("suma%d\n",sum);}
    printf("///////////////////////////////\n");
    {int sum=0;
    for(int i=0;i<10;i++)
        sum+=numbers[i];
    float average;
    average+=(float)sum/10;
    printf("average=%f\n",average);}
    printf("///////////////////////////////\n");

float median(int numbers[10],int i){qsort(numbers,i,sizeof int),compare0;}
}