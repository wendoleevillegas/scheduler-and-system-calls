#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"
#include "kernel/riscv.h"
#include "kernel/process.h"

extern struct process_control_block process_table[NPROC];

const char *state_names(enum procstate state) // make function of state names for each process
{
    switch(state)
    {
        case UNUSED:
            return "UNUSED";
        case USED:
            return "USED";
        case SLEEPING:
            return "SLEEPING";
        case RUNNABLE:
            return "RUNNABLE";
        case ZOMBIE:
            return "ZOMBIE";
        default:
            return "RUNNING";
        }
   }


int main(int argc, char *argv[])
{

    struct pstat ps;
    getpinfo(&ps); // call the function getpinfo
    
    printf("NAME\tPID\tSTATUS\tPRIORITY\n");

    for(int i = 0; i < NPROC; i++) // go through each process, print out the values of the table
    {
        if(ps.inuse[i])
        {
            printf("%s\t%d\t%s\t%d\n", ps.name[i], ps.pid[i], state_names(ps.state[i]), ps.real_priority[i]);
        }
    }

    return 0;
}

    // Printed output:
    /*
        NAME    PID   STATUS    PRIORITY
        init    1     SLEEPING     1
        sh      2     SLEEPING     1
        test    4     SLEEPING     -10
        ps      6     RUNNING      20
    
    */