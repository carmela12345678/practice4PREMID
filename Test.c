#include <stdio.h>
#include <string.h>
#include "Exercise1.h"
#include "CircularArrayQ.h"
#include "Person.c"


int main(void) 
{
	CircularArrayQueue create = create_array_queue();
	init_array_queue(&create);
	
	PersonLinkedList getf;
	PersonDynamicArrayList getM;
	
	int queuelength;
	
	Person p1 = createPerson("Carmela", 'F', "Cebu City");
	Person p2 = createPerson("Joan", 'F', "Cabancalan City");
	Person p3 = createPerson("Niks", 'M', "Toledo City");
	Person p4 = createPerson("jJason", 'M', "Ambot City");
	Person info = createPerson("Daniela", 'F', "Mandaue City");
	enqueue(&create, p4);
	enqueue(&create, p1);
	enqueue(&create, p2);
	enqueue(&create, p3);
	visualizeQueue(create);
//	dequeue(&create);
//	visualizeQueue(create);
	queuelength = get_queue_length(create);
	printf("\nQueue lenght is: %d\n", queuelength);
	
//	getf = get_all_females(create);
	
	getM = remove_all_males(&create);
	

	

    return 0;
}
