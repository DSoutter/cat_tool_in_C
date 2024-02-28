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