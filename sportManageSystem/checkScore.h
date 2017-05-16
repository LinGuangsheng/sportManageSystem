void goBacktoReferee(){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	initReferee();
}


void checkScore(){

	//����������

	//�������ѡ���������
	GtkWidget *athleteList;

	//������ı���ͱ������ϵ�4��label
	GtkWidget *athleteListTitle;
	GtkWidget *athleteName;
	GtkWidget *athleteGradeAndMajor;
	GtkWidget *atheleteItemNum;
	GtkWidget *athleteListOperator;

	//���巵�ذ�ť
	GtkWidget *cancel;

	//�����������
	GtkWidget *scrolledWindow;

	//�����б����grid����
	GtkWidget *itemGrid;

	//��������fixed������ʼ������
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//�����������
	athleteList = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(athleteList), 600, 300);

	//���ñ���
	athleteListTitle = gtk_label_new(_T("������λѡ���б�"));
	gtk_widget_set_size_request(GTK_WIDGET(athleteListTitle), 600, 40);
	gtk_grid_attach(GTK_GRID(athleteList), athleteListTitle, 0, 0, 600, 40);

	//���ñ������ϵ�4��label
	athleteName = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(athleteName), 160, 40);
	gtk_grid_attach(GTK_GRID(athleteList), athleteName, 0, 40, 160, 40);

	athleteGradeAndMajor = gtk_label_new(_T("�꼶רҵ"));
	gtk_widget_set_size_request(GTK_WIDGET(athleteGradeAndMajor), 180, 40);
	gtk_grid_attach(GTK_GRID(athleteList), athleteGradeAndMajor, 160, 40, 180, 40);

	atheleteItemNum = gtk_label_new(_T("�ɼ�"));
	gtk_widget_set_size_request(GTK_WIDGET(atheleteItemNum), 160, 40);
	gtk_grid_attach(GTK_GRID(athleteList), atheleteItemNum, 340, 40, 160, 40);

	athleteListOperator = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(athleteListOperator), 100, 40);
	gtk_grid_attach(GTK_GRID(athleteList), athleteListOperator, 500, 40, 100, 40);

	//���ù�������
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 220);

	//�����б����grid����
	itemGrid = gtk_grid_new();

	//ͨ��forѭ��������б���
	baseNode *head = getBaseListHead(Revent->participantList);
	for (int i = 0; i < Revent->participantList->size; i++){

		head = head->next;

		participantNode *par = getParticipantNodeByID(parlist, head->id);

		GtkWidget *athleteName_i = gtk_label_new(_T(par->participantInfomation.name));
		gtk_widget_set_size_request(GTK_WIDGET(athleteName_i), 160, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), athleteName_i, 0, i * 40, 160, 40);

		GtkWidget *atheleteItemNum_i = gtk_label_new(_T(par->participantInfomation.gradeMajor));
		gtk_widget_set_size_request(GTK_WIDGET(atheleteItemNum_i), 180, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), atheleteItemNum_i, 160, i * 40, 180, 40);


		eventDetailNode *ED = getEventDetailNodeByID(par->eventList, Revent->eventInfomation.id);

		GtkWidget *athleteGradeAndMajor_i = gtk_label_new(_T(ED->eventDetail.eventScore));
		gtk_widget_set_size_request(GTK_WIDGET(athleteGradeAndMajor_i), 160, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), athleteGradeAndMajor_i, 340, i * 40, 160, 40);

		char tem[200];
		_itoa_s(ED->eventDetail.eventRank,tem,10);
		GtkWidget *change = gtk_label_new(_T(tem));
		gtk_widget_set_size_request(GTK_WIDGET(change), 100, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), change, 500, i * 40, 100, 40);

	}

	//���б���grid������ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);
	gtk_grid_attach(GTK_GRID(athleteList), scrolledWindow, 0, 80, 600, 220);

	//���÷��ذ�ť
	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 200, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(goBacktoReferee), NULL);

	//�õ�fixed���֣����ѿؼ�������
	gtk_fixed_put(GTK_FIXED(fixed), athleteList, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 300, 520);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}