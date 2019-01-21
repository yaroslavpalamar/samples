#include <iostream>
using namespace std;

/*
 * 1. Round Robin when all processes alomos equal, for example user operation system.
 * 2. When you type something on keyboard for example and want fast reaction.
 * 3. Round Robin preempt processes in cycle.
 * 4. The disadvantage of it is more overhead of context switching
 * 5. Turn Around Time: Time Difference between completion time and arrival time. Turn Around Time = Completion Time – Arrival Time
 * 6. Waiting Time(W.T): Time Difference between turn around time and burst time.
 * Waiting Time = Turn Around Time – Burst Time
 * 7. Burst Time:         Time required by a process for CPU execution. 
 * 8. Burst time can be predicted for SJF algo (exist static method(calc proc size and process type) and dynamic method)
 * 9. Exist other algorithms:
	First Come First Serve (FCFS): Simplest scheduling algorithm that schedules according to arrival times of processes.
	Shortest Job First(SJF): Process which have the shortest burst time are scheduled first.
 
1- Create an array rem_bt[] to keep track of remaining
   burst time of processes. This array is initially a 
   copy of bt[] (burst times array)
2- Create another array wt[] to store waiting times
   of processes. Initialize this array as 0.
3- Initialize time : t = 0
4- Keep traversing the all processes while all processes
   are not done. Do following for i'th process if it is
   not done yet.
    a- If rem_bt[i] > quantum
       (i)  t = t + quantum
       (ii) bt_rem[i] -= quantum;
    c- Else // Last cycle for this process
       (i)  t = t + bt_rem[i];
       (ii) wt[i] = t - bt[i]
       (ii) bt_rem[i] = 0; // This process is over
 */

 
// Function to find the waiting time for all processes 
void findWaitingTime(int processes[], int n, 
             int bt[], int wt[], int quantum) 
{ 
	// Make a copy of burst times bt[] to store remaining burst times. 
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] =  bt[i]; 
  
	int t = 0; // Current time 
  
	// Keep traversing processes in round robin manner until all of them are not done. 
	while (1) { 
		bool done = true; 
  		
		// Traverse all processes one by one repeatedly 
		for (int i = 0 ; i < n; i++) { 
			// If burst time of a process is greater than 0 
			// then only need to process further 
			if (rem_bt[i] > 0) { 
				done = false; // There is a pending process 
  
				if (rem_bt[i] > quantum) { 
					// Increase the value of t i.e. shows 
					// how much time a process has been processed 
					t += quantum; 
  
					// Decrease the burst_time of current process by quantum 
					rem_bt[i] -= quantum; 
                		}
				// If burst time is smaller than or equal to 
				// quantum. Last cycle for this process 
				else { 
					// Increase the value of t i.e. shows 
					// how much time a process has been processed 
					t = t + rem_bt[i]; 
  
					// Waiting time is current time minus time used by this process 
					wt[i] = t - bt[i]; 
  
					// As the process gets fully executed 
					// make its remaining burst time = 0 
					rem_bt[i] = 0; 
				}
			}
		}
		// If all processes are done 
		if (done == true) 
			break; 
	} 
}
  
// Function to calculate turn around time 
void findTurnAroundTime(int processes[], int n, 
                        int bt[], int wt[], int turnArTime[]) 
{
	// calculating turnaround time by adding bt[i] + wt[i] 
	for (int i = 0; i < n ; i++) 
		turnArTime[i] = bt[i] + wt[i]; 
}
  
// Function to calculate average time 
void findAvgTime(int processes[], int n, int bt[], int quantum) 
{ 
	// tat mean turn around time
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
	// Function to find waiting time of all processes 
	findWaitingTime(processes, n, bt, wt, quantum); 
  
	// Function to find turn around time for all processes 
	findTurnAroundTime(processes, n, bt, wt, tat); 
  
	// Display processes along with all details 
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 
  
	// Calculate total waiting time and total turn around time 
	for (int i=0; i<n; i++) { 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 
  
	cout << "Average waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
}

// Driver code 
int main() 
{ 
	int processes[] = { 1, 2, 3}; 
	int n = sizeof processes / sizeof processes[0]; 
  
	// Burst time of all processes 
	int burstTime[] = {10, 5, 8}; 
  
	// Time quantum 
	int quantum = 2; 
	findAvgTime(processes, n, burstTime, quantum); 
	return 0; 
}
