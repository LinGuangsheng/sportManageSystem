#include <gtk\gtk.h>
void show_isLeader()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("����д����˻�"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));

	gint response =  gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//����дgettext����
		
		gtk_widget_destroy(dialog);

	}


}




void instituteManage_to_changeInstitute(GtkWidget *button, gpointer data){
	MunitNode = (unitNode*)data;
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	changeInstitute();
}

void instituteManage_to_leaderRegister(GtkWidget *button, gpointer data){
	show_isLeader();
	gtk_container_remove(GTK_CONTAINER(window), fixed);

	//���
	create_registration_window();
}

void instituteManage_to_manage(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	manager();
}




void deleteUnit(GtkWidget *button, gpointer data){
	MunitNode = (unitNode*)data;
	long unitID = MunitNode->unitInfomation.id;
	baseNode *bNode = getBaseListHead(MunitNode->participantList);
	for (int i = 0; i < MunitNode->participantList->size; i++){
		bNode = bNode->next;
		participantNode *pNode = getParticipantNodeByID(parlist, bNode->id);
		accountNode *account = getAccountNodeByID(accountlist, pNode->participantInfomation.id);
		eventDetailNode *eventNode = getEventDetailListHead(pNode->eventList);
		for (int j = 0; j < pNode->eventList->size; j++){
			eventNode = eventNode->next;
			deletEeventParticipantByID(eventlist, eventNode->eventDetail.id, pNode->participantInfomation.id);
		}
		deleteAccountNodeByID(accountlist, account->account.id);
		deleteParticipantNodeByID(parlist, pNode->participantInfomation.id);
	
	}
	deleteUnitNodeByID(unitlist, unitID);
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	instituteManage();
}


void show_deleteUnitConfirm(GtkWidget *button, gpointer data)
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("ȷ��ɾ���õ�λ��"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));


	gint response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//����дgettext����
		deleteUnit(button, data);
		gtk_widget_destroy(dialog);

	}

}

void instituteManage(){

	//�����������
	GtkWidget *instituteList;
	//������ı���
	GtkWidget *instituteListTitle;
	//����������ĵ�һ�����
	GtkWidget *instituteListName;
	//����������ĵڶ���μ���Ŀ��
	GtkWidget *instituteListItemNum;
	//����������ĵ����ѡ����
	GtkWidget *instituteListXSN;
	//����������ĵ��������
	GtkWidget *instituteListOperator;
	//����grid���֣�����б�����Ž�scroll��
	GtkWidget *itemGrid;

	//�������������������λ
	GtkWidget *addNew;
	//�������������
	GtkWidget *return_;

	//�����������
	GtkWidget *scrolledWindow;

	//�õ�fixed���֣�����ʼ������
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//����һ��grid���֣����ڴ�������б�
	instituteList = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(instituteList), 600, 300);

	//���ñ��ĸ�����������⣬��������4�������
	instituteListTitle = gtk_label_new(_T("������λ�б�"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListTitle), 600, 40);
	gtk_grid_attach(GTK_GRID(instituteList), instituteListTitle, 0, 0, 600, 40);

	instituteListName = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListName), 195, 40);
	gtk_grid_attach(GTK_GRID(instituteList), instituteListName, 0, 40, 195, 40);

	instituteListItemNum = gtk_label_new(_T("ѡ����"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListItemNum), 195, 40);
	gtk_grid_attach(GTK_GRID(instituteList), instituteListItemNum, 195, 40, 195, 40);


	instituteListOperator = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListOperator), 210, 40);
	gtk_grid_attach(GTK_GRID(instituteList), instituteListOperator, 390, 40, 210, 40);

	//����scroll���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 220);

	//�½�һ��gred���֣����ڴ���б���
	itemGrid = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(itemGrid), 600, 40);

	//ͨ��ѭ�������б�����ӽ�itemGrid
	unitNode *head = getUnitHead(unitlist);
	for (int i = 0; i < unitlist->size; i++){

		head = head->next;

		GtkWidget *instituteListName_i = gtk_label_new(_T(head->unitInfomation.unitName));
		gtk_widget_set_size_request(GTK_WIDGET(instituteListName_i), 195, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), instituteListName_i, 0, i * 40, 195, 40);

		char tem[200];
		_itoa_s(head->unitInfomation.participantSize, tem, 10);
		GtkWidget *instituteListItemNum_i = gtk_label_new(_T(tem));
		gtk_widget_set_size_request(GTK_WIDGET(instituteListItemNum_i), 195, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), instituteListItemNum_i, 195, i * 40, 195, 40);

		/*GtkWidget *instituteListXSN_i = gtk_label_new(_T("��ʱ"));
		gtk_widget_set_size_request(GTK_WIDGET(instituteListXSN_i), 130, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), instituteListXSN_i, 260, i * 40, 130, 40);*/

		GtkWidget *lookChange = gtk_button_new_with_label(_T("�鿴/�޸�"));
		gtk_widget_set_size_request(GTK_WIDGET(lookChange), 105, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), lookChange, 390, i * 40, 105, 40);
		//g_signal_connect_swapped(G_OBJECT(lookChange), "clicked", G_CALLBACK(instituteManage_to_checkInstitute), NULL);
		g_signal_connect(G_OBJECT(lookChange), "clicked", G_CALLBACK(instituteManage_to_changeInstitute), head);

		GtkWidget *deletes = gtk_button_new_with_label(_T("ɾ��"));
		gtk_widget_set_size_request(GTK_WIDGET(deletes), 105, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), deletes, 495, i * 40, 105, 40);
		g_signal_connect(G_OBJECT(deletes), "clicked", G_CALLBACK(show_deleteUnitConfirm), head);

	}

	//��itemGrid��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);

	//��scroll�����ӵ������
	gtk_grid_attach(GTK_GRID(instituteList), scrolledWindow, 0, 80, 600, 220);

	//�������������������λ������
	addNew = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(addNew), _T("����������λ"));
	gtk_widget_set_size_request(GTK_WIDGET(addNew), 220, 40);
	g_signal_connect_swapped(G_OBJECT(addNew), "clicked", G_CALLBACK(instituteManage_to_leaderRegister), NULL);

	return_ = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(return_), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(return_), 220, 40);
	g_signal_connect_swapped(G_OBJECT(return_), "clicked", G_CALLBACK(instituteManage_to_manage), NULL);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), instituteList, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), addNew, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), return_, 440, 520);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}