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

    downloadFile(1);

    return 0;
}