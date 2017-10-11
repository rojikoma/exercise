#include <stdlib.h>
#include <stdio.h>

int move(int disk, char src, char dest, char aux)
{
    if (disk == 1){
        printf("- moving %d from %c to %c\n", disk, src, dest);
        return 0;
    }
    move(disk-1, src, aux, dest);     

    printf("- moving %d from %c to %c\n", disk, src, dest);

    move(disk-1, aux, dest, src);
}

void print_setting(int num_disk)
{
    int i,j;

    printf("disk info\n");
    for(j=0; j<num_disk; j++) {
        printf("%d", j+1);
        for(i=0; i<num_disk-j; i++) {
            printf(" ");
        }
        printf("[");
        for(i=0;i<j; i++) {
            printf("__");
        }
        printf("]\n");
    }
    printf("\npole info\n\n");
    printf(" ||   ||   ||  \n");
    printf(" ||   ||   ||  \n");
    printf("_||_ _||_ _||_ \n");
    printf(" A     B    C\n");
}

void run(int num_disk)
{
    move(num_disk, 'A', 'C', 'B'); 
}

int main()
{
    int num_disk;
    printf("enter disk num=");
    scanf("%d", &num_disk);
    print_setting(num_disk);    
    run(num_disk);
    return 0;
}


