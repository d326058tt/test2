#include<stdio.h>
#include<string.h>


int main(){
	int i,t=100;
	char word[100000]={' '},a,b,c,d;
	char word1[100000]={' '};
	char word2[100000]={' '};
	char cmd[10];
	scanf("%s",&word);
	int n = strlen(word);
	while(strcmp(cmd,"end") != 0){
		scanf("%s",cmd);
		if(strcmp(cmd,"replace") != 0 && strcmp(cmd,"remove") != 0 && strcmp(cmd,"addhead") != 0 && strcmp(cmd,"addtail") != 0 && strcmp(cmd,"end") != 0){
			printf("invaild command %s\n",cmd);
			return 0;
		}
		
		if(strcmp(cmd,"replace") == 0){
			scanf("%c%c%c%c",&a,&b,&c,&d);
			for(i=0;i<n;i++){
				if(word[i] == b){
					word[i] = d;
				}
			}
			printf("%s\n",word);
			
		}
		if(strcmp(cmd,"remove") == 0){
			scanf("%c%c",&a,&b);
			for(i=0;i<n;i++){
				if(word[i] == b){
					word[i] = ' ';
				}
			}
			printf("%s\n",word);
			
		}	
		if(strcmp(cmd,"addhead") == 0){
			int j=0;
			scanf("%c%c",&a,&b);
			word1[0] = b;
			for(i=0;i<n;i++){
				if(word[i] != ' '){
				word1[j+1]=word[i];
				j++;
				}
			}
			printf("%s\n",word1);
			int m = strlen(word1);
			for(i=0;i<n;i++){
				word[i]=word1[i];
			}
			printf("%s\n",word);
		}		
		if(strcmp(cmd,"addtail") == 0){
			int j=strlen(word);
			int k=0;
			scanf("%c%c",&a,&b);
			word1[0] = b;
			for(i=j;i>0;i--){
				if(word[i-1] != ' '){
				word1[k+1]=word[i-1];
				k++;
				}
			}
			printf("%s\n",word1);
			int m = strlen(word1);
			for(i=m;i>0;i--){
				word[m-i]=word1[i-1];
			}
			printf("%s\n",word);
			continue;
		}				
		
	}
	int m = strlen(word1);
	for(i=0;i<m;i++){
				if(word[i] != ' '){
					printf("%c",word[i]);
				}
			}
	return 0;
}
