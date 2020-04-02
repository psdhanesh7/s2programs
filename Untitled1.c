#include<stdio.h>

#define resources 3

void main() {

	int n; // Number of processes
	int allocation[10][resources], max[10][resources], required[10][resources];
	int totalResource[] = {10, 5, 7};
	int available[resources];
	int completed[10];

	for(int i = 0; i < resources; i++) {
		available[i] = totalResource[i];
	}

	printf("Enter the number of process : ");
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		printf("Enter the total required resources of process P%d\n", i);
		for(int j = 0; j < resources; j++) {
			scanf("%d", &max[i][j]);
		}

		completed[i] = 0; // setting each process as not completed
	}

	for(int i = 0; i <  n; i++) {
		printf("Enter the current allocation of process P%d : \n", i);
		for(int j = 0; j < resources; j++) {
			scanf("%d", &allocation[i][j]);

			available[j] -= allocation[i][j]; // calculating the currently available instances of each resource

			required[i][j] = max[i][j] - allocation[i][j]; // calcaulting the required number of instances for each process
		}
	}

	int completedProcess = 0; // count of the completed prcess
	while(completedProcess < p) {

		int nextProcess = getNextPossinbleProcess(required, available, completed);

		if(nextProcess == -1) {
			break;
		}

		printf("Prcocess P%d is completed succesfully\n", nextProcess);

		// releasing the resources of the completed process
		for(int i = 0; i < resources; i++) {
			available[i] += allocation[nextProcess][i];
		}
	}

	if(completedProcess != p) {
		printf("System went into an usafe state!!!\n");
	}
	else {
		printf("System is in a safe state\n");
	}
}
