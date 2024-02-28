#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 80
char buffer[BUFFER_SIZE];

int main()
{
    ssize_t bytes_read;
    bytes_read = read(0, buffer, BUFFER_SIZE);
    write (1, buffer, bytes_read);
}