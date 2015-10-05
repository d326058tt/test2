#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,k,i,j,m;
	scanf("%d%d",&n,&k);
	int arraya[100][100]={0},arrayb[100][100]={0},arrayc[100][100]={0},counta[100][100]={0};
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&arraya[i][j]);
			if(arraya[i][j]==1){
				counta[i][j]+=1;
			}
		}
	}
	
	for(m=0;m<k;m++){
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			int count = 0;
			if(i-1 != -1 && j-1 != -1){
				if (arraya[i-1][j-1]==1){
					count += 1;
				}
			}
			if(i-1 != -1){
				if (arraya[i-1][j]==1){
					count += 1;
				}
			}
			if(i-1 != -1 && j+1 !=n){
				if (arraya[i-1][j+1]==1){
					count += 1;
				}
			}
			if(j+1 !=n){
				if (arraya[i][j+1]==1){
					count += 1;
				}
			}
			if(j-1 != -1){
				if (arraya[i][j-1]==1){
					count += 1;
				}
			}
			if(i+1 != n && j+1 !=n){
				if (arraya[i+1][j+1]==1){
					count += 1;
				}
			}
			if(i+1 != n){
				if (arraya[i+1][j]==1){
					count += 1;
				}
			}
			if(i+1 != n && j-1 !=-1){
				if (arraya[i+1][j-1]==1){
					count += 1;
				}
			}
		
			if(arraya[i][j] == 1){
				
				if(count < 2){
					arrayb[i][j] = 0;
				}
				if(count == 2 || count == 3){
					arrayb[i][j] = 1;
				}
				if(count > 3){
					arrayb[i][j] = 0;
				}
			}
			if(arraya[i][j] == 0){
				if(count == 3){
					arrayb[i][j] = 1;
				}
				else arrayb[i][j] = 0;
			}
			if(arrayb[i][j] == 1){
				counta[i][j] = counta[i][j] + 1;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			arrayc[i][j]=arrayb[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			arrayb[i][j]=arraya[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			arraya[i][j]=arrayc[i][j];
		}
	}
}

for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			printf("%d ",arraya[i][j]);
		}
		printf("%d",arraya[i][n]);
		printf("\n");
	}
int maxi=0,maxj=0;
for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(counta[i][j]>=counta[maxi][maxj]){
				maxi=i;
				maxj=j;
			}
			}
			
		}
printf("%d %d",maxi+1,maxj+1);		
	
	
	
	
	
	
	
	return 0;
}
