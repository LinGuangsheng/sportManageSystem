#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef struct refereeInfo{
	char refereeName[200];
	char refereeIntro[2000];
	char refereeContact[200];
	
	long eventSize;
	long id;
}refereeInfo;


typedef struct refereeNode{
	refereeInfo refereeInfomation;
	baseList *eventList;
	refereeNode *pre;
	refereeNode *next;
}refereeNode;

typedef struct refereeList{
	refereeNode *head;
	refereeNode *tail;
	long size;
}refereeList;

//�õ�һ���ڵ�
refereeNode* makeRefereeNode(refereeInfo refereeInfomation){
	refereeNode *node = NULL;
	node = (refereeNode*)malloc(sizeof(refereeNode));
	if (node != NULL){
		node->refereeInfomation = refereeInfomation;
		node->eventList = initBaseList();
		node->pre = NULL;
		node->next = NULL;
	}
	return node;
}

//��ʼ����Ŀ����
refereeList* initRefereeList(){
	struct refereeInfo tem = { "","","",0,0 };
	refereeList* list = (refereeList*)malloc(sizeof(refereeList));
	refereeNode* head = makeRefereeNode(tem);
	list->head = head;
	list->tail = head;
	list->size = 0;
	return list;
}

//�õ�ͷ��
refereeNode* getRefereeHead(refereeList* list){
	return list->head;
}

//�õ�β��
refereeNode* getRefereeTail(refereeList *list){
	return list->tail;
}


//���һ���µĽڵ�=�������Ŀ
void addRefereeNode(refereeList* list, refereeNode* node){
	refereeNode* tail = getRefereeTail(list);
	tail->next = node;
	node->pre = tail;
	list->size++;
	list->tail = node;
	s.refereeSize++;
}



//ͨ��IDɾ����Ŀ=ɾ��
void deleteRefereeNodeByID(refereeList* list, long id){
	refereeNode* head = getRefereeHead(list);
	refereeNode* tail = getRefereeTail(list);
	if (tail->refereeInfomation.id == id){
		refereeNode* pre = tail->pre;
		pre->next = NULL;
		free(tail);
		list->tail = pre;
		list->size--;
		s.refereeSize--;
	}
	else if (head->refereeInfomation.id == id){
		refereeNode* next = head->next;
		next->pre = NULL;
		free(head);
		list->head = next;
		list->size--;
		s.refereeSize--;
	}
	else{
		while (head->refereeInfomation.id != id){
			head = head->next;
		}
		refereeNode* pre = head->pre;
		refereeNode* next = head->next;

		pre->next = next;
		next->pre = pre;
		free(head);
		list->size--;
		s.refereeSize--;
	}
}


refereeNode* getRefereeNodeByEventID(refereeList *list, long id){
	refereeNode* head = getRefereeHead(list);
	refereeNode* tail = getRefereeTail(list);
	while (getBaseNodeByID(head->eventList, id) == NULL&&head != tail){
		head = head->next;
	}
	if (getBaseNodeByID(head->eventList, id) != NULL){
		return head;
	}  
	else{
		return NULL;
	}
}


//ͨ��ID��ȡ��Ŀ�ڵ�=�鿴
refereeNode* getRefereeNodeByID(refereeList* list, long id){
	refereeNode* head = getRefereeHead(list);
	refereeNode* tail = getRefereeTail(list);
	while (head->refereeInfomation.id != id&&head!=tail){
		head = head->next;
	}
	if (head->refereeInfomation.id == id){
		return head;
	}
}


//ͨ��ID��ȡ��Ŀ��Ϣ=�޸�
refereeInfo getrefereeInfoByID(refereeList* list, long refereeID){
	refereeNode* referee = getRefereeNodeByID(list, refereeID);
	return referee->refereeInfomation;
}



//ͨ����ĿID��ѡ��IDɾ��ѡ��=ɾ��ѡ��
void deleteRefereeEventByID(refereeList *list, long refereeID, long eventID){
	refereeNode *referee = getRefereeNodeByID(list, refereeID);
	baseList *baselist = referee->eventList;
	deleteBaseNodeByID(baselist, eventID);
	referee->refereeInfomation.eventSize = referee->eventList->size;
}


