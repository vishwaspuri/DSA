#include <que.h>

// newQ - returns an empty Queue
Queue newQ(){
	Queue q;
	q.first = NULL;
	q.last = NULL;
	q.size=0;
	return q;
}

// isEmptyQ - tests whether q is empty
bool isEmptyQ(Queue q){
	return !!q.size;
}

// delQ - deletes the element from the front of the Queue;returns the modified Queue
Queue delQ(Queue q){
	if(isEmptyQ(q)){
		return q;
	}
	else{
		if(q.size==1){
			q.size=0;
			q.first=NULL;
			q.last=NULL;
			return q;
		}
		else{
			q.first = q.first->next;
			q.size--;
			return q;
		}
	}
}

// front - returns the element from the front of the Queue;
Node front(Queue q){
	return *(q.first);
}

// addQ - adds new node to the rear of the Queue; returns the modified Queue
Queue addQ(Queue q , Node n){

	Node* node = malloc(sizeof(Node));
	node->data = n.data;
	node->next = n.next;
	if(isEmptyQ(q)){
		q.size=1;
		q.first = q.last = node;
	}
	else{
		q.size++;
		q.last->next = node;
		q.last=node;
	}
	return q;
}

int lengthQ(Queue q){
	return q.size;
}

Node newNode(int val){
	Node n;
	n.data = val;
	n.next = NULL;
	return n;
}