#include <iostream>
#include <string>
#include <unistd.h>
#include <queue>
//#include <algorithm>
using namespace std;

class Process {
        public:
        string  name;
        int     arrival_time;
        int     waitint_time;
        int     burst_time;
        int     turnaround_time;
        int     response_time;
        int     finish_time;
        int     is_teacher = 0;
};

//sort the process array based on arrival time using Bubble sort
void sort_processes(vector<Process> &process_arr) {   
        for (int i = 0; i < process_arr.size(); i++) {
                for (int j = i + 1; j < process_arr.size(); j++) {
                        if (process_arr[i].arrival_time >= process_arr[j].arrival_time) {
                                swap(process_arr[i], process_arr[j]);
                        }
                }
        }
}

int process_count_time_t(vector<Process> process_arr, int t) {
        int count = 0;
        for (int i = 0; i < process_arr.size(); i++) {
                if (process_arr[i].arrival_time == t) {
                        count++;
                }
        }
        return count;
}

int main() {
        int num_of_processes;
        cout << "\tEnter the number of processes: ";
        cin >> num_of_processes;

        vector<Process> process_arr(num_of_processes);
        cout << "\tTaking input for " << num_of_processes << " processes one by one\n";

        sleep(2);
        for (int i = 0; i < num_of_processes; i++) {
                cout << "\t--------------------\n";
                cout << "\t     Process #" << i << "\n";
                cout << "\t--------------------\n";

                process_arr[i].name = "P" + to_string(i); 
                cout << "\t\tEnter the arrival time for this process: ";
                cin >> process_arr[i].arrival_time;
                cout << "\t\tEnter the burst time for this process: ";
                cin >> process_arr[i].burst_time;
                cout << "\t\tTeacher or student? (1 = Teacher/0 = Student): ";
                cin >> process_arr[i].is_teacher;
        }
        cout << "\n\n\tAll inputs taken successfully!" << endl;

        queue<Process> Q1, Q2, Q3;
        /*
                Q1 uses Round Robin algorithm with time quantum 5
                Q2 uses Round Robin algorithm with time quantum 8
                Q3 uses FCFC algorithm and is also the highest priority queue

                Any student processes requesting for the processor are added to the 
                Q1 first and make their way up until Q3.
                Any teacher processes requesting for the processor are added to the 
                Q3(highest priority queue) by default
        */

       sort_processes(process_arr);
       //for (auto x : process_arr) cout << x.name << endl;
        cout << "\n\n";
        cout << "\t-----------------------------------\n";
        cout << "\t        Starting Scheduling... \n";
        cout << "\t-----------------------------------\n";

        int t = 0;
        while(1) {
                cout << "\t At t = 0, number of processes asking for CPU: " << process_count_time_t(process_arr, 0) << endl;
                break;
        }
        sleep(2);
       for (int i = 0; i < num_of_processes; i++) {
               if (process_arr[i].is_teacher) {
                       Q3.push(process_arr[i]);
               }
       }
}