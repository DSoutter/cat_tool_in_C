#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 80
char buffer[BUFFER_SIZE];

int main()
{
    ssize_t bytes_read;
    while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE))) {
        write (STDOUT_FILENO, buffer, bytes_read);
    };
}
// running gcc myCat.c creates the a.out executable
// run using ./a.out <test.txt
// the '<' is for input redirection
// ./a.out <test.txt <test2.txt does both files sequentially
// ./a.out >output.txt
// the '>' is for output redirection so instead of outputting to the terminal, it outputs to the file
