#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **env)
{
    // GET ENV back /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
    char *path = getenv("PATH");
    int p = path - 0;
    printf("%s %d GETENV\n", path, p);
    struct stat st;
}