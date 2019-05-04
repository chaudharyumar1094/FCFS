#include<iostream>
using namespace std;
int main() {
	int n,brst[20],wrst[20],tat[20],avgwt=0,avgtat=0,i,j;
	cout<<"Enter total number of processes(maximum 20):";
	cin>>n;
	cout<<"nEnter Process Burst Timen";
	for (i=0;i<n;i++) {
		cout<<"P["<<i+1<<"]:";
		cin>>brst[i];
	}
	wrst[0]=0;
	//waiting time for first process is 0
	//calculating waiting time
	for (i=1;i<n;i++) {
		wrst[i]=0;
		for (j=0;j<i;j++)
		            wrst[i]+=brst[j];
	}
	cout<<"nProcessttBurst TimetWaiting TimetTurnaround Time";
	//calculating turnaround time
	for (i=0;i<n;i++) {
		tat[i]=brst[i]+wrst[i];
		avgwt+=wrst[i];
		avgtat+=tat[i];
		cout<<"nP["<<i+1<<"]"<<"tt"<<brst[i]<<"tt"<<wrst[i]<<"tt"<<tat[i];
	}
	avgwt/=i;
	avgtat/=i;
	cout<<"nnAverage Waiting Time:"<<avgwt;
	cout<<"nAverage Turnaround Time:"<<avgtat;
	return 0;
}
