#include<stdio.h>
#include<stdbool.h>

int main(){
	bool win = false,check=true;
	int a[4][4]={0},i,j,n,count=0,oi,oj,b;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			
			scanf("%d",&a[i][j]);
			if(a[i][j]==0){
				oi=i;
				oj=j;
			}
		}
	}
	

	while(scanf("%d",&b)!=EOF){
		check=true;
		if(oi-1 != -1){
			
			if(a[oi-1][oj]==b){
				a[oi-1][oj]=0;
				a[oi][oj]=b;
				oi=oi-1;
				count++;
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(i==3 && j==3){
						if(a[i][j]==0){
							continue;
						}
						else {
					check = false;
					break;
}
					}
					if(a[i][j]==4*i+(j+1)){
						continue;
			}
			else{
				check = false;
				break;
				
			} 
	
	}
	
	}
			if(check==false){
			continue;
	
			}
			else {
				win = true;
				break;
	}
			}
		}
		if(oi+1 != 4){
	
			if(a[oi+1][oj]==b){
				a[oi+1][oj]=0;
				a[oi][oj]=b;
				oi=oi+1;
				count++;
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(i==3 && j==3){
						if(a[i][j]==0){
							continue;
						}
					
					else {
					check = false;
					break;
			}
				}
					if(a[i][j]==4*i+(j+1)){
						continue;
			}
				else{
					check = false;
					break;

			} 
	
	}
	
			}
			if(check==false){
	
			continue;
			}
			else {
				win = true;
				break;
	}
			}
		}
		if(oj-1 != -1){
	
			if(a[oi][oj-1]==b){
				a[oi][oj-1]=0;
				a[oi][oj]=b;
				oj=oj-1;
				count++;
				for(i=0;i<4;i++){
					for(j=0;j<4;j++){
					if(i==3 && j==3){
						if(a[i][j]==0){
							continue;
							
						}
					
					else {
					check = false;
					break;
					}
				}
					if(a[i][j]==4*i+(j+1)){
						continue;
			}
			else{
				check = false;
				break;
			} 
	
	}
	
	}
			if(check==false){
	
		continue;
			}
			else {
				win = true;
				break;
	}
			}
		}
		if(oj+1 != 4){
	
			if(a[oi][oj+1]==b){
				a[oi][oj+1]=0;
				a[oi][oj]=b;
				oj=oj+1;
				count++;
				
				for(i=0;i<4;i++){
					for(j=0;j<4;j++){
					if(i==3 && j==3){
						if(a[i][j]==0){
							continue;
						}
						else {
					check = false;
					break;
					}
					}
			
					if(a[i][j]==4*i+(j+1)){
						continue;
			}
						else{
							check = false;
							break;
			} 
	
	}
	
	}
			if(check==false){
	
			continue;
			}
			else {
				win = true;
				break;
	}
			}
	}
		
		

		
	}
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
		
			printf("%d ",a[i][j]);
	}
	printf("%d",a[i][3]);
	printf("\n");
	}
	if(win==true){
		printf("1 ");
		printf("%d",b);
	}
	else printf("0");
	return 0;
	
	
}
