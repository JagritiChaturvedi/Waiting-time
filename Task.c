#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;         
    int exec;
} Task;
int cmp(const void *a,const void *b) {
    Task *A=(Task*)a;
    Task *B=(Task*)b;
    return A->exec-B->exec;
}
void sch(Task t[], int n) {
	int i;
    qsort(t, n, sizeof(Task), cmp);
	int total=0;
    printf("Execution order will be:\n");
    for ( i = 0; i < n; i++) {
        printf("Task Number: %d, Execution Time: %d\n",t[i].id,t[i].exec);
        total += (i * t[i].exec);
    }
    printf("Total waiting time is : %d\n", total);
}

int main() {
    int n,i;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    Task *t=(Task*)malloc(n*sizeof(Task));
    for(i=0;i<n;i++){
        t[i].id=i+1; 
        printf("Enter execution time for %d: ",t[i].id);
        scanf("%d",&t[i].exec);
    }
    sch(t,n);
	free(t);
    return 0;
}
