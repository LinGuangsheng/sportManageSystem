#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef struct eventInfo{
	char name[200];
	char intro[2000];
	char rule[2000];
	char place[200];
	char time[200];
	long a;
	long timeNum;
	long participantSize;
	long id;
	long addSize;
}eventInfo;


typedef struct eventNode{
	eventInfo eventInfomation;
	baseList *participantList;
	eventNode *pre;
	eventNode *next;
}eventNode;

typedef struct eventList{
	eventNode *head;
	eventNode *tail;
	long size;
}eventList;

//得到一个节点
eventNode* makeEventNode(eventInfo eventInfomation){
	eventNode *node = NULL;
	node = (eventNode*)malloc(sizeof(eventNode));
	if (node != NULL){
		node->eventInfomation = eventInfomation;
		node->participantList = initBaseList();
		node->pre = NULL;
		node->next = NULL;
	}
	return node;
}

//初始化项目链表
eventList* initEventList(){
	struct eventInfo tem = { "", "", "", "","", 0, 0 };
	eventList* list = (eventList*)malloc(sizeof(eventList));
	eventNode* head = makeEventNode(tem);
	list->head = head;
	list->tail = head;
	list->size = 0;
	return list;
}

//得到头部
eventNode* getEventHead(eventList* list){
	return list->head;
}

//得到尾部
eventNode* getEventTail(eventList *list){
	return list->tail;
}


//添加一个新的节点=添加新项目
void addEventNode(eventList* list, eventNode* node){
	eventNode* tail = getEventTail(list);
	tail->next = node;
	node->pre = tail;
	list->size++;
	list->tail = node;
	s.eventSize++;
}

//通过ID删除项目=删除
void deleteEventNodeByID(eventList* list, long id){
	eventNode* head = getEventHead(list);
	eventNode* tail = getEventTail(list);
	if (tail->eventInfomation.id == id){
		eventNode* pre = tail->pre;
		pre->next = NULL;
		free(tail);
		list->tail = pre;
		list->size--;
		s.eventSize--;
	}
	else if (head->eventInfomation.id == id){
		eventNode* next = head->next;
		next->pre = NULL;
		free(head);
		list->head = next;
		list->size--;
		s.eventSize--;
	}
	else{
		while (head->eventInfomation.id != id){
			head = head->next;
		}
		eventNode* pre = head->pre;
		eventNode* next = head->next;

		pre->next = next;
		next->pre = pre;
		free(head);
		list->size--;
		s.eventSize--;
	}
}



//通过ID获取项目节点=查看
eventNode* getEventNodeByID(eventList* list, long id){
	eventNode* head = getEventHead(list);
	eventNode* tail = getEventTail(list);
	while (head->eventInfomation.id != id&&head != tail){
		head = head->next;
	}
	if (head->eventInfomation.id == id){
		return head;
	}
	else{
		return NULL;
	}
}

eventNode* getEventNodeByName(eventList* list, char *name){
	eventNode* head = getEventHead(list);
	eventNode* tail = getEventTail(list);
	while (strcmp(head->eventInfomation.name, name)!=0){
		head = head->next;
	}
	if (strcmp(head->eventInfomation.name, name) == 0){
		return head;
	}
	else{
		return NULL;
	}
}


//通过ID获取项目信息 = 修改
eventInfo getEventInfoByID(eventList* list, long eventID){
	eventNode* event = getEventNodeByID(list, eventID);
	return event->eventInfomation;
}



//通过项目ID，选手ID删除选手=删除选手
void deletEeventParticipantByID(eventList *list, long eventID, long participantID){
	eventNode *event = getEventNodeByID(list, eventID);
	baseList *baselist = event->participantList;
	deleteBaseNodeByID(baselist, participantID);
	event->eventInfomation.participantSize = event->participantList->size;
}


//通过ID添加选手到项目中=新增选手
void addEventParticipantByID(eventList* list, long eventID, long participantID){
	eventNode* event = getEventNodeByID(list, eventID);
	baseNode *node = makeBaseNode(participantID);
	addBaseNode(event->participantList, node);
	event->eventInfomation.participantSize = event->participantList->size;
	event->eventInfomation.addSize++;
}


