#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#define INT_FAST32_MAX INT32_MAX

#define BUFFER_SIZE 80
char buffer[BUFFER_SIZE];

int main(int argc, char *argv[])
{
    int fd = STDIN_FILENO; // file descriptor
    int num_lines = INT_FAST32_MAX;// will work for files up to 2b lines



    if (argc > 1) {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1){ // function returns -1 if error opening the file
            write(STDERR_FILENO, "no file\n", 8);
            exit(EXIT_FAILURE);
        }
    }
    ssize_t bytes_read;
    if(argc > 2) {
        num_lines = atoi(argv[2]);

        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        FILE *file = fopen(argv[1], "r");
    for (int i = 0; i < num_lines; i++) {
        read = getline(&line, &len, file);
        write(STDOUT_FILENO, line, read);
    }

    free(line);
    } else {
        while ((bytes_read = read(fd, buffer, BUFFER_SIZE))) {
            write (STDOUT_FILENO, buffer, bytes_read);
        }   
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
