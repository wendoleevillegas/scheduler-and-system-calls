#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"
#include "process.h"

struct pstat 
{
    char name[NPROC][16];               // name of process
    enum procstate state[NPROC];        // state of process
    int inuse[NPROC];                   // whether this slot of the process table is in use (1 or 0)
    int effective_priority[NPROC];      // the effective priority of the process
    int real_priority[NPROC];           // real priority of the process
    int pid[NPROC];                     // PID of each process
    int ticks[NPROC];                   // number of ticks each process has accumulated

    // Printed output:
    /*
        NAME    PID   STATUS    PRIORITY
        init    1     SLEEPING     1
        sh      2     SLEEPING     1
        test    4     SLEEPING     -10
        ps      6     RUNNING      20
    
    */
};


#endif 