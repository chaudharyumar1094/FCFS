#include<iostream>
using namespace std;
int main() {
	int brst[20],p1[20],wrst[20],tat[20],prt[20],i,j,n,total=0,pos,temp,avg_wrst,avg_tat;
	cout<<"Enter Total Number of Process:";
	cin>>n;
	cout<<"nEnter Burst Time and Priorityn";
	for (i=0;i<n;i++) {
		cout<<"nP["<<i+1<<"]n";
		cout<<"Burst Time:";
		cin>>brst[i];
		cout<<"Priority:";
		cin>>prt[i];
		p1[i]=i+1;
		//contains process number
	}
	//sorting burst time, priority and process number in ascending order using selection sort
	for (i=0;i<n;i++) {
		pos=i;
		for (j=i+1;j<n;j++) {
			if(prt[j]<prt[pos])
			                pos=j;
		}
		temp=prt[i];
		prt[i]=prt[pos];
		prt[pos]=temp;
		temp=brst[i];
		brst[i]=brst[pos];
		brst[pos]=temp;
		temp=p1[i];
		p1[i]=p1[pos];
		p1[pos]=temp;
	}
	wrst[0]=0;
	//waiting time for first process is zero
	//calculate waiting time
	for (i=1;i<n;i++) {
		wrst[i]=0;
		for (j=0;j<i;j++)
		            wrst[i]+=brst[j];
		total+=wrst[i];
	}
	avg_wrst=total/n;
	//average waiting time
	total=0;
	cout<<"nProcesst    Burst Time    tWaiting TimetTurnaround Time";
	for (i=0;i<n;i++) {
		tat[i]=brst[i]+wrst[i];
		//calculate turnaround time
		total+=tat[i];
		//cout<<"nP["<<p[i]<<"]tt  "<<bt[i]<<"tt    "<<wt[i]<<"ttt"<<tat[i];
		cout<<"nP"<<p1[i];
		cout<<brst[i];
		cout<<wrst[i];
		cout<<tat[i];
	}
	avg_tat=total/n;
	//average turnaround time
	cout<<"nnAverage Waiting Time="<<avg_wrst;
	cout<<"nAverage Turnaround Time="<<avg_tat;
	return 0;
}
