//#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct map {
	int key[1024];
	char value[1024][127];
	int count;
} Map ;
void init(Map *map){
	int i,j;
	map->count=0;
	
	for(i=0;i<1024;i++){
		for(j=0;j<127;j++){
		
		strcpy(&map->value[i][j],"");
		}
	}
	return ;
}
int map(Map *map, const int key, const char *value){
	int i;
	if(strcmp(&map->value[key][0],"") != 0){
	strcpy (&map->value[key][0], value);
	return 0;
	}
	else{
		strcpy (&map->value[key][0], value);
		return 1;
	}
	map->count++;
}
int numPairs(Map *map){
/*	int count1=0,i;
	for(i=0;i<1024;i++){
		if(strcmp(&map->value[i][0],"")!=0){
			count1++;
			
		}
		if(count1 == map->count){
			
		}
	}
	*/
	return map->count;
}
void print(Map *map){
	printf("----- map begin -----\n");
	int i,count1=0;
	for(i=0;i<1024;i++){
		if(strcmp(&map->value[i][0],"") != 0){
			printf("%d %s\n",i,&map->value[i]);
			count1++;
		}	
		if(count1 == map->count){
			break;
		}	
	}
	printf("----- end       -----\n");
	return ;
}
const char *getValue(Map *map, const int key){
	if(strcmp(&map->value[key][0],"") != 0){
		return &map->value[key][0];
	}
	else return NULL;
}
int unmap(Map *map, int key){
	if(strcmp(&map->value[key][0],"") != 0){
		strcpy(&map->value[key][0],"");
		return 1;
    }
	else{
		strcpy(&map->value[key][0],"");
		return 0;
	}
	map->count--;
}
int reverseMap(Map *map, const char *value, int keys[]){
	int i,j=0,count=0;
	for(i=0;i<1024;i++){
		if(strcmp(&map->value[i][0],value) == 0){
			keys[j]=i;
			j++;
			count++;
		}
	}
	return count;	
}
 
void test_all(Map *maps, int map_n) {
    int i;
	for (i = 0; i < map_n; i++)
        init(&maps[i]);
    int cmds, mid, cmd, key;
    char val[128];
    int keylist[1024];
    scanf("%d", &cmds);
    for (i = 0; i < cmds; i++) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d", &mid);
            print(&maps[mid]);
        } else if (cmd == 2) {    
            scanf("%d %d %s", &mid, &key, val);
            int f = map(&maps[mid], key, val);
            printf("mf %d\n", f);
        } else if (cmd == 3) {
            scanf("%d %d", &mid, &key);
            int f = unmap(&maps[mid], key);
            printf("uf %d\n", f);
        } else if (cmd == 4) {
            scanf("%d %s", &mid, val);
            int keylist_n = reverseMap(&maps[mid], val, keylist);
            assert(keylist_n <= 1024);
            printf("list ");
            for (i = 0; i < keylist_n; i++)
                printf("%d%c", keylist[i], " \n"[i == keylist_n-1]);
        } else if (cmd == 5) {
            scanf("%d", &mid);
            int ret = numPairs(&maps[mid]);
            assert(ret <= 1024);
            printf("size %d\n", ret);
        } else {
            assert(false);
        }
    }
}
int main() {
    int spec;
    int map_n = 1;
    Map *maps = (Map *) malloc(sizeof(Map) * map_n);
    test_all(maps, map_n);
    free(maps);
    return 0;
}
	
	
	
	
	
	
	
	

