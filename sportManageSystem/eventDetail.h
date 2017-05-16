#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct eventDetail{
	long id;
	char eventScore[200];
	int eventRank;
	int number;
}eventDetail;


// 定义结点类型
typedef struct eventDetailNode{
	eventDetail eventDetail;
	eventDetailNode *pre;
	eventDetailNode *next;
}eventDetailNode;


//定义链表类型 
typedef struct eventDetailList{
	eventDetailNode *head;
	eventDetailNode *tail;
	long size;
}eventDetailList;



//得到一个节点 
eventDetailNode* makeEventDetailNode(eventDetail eventDetail){
	eventDetailNode *p = NULL;
	p = (eventDetailNode*)malloc(sizeof(eventDetailNode));
	if (p != NULL){
		p->eventDetail = eventDetail;
		p->pre = NULL;
		p->next = NULL;
	}
	return p;
}


// c初始化链表，得到一个链表，只有一个节点(占位)，ID=0 
eventDetailList *initEventDetailList(){
	eventDetailList *plist = (eventDetailList*)malloc(sizeof(eventDetailList));
	eventDetail eventDetail = { 0, "", 0 };
	eventDetailNode *head = makeEventDetailNode(eventDetail);
	plist->head = head;
	plist->tail = head;
	plist->size = 0;
	return plist;
}


//得到表头 
eventDetailNode* getEventDetailListHead(eventDetailList *plist){
	return plist->head;
}

//得到尾巴 
eventDetailNode* getEventDetailListTail(eventDetailList *plist){
	return plist->tail;
}

//得到长度 
int getEventDetailListSize(eventDetailList *plist){
	return plist->size;
}


//获得节点的数据项 
long getEventDetailNodeID(eventDetailNode* p){
	return p->eventDetail.id;
}

// 增加一个新的节点

void addEventDetailNode(eventDetailList *list, eventDetailNode* node){
	eventDetailNode* tail = getEventDetailListTail(list);
	tail->next = node;
	node->pre = tail;
	list->size++;
	list->tail = node;
}

void deleteEventDetailNodeByID(eventDetailList *list, long id){
	eventDetailNode* head = getEventDetailListHead(list);
	eventDetailNode* tail = getEventDetailListTail(list);
	if (tail->eventDetail.id == id){
		eventDetailNode* pre = tail->pre;
		pre->next = NULL;
		free(tail);
		list->tail = pre;
		list->size--;
	}
	else if (head->eventDetail.id == id){
		eventDetailNode* next = head->next;
		next->pre = NULL;
		free(head);
		list->head = next;
		list->size--;
	}
	else{
		while (head->eventDetail.id != id){
			head = head->next;
			if (head == tail){
			}
		}
		eventDetailNode* pre = head->pre;
		eventDetailNode* next = head->next;

		pre->next = next;
		next->pre = pre;
		free(head);
		list->size--;
	}
}

//通过ID获取项目节点=查看
eventDetailNode* getEventDetailNodeByID(eventDetailList* list, long id){
	eventDetailNode* head = getEventDetailListHead(list);
	eventDetailNode* tail = getEventDetailListTail(list);
	while (head->eventDetail.id != id&&head != tail){
		head = head->next;
	}
	if (head->eventDetail.id == id){
		return head;
	}
	else{
		return NULL;
	}
}












