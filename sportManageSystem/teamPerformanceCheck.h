#include <gtk\gtk.h>
void teamPerformanceCheck_to_leader(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	leader();
}

void teamPerformanceCheck(){

	GtkWidget *confirm;
	GtkWidget *totalRankLabel;
	GtkWidget *totalRank;
	GtkWidget *totalScoreLabel;
	GtkWidget *totalScore;

	GtkWidget *facultyList;
	GtkWidget *facultyListTitle;
	GtkWidget *facultyListName;
	GtkWidget *facultyListItemNum;
	GtkWidget *facultyListXSN;
	GtkWidget *facultyListOperator;
	GtkWidget *scrolledWindow;



	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С



	confirm = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(confirm), _T("ȷ��"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 220, 40);
	g_signal_connect_swapped(G_OBJECT(confirm), "clicked", G_CALLBACK(teamPerformanceCheck_to_leader), NULL);


	facultyList = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(facultyList), 600, 300);

	facultyListTitle = gtk_label_new(_T("����ɼ�"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListTitle), 600, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListTitle, 0, 0, 600, 40);

	facultyListName = gtk_label_new(_T("ѡ��"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListName), 130, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListName, 0, 40, 130, 40);

	facultyListItemNum = gtk_label_new(_T("��Ŀ"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListItemNum), 130, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListItemNum, 130, 40, 130, 40);

	facultyListXSN = gtk_label_new(_T("�ɼ�"));
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

	baseNode *head = getBaseListHead(unit_node->participantList);
	int j = 0;
	for (int i = 0; i < unit_node->participantList->size; i++){

		head = head->next;
		participantNode *p = getParticipantNodeByID(parlist, head->id);
		eventDetailNode *eventD = getEventDetailListHead(p->eventList);
		for (int k = 0; k < p->eventList->size; k++){
			eventD = eventD->next;
			eventNode *e = getEventNodeByID(eventlist, eventD->eventDetail.id);

			GtkWidget *facultyListName_i = gtk_label_new(_T(p->participantInfomation.name));
			gtk_widget_set_size_request(GTK_WIDGET(facultyListName_i), 130, 40);
			gtk_grid_attach(GTK_GRID(itemGrid), facultyListName_i, 0, j * 40, 130, 40);

			GtkWidget *facultyListItemNum_i = gtk_label_new(_T(e->eventInfomation.name));
			gtk_widget_set_size_request(GTK_WIDGET(facultyListItemNum_i), 130, 40);
			gtk_grid_attach(GTK_GRID(itemGrid), facultyListItemNum_i, 130, j * 40, 130, 40);


			GtkWidget *facultyListXSN_i = gtk_label_new(_T(eventD->eventDetail.eventScore));
			gtk_widget_set_size_request(GTK_WIDGET(facultyListXSN_i), 130, 40);
			gtk_grid_attach(GTK_GRID(itemGrid), facultyListXSN_i, 260, j * 40, 130, 40);

			GtkWidget *empty = gtk_label_new(_T(" "));
			gtk_widget_set_size_request(GTK_WIDGET(empty), 70, 40);
			gtk_grid_attach(GTK_GRID(itemGrid), empty, 390, j * 40, 70, 40);

			char tem2[200];
			_itoa_s(eventD->eventDetail.eventRank, tem2, 10);

			GtkWidget *rank = gtk_label_new(_T(tem2));
			gtk_widget_set_size_request(GTK_WIDGET(rank), 70, 40);
			gtk_grid_attach(GTK_GRID(itemGrid), rank, 460, j * 40, 70, 40);
			j++;
		}

		//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolledWindow), itemGrid);
		//gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);
	}

	//��itemGrid��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);

	gtk_grid_attach(GTK_GRID(facultyList), scrolledWindow, 0, 80, 600, 220);


	//�õ�fixed���֣����ѿؼ�������ȥ
	fixed = gtk_fixed_new();

	initialWindow(fixed);


	gtk_fixed_put(GTK_FIXED(fixed), bgImage, 0, 0);

	gtk_fixed_put(GTK_FIXED(fixed), logo, 320, 30);


	gtk_fixed_put(GTK_FIXED(fixed), confirm, 280, 520);

	gtk_fixed_put(GTK_FIXED(fixed), facultyList, 100, 120);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//��ʾ
	gtk_widget_show_all(window);
}
