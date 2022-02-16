#include <multiq.h>

// createMQ - creating multi-queue
MultiQ createMQ(int num){
	MultiQ mq;
	mq.size = num;
	mq.qarr = malloc(sizeof(Queue)*num);
	return mq;
}

// addMQ - adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
MultiQ addMQ(MultiQ mq, Task t){
	//the Queue corresponding to priority p is mq[p-1]
	Node nn = newNode(t.tid);
	mq.qarr[t.p-1] = addQ(mq.qarr[t.p-1],nn);
	return mq;
} 

// nextMQ - returns the front of the non-empty Queue in mq with the highest priority.
Task nextMQ(MultiQ mq){
	if(isEmptyMQ(mq)){
		Task emptyTask;
		emptyTask.tid = -1;
		emptyTask.p = -1;
		return emptyTask;
	}
	else{
		int i=mq.size-1;
		while(isEmptyQ(mq.qarr[i])) i--;
		Task newTask;
		newTask.tid =  front(mq.qarr[i]).data;
		newTask.p = i+1;
		return newTask;
	}
} 

// delNextMQ - removes the front of the non-empty Queue in mq with the highest priority and returns multiQ
MultiQ delNextMQ(MultiQ mq){
	if(isEmptyMQ(mq)){
		return mq;
	}
	else{
		int i=maxPriority-1;
		while(isEmptyQ(mq.qarr[i])) i--;
		mq.qarr[i] = delQ(mq.qarr[i]);
		return mq;
	}
}

// isEmptyMQ - checks if queue is empty
bool isEmptyMQ(MultiQ mq){
	for(int i=mq.size-1;i>=0;i--){
		if(isEmptyQ(mq.qarr[i])){
		}
		else{
			return false;
		}
	}
	return true;
} 

// sizeMQ - returns the total number of items in the MultiQ
int sizeMQ(MultiQ mq){
	int size=0;
	for(int i=mq.size-1;i>=0;i--){
		size+=lengthQ(mq.qarr[i]);
	}
	return size;
} 

// sizeMQbyPriority - returns the number of items in mq with the priority p.
int sizeMQbyPriority(MultiQ mq, Priority p){
	return lengthQ(mq.qarr[p-1]);
} 

// getQueueFromMQ - returns the Queue with priority p.
Queue getQueueFromMQ(MultiQ mq, Priority p){
	return mq.qarr[p-1];
}