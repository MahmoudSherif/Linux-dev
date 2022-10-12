#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>



int main(int argc, char** argv )
{
    char buf[100];
    int src_fd;
    int dest_fd;
    int read_count =0;

    src_fd = open(argv[1],O_RDONLY);
    if(src_fd == -1)
    {
        /* TODO : CHECK ON ERROR TYPE */
        puts("ERROR");
        return 0;
    }

    dest_fd = open(argv[2],O_CREAT | O_RDWR, 0644 );
    if(dest_fd == -1)
    {
        /* TODO : CHECK ON ERROR TYPE */
        puts("ERROR");
        return 0;
    }
    
    while ( (read_count = read(src_fd, buf, 100) ) != 0  )
    {
        /* TODO : ERROR CHECKING*/
        
        write(dest_fd,buf,read_count);
        /* TODO : ERROR CHECKING*/
    } 

    close(src_fd);
    /* TODO : ERROR CHECKING*/
    close(dest_fd);
    /* TODO : ERROR CHECKING*/

    return 0;
}
