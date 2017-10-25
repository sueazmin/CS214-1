// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>


// int main(int c, char **v)
// {
// 	while(--c > 1 && !fork()); // child process
// 	int val = atoi(v[c]);
// 	sleep(val);
// 	printf("%d\n", val);

// 	return 0;

// }
/* ----------------------------------------------------------------- */
/* PROGRAM  fork-01.c                                                */
/*    This program illustrates the use of fork() and getpid() system */
/* calls.  Note that write() is used instead of printf() since the   */
/* latter is buffered while the former is not.                       */
/* ----------------------------------------------------------------- */

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
 
int main()
{
    int i;
    int pid = fork();
 
    if (pid == 0)
    {
        for (i=0; i<20; i++)
            printf("I am Child\n");
    }
    else
    {
    	wait(NULL);
        printf("I am Parent\n");
        while(1);
    }
}