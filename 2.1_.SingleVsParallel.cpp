#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void downloadFile(int fileNumber){
    cout<<"Starting download of file_"<<fileNumber<<".txt\n";
    std::this_thread::sleep_for(chrono::seconds(2));
    cout<<"Finish downloading file_"<<fileNumber<<".txt\n";
}
int main(){

    auto startTime = chrono::high_resolution_clock::now();
    downloadFile(1);
    downloadFile(2);
    downloadFile(3);
    downloadFile(4);
    downloadFile(5);
    auto endTime = chrono::high_resolution_clock::now();
    auto totalDuration = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
    cout<<"The total time Taken : " << totalDuration <<" seconds" <<endl;
    return 0;
}