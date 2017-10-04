#include <stdlib.h>
#include <stdio.h>

/*
 * pole : 1, 2, 3
 * disk : 1, 2, 3
 */
int move(int disk, char src, char dest, char aux)
{
    if (disk == 1){
        printf("->moving %d from %c to %c\n", disk, src, dest);
        return 0;
    }
    move(disk-1, 1, 2, 3);     

    printf(">moving %d from %c to %c\n", disk, src, dest);

    move(disk-1, 2, 3, 1);
}

void run()
{
    move(3, 'A', 'B', 'C'); 
}

int main()
{
    int num_disk = 3;
    
    run();
    return 0;
}


