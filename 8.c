#include <stdio.h>
#include <ctype.h>

int main(){
	
	int N,m=0,n=0,i,j,k,check,count,countn,countsame,ccount,countN1=0,countN2=0,minn;
	char c =48;
	scanf("%d",&N);
	char A[6];
	char B[100]={'~'};
	char C[100]={'~'};
	for(i=0;i<N;i++){
		check=1;
		count=0;
		countn=0;
		ccount=0;
		scanf("%s",&A);
		if(A[2] != '-' && A[3] != '-'){
			check=0;
		}
		else{
			for(j=0;j<7;j++){
				if(isalnum(A[j])!=0){
					ccount++;
				}
				if(isalpha(A[j])!=0){
					count++;
				}
				else if(isdigit(A[j])!=0){
					int b = A[j]-'0';
					countn += b;
				}
			}
			if(count==6)check=0;
			else if(countn % 7 == 0)check=0;
			else if(ccount != 6)check=0;
			for(j=0;j<6;j++){
				countsame=1;
				for(k=j+1;k<7;k++){
					if(A[j]==A[k]){
						countsame++;
					}
				}
				if(countsame > 2){
					check=0;
					break;
				}
			}
			
			if(A[2]=='-'){
				if((A[0]=='4'&&A[1]=='4') == 1){
					check=0;
				}
				for(j=3;j<6;j++){
					if((A[j]=='4'&&A[j+1]=='4') == 1){
						check=0;
						break;
					}
				}
			}
			else if(A[3]=='-'){
				if(((A[0]=='4'&&A[1]=='4') || (A[1]=='4'&&A[2]=='4'))== 1){
					check=0;
				}
				else if(((A[4]=='4'&&A[5]=='4') || (A[5]=='4'&& A[6]=='4')) == 1){
					check=0;
				}
			}
			
		}
		if(check != 0 && A[2]=='-'){
			k=0;
			for(j=m;j<m+7;j++){
				B[j] = A[k];
				k++;
			}
			m=j;
			countN1++;	
		}
		else if	(check != 0 && A[3]=='-'){
			k=0;
			for(j=n;j<n+7;j++){
				C[j] = A[k];
				k++;
			}
			n=j;	
			countN2++;
		}	
	}
//	printf("%s",B);
//	printf("%s",C);
//	printf("%d %d ",countN1,countN2);
	for(k=0;k<countN1;k++){
		int minn = 0;
		char min=127;
		for(i=0;i<7*countN1;i+=7){
			
		 
		 
		 if(B[i]<min){
		 	min = B[i];
		 	minn = i;
		 }
		 else if(B[i]==min){
		 		for(j=1;j<7;j++){
		 			if(B[i+j]<B[minn+j]){
		 				min = B[i];
		 				minn = i;
		 				break;
					 }
				 }
		 }
		}
		for(i=minn;i<minn+7;i++){
			printf("%c",B[i]);
			B[i]='~';
			}
//		printf("%s",B);
		printf("\n");
	}
	for(k=0;k<countN2;k++){
		int minn = 0;
		char min=127;
		for(i=0;i<7*countN2;i+=7){
			
		 
		 
		 if(C[i]<min){
		 	min = C[i];
		 	minn = i;
		 }
		 else if(C[i]==min){
		 		for(j=1;j<7;j++){
		 			if(C[i+j]<C[minn+j]){
		 				min = C[i];
		 				minn = i;
		 				break;
					 }
				 }
		 }
		}
		for(i=minn;i<minn+7;i++){
			printf("%c",C[i]);
			C[i]='~';
			}
//		printf("%s",B);
		printf("\n");
	}
/*	for(i=0;i<100000;i+=8){
		if(B[i] == ' '){
			break;
		}
		else {
			if(B[i]==c){
				for(j=i;j<i+7;j++){
					printf("%c\n",B[j]);
				}
			}
		}
	}
*/	
	return 0;
}
