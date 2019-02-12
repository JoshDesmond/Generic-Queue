#include "queue.h"
#include <string.h>

queue * createQueue(size_t allocSize)
{
	queue * q = (queue*)malloc(sizeof(queue));
	if (q == NULL) {
		return NULL;
	}
	q->allocationSize = allocSize;
	q->size = 0;
	q->head = q->tail = NULL;
	return q;
}

void enqueue(queue * q, void * _data)
{
	if (q==NULL) {
		return NULL;
	}

	data * toInsert = (data*)malloc(sizeof(data));
	if (toInsert == NULL) {
		return NULL;
	}
	toInsert->data = malloc(sizeof(q->allocationSize));
	if (toInsert->data == NULL) {
		return NULL;
	}
	toInsert->next = NULL;
	memcpy(toInsert->data, _data, q->allocationSize);
	if (q->size == 0) {//First insertion
		q->head = q->tail = toInsert;
	}
	else {
		q->tail->next = toInsert;
		q->tail = toInsert;
	}

	q->size++;
}

void  dequeue(queue * q,void * toRet)
{
	if (q == NULL || isEmpty(q) ) {
		return NULL;
	}

	data *toDel = q->head;
	if (q->size == 1) {
		memcpy(toRet, toDel->data, q->allocationSize);
		free(toDel->data);
		free(toDel);
		q->head = q->tail = NULL;
		q->size--;
		return;
	}
	q->head = q->head->next;
	memcpy(toRet, toDel->data, q->allocationSize);
	free(toDel->data);
	free(toDel);
	q->size--;
}

void * front(queue*q)
{
	if (q == NULL) {
		return NULL;
	}

	return q->head->data;
}

void clearQueue(queue * q)
{
	if (q == NULL) {
		return NULL;
	}
	
	while (!isEmpty(q)) {
		data* temp = q->head;
		printf("Cleared temp %d\n", temp->data);
		q->head = q->head->next;
		free(temp->data);
		free(temp);
		q->size--;
	}

}

size_t getSize(queue * q)
{
	if (q == NULL) {
		return NULL;
	}

	return q->size;
}

bool isEmpty(queue * q)
{
	if (q == NULL) {
		return NULL;
	}
	if (q->size == 0) {
		return true;
	}
	else {
		return false;
	}
}

void destroyQueue(queue *q){
	clearQueue(q);
	free(q);
}