//ͨ��ID���ѡ�ֵ���Ŀ��=����ѡ��
void addRefereeEventByID(refereeList* list, long refereeID, long eventID){
	refereeNode* referee = getRefereeNodeByID(list, refereeID);
	baseNode *node = makeBaseNode(eventID);
	addBaseNode(referee->eventList, node);
	referee->refereeInfomation.eventSize = referee->eventList->size;
}

void saveReferee(refereeList *list){
	FILE *fp;
	fopen_s(&fp, "referee/refereeList.txt", "wb");
	refereeNode *head = getRefereeHead(list);
	refereeInfo info = head->refereeInfomation;
	for (int i = 0; i < list->size; i++){
		head = head->next;
		info = head->refereeInfomation;
		fwrite(&info, sizeof(refereeInfo), 1, fp);

		char id[200] = "referee/";
		char tem[200];
		_itoa_s(info.id, tem, 10);
		strcat_s(id, tem);
		
		baseList *baselist = head->eventList;
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

refereeList* getReferee(){
	FILE *fp;
	fopen_s(&fp, "referee/refereeList.txt", "rb");
	refereeList *list = initRefereeList();
	refereeInfo info = { "", "", ""};
	refereeNode *node = makeRefereeNode(info);
	int temSize = s.refereeSize;
	for (int i = 0; i < temSize; i++){
		fread(&info, sizeof(refereeInfo), 1, fp);
		node = makeRefereeNode(info);
		addRefereeNode(list, node);

		char id[200] = "referee/";
		char tem[200];
		_itoa_s(info.id, tem, 10);
		strcat_s(id, tem);

		FILE *idFP;
		fopen_s(&idFP, id, "rb");
		baseNode *basenode = makeBaseNode(0);
		for (int i = 0; i < info.eventSize; i++){
			long iD = 0;
			fread(&iD, sizeof(long), 1, idFP);
			basenode = makeBaseNode(iD);
			addRefereeEventByID(list, node->refereeInfomation.id, iD);
		}
		fclose(idFP);
		
	}
	s.refereeSize = temSize;
	fclose(fp);
	return list;
}

//int main(){
//
//	refereeList *list = initRefereeList();
//
//	refereeInfo refereeInfomation = { "���", "��", "��" , 4, 1};
//	refereeNode *node = makeRefereeNode(refereeInfomation);
//
//	refereeInfo refereeInfomation1 = { "��", "��", "��", 0,2};
//	refereeNode *node1 = makeRefereeNode(refereeInfomation1);
//
//
//	addRefereeNode(list, node);
//	addRefereeNode(list, node1);
//
//	//deleterefereeNodeByID(list, 1);
//	
//	/*FILE *fp;
//	fopen_s(&fp, "refereeList.txt", "rb");
//	refereeList *list = getReferee(fp);*/
//
//	refereeNode *head = list->head;
//
//	printf("%s\n", head->next->refereeInfomation.refereeContact);
//	printf("%s\n", head->next->refereeInfomation.refereeName);
//	printf("%s\n", head->next->refereeInfomation.refereeIntro);
//	printf("%d\n", head->next->refereeInfomation.id);
//	
//	printf("1111111111111111111111111111111111111111111\n");
//	addRefereeEventByID(list, 1, 11);
//	addRefereeEventByID(list, 1, 12);
//	addRefereeEventByID(list, 1, 13);
//	addRefereeEventByID(list, 1, 14);
//	//addrefereeEventByID(list, 1, 11);
//	baseNode *basenode = head->next->eventList->head;
//	for (int i = 0; i < head->next->eventList->size; i++){
//		basenode = basenode->next;
//		printf("%d\n",basenode->id);
//	}
//	printf("-----------------");
//
//	//	//д���ʱ�򣬸�Ϊwb,��ȡ��ʱ��Ϊrb
//
//	//savereferee(fp, list);
//
//	FILE *fp;
//	fopen_s(&fp, "referee/refereeList.txt", "wb");
//	saveReferee(fp, list);
//	//refereeList *list = getreferee(fp);
//
//	int a;
//	scanf_s("%d", &a);
//
//}