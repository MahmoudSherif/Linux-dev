#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char** argv )
{

    int my_pid = getpid();
    printf("my pid is %d\n",my_pid);
    while (1)
    {
        char buf[100];
        char args[100][100]; 
        char* myargv[10];
        char* myargc[10];

        fputs("ana gahez ya basha >\n",stdout);
        fgets(buf,100,stdin);
        
        int len = strlen(buf);

        buf[len -1 ] = 0;
        int i=0,j=0,k=0;
        char lastChar = ' ';

        for(;i<len;i++)
        {
            if(buf[i]!=' ')
            {
                if (lastChar == ' ' && k!=0)
                {
                    args[j][k]=0;
                    myargv[j] = args[j];
                    j++;
                    k=0;
                }
                args[j][k]=buf[i];
                k++;
            }
            lastChar = buf[i];
        }
        args[j][k]=0;
        myargv[j] = args[j];
        j++;
        myargv[j] = 0;

        int ret_pid = fork();
        
        if(ret_pid < 0)
        {
            fputs("ERROR HAPPENED", stdout);
            /* TODO: ERROR CHECKING */

        }else if (ret_pid > 0)
        {
            printf("this is the parent and my pid is %d and my child pid is %d\n",getpid(),ret_pid);
            int status;
            wait(&status);
        }else if (ret_pid == 0)
        {
	    printf("The is the child - my id id %d and my parent id is %d\n",getpid(),getppid());

            sleep(1);

            execvp(myargv[0],myargv);

        }
    }
        
    return 0;

}
