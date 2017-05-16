#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
typedef struct unitInfo{

	char leaderName[200];
	char leaderIntro[2000];
	char leaderContact[200];
	
	char unitName[200];
	char unitSolgan[200];
	char unitIntroduction[2000];

	long participantSize;
	long id;
	long score;
	long rank;
}unitInfo;


typedef struct unitNode{
	unitInfo unitInfomation;
	baseList *participantList;
	unitNode *pre;
	unitNode *next;
}unitNode;

typedef struct unitList{
	unitNode *head;
	unitNode *tail;
	long size;
}unitList;

//得到一个节点
unitNode* makeUnitNode(unitInfo unitInfomation){
	unitNode *node = NULL;
	node = (unitNode*)malloc(sizeof(unitNode));
	if (node != NULL){
		node->unitInfomation = unitInfomation;
		node->participantList = initBaseList();
		node->pre = NULL;
		node->next = NULL;
	}
	return node;
}

//初始化项目链表
unitList* initUnitList(){
	struct unitInfo tem = { "","","","", "", "", 0, 0 };
	unitList* list = (unitList*)malloc(sizeof(unitList));
	unitNode* head = makeUnitNode(tem);
	list->head = head;
	list->tail = head;
	list->size = 0;
	return list;
}

//得到头部
unitNode* getUnitHead(unitList* list){
	return list->head;
}

//得到尾部
unitNode* getUnitTail(unitList *list){
	return list->tail;
}


//添加一个新的节点=添加新项目
void addUnitNode(unitList* list, unitNode* node){
	unitNode* tail = getUnitTail(list);
	tail->next = node;
	node->pre = tail;
	list->size++;
	list->tail = node;
	s.unitSize++;
}

//通过ID删除项目=删除
void deleteUnitNodeByID(unitList* list, long id){
	unitNode* head = getUnitHead(list);
	unitNode* tail = getUnitTail(list);
	if (tail->unitInfomation.id == id){
		unitNode* pre = tail->pre;
		pre->next = NULL;
		free(tail);
		list->tail = pre;
		list->size--;
		s.unitSize--;
	}
	else if (head->unitInfomation.id == id){
		unitNode* next = head->next;
		next->pre = NULL;
		free(head);
		list->head = next;
		list->size--;
		s.unitSize--;
	}
	else{
		while (head->unitInfomation.id != id){
			head = head->next;
		}
		unitNode* pre = head->pre;
		unitNode* next = head->next;

		pre->next = next;
		next->pre = pre;
		free(head);
		list->size--;
		s.unitSize--;
	}
}



//通过ID获取项目节点=查看
unitNode* getUnitNodeByID(unitList* list, long id){
	unitNode* head = getUnitHead(list);
	unitNode* tail = getUnitTail(list);
	while (head->unitInfomation.id != id&&head!=tail){
		head = head->next;
	}
	if (head->unitInfomation.id == id){
		return head;
	}
}


unitNode* getUnitNodeByName(unitList* list, char *name){
	unitNode* head = getUnitHead(list);
	unitNode* tail = getUnitTail(list);
	while (strcmp(head->unitInfomation.unitName,name)!=0&&head != tail){
		head = head->next;
	}
	if (strcmp(head->unitInfomation.unitName, name) == 0){
		return head;
	}
}


//通过ID获取项目信息=修改
unitInfo getUnitInfoByID(unitList* list, long unitID){
	unitNode* unit = getUnitNodeByID(list, unitID);
	return unit->unitInfomation;
}



//通过项目ID，选手ID删除选手=删除选手
void deleteUnitParticipantByID(unitList *list, long unitID, long participantID){
	unitNode *unit = getUnitNodeByID(list, unitID);
	baseList *baselist = unit->participantList;
	deleteBaseNodeByID(baselist, participantID);
	unit->unitInfomation.participantSize = unit->participantList->size;
}


