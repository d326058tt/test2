#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
	int arr[100000]={0},n,a,counttr=0,countfal=0,length=0,len[100]={0},i,j,k;
	bool check = true;
	scanf("%d",&n);
	for (i=0;i<100000;i++){
		scanf("%d",&a);
		if (a!=0){
			arr[i]=a;
			continue;
		}
		else break;
	}
	for (i=0;i<100000;i++){
		if(length == 0 && arr[i] < 0){
			continue;
		}
		else{
			if(check == true && arr[i] > 0){
				length += 1;
				counttr += 1;
			}
			else if(check == false && arr[i] < 0){
				length += 1;
				countfal += 1;
			}
			else{
				if(arr[i]<0){
					length -= n;
					length -= counttr;
					for(k=0;k<100;k++){
					if(len[k]!=0){
						continue;
					}
					else {
						len[k]=length;
						length = 0;
						counttr = 0;
						countfal = 0;
						check = true;
						break;
					}
				}
				}
				else{
					for(k=0;k<100;k++){
					if(len[k]!=0){
						continue;
					}
					else {
						len[k]=length;
						length = 1;
						counttr = 1;
						countfal = 0;
						if(counttr == n){
							check = false;
							counttr = 0;
						}
						break;
					}
					
				}
				
			}
		}
			if(counttr == n){
				check = false;
				counttr = 0;
			}
			if(countfal == n){
				check = true;
				countfal = 0;
			}
		
	}
}
		int max = len[0];
		for(j=1;j<100;j++){
		if(len[j]>max){
			max = len[j];
		}
			else continue;
		}
		printf("%d",max);
		return 0;
}
