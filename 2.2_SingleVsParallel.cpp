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
   return 0;
}
