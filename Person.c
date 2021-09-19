#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "Person.h"

int main(){
	//static Array
//	PersonStaticArrayList myList;
//	init_SAL(&myList);
	Person p1 = createPerson("Carmela", 'L', "Cebu City");
	Person p2 = createPerson("Joan", 'C', "Cabancalan City");
	Person p3 = createPerson("Niks", 'S', "Toledo City");
//
//	
//	insert_first_SAL(&myList, p1);
//	insert_last_SAL(&myList, p2);
//	insert_first_SAL(&myList, p3);

//	insert_at_SAL(&myList, p3,0);
//	delete_first_SAL(&myList);
//	delete_last_SAL(&myList);
//	delete_by_sex_SAL(&myList, 'C');
//	display_SAL(myList);
	
	//endOf Static Array
	
	//Linked List
	PersonLinkedList ll = NULL;
	
	insert_first_LL(&ll, p1);
	insert_first_LL(&ll, p3);
	insert_last_LL(&ll, p2);
	//delete_first_LL(&ll);
	//delete_last_LL(&ll);
	//delete_by_city_LL(&ll,"Toledo City");
	
	display_LL(ll);
	
	return 0;
}

Person createPerson(String name, char sex, String city) {
    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("{%s | %c | %s}", p.name, p.sex, p.city);
}
/* Static Array List*/
void init_SAL(PersonStaticArrayList *list){
	list->count = 0;
}
void insert_first_SAL(PersonStaticArrayList *list, Person p){
	int x;
	if(list->count < MAX_LIST){
		for(x = list->count; x>=0; x--){
			list->data[x+1] = list->data[x];
		}
		list->data[0] = p;
		list->count++;
	}
}
void insert_last_SAL(PersonStaticArrayList *list, Person p){
	if(list->count < MAX_LIST){
		list->data[list->count] = p;
		list->count++;
	}
}
void insert_at_SAL(PersonStaticArrayList *list, Person p, int index){
	int x;
	if(list->count < MAX_LIST){
		if(index < list->count-1 && index >= 0){
			for(x = list->count; x!=index; x--){
				list->data[x] = list->data[x-1];
			}
			list->data[index] = p;
			list->count++;
		}
	}
}
void delete_first_SAL(PersonStaticArrayList *list){
	int x;
	if(list->count != 0){
		for(x=0; x<list->count; x++){
			list->data[x] = list->data[x+1];
		}
		list->count--;
	}
	
}
void delete_last_SAL(PersonStaticArrayList *list){
	if(list->count != 0){
		list->count = list->count-1;	
	}

}
void delete_by_sex_SAL(PersonStaticArrayList *list, char sex){ // all ocurrences

	int x;
	for(x=0; x<list->count && list->data[x].sex != sex; x++){}
	list->data[x] = list->data[x+1];
	list->count--;
}
void display_SAL(PersonStaticArrayList list){
	int x;
	
	printf("\n\n%-13s", "Name");
	printf("%-5s", "Sex");   
	printf("%-30s", "City");

	for(x=0; x < list.count; x++){
		
		printf("\n\n%-13s", list.data[x].name);
		printf("%-5c", list.data[x].sex );   
		printf("%-30s", list.data[x].city);	
		
	}	
}

/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */
void init_DAL(PersonDynamicArrayList *list){
	list->count = 0;
	list->max = 0;
}
void insert_first_DAL(PersonDynamicArrayList *list, Person p){
	int x;
	if(list->count >= list->max){
		list->max *=2;
		list->data = realloc(list->data, list->max);
	}
	
	for(x=list->count; x >=0; x--){
		list->data[x] = list->data[x-1];
	}
	
	list->data[0] = p;
	list->count++;
}
void insert_last_DAL(PersonDynamicArrayList *list, Person p){
	if(list->count >= list->max){
		list->max *=2;
		list->data = realloc(list->data, list->max);
	}
	
	list->data[list->count] = p;
	list->count++;
}
void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index){
	int x;
	if(list->count >= list->max){
		list->max *=2;
		list->data = realloc(list->data, list->max);
	}
	
	if(index <list->count && index >=0){
		for(x=list->count; x!= index; x--){
			list->data[x] = list->data[x-1];
		}
		list->data[index] = p;
		list->count++;
	}
}
void delete_first_DAL(PersonDynamicArrayList *list){
	int x;
	if(list->count != 0){
		for(x=0; x<list->count; x++){
			list->data[x] = list->data[x+1];
		}
		list->count--;
	}
}
void delete_last_DAL(PersonDynamicArrayList *list){
	if(list->count != 0){
		list->count--;
	}
}
void delete_by_city_DAL(PersonDynamicArrayList *list, String city){ // first ocurrence
	int x;
	for(x=0; x<list->count && strcmp(list->data[x].city,city)!=0; x++){}
	list->data[x] = list->data[x+1];
	list->count--;
}
void display_DAL(PersonDynamicArrayList list){
		int x;
	
	printf("\n\n%-13s", "Name");
	printf("%-5s", "Sex");   
	printf("%-30s", "City");

	for(x=0; x < list.count; x++){
		
		printf("\n\n%-13s", list.data[x].name);
		printf("%-5c", list.data[x].sex );   
		printf("%-30s", list.data[x].city);	
		
	}	
}


