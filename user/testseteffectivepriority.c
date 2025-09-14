#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int pid = atoi(argv[1]);
    int priority = atoi(argv[2]);

    if(setEffectivePriority(pid, priority) == 0)
    {
        printf("PID: %d PRIORITY: %d\n", pid, priority);
    }

    else
    {
        printf("Failed to set priority to pid.\n");
    }

    

    exit(0);
}