void saveEvent(eventList *list){
	FILE *fp;
	fopen_s(&fp, "event/eventList.txt", "wb");

	eventNode *head = getEventHead(list);
	eventInfo info = head->eventInfomation;
	for (int i = 0; i < list->size; i++){
		head = head->next;
		info = head->eventInfomation;
		fwrite(&info, sizeof(eventInfo), 1, fp);

		char id[200] = "event/";
		char tem[200];
		_itoa_s(info.id, tem, 10);
		strcat_s(id, tem);

		baseList *baselist = head->participantList;
		baseNode *basehead = getBaseListHead(baselist);

		FILE *idFP;
		fopen_s(&idFP, id, "wb");
		for (int j = 0; j < baselist->size; j++){
			basehead = basehead->next;
			long baseID = (*basehead).id;
			fwrite(&baseID, sizeof(long), 1, idFP);
		}
		fclose(idFP);
	}
	fclose(fp);
}

eventList* getEvent(){
	FILE *fp;
	fopen_s(&fp, "event/eventList.txt", "rb");
	eventList *list = initEventList();
	eventInfo info = { "", "", "", "", 0, 0 };
	eventNode *node = makeEventNode(info);
	int temSize = s.eventSize;
	for (int i = 0; i < temSize; i++){
		fread(&info, sizeof(eventInfo), 1, fp);
		node = makeEventNode(info);
		addEventNode(list, node);


		char id[200] = "event/";
		char tem[200];
		_itoa_s(info.id, tem, 10);
		strcat_s(id, tem);

		FILE *idFP;
		fopen_s(&idFP, id, "rb");
		baseNode *basenode = makeBaseNode(0);
		node->eventInfomation.addSize = node->eventInfomation.addSize - info.participantSize;
		for (int i = 0; i < info.participantSize; i++){
			long iD = 0;
			fread(&iD, sizeof(long), 1, idFP);
			basenode = makeBaseNode(iD);
			addEventParticipantByID(list, node->eventInfomation.id, iD);
		}
		fclose(idFP);

	}
	s.eventSize = temSize;
	fclose(fp);
	return list;
}

//int main(){
//
//	/*eventList *list = initEventList();
//
//	eventInfo eventInfomation = { "你好", "你", "好", "你的", 4,1};
//	eventNode *node = makeEventNode(eventInfomation);
//
//	eventInfo eventInfomation1 = { "好", "你", "好", "的", 0,2};
//	eventNode *node1 = makeEventNode(eventInfomation1);
//
//
//	addEventNode(list, node);
//	addEventNode(list, node1);*/
//
//	//deleteeventNodeByID(list, 1);
//
//	eventList *list = getEvent();
//
//	eventNode *head = list->head;
//
//	printf("%s\n", head->next->eventInfomation.name);
//	printf("%s\n", head->next->eventInfomation.intro);
//	printf("%s\n", head->next->eventInfomation.place);
//	printf("%s\n", head->next->eventInfomation.time);
//	printf("%d\n", head->next->eventInfomation.participantSize);
//	printf("%d\n", head->next->eventInfomation.id);
//	printf("1111111111111111111111111111111111111111111\n");
//	/*addEventParticipantByID(list, 1, 11);
//	addEventParticipantByID(list, 1, 12);
//	addEventParticipantByID(list, 1, 13);
//	addEventParticipantByID(list, 1, 14);*/
//	baseNode *basenode = head->next->participantList->head;
//	for (int i = 0; i < head->next->participantList->size; i++){
//		basenode = basenode->next;
//		printf("%d\n", basenode->id);
//	}
//	printf("-----------------");
//
//	/*FILE *fp;
//	fopen_s(&fp, "eventList.txt", "wb");
//	saveEvent(fp, list);*/
//
//
//	int a;
//	scanf_s("%d", &a);
//
//}