#include <stdio.h>
#include <string.h>
#include <malloc.h>


//����������
typedef struct accountInfo{
	long id;
	char name[200];
	char passwd[200];
	int type; //0�ǹ���Ա��1����ӣ�2�ǲ���Ա��3�ǲ���ѡ��
}accountInfo;

typedef struct accountNode{
	accountInfo account;
	accountNode *pre;
	accountNode *next;
}accountNode;

//������������ 
typedef struct accountList{
	accountNode *head;
	accountNode *tail;
	long size;
}accountList;



//�õ�һ���ڵ� 
accountNode* makeAccountNode(accountInfo account){
	accountNode *p = NULL;
	p = (accountNode*)malloc(sizeof(accountNode));
	if (p != NULL){
		p->account = account;
		p->pre = NULL;
		p->next = NULL;
	}
	return p;
}


// c��ʼ�������õ�һ������ֻ��һ���ڵ�(ռλ)��ID=0 
accountList *initAccountList(){
	accountList *plist = (accountList*)malloc(sizeof(accountList));
	accountInfo account = { 0, "", "", 4 };
	accountNode *head = makeAccountNode(account);
	plist->head = head;
	plist->tail = head;
	plist->size = 0;
	return plist;
}


//�õ���ͷ 
accountNode* getAccountListHead(accountList *plist){
	return plist->head;
}

//�õ�β�� 
accountNode* getAccountNodeTail(accountList *plist){
	return plist->tail;
}

//�õ����� 
int getAccountListSize(accountList *plist){
	return plist->size;
}


//��ýڵ�������� 
long getAccountNodeID(accountNode* p){
	return p->account.id;
}

//����һ���µĽڵ�

void addAccountNode(accountList *list, accountNode* node){
	accountNode* tail = getAccountNodeTail(list);
	tail->next = node;
	node->pre = tail;
	list->size++;
	list->tail = node;
	s.accountSize++;
}

void deleteAccountNodeByID(accountList *list, long id){
	accountNode* head = getAccountListHead(list);
	accountNode* tail = getAccountNodeTail(list);


	if (tail->account.id == id){
		accountNode* pre = tail->pre;
		pre->next = NULL;
		free(tail);
		list->tail = pre;
		list->size--;
		s.eventSize--;
	}
	else if (head->account.id == id){
		accountNode* next = head->next;
		next->pre = NULL;
		free(head);
		list->head = next;
		list->size--;
		s.eventSize--;
	}
	else{
		while (head->account.id != id){
			head = head->next;
		}
		accountNode* pre = head->pre;
		accountNode* next = head->next;

		pre->next = next;
		next->pre = pre;
		free(head);
		list->size--;
		s.accountSize--;
	}
}


accountNode* getAccountNodeByNameAndPasswd(accountList *list, char *name, char *passwd){
	accountNode* head = getAccountListHead(list);
	accountNode* tail = getAccountNodeTail(list);
	while ((strcmp(head->account.name, name) != 0 || strcmp(head->account.passwd, passwd) != 0)&&(head!=tail)){
		head = head->next;
		if (head == tail){
			if (strcmp(head->account.name, name) == 0 && strcmp(head->account.passwd, passwd) == 0){
				return head;
			}
			else{
				return NULL;
			}
		}
	}
	if (strcmp(head->account.name, name) == 0 && strcmp(head->account.passwd, passwd) == 0){
		return head;
	}
	else{
		return NULL;
	}
}


accountNode* getAccountNodeByID(accountList *list, long id){
	accountNode* head = getAccountListHead(list);
	accountNode* tail = getAccountNodeTail(list);
	while (head->account.id != id&&head != tail){
		head = head->next;
	}
	if (head->account.id == id){
		return head;
	}
	else{
		return NULL;
	}
}

accountNode* getAccountNodeByName(accountList *list, char *name){
	accountNode* head = getAccountListHead(list);
	accountNode* tail = getAccountNodeTail(list);
	while (strcmp(head->account.name, name) != 0 && head != tail){
		head = head->next;
		if (head == tail){
			if (strcmp(head->account.name, name) == 0){
				return head;
			}
			else{
				return NULL;
			}
		}
	}
	if (strcmp(head->account.name, name) == 0){
		return head;
	}
	else{
		return NULL;
	}
}


