#include <stdio.h>
#include <string.h>
#include "Exercise1.h"
#include "CircularArrayQ.h"
#include "Person.c"


int main(void) 
{
	CircularArrayQueue create = create_array_queue();
	Person info = createPerson("Carmela", 'F', "Mandaue City");
	enqueue(&create, info);

    return 0;
}
