#pragma once

#include <windows.h>
#include <string>

using namespace std;

#define MAX_PROCESS_CAPACITY 5

struct Process
	{
	string pName;
	int arrivalTime;
	int cpuBurstTime;
	BOOL isCompleted;
	};
	
class cpuschedule
	{
	private:
		int currentProcessNum;
		int totalNumberOfCPUCycles;
		int maxBurstTime;
		int maxArivalTime;
		int currentNumOfProcess;
		int currentProcIndex;

	public:

		cpuschedule(void);
		virtual ~cpuschedule(void);
		
		static bool compare(const Process& first, const Process& second);

		BOOL SetProcessInTheReadyQueue();
		BOOL SetRequiredCPUCycles();
		void StartProcessingTheQueue();
		void SetPriority();
		void UpdateProcessData(string procName);
		void UpdateProcessListUntilNow(int t,int& currentNumOfProcess);
	};
