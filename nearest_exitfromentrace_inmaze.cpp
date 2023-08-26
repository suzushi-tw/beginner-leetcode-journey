#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int findentrace(char **m, int r, int c, int startx, int starty){
    queue<pair<int,int>> q;
    q.push({startx, starty});
    int x=0;
    int y=0;
    int steps=1;
    vector<vector<int>> direction={{0,1}, {1,0}, {0,-1}, {-1,0}};
    m[startx][starty]='+';
    while(!q.empty()){
        int length=q.size();
        for(int i=0; i<length; i++){
            pair<int,int> temp=q.front();
            cout<<"temp"<<temp.first<<" "<<temp.second<<" \n"; 
            q.pop();
            for(int f=0; f<4; f++){
                x=temp.first+direction[f][0];
                y=temp.second+direction[f][1];
                cout<<"x and y"<<x<<" "<<y<<" \n";
                if(x<0 || y<0 || x>=r || y>=c || m[x][y]=='+'){
                    continue;
                }
                if(x==0 || y==0 || x==r-1 || y==c-1){
                    return steps;
                }
                m[x][y]='+';
                q.push({x, y});
            }
        }
        steps++;
    }
    return -1;
}

int main(){
    int r=0;
    cout<<"pls enter the number of rows:\n";
    scanf("%d", &r);
    int c=0;
    cout<<"pls enter theu number of columns:\n";
    scanf("%d", &c);
    fflush(stdin);
    cout<<"pls enter the element of the matrix\n";
	char **m=(char**)malloc(r*sizeof(char*));
	for(int i=0; i<r;i++){
		m[i]=(char*)malloc(c*sizeof(char));
	}
	for(int i=0; i<r; i++){
		for(int k=0; k<c; k++){
			printf("Enter element %d%d  ", i+1,k+1);
			scanf("%c", &m[i][k]);
            fflush(stdin);
		}
	}
    cout<<"pls enter the starting x coordinate:\n";
    int startx=0;
    scanf("%d", &startx);
    cout<<"pls enter the starting y coordinate:\n";
    int starty=0;
    scanf("%d", &starty);
    int result=0;
    result=findentrace(m, r, c, startx, starty);
    cout<<"the nearest exit from entrace is:"<<result;
    return 0;
}