#include <que.h>
#define maxPriority 10


// Type definitions
typedef struct{
	int size;
	Queue* qarr;
} MultiQ;

typedef int Priority;
typedef int TaskID;
typedef struct {
	TaskID tid;
	Priority p;
} Task;

// Function definitions
MultiQ createMQ(int num); 
MultiQ addMQ(MultiQ mq, Task t); 
Task nextMQ(MultiQ mq); 
MultiQ delNextMQ(MultiQ mq); 
bool isEmptyMQ(MultiQ mq); 
int sizeMQ(MultiQ mq); 
int sizeMQbyPriority(MultiQ mq, Priority p); 
Queue getQueueFromMQ(MultiQ, Priority p);