void saveIntoFile(accountList *list){
	FILE *fp;
	fopen_s(&fp, "account/account", "wb");
	accountNode *head = getAccountListHead(list);
	accountInfo info = head->account;
	for (int i = 0; i < list->size; i++){
		head = head->next;
		info = head->account;
		fwrite(&info, sizeof(accountInfo), 1, fp);
	}
	fclose(fp);
}


accountList* getAcountFromFile(){
	FILE *fp;
	fopen_s(&fp, "account/account", "rb");
	accountList *list = initAccountList();
	accountInfo info = { 0, "", "", 0 };
	accountNode *node = makeAccountNode(info);
	int temSize = s.accountSize;
	for (int i = 0; i < temSize; i++){
		//printf("%d\n", i);  //����ʹ��
		fread(&info, sizeof(accountInfo), 1, fp);
		node = makeAccountNode(info);
		addAccountNode(list, node);
	}
	s.accountSize = temSize;
	fclose(fp);
	return list;
}

//int main(){
//
//
//	//��Ҫд���ʱ�򣬰��������ע��ȥ��
//	/*accountList *list = initAccountList();
//
//	accountInfo account1 = { 0, "����Ա", "1234", 0 };
//	accountNode *node1 = makeAccountNode(account1);
//
//	accountInfo account2 = { 0, "���", "5678", 1 };
//	accountNode *node2 = makeAccountNode(account2);
//
//	accountInfo account3 = { 0, "����", "9012", 2 };
//	accountNode *node3 = makeAccountNode(account3);
//
//	accountInfo account4 = { 0, "����ѡ��", "3456", 3 };
//	accountNode *node4 = makeAccountNode(account4);
//
//	accountInfo	account5 = { 0, "1234567890", "pass", 3 };
//	accountNode *node5 = makeAccountNode(account5);
//
//	addAccountNode(list, node1);
//	addAccountNode(list, node2);
//	addAccountNode(list, node3);
//	addAccountNode(list, node4);
//	addAccountNode(list, node5);*/
//
//	accountList *list = getAcountFromFile();
//
//	accountNode *head = getAccountListHead(list);
//
//	for (int i = 0; i < list->size; i++){
//		head = head->next;
//		printf("%d\n", head->account.id);
//		printf("%s\n", head->account.name);
//		printf("%s\n", head->account.passwd);
//		printf("%d\n", head->account.type);
//		printf("------------------------------------------\n");
//	}
//
//
//	accountNode *node = getAccountNodeByNameAndPasswd(list, "1234567890", "pass");
//
//	if (node != NULL){
//		printf("%d\n", node->account.id);
//		printf("%s\n", node->account.name);
//		printf("%s\n", node->account.passwd);
//		printf("%d\n", node->account.type);
//	}
//	else{
//		printf("NONONONO");
//	}
//
//	saveIntoFile(list);
//	//FILE *fp;
//	//д���ʱ�򣬸�Ϊwb,��ȡ��ʱ��Ϊrb
//	//fopen_s(&fp, "accountRecord.txt", "rb");
//	//fopen("accountRecord.txt", "w");
//	//saveIntoFile(fp, list);
//
//	//Ҫ��ȡ��ʱ�򣬰������ע��ȥ��
//	/*accountList* list = getFromFile(fp);
//	accountNode *head = getAccountListHead(list);
//	for (int i = 0; i < list->size; i++){
//	head = head->next;
//	printf("%d\n", head->account.id);
//	printf("%s\n", head->account.name);
//	printf("%s\n", head->account.passwd);
//	printf("%d\n", head->account.type);
//	printf("------------------------------------------\n");
//	}*/
//
//
//	/*
//	node->type������type��������ת���ĸ�����
//	node->id����ID������溯��������Ψһ��ʶ
//	*/
//
//
//
//	int a;
//	scanf_s("%d", &a);
//}












