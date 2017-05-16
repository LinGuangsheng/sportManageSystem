#include <gtk\gtk.h>

void eventInfoManage_to_eventRegister(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	eventRegister();
}

void eventInfoManage_to_manager(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	manager();
}

void deleteEvent(GtkWidget *button, gpointer data){
	Mevent = (eventNode*)data;
	baseList *basel = Mevent->participantList;
	baseNode *bN = getBaseListHead(basel);
	for (int i = 0; i < basel->size; i++){
		bN = bN->next;
		deleteParticipantEventByID(parlist, bN->id, Mevent->eventInfomation.id);
	}
	int flag = 1;
	while (flag){
		refereeNode *node = getRefereeNodeByEventID(refereelist, Mevent->eventInfomation.id);
		if (node == NULL){
			flag = 0;
		}
		else{
			deleteRefereeEventByID(refereelist, node->refereeInfomation.id, Mevent->eventInfomation.id);
		}
	}

	deleteEventNodeByID(eventlist, Mevent->eventInfomation.id);
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	eventInfoManage();
}

//void eventInfoManage_to_eventCheck(GtkWidget *button, gpointer data){
//	gtk_container_remove(GTK_CONTAINER(window), fixed);
//	eventCheck();
//}

void eventInfoManage_to_eventInfoChange(GtkWidget *button, gpointer data){
	Mevent = (eventNode*)data;
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	eventInfoChange();
}

void show_deleteEventConfirm(GtkWidget *button, gpointer data)
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("ȷ��ɾ������Ŀ��"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));


	gint response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//����дgettext����
		deleteEvent(button, data);
		gtk_widget_destroy(dialog);

	}

}


void eventInfoManage(){
	//������ؿؼ�������:window������ͼ:bgImage,Logo:logo,fixed����:fixed�������ľ���Щ��

	GtkWidget *finish;
	GtkWidget *cancel;



	GtkWidget *facultyList;

	GtkWidget *facultyListTitle;
	GtkWidget *facultyListName;
	GtkWidget *facultyListItemNum;
	GtkWidget *facultyListXSN;
	GtkWidget *facultyListOperator;
	GtkWidget *scrolledWindow;





	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С




	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("������Ŀ"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(eventInfoManage_to_eventRegister), NULL);
	if (flag){
		gtk_widget_set_sensitive(GTK_WIDGET(cancel), FALSE);
	}


	finish = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(finish), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(finish), 220, 40);
	g_signal_connect_swapped(G_OBJECT(finish), "clicked", G_CALLBACK(eventInfoManage_to_manager), NULL);


	facultyList = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(facultyList), 600, 300);

	facultyListTitle = gtk_label_new(_T("�˶�����Ŀ�б�"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListTitle), 600, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListTitle, 0, 0, 600, 40);

	facultyListName = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListName), 130, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListName, 0, 40, 130, 40);

	facultyListItemNum = gtk_label_new(_T("ʱ��"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListItemNum), 130, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListItemNum, 130, 40, 130, 40);

	facultyListXSN = gtk_label_new(_T("�ص�"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListXSN), 130, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListXSN, 260, 40, 130, 40);

	facultyListOperator = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListOperator), 210, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListOperator, 390, 40, 210, 40);


	//�½�һ��scrolled���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 220);
	//�½�һ��gred���֣����ڴ���б���
	GtkWidget *itemGrid = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(itemGrid), 600, 40);
	//ͨ��ѭ�������б�����ӽ�itemGrid

	eventNode *head = getEventHead(eventlist);
	for (int i = 0; i < eventlist->size; i++){

		head = head->next;

		GtkWidget *facultyListName_i = gtk_label_new(_T(head->eventInfomation.name));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListName_i), 130, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListName_i, 0, i * 40, 130, 40);

		GtkWidget *facultyListItemNum_i = gtk_label_new(_T(head->eventInfomation.time));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListItemNum_i), 130, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListItemNum_i, 130, i * 40, 130, 40);

		GtkWidget *facultyListXSN_i = gtk_label_new(_T(head->eventInfomation.place));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListXSN_i), 130, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListXSN_i, 260, i * 40, 130, 40);

		GtkWidget *lookChange = gtk_button_new_with_label(_T("�鿴/�޸�"));
		gtk_widget_set_size_request(GTK_WIDGET(lookChange), 105, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), lookChange, 390, i * 40, 105, 40);
		//g_signal_connect(G_OBJECT(lookChange), "clicked", G_CALLBACK(eventInfoManage_to_eventCheck), head);
		g_signal_connect(G_OBJECT(lookChange), "clicked", G_CALLBACK(eventInfoManage_to_eventInfoChange), head);



		GtkWidget *deletes = gtk_button_new_with_label(_T("ɾ��"));
		gtk_widget_set_size_request(GTK_WIDGET(deletes), 105, 40);
		g_signal_connect(G_OBJECT(deletes), "clicked", G_CALLBACK(show_deleteEventConfirm), head);


		gtk_grid_attach(GTK_GRID(itemGrid), deletes, 495, i * 40, 105, 40);
		//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolledWindow), itemGrid);
		//gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);
	}

	//��itemGrid��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);

	gtk_grid_attach(GTK_GRID(facultyList), scrolledWindow, 0, 80, 600, 220);

	//�õ�fixed���֣����ѿؼ�������ȥ
	fixed = gtk_fixed_new();
	initialWindow(fixed);




	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), finish, 440, 520);

	gtk_fixed_put(GTK_FIXED(fixed), facultyList, 100, 180);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//��ʾ
	gtk_widget_show_all(window);
}