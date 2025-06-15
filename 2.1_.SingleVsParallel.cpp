// Sequential Way of Downloading  files (single threaded)
#include<iostream>
#include<thread>
#include<chrono> //Header file for handling time related work
using namespace std;

void downloadFile(int fileNumber){
    cout<<"Starting download of file_"<<fileNumber<<".txt\n";
    std::this_thread::sleep_for(chrono::seconds(2)); // simulates a 2 second download by putitng the working thread in sleep
    cout<<"Finish downloading file_"<<fileNumber<<".txt\n";
}
int main(){

    auto startTime = chrono::high_resolution_clock::now(); // starts a timer
    downloadFile(1);
    downloadFile(2);
    downloadFile(3);
    downloadFile(4);
    downloadFile(5);
    auto endTime = chrono::high_resolution_clock::now(); // ends the timer
    //Total time Taken = endTime - startTime
    auto totalDuration = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
    // we have to convert it to something readable to human so typecasting it to duration_cast and then extracting the seconds using .count()
    cout<<"The total time Taken : " << totalDuration <<" seconds" <<endl;
    return 0;
}