In my CSE3320 course, I implemented a priority scheduler, the user program ps, a number of system calls, and a test application. <br> <br>

Process Control Block <br>
I modified the process control block to include the effective priority and real priority of a process. The priority must be in the p->lock section of the process. All processes default to a priority of 0.

<br> <br>
System Calls <br>
int setPrority( int pid, int priority ) <br>
You will implement a system call that will set the priority of a process. Valid priority levels are -20 to 20. You will store the priority of a process in its process control block as the process's real priority. This routine should return 0 if successful, and -1 otherwise (if, for example, the caller passes in an invalid prority).

int setEffectivePriority( int pid, int priority ) <br>
This system call sets the effective priority of the process with the given pid. This routine should return 0 if successful, and -1 otherwise (if, for example, the caller passes in an invalid pid or a priority < -20 or > 20.

int getpinfo(struct pstat *) <br>
The next is int getpinfo(struct pstat *). This routine returns some information about all running processes, including how many times each has been chosen to run and the process ID of each. You will use this system call to build a variant of the command line program ps, which can then be called to see what is going on. The structure pstat is defined below; note, you cannot change this structure, and must use it exactly as is. This routine should return 0 if successful, and -1 otherwise (if, for example, a bad or NULL pointer is passed into the kernel). getpinfo will read from the process table and populate the pstat function and then copy out the pstat function.

<br> <br>
ps <br>
The ps application prints the following: <br>
Your ps application will print the following: <br> <br>

NAME    PID     STATUS      PRIORITY <br>    
init    1       SLEEPING    1      <br>
sh      2       SLEEPING    1   <br>
test    4       SLEEPING    -10       <br>
ps      6       RUNNING     20   <br>

<br> <br>
Building and Running XV6 <br> <br>

To build the kernel: <br> <br>
make 

<br> <br>
To build the userspace applications and run the OS <br> <br>
make qemu

<br> <br>
To exit xv6
<br> <br>
ctrl-a x
