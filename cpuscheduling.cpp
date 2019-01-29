#include "cpuschedule.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <list>
#include <algorithm>


using namespace std;

list<Process> initialReadyQueue;
list<Process> tempReadyQueue;
list<Process> updatedReadyQueue;

cpuschedule::cpuschedule(void)
	{
	cout<<"\n\n================ WELCOME TO SHORTEST REMAINING TIME FIRST SCHEDULING ================\n\n";
	currentProcessNum = 0;
	totalNumberOfCPUCycles = 0;
	}

cpuschedule::~cpuschedule(void)
	{
	}

BOOL cpuschedule::SetProcessInTheReadyQueue()
	{
	BOOL retVal = FALSE;
	char text[256];
	char chTmp[50];
	string procName;
	int bTime = 0,aTime = 0;
	Process tmp;

	while(1)
		{
		cout<<"\n\n\n\n\tPlease Enter Number Of Processes In The ReadyQueue\n";
		cout<<"\n\tNumber of Processes: ";cin>>currentProcessNum;

		if(currentProcessNum > 0 && currentProcessNum <= MAX_PROCESS_CAPACITY)
			{
			retVal = TRUE;
			for(int i=0; i<currentProcessNum; i++)
				{

				procName = "Process";
				itoa(i+1,chTmp,10);
				procName.append(chTmp);

				cout<<"\nPlease Enter The Arival & The Burst Time Of "<<procName;
				cout<<"\n\n\tProcess" <<i+1 <<" Arival Time = ";
				cin>>aTime;
				cout<<"\n\tProcess" <<i+1 <<" Burst Time = ";
				cin>>bTime;

				if(aTime > maxArivalTime)
					maxArivalTime = aTime;

				if(bTime > maxBurstTime)
					maxBurstTime = bTime;


				tmp.pName = procName;
				tmp.arrivalTime = aTime;
				tmp.cpuBurstTime = bTime;
				tmp.isCompleted = FALSE;

				initialReadyQueue.push_back(tmp);

				}
			break;
			}
		else
			{
			sprintf(text,"\n\n\tMAX number of supported processes is %d \n\tPlease Try Again",MAX_PROCESS_CAPACITY);
			printf(text);
			}
		}
		return retVal;
	}

BOOL cpuschedule::SetRequiredCPUCycles()
	{
	BOOL retVal = TRUE;
	Process tmp;
	int val;
	for(list<Process>::iterator Iter = initialReadyQueue.begin(); Iter != initialReadyQueue.end(); Iter++)
		{
		tmp = *Iter;
		val = tmp.cpuBurstTime;
		totalNumberOfCPUCycles = totalNumberOfCPUCycles + val;
		}
	return retVal;
	}

void cpuschedule::UpdateProcessListUntilNow(int t,int& currentNumOfProcess)
	{
	char text[256];
	currentNumOfProcess = 0;
	sprintf(text,"\n\n-> At Cycle: %d",t);
	printf(text);
	Process tmp,tmp1;
	updatedReadyQueue.clear();

	for(list<Process>::iterator Iter = initialReadyQueue.begin(); Iter != initialReadyQueue.end(); Iter++)
		{
		tmp = *Iter;
		if((tmp.arrivalTime == t || tmp.arrivalTime < t))
			{
			if(tmp.cpuBurstTime > 0)
				{
				currentNumOfProcess++;
				tmp1.arrivalTime = tmp.arrivalTime;
				tmp1.cpuBurstTime = tmp.cpuBurstTime;
				tmp1.pName = tmp.pName;
				tmp1.isCompleted = tmp.isCompleted;
				updatedReadyQueue.push_back(tmp1);
				}
			}
		}
	}

bool cpuschedule::compare(const Process& first, const Process& second)
{
if (first.cpuBurstTime < second.cpuBurstTime)
	{
		return true;
	}
else if(first.cpuBurstTime == second.cpuBurstTime)
	{
	if(first.arrivalTime > second.arrivalTime)
		return false;
	}
  else
	{
    return false;
	}

}

void cpuschedule::SetPriority()
	{
	if(updatedReadyQueue.size() > 0)
		updatedReadyQueue.sort(compare);
	}

void cpuschedule::UpdateProcessData(string procName)
	{
	Process tmp;
	for(list<Process>::iterator Iter = initialReadyQueue.begin(); Iter != initialReadyQueue.end(); Iter++)
		{
		tmp = *Iter;
		if((*Iter).pName.compare(procName) == 0)
			{
			(*Iter).cpuBurstTime--;
			if((*Iter).cpuBurstTime == 0)
				{
				(*Iter).isCompleted = TRUE;
				}
			break;
			}
		}
	}

void cpuschedule::StartProcessingTheQueue()
	{
	cout<<"\n\n\t============ Execution Started ============ \n\n";
	currentProcIndex = 0;
	char text[1024];
	memset(text,'\0',sizeof(char)*1024);
	string procName,arivalTime,cpuBrustTime;
	Process currentProc;

	for(int t=0; t<totalNumberOfCPUCycles; t++)
		{
		UpdateProcessListUntilNow(t,currentNumOfProcess);
		SetPriority();
		if(updatedReadyQueue.size() > 0)
			{
			currentProc = updatedReadyQueue.front();
		if(currentProc.cpuBurstTime != 0 && 
			currentProc.isCompleted == FALSE)
			{

			UpdateProcessData(currentProc.pName);
			sprintf(text,"\n\t\t %s being processed, RemainingBrustTime:%d",currentProc.pName.c_str(),currentProc.cpuBurstTime-1);
			printf(text);

			}
			}
		}
	}
