#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char** argv )
{

    int my_pid = getpid();
    printf("my pid is %d\n",my_pid);

    
    char localVarStr[10][10]={0};
    int lv_counter =0;
    
    char local_vars[10][10];
    char local_vars_values[10][10];
    while (1)
    {
        char buf[100];
        char args[100][100]; 
        char* myargv[10];
        char* myargc[10];

        fputs("ana gahez ya basha >",stdout);
        fgets(buf,100,stdin);
        // printf("%d",buf[0]);
        int lVar_flag=0;

        if (buf[0]==10)
        {
            continue;
        }else 
        {
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
                    /* handling local variables */
                    if (lastChar == '=')
                    {
                        args[j][k-1]=0;
                        myargv[j] = args[j];
                        j++;
                        k=0;
                        lVar_flag = 1;
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



            if(strcasecmp(myargv[0],"set")== 0)
            {
                /* display local variables */
                for(int i=0;i<lv_counter;i++)
                {
                    printf("Local_variable[%d] %s\n",i,localVarStr[i]);
                }
            }else if (strcasecmp(myargv[0],"export")== 0)
            {
                /* adding the local variable to the environment */
                for(int i=0;i<lv_counter;i++)
                {
                    if (strcasecmp(myargv[1],local_vars[i])==0)
                    {
                        setenv(local_vars[i],local_vars_values[i],1);
                    }
                }
            }else if(lVar_flag==1)
            {
                strcpy(local_vars[lv_counter],myargv[0]);
                strcpy(local_vars_values[lv_counter],myargv[1]);

                // printf("local var %s is %s",local_vars[lv_counter],local_vars_values[lv_counter]);
                strcpy(localVarStr[lv_counter],buf);
                lv_counter ++;
                /* add a local variable to the list */
            }else 
            {
                
                int ret_pid = fork();
                
                if(ret_pid < 0)
                {
                    fputs("ERROR HAPPENED", stdout);
                    /* TODO: ERROR CHECKING */

                }else if (ret_pid > 0)
                {
                    // printf("this is the parent and my pid is %d and my child pid is %d\n",getpid(),ret_pid);
                    int status;
                    wait(&status);
                }else if (ret_pid == 0)
                {
                // printf("The is the child - my id id %d and my parent id is %d\n",getpid(),getppid());

                    sleep(1);

                    execvp(myargv[0],myargv);

                }                
            }
            
        }
    }

        
    return 0;

}
