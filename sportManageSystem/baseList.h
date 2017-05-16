#include <stdio.h>
#include <string.h>
#include <malloc.h>


// 定义结点类型
typedef struct baseNode{
	long id;
	baseNode *pre;
	baseNode *next;
}baseNode;


//定义链表类型 
typedef struct baseList{
	baseNode *head;
	baseNode *tail;
	long size;
}baseList;



//得到一个节点 
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


// c初始化链表，得到一个链表，只有一个节点(占位)，ID=0 
baseList *initBaseList(){
	baseList *plist = (baseList*)malloc(sizeof(baseList));
	baseNode *head = makeBaseNode(0);
	plist->head = head;
	plist->tail = head;
	plist->size = 0;
	return plist;
}


//得到表头 
baseNode* getBaseListHead(baseList *plist){
	return plist->head;
}

//得到尾巴 
baseNode* getBaseNodeTail(baseList *plist){
	return plist->tail;
}

//得到长度 
int getBaseListSize(baseList *plist){
	return plist->size;
}


//获得节点的数据项 
long getBaseNodeID(baseNode* p){
	return p->id;
}

// 增加一个新的节点

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
				//报错 
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













