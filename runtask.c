#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define TASK_SCHEDULER "/usr/lib/taskrelay/task-scheduler"

int main(int argc, char** argv)
{
    uid_t caller_uid = getuid();
    struct passwd* p = getpwuid(caller_uid);
    if(!p)
    {
        perror("Unable to obtain user name");
        return 1;
    }

    char** args = malloc(sizeof(char*)*(argc+2));
    if(!args)
    {
        perror("Unable to allocate memory");
        return 1;
    }

    args[0] = TASK_SCHEDULER;
    args[1] = p->pw_name;
    for(int i = 1; i < argc; ++i)
        args[i+1] = argv[i];
    args[argc+1] = NULL;

    execv(TASK_SCHEDULER, args);

    perror("Unable to run task scheduler");
    return 1;
}
