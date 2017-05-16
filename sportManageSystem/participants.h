#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef struct participantInfo{
	char name[200];
	char intro[2000];
	char gradeMajor[200];
	char contact[200];
	long eventSize;
	long id;
	long unitID;
	int gender;
}participantInfo;


typedef struct participantNode{
	participantInfo participantInfomation;
	eventDetailList *eventList;
	participantNode *pre;
	participantNode *next;
}participantNode;

typedef struct participantList{
	participantNode *head;
	participantNode *tail;
	long size;
}participantList;

//得到一个节点
participantNode* makeParticipantNode(participantInfo participantInfomation){
	participantNode *node = NULL;
	node = (participantNode*)malloc(sizeof(participantNode));
	if (node != NULL){
		node->participantInfomation = participantInfomation;
		node->eventList = initEventDetailList();
		node->pre = NULL;
		node->next = NULL;
	}
	return node;
}

//初始化项目链表
participantList* initParticipantList(){
	struct participantInfo tem = { "","", "", "", 0, 0 };
	participantList* list = (participantList*)malloc(sizeof(participantList));
	participantNode* head = makeParticipantNode(tem);
	list->head = head;
	list->tail = head;
	list->size = 0;
	return list;
}

//得到头部
participantNode* getParticipantHead(participantList* list){
	return list->head;
}

//得到尾部
participantNode* getParticipantTail(participantList *list){
	return list->tail;
}


//添加一个新的节点=添加新项目
void addParticipantNode(participantList* list, participantNode* node){
	participantNode* tail = getParticipantTail(list);
	tail->next = node;
	node->pre = tail;
	list->size++;
	list->tail = node;
	s.participantSize++;
}

//通过ID删除项目=删除
void deleteParticipantNodeByID(participantList* list, long id){
	participantNode* head = getParticipantHead(list);
	participantNode* tail = getParticipantTail(list);
	if (tail->participantInfomation.id == id){
		participantNode* pre = tail->pre;
		pre->next = NULL;
		free(tail);
		list->tail = pre;
		list->size--;
		s.participantSize--;
	}
	else if (head->participantInfomation.id == id){
		participantNode* next = head->next;
		next->pre = NULL;
		free(head);
		list->head = next;
		list->size--;
		s.participantSize--;
	}
	else{
		while (head->participantInfomation.id != id){
			head = head->next;
		}
		participantNode* pre = head->pre;
		participantNode* next = head->next;

		pre->next = next;
		next->pre = pre;
		free(head);
		list->size--;
		s.participantSize--;
	}
}



//通过ID获取项目节点=查看
participantNode* getParticipantNodeByID(participantList* list, long id){
	participantNode* head = getParticipantHead(list);
	participantNode* tail = getParticipantTail(list);
	while (head->participantInfomation.id != id&&head!=tail){
		head = head->next;
	}
	if (head->participantInfomation.id == id){
		return head;
	}
	else{
		return NULL;
	}
}

participantNode* getParticipantNodeByName(participantList* list, char *name){
	participantNode* head = getParticipantHead(list);
	participantNode* tail = getParticipantTail(list);
	while (strcmp(head->participantInfomation.name,name)!=0&&head != tail){
		head = head->next;
	}
	if (strcmp(head->participantInfomation.name, name) == 0){
		return head;
	}
	else{
		return NULL;
	}
}


//通过ID获取项目信息=修改
participantInfo getParticipantInfoByID(participantList* list, long participantID){
	participantNode* participant = getParticipantNodeByID(list, participantID);
	return participant->participantInfomation;
}



//通过项目ID，选手ID删除选手=删除选手
void deleteParticipantEventByID(participantList *list, long participantID, long eventID){
	participantNode *participant = getParticipantNodeByID(list, participantID);
	eventDetailList *eventDetaillist = participant->eventList;
	deleteEventDetailNodeByID(eventDetaillist, eventID);
	participant->participantInfomation.eventSize = participant->eventList->size;
}


//通过ID添加选手到项目中=新增选手
void addParticipantEventByID(participantList* list, long participantID, eventDetail eventDetail){
	participantNode* participant = getParticipantNodeByID(list, participantID);
	eventDetailNode *node = makeEventDetailNode(eventDetail);
	addEventDetailNode(participant->eventList, node);
	participant->participantInfomation.eventSize = participant->eventList->size;
}

void saveParticipant(participantList *list){

	FILE *fp;
	fopen_s(&fp, "participants/participantList", "wb");
	participantNode *head = getParticipantHead(list);
	participantInfo info = head->participantInfomation;
	for (int i = 0; i < list->size; i++){
		head = head->next;
		info = head->participantInfomation;
		fwrite(&info, sizeof(participantInfo), 1, fp);

		char id[200] = "participants/";
		char tem[200];
		_itoa_s(info.id, tem, 10);
		strcat_s(id, tem);
		
		eventDetailList *eventDetaillist = head->eventList;
		eventDetailNode *eventDetailhead = getEventDetailListHead(eventDetaillist);

		FILE *idFP;
		fopen_s(&idFP, id, "wb");
		for (int j = 0; j < eventDetaillist->size; j++){
			eventDetailhead = eventDetailhead->next;
			eventDetail eventDetail = eventDetailhead->eventDetail;
			fwrite(&eventDetail, sizeof(eventDetail), 1, idFP);
		}
		fclose(idFP);
	}
	fclose(fp);
}

