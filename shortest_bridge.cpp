#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void increaseisland(int **m, int n, int i, int j, queue<pair<int,int>>& q){
	if(i>=n || j>=n || i<0 || j<0 || m[i][j]!=1){
		return;
	}
	m[i][j]=2;
	q.push({i,j});
	increaseisland(m, n, i-1, j, q);
	increaseisland(m, n, i+1, j, q);
	increaseisland(m, n, i, j+1, q);
	increaseisland(m, n, i, j-1, q);
}


int shortestbridge(int **m, int n){
	 queue<pair<int, int>> q;

    // Find the first island and mark it as visited
    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < n && !found; j++) {
            if (m[i][j] == 1) {
            	increaseisland(m, n, i, j, q);
                found = true;
            }
        }
    }

    // BFS to find the shortest bridge
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int distance = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;

            for (int j = 0; j < 4; j++) {
                int nx = x + directions[j][0];
                int ny = y + directions[j][1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (m[nx][ny] == 1) {
                        return distance;
                    }
                    if (m[nx][ny] == 0) {
                        m[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
        }
        distance++;
    }

    return -1; // If no bridge is found
}

int main(){
    int n=0;
    cout<<"pls enter the size of matrix:\n";
    scanf("%d", &n);
	fflush(stdin);
    cout<<"pls enter the element of the matrix\n";
	int **m=(int**)malloc(n*sizeof(int*));
	for(int i=0; i<n;i++){
		m[i]=(int*)malloc(n*sizeof(int));
	}
	for(int i=0; i<n; i++){
		for(int k=0; k<n; k++){
			printf("Enter element %d%d  ", i+1,k+1);
			scanf("%d", &m[i][k]);
			fflush(stdin);
		}
	}
	// for(int f=0; f<n; f++){
	// 	for(int l=0; l<n; l++){
	// 		cout<<m[f][l]<<" "<<f<<" "<<l<<" \n";
	// 	}
	// }
    int result=0;
    result=shortestbridge(m, n);
    cout<<"the shortest bridge is:\n"<<result;
    return 0;
}