#include "stdafx.h"
#include "cpuschedule.h"


int _tmain(int argc, _TCHAR* argv[])
{
	cpuschedule objCpuSchedule;
	objCpuSchedule.SetProcessInTheReadyQueue();
	objCpuSchedule.SetRequiredCPUCycles();
	objCpuSchedule.StartProcessingTheQueue();

	return 0;
}
