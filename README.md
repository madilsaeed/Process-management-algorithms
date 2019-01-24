# Process-management-algorithms
Analysis and implementation of process management algorithms

# What is process management?
Process Management is a process of allocating and managing the system resources among different process running in the operating system to enable the data sharing and exchange of information, protect the resources allocated by a process from another process and maintain synchronization among them to avoid dead locks.
# Why do we need it?
A process during its execution can have distinct process states. Various actions can change the process states. Process can state can be, submit state, Hold State, running state, Waiting state and completion state. 
To achieve the functionality of multiprocessing in the operation system, process management is one of the most important functionalities. We all know that a computer machine must have a limited number of resources. To manage these resources among different processes being executed in parallel operating systems use process management.
# Process Management Algorithms:
1.	First Come First Served
2.	Shortest-Job-First (non-preemptive)
3.	Shortest Remaining Time First (Preemptive Version of SJF)
4.	Priority Based
5.	Round Robin
6.	Multi-Level Queues
7.	Multiple Processor Scheduling
8.	Real Time Scheduling
# Shortest Remaining Time First (Preemptive Version of SJF):
The process with the smallest remaining time will be executed until its completion. If a new process come in, the execution of the current process gets suspended. If the Burst Time of the new process is lesser than the remaining Burst Time of the process that was being executed, operating system will save the state of the long process and start the execution of small one.

