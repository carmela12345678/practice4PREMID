#ifndef EXERCISE1_H
#define EXERCISE1_H
#include <stdio.h>

#include "CircularArrayQ.h"



/** \fn int get_queue_length(CircularArrayQueue list);
 *  \brief Get the number of elements in the current queue.
 *  \param list The current queue.
*/
int get_queue_length(CircularArrayQueue list){
	int cnt=0, x;
	for(x = list.front; x!= (list.rear+1) % MAX ; x = (x+1)%MAX ){
		cnt++;
	}
	
	return cnt;
}


/** \fn PersonLinkedList get_all_females(CircularArrayQueue list);
 *  \brief Returns all females as a linked list using the current list without removing them in the current list.
 *  \param list The current queue.
 *  Note: Use the queue basic operations (enqueue, dequeue, front)
*/
PersonLinkedList get_all_females(CircularArrayQueue list){
	PersonLinkedList retFem = NULL;
	int trav;
	CircularArrayQueue temp;
	int x;
	
	temp = list;
	for(trav = list.front; trav != (list.rear+1)%MAX; trav = (trav+1)%MAX){
		if(temp.data[trav].sex == 'F' || temp.data[trav].sex == 'f'){
			insert_first_LL(&retFem, temp.data[trav]);
		}
	}
	display_LL(retFem);
	return retFem;
}

/** \fn PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);
 *  \brief Remove all males in the current list and returns the removed males as a dynamic array list.
 *  \param list The current queue.
 *  Note: Use the concept of queue with out using the basic operations.
*/
PersonDynamicArrayList remove_all_males(CircularArrayQueue *list){
	PersonDynamicArrayList retM;
	int trav;
	CircularArrayQueue *temp;
	int x;
	
	init_DAL(&retM);
	temp = list;
	for(trav = list->front; trav != (list->rear+1)%MAX; trav = (trav+1)%MAX){
		if(temp->data[trav].sex == 'M' || temp->data[trav].sex == 'm'){
			insert_first_DAL(&retM, temp->data[trav]);
			dequeue(temp);
		}
	}
	
	display_DAL(retM);
	return retM;
}

#endif
