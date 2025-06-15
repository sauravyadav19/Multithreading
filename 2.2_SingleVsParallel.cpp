//Converting Sequential File Downloading (single threaded) into Parallel one (Multiple threads)
//For sequential version of this refer to 2.1_SingleVsParallel.cpp
#include<iostream>
#include<thread>
#include<vector>
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
    vector<thread> threads;
        //assing each of thread with task of dowloading a file
    for (int i = 1; i<=5; i++){
        //creating 5 threads and asinging each thread the task of running downloadFile
        //the constructor of thread looks like this:
        //std::thread(Callable&& f, Args&&... args);
        //so whatever argument we want to pass to the function that we are passing to thread and  we want to give its
        //parameter as an arugment meaning downloadfile(i) => thread(download,i)
        threads.emplace_back(downloadFile,int(i));
        // the above line of code is just a shorter and more memory efficient code of following:
            //std::thread t(download_file, i);
            //threads.push_back(std::move(t));
        //when passing the arugments to the fucntion that will be called its better to explictly say its type or else it would 
        //lead to some unexpected result. so instead of `threads.emplace_back(downloadFile,i);` we do this threads.emplace_back(downloadFile,int(i));

    }
        // join them
    for(auto&t:threads){
        t.join();
    }
    auto endTime = chrono::high_resolution_clock::now();
    auto totalDuration= chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
    cout<<"The total time Taken : " << totalDuration <<" seconds" <<endl;

   return 0;
}

/*
******conclusion******
1. Time
 => total time taken in sequential (single thread) = numOfFiles * time Taken by one file
                                                   = 5 * 2
                                                   = 10 seconds
 => total time taken in parallel (multiple threads) = max(Time by one file)
                                                    = max(2)
                                                    = 2 seconds
2. The ouput might look like "jumbled"
    Starting download of file_1.txt
    Starting download of file_2.txt
    Starting download of file_3.txt
    Starting download of file_4.txt
    Starting download of file_5.txt
    Finish downloading file_Finish downloading file_2.txt
    1.txt
    Finish downloading file_3.txt
    Finish downloading file_4.txt
    Finish downloading file_5.txt
    The total time Taken : 2 seconds
=> this is happending becasue all the threads are trying to write to the output at the same time, as output stream is shared resource
=> how to solve? Next topic
*/
