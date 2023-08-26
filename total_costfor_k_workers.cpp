#include<stdio.h>
#include<iostream>
using namespace std;

void insertionsort(int cost[], int num){
    int key=0;
    int j=0;
    for(int i=0; i<num; i++){
        key=cost[i];
        j=i-1;
        while(j>=0 && cost[j]>key){
            cost[j+1]=cost[j];
            j=j-1;
        }
        cost[j+1]=key;
    } 
}

int totalcost(int cost[], int candidates, int k, int num){
    insertionsort(cost, num);
    int sum=0;
    for(int f=0; f<k; f++){
        sum+=cost[f];
    }
    return sum;
}

int main(){
    int num=0;
    cout<<"pls enter the number of interviewers:\n";
    scanf("%d", &num);
    int cost[num];
    for(int i=0; i<num; i++){
        scanf("%d", &cost[i]);
    }
    int candidates=0;
    cout<<"pls enter the number of candidates:\n";
    scanf("%d", &candidates);
    int k=0;
    cout<<"pls enter the amount of sessions to be interviewed:\n";
    //each session there will be one canditate hired
    int result=0;
    result=totalcost(cost, candidates, k, num);
    cout<<"the lowest cost to hire "<<k<<" worker is:";
    return 0;
}