/* Singly Linked List */
void insert_first_LL(PersonLinkedList *list, Person p){
	PersonLinkedList temp = (PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(temp != NULL){
		temp->next = *list;
		*list = temp;
		temp->elem = p;
	}
}
void insert_last_LL(PersonLinkedList *list, Person p){
	PersonLinkedList temp, *trav;
	temp = (PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(temp != NULL){
		for(trav = list; *trav != NULL; trav = &(*trav)->next){}
		temp->elem = p;
		temp->next = NULL;
		*trav = temp;
		
	}
	
}
void insert_after_LL(PersonLinkedList *list, Person p, String name){
	
}
void delete_first_LL(PersonLinkedList *list){
	PersonLinkedList temp;
	
	temp = *list;
	*list = (*list)->next;
	free(temp);
}
void delete_last_LL(PersonLinkedList *list){
	PersonLinkedList temp, *trav;
	for(trav = list; (*trav)->next != NULL; trav = &(*trav)->next){}
	temp = *trav;
	*trav = temp->next;
	free(temp);
}
void delete_by_city_LL(PersonLinkedList *list, String city){ // all ocurrences
	PersonLinkedList temp, *trav;
	
	if(*list != NULL){
		for(trav = list; *trav!=NULL && strcmp((*trav)->elem.city, city) != 0; trav=&(*trav)->next){}
		temp = *trav;
		*trav = temp->next;
		free(temp);
	}
	
}
void display_LL(PersonLinkedList list){
	PersonLinkedList trav;
	int count=0;
	
	printf("\n\n%-13s", "Name");
	printf("%-5s", "Sex");   
	printf("%-30s", "City");	
	
	for(trav=list; trav != NULL; trav=trav->next){
		count++;
		
		printf("\n\n%-13s", trav->elem.name );   
		printf("%-5c", trav->elem.sex);
		printf("%-30s", trav->elem.city);
	
	}
	
	printf("\nCount is: %d", count);
}

/* Implement all VSpace conncept and Cusor Based List*/
void init_vspace(VSpace *vs){
	int x;
	for(x=MAX_VSPACE-1; x>=0; x--){
		vs->data[x].next = x-1;
	}
	vs->avail = MAX-1;
}
Position alloc_space(VSpace *vs){
	Position available = vs->avail;
	if(available != -1){
		vs->avail = vs->data[available].next;
	}
	return available;
}
void free_space(VSpace *vs, Position index){
	if(index != -1 && index < MAX_SPACE){
		vs->data[index].next = vs->avail;
		vs->avail = index;
	}
}
void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
	PersonCusorBasedList temp = alloc_space(vs);

	if(temp!= -1){
		vs->data[temp].elem = p;
		vs->data[temp].next = *list;
		*list = temp;
	}
}
void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
	PersonCusorBasedList *trav, temp =alloc_space(vs);
	
	if(temp != -1){
		for(trav=list; *trav != -1; trav = & vs->data[*trav].next){}
		vs->data[temp].elem = elem;
		vs->data[temp].next = *trav;
		*trav = temp;
	}
}
void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index);
void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list){
	PersonCusorBasedList temp = *list;
	if(*list != -1){
		*list = vs->data[*list].next;
		free_space(vs, temp);
	}
}
void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list){
	PersonCusorBasedList temp = MAX_VSPACE -1;

	if(*list != -1){
		vs->data[temp].elem =0;
		free_space(vs, temp);
	}
}
void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex); // all ocurrences
void display_CBL(VSpace vs, PersonCusorBasedList list){
	int x = list;
	printf("{");
	
	while(x != -1){
		printf("%s", vs.data[x].elem);
		x = vs.data[x].next;
	}
	printf("}\n");
}