participantList* getParticipant(){
	FILE *fp;
	fopen_s(&fp, "participants/participantList", "rb");
	participantList *list = initParticipantList();
	participantInfo info = { "", "", "", "", 0, 0 };
	participantNode *node = makeParticipantNode(info);
	int temSize = s.participantSize;
	for (int i = 0; i < temSize; i++){
		fread(&info, sizeof(participantInfo), 1, fp);
		node = makeParticipantNode(info);
		addParticipantNode(list, node);
		char id[200] = "participants/";
		char tem[200];
		_itoa_s(info.id, tem, 10);
		strcat_s(id, tem);

		FILE *idFP;
		fopen_s(&idFP, id, "rb");
		eventDetail eventDetail = { 0, 0, 0 };
		eventDetailNode *eventDetailnode = makeEventDetailNode(eventDetail);
		for (int i = 0; i < info.eventSize; i++){
			fread(&eventDetail, sizeof(eventDetail), 1, idFP);
			eventDetailnode = makeEventDetailNode(eventDetail);
			addEventDetailNode(node->eventList, eventDetailnode);
		}
		fclose(idFP);
		
	}
	s.participantSize = temSize;
	fclose(fp);
	return list;
}


//void addParticipantEventDetail(participantList *list, long participantID, long eventID, int score, int rank){
//	participantNode *node = getParticipantNodeByID(list, participantID);
//	eventDetailNode *event = makeEventDetailNode({ eventID, score, rank });
//
//	addEventDetailNode(list, event);
//	/*eventDetailNode *eventDetailNode = getEventDetailNodeByID(node->eventList, eventID);
//	eventDetailNode->eventDetail.eventScore = score;
//	eventDetailNode->eventDetail.eventRank = rank;*/
//
//}

//int main(){
//
//	participantList *list = initParticipantList();
//
//	participantInfo participantInfomation = { "12","34","你好", "你", "好", "你的", 4,1, 1};
//	participantNode *node = makeParticipantNode(participantInfomation);
//
//	participantInfo participantInfomation1 = {"!2222","#333", "好", "你", "好", "的", 0,2, 2};
//	participantNode *node1 = makeParticipantNode(participantInfomation1);
//
//
//	addParticipantNode(list, node);
//	addParticipantNode(list, node1);
//
//	//deleteParticipantNodeByID(list, 1);
//	
//	FILE *fp;
//	fopen_s(&fp, "participantList.txt", "rb");
////	participantList *list = getParticipant(fp);
//
//	participantNode *head = list->head;
//
//	printf("%s\n", head->next->participantInfomation.loginName);
//	printf("%s\n", head->next->participantInfomation.loginPasswd);
//	printf("%s\n", head->next->participantInfomation.name);
//	printf("%s\n", head->next->participantInfomation.contact);
//	printf("%s\n", head->next->participantInfomation.gradeMajor);
//	printf("%s\n", head->next->participantInfomation.intro);
//	printf("%d\n", head->next->participantInfomation.unitID);
//	printf("%d\n", head->next->participantInfomation.id);
//	printf("1111111111111111111111111111111111111111111\n");
//	eventDetail eventDetail1 = { 0, 0, 0 };
//	addParticipantEventByID(list, 1, eventDetail1);
//	eventDetail eventDetail2 = { 1, 1, 1 };
//	addParticipantEventByID(list, 1, eventDetail2);
//	eventDetail eventDetail3 = { 2, 2, 2 };
//	addParticipantEventByID(list, 1, eventDetail3);
//	eventDetail eventDetail4 = { 3, 3, 3 };
//	addParticipantEventByID(list, 1, eventDetail4);
//	//addParticipantEventByID(list, 1, 11);
//	eventDetailNode *eventDetailnode = head->next->eventList->head;
//	for (int i = 0; i < head->next->eventList->size; i++){
//		eventDetailnode = eventDetailnode->next;
//		printf("%d\n",eventDetailnode->eventDetail.id);
//		printf("%d\n", eventDetailnode->eventDetail.eventScore);
//		printf("%d\n", eventDetailnode->eventDetail.eventRank);
//		printf("!!!!!!!!!!!!!!!!!!!!\n");
//	}
//	printf("-----------------");
//
//	//	//写入的时候，改为wb,读取的时候为rb
//
//	/*FILE *fp;
//	fopen_s(&fp, "participantList.txt", "wb");
//	saveParticipant(fp, list);*/
//
//
//	int a;
//	scanf_s("%d", &a);
//
//}