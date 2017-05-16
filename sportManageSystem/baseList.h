#include <stdio.h>
#include <string.h>
#include <malloc.h>


// ����������
typedef struct baseNode{
	long id;
	baseNode *pre;
	baseNode *next;
}baseNode;


//������������ 
typedef struct baseList{
	baseNode *head;
	baseNode *tail;
	long size;
}baseList;



//�õ�һ���ڵ� 
baseNode* makeBaseNode(long id){
	baseNode *p = NULL;
	p = (baseNode*)malloc(sizeof(baseNode));
	if (p != NULL){
		p->id = id;
		p->pre = NULL;
		p->next = NULL;
	}
	return p;
}


// c��ʼ�������õ�һ������ֻ��һ���ڵ�(ռλ)��ID=0 
baseList *initBaseList(){
	baseList *plist = (baseList*)malloc(sizeof(baseList));
	baseNode *head = makeBaseNode(0);
	plist->head = head;
	plist->tail = head;
	plist->size = 0;
	return plist;
}


//�õ���ͷ 
baseNode* getBaseListHead(baseList *plist){
	return plist->head;
}

//�õ�β�� 
baseNode* getBaseNodeTail(baseList *plist){
	return plist->tail;
}

//�õ����� 
int getBaseListSize(baseList *plist){
	return plist->size;
}


//��ýڵ�������� 
long getBaseNodeID(baseNode* p){
	return p->id;
}

// ����һ���µĽڵ�

void addBaseNode(baseList *list, baseNode* node){
	baseNode* tail = getBaseNodeTail(list);
	tail->next = node;
	node->pre = tail;
	list->size++;
	list->tail = node;
}

void deleteBaseNodeByID(baseList *list, long id){
	baseNode* head = getBaseListHead(list);
	baseNode* tail = getBaseNodeTail(list);
	if (tail->id == id){
		baseNode* pre = tail->pre;
		pre->next = NULL;
		free(tail);
		list->tail = pre;
		list->size--;
	}
	else if (head->id == id){
		baseNode* next = head->next;
		next->pre = NULL;
		free(head);
		list->head = next;
		list->size--;
	}
	else{
		while (head->id != id){
			head = head->next;
			if (head == tail){
				//���� 
			}
		}
		baseNode* pre = head->pre;
		baseNode* next = head->next;

		pre->next = next;
		next->pre = pre;
		free(head);
		list->size--;
	}
}

baseNode* getBaseNodeByID(baseList* list, long id){
	baseNode* head = getBaseListHead(list);
	baseNode* tail = getBaseNodeTail(list);
	while (head->id != id&&head != tail){
		head = head->next;
	}
	if (head->id == id){
		return head;
	}
	else{
		return NULL;
	}
}













