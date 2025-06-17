/*
Problem : In the previous Exercise (2.2_SingleVsParallel.cpp) we saaw how the output for our parallel 
code look "jumbled", this exercise is about exploring that problem in depth and the solution.

**Does the problem has a name? 
=> yes, it called Race condition, wherein two threads are trying to compete for the same resource
at the same time, the resouce could be a variable, a file or in our case the output stream; The race
condition will result in unexpected outputs and sometime in outright wrong ones.

** How can it be solved ?
=> we solve this by locking whatever resouce that is being shared for the duration of the thread currently
working on it for its duration.
Eg: Thread_1 and Thread 2 both require access to our output stream (cout)
so, say thread_1 get the access first
    LOCK
    Thread_1 using cout
    UNLOCK
and then Thread_2 get the access
    LOCK
    Thread_2 using cout
    UNLOCK

This Locking and Unlocking is using Mutex in C++
*/