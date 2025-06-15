//Converting Sequential File Downloading (single threaded) into Parallel one (Multiple threads)
//For sequential version of this refer to 2.1_SingleVsParallel.cpp
#include<iostream>
#include<thread>
using namespace std;

void downloadFile(int fileNumber){
    cout<<"Starting download of file_"<<fileNumber<<".txt\n";
    std::this_thread::sleep_for(chrono::seconds(2));
    cout<<"Finish downloading file_"<<fileNumber<<".txt\n";

}
int main(){

    auto startTime = chrono::high_resolution_clock::now();
    //Implement the thread-ed code
        //create multiple threads using vector
        //assing each of thread with task of dowloading a file
        // join them
    auto endTime = chrono::high_resolution_clock::now();
    auto totalDuration= chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
    cout<<"The total time Taken : " << totalDuration <<" seconds" <<endl;

   return 0;
}
