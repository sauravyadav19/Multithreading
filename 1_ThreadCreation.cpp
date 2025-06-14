#include <iostream>
#include <thread> //contains all the thread related code
using namespace std;

void taskA(){
    cout<<"Task A Starts\n";
    cout<<"Task A ends\n";
}

void taskB(){
    cout<<"Task B Starts\n";
    cout<<"Task B ends\n";
}


int main(){

    thread t1(taskA); // create a thread and assign it to do taskA
    thread t2(taskB); // create a thread and assign it to do taskB

    //these two threads are running in parallel

    // join() is always called from the perspective of the thread that created the other threads
    //here "main" thread is manager for both t1 and t2
    t1.join();
    t2.join();

    return 0;
}