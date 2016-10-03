de <stdio.h>


int main(){
	int N,M,i,j,n,d,k=0,l,no=0;
	scanf("%d%d",&N,&M);
	int place[10][10]={0};	
	int SX,SY,EX,EY;
	scanf("%d%d%d%d",&SX,&SY,&EX,&EY);
	if(SX==EX){
		if(SY<EY){
			for(i=SY;i<=EY;i++){
				place[SX][i]=k+1;
				k++;
			}
		}
		else{
			for(i=SY;i>=EY;i--){
				place[SX][i]=k+1;
				k++;
			}
		}
	}
	else if(SY==EY){
		if(SX<EX){
			for(i=SX;i<=EX;i++){
				place[i][SY]=k+1;
				k++;
			}
		}
		else{
			for(i=SX;i>=EX;i--){
				place[i][SY]=k+1;
				k++;
			}
		}
	}
	scanf("%d",&n);
	for(l=n;l>0;l--){
		if(no==1){
			break;
		}
		scanf("%d",&d);
		switch(d){
			case 0:
				if(SX+1==N){
					break;
				}
				if(place[SX+1][SY]!=0 && place[SX+1][SY]!=k){
					no=1;
					break;
				}
				place[EX][EY]=0;
				place[SX+1][SY]=-1;
				
				for(i=0;i<N;i++){
					for(j=0;j<M;j++){
						if(place[i][j]!=-1 && place[i][j]!=0){
							place[i][j]++;
						}
					}
				}
					for(i=0;i<N;i++){
						for(j=0;j<M;j++){
							if(place[i][j]==-1){
								SX=i;
								SY=j;
							}
							else if(place[i][j]==k){
								EX=i;
								EY=j;
							}
						}
				}
				place[SX][SY]=1;
				break;
			case 1:
				if(SX-1<0){
					break;
				}
				if(place[SX-1][SY]!=0 && place[SX-1][SY]!=k){
					no=1;
					break;
				}
				
				place[EX][EY]=0;
				place[SX-1][SY]=-1;
				
					for(i=0;i<N;i++){
					for(j=0;j<M;j++){
						if(place[i][j]!=-1 && place[i][j]!=0){
							place[i][j]++;
						}
					}
				}
					for(i=0;i<N;i++){
						for(j=0;j<M;j++){
							if(place[i][j]==-1){
								SX=i;
								SY=j;
							}
							else if(place[i][j]==k){
								EX=i;
								EY=j;
							}
						}
				}
				place[SX][SY]=1;
				break;
			case 2:
				if(SY+1==M){
					break;
				}
				if(place[SX][SY+1]!=0 && place[SX][SY+1]!=k){
					no=1;
					break;
				}
				
				place[EX][EY]=0;
				place[SX][SY+1]=-1;
				
				for(i=0;i<N;i++){
					for(j=0;j<M;j++){
						if(place[i][j]!=-1 && place[i][j]!=0){
							place[i][j]++;
						}
					}
				}
					for(i=0;i<N;i++){
						for(j=0;j<M;j++){
							if(place[i][j]==-1){
								SX=i;
								SY=j;
							}
							else if(place[i][j]==k){
								EX=i;
								EY=j;
							}
						}
				}
				place[SX][SY]=1;
				break;
			case 3:
				if(SY-1<0){
					break;
				}
				if(place[SX][SY-1]!=0 && place[SX][SY-1]!=k){
					no=1;
					break;
				}
				place[EX][EY]=0;
				place[SX][SY-1]=-1;
				
					for(i=0;i<N;i++){
					for(j=0;j<M;j++){
						if(place[i][j]!=-1 && place[i][j]!=0){
							place[i][j]++;
						}
					}
				}
					for(i=0;i<N;i++){
						for(j=0;j<M;j++){
							if(place[i][j]==-1){
								SX=i;
								SY=j;
							}
							else if(place[i][j]==k){
								EX=i;
								EY=j;
							}
						}
				}
				place[SX][SY]=1;
				break;
			default:
				break;
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(j==M-1 && place[i][j]!=0){
				printf("1\n");
			}
			else if(j==M-1 && place[i][j]==0){
				printf("0\n");
			}
			else if(place[i][j]!=0){
				printf("1");
			}
			else if(place[i][j]==0){
				printf("0");
			}
		}
	}
	return 0;
}
