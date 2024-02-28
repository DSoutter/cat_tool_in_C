#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 80
char buffer[BUFFER_SIZE];

int main(int argc, char *argv[])
{
    int fd = STDIN_FILENO; // file descriptor

    if (argc > 1) {
        fd = open(argv[1], O_RDONLY);
    }
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE))) {
        write (STDOUT_FILENO, buffer, bytes_read);
    }

    close(fd);
}
// running gcc myCat.c creates the a.out executable
// run using ./a.out <test.txt
// the '<' is for input redirection
// ./a.out <test.txt <test2.txt does both files sequentially
// ./a.out >output.txt
// the '>' is for output redirection so instead of outputting to the terminal, it outputs to the file
// Adding fd and fd = open("./test.txt", O_RDONLY); reads directly from the file
// argc = count
// *argv = pointer to array of strings
// argv[0] = name of program so argv[1] is first input parameter