//通过ID添加选手到项目中=新增选手
void addUnitParticipantByID(unitList* list, long unitID, long participantID){
	unitNode* unit = getUnitNodeByID(list, unitID);
	baseNode *node = makeBaseNode(participantID);
	addBaseNode(unit->participantList, node);
	unit->unitInfomation.participantSize = unit->participantList->size;
}

void saveUnit(unitList *list){
	FILE *fp;
	fopen_s(&fp, "unit/unit", "wb");
	unitNode *head = getUnitHead(list);
	unitInfo info = head->unitInfomation;
	for (int i = 0; i < list->size; i++){
		head = head->next;
		info = head->unitInfomation;
		fwrite(&info, sizeof(unitInfo), 1, fp);

		char id[200] = "unit/";
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

unitList* getUnit(){
	FILE *fp;
	fopen_s(&fp, "unit/unit", "rb");
	unitList *list = initUnitList();
	unitInfo info = { "","","", "", "", "", 0, 0 };
	unitNode *node = makeUnitNode(info);
	int temSize = s.unitSize;
	for (int i = 0; i < temSize; i++){
		fread(&info, sizeof(unitInfo), 1, fp);
		node = makeUnitNode(info);
		addUnitNode(list, node);

		char id[200] = "unit/";
		char tem[200];
		_itoa_s(info.id, tem, 10);
		strcat_s(id, tem);

		FILE *idFP;
		fopen_s(&idFP, id, "rb");
		baseNode *basenode = makeBaseNode(0);
		printf("%ld", info.participantSize);
		for (int i = 0; i < info.participantSize; i++){
			long iD = 0;
			fread(&iD, sizeof(long), 1, idFP);
			printf("Unit%ld", iD);
			basenode = makeBaseNode(iD);
			addUnitParticipantByID(list, node->unitInfomation.id, iD);
		}
		fclose(idFP);
		
	}
	s.unitSize = temSize;
	fclose(fp);
	return list;
}

//int main(){
//
//	/*unitList *list = initUnitList();
//
//	unitInfo unitInfomation = { "你好", "你", "好", "你的", "he", "qw", 4, 1};
//	unitNode *node = makeUnitNode(unitInfomation);
//
//	unitInfo unitInfomation1 = { "好", "你", "好", "的", "as","12",0, 2};
//	unitNode *node1 = makeUnitNode(unitInfomation1);
//
//
//	addUnitNode(list, node);
//	addUnitNode(list, node1);*/
//
//	//deleteunitNodeByID(list, 1);
//	
//	FILE *fp;
//	fopen_s(&fp, "unitList.txt", "rb");
//	unitList *list = getUnit();
//
//	unitNode *head = list->head;
//
//	printf("%s\n", head->next->unitInfomation.leaderContact);
//	printf("%s\n", head->next->unitInfomation.leaderName);
//	printf("%s\n", head->next->unitInfomation.leaderIntro);
//	printf("%s\n", head->next->unitInfomation.unitIntroduction);
//	printf("%s\n", head->next->unitInfomation.unitName);
//	printf("%s\n", head->next->unitInfomation.unitSolgan);
//	printf("%d\n", head->next->unitInfomation.participantSize);
//	printf("%d\n", head->next->unitInfomation.id);
//	
//	printf("1111111111111111111111111111111111111111111\n");
//	/*addUnitParticipantByID(list, 1, 11);
//	addUnitParticipantByID(list, 1, 12);
//	addUnitParticipantByID(list, 1, 13);
//	addUnitParticipantByID(list, 1, 14);*/
//	//addunitEventByID(list, 1, 11);
//	baseNode *basenode = head->next->participantList->head;
//	for (int i = 0; i < head->next->participantList->size; i++){
//		basenode = basenode->next;
//		printf("%d\n",basenode->id);
//	}
//	printf("-----------------");
//
//	//	//写入的时候，改为wb,读取的时候为rb
//
//	//saveunit(fp, list);
//
//	/*FILE *fp;
//	fopen_s(&fp, "unitList.txt", "wb");
//	saveUnit(fp, list);*/
//	//unitList *list = getUnit(fp);
//
//	int a;
//	scanf_s("%d", &a);
//
//}