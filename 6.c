#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define OUTOFBOUND -2147483648
#define HAVENOTSET -2147483647
#define SETSUCCESS 1
typedef struct array{
	int start;
	int length; 
	int value[10000];
} ARRAY;

void init(ARRAY *a,  int left, int right){
	a->start=left;
	a->length=right-left+1;
	int i,j;
	for(i=0;i<a->length;i++){
		a->value[i]=-9999;
	}
	return;
	/*
	for(i=0;i<10000;i++){
		if(a->value[i]==-1){
			for(j=left;j<right+1;j++){
				a->value[j+5000]=-1;
			}
			return;
		}
	}
	for(i=left;i<right+1;i++){
		a->value[i+5000]=-1;
	}
	for(i=left-1;i>=-5000;i--){
		a->value[i+5000]=-9999;
	}
	for(i=right+1;i<5000;i++){
		a->value[i+5000]=-9999;
	}
	return;
	*/
}
int set(ARRAY *a, int index, int value){
	if(index-(a->start)>=0 && index-(a->start)<a->length){
		a->value[index-(a->start)]=value;
		return 1;
	}
	return -2147483648;
}
int get(ARRAY *a, int index){
	if(index-(a->start)>=0 && index-(a->start)<a->length){
		if(a->value[index-(a->start)]!=-9999){
			return a->value[index-(a->start)];
		}
		else return -2147483647;
	}
	return -2147483648;	
}
void print(ARRAY *a){
	int i;
	for(i=0;i<a->length;i++){
			if(a->value[i]==-9999){
				printf("No value\n");
			}
			else printf("%d\n",a->value[i]);
		}
	
	return;
}
void sort(ARRAY *a){
	int i,put=a->length-1;
	for(i=a->length-1;i>=0;i--){
		if(a->value[i]!=-9999){
			int temp = a->value[i];
			a->value[i] = -9999;
			a->value[put] = temp;
			put--;
		}
	}
	return;
}

void test_specall() {
    int n, l, r , i;
    int cmds, cmd, aid;
    int index, value;
    scanf("%d", &n);
    ARRAY *a = (ARRAY *) malloc(sizeof(ARRAY)*n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);
        init(&a[i], l, r);
    }
    scanf("%d", &cmds);
    for (i = 0; i < cmds; i++) {
        scanf("%d %d", &cmd, &aid);
        if (cmd == 1) {
            print(&a[aid]);
        } else if (cmd == 2) {
            scanf("%d %d", &index, &value);
            int ret = set(&a[aid], index, value);
            printf("ARRAY ID %d, set(%d, %d) %s\n", aid, index, value, 
                ret == SETSUCCESS ? "SUCCESS" : (ret == OUTOFBOUND ? "OUTOFBOUND" : "HAVENOTSET"));
        } else if (cmd == 3) {
            scanf("%d", &index);
            int ret = get(&a[aid], index);
            printf("ARRAY ID %d, get(%d) ", aid, index);
            if (ret == OUTOFBOUND)    
                printf(": OUTOFBOUND\n");
            else if (ret == HAVENOTSET)
                printf(": HAVENOTSET\n");
            else
                printf("= %d\n", ret);
        } else if (cmd == 4) {
            sort(&a[aid]);
        } else {
            assert(0);
        }
    }
}
int main() {
    int spec = 0;
    void (*FUNC[])() = {test_specall};
    FUNC[spec]();
    return 0;
}
