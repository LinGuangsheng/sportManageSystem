void goBacktoReferee(){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	initReferee();
}


void checkScore(){

	//定义相关组件

	//定义参赛选手整个表格
	GtkWidget *athleteList;

	//定义表格的标题和标题栏上的4个label
	GtkWidget *athleteListTitle;
	GtkWidget *athleteName;
	GtkWidget *athleteGradeAndMajor;
	GtkWidget *atheleteItemNum;
	GtkWidget *athleteListOperator;

	//定义返回按钮
	GtkWidget *cancel;

	//定义滚动窗口
	GtkWidget *scrolledWindow;

	//定义列表项的grid布局
	GtkWidget *itemGrid;

	//重新设置fixed，并初始化窗口
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//设置整个表格
	athleteList = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(athleteList), 600, 300);

	//设置标题
	athleteListTitle = gtk_label_new(_T("参赛单位选手列表"));
	gtk_widget_set_size_request(GTK_WIDGET(athleteListTitle), 600, 40);
	gtk_grid_attach(GTK_GRID(athleteList), athleteListTitle, 0, 0, 600, 40);

	//设置标题栏上的4个label
	athleteName = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(athleteName), 160, 40);
	gtk_grid_attach(GTK_GRID(athleteList), athleteName, 0, 40, 160, 40);

	athleteGradeAndMajor = gtk_label_new(_T("年级专业"));
	gtk_widget_set_size_request(GTK_WIDGET(athleteGradeAndMajor), 180, 40);
	gtk_grid_attach(GTK_GRID(athleteList), athleteGradeAndMajor, 160, 40, 180, 40);

	atheleteItemNum = gtk_label_new(_T("成绩"));
	gtk_widget_set_size_request(GTK_WIDGET(atheleteItemNum), 160, 40);
	gtk_grid_attach(GTK_GRID(athleteList), atheleteItemNum, 340, 40, 160, 40);

	athleteListOperator = gtk_label_new(_T("排名"));
	gtk_widget_set_size_request(GTK_WIDGET(athleteListOperator), 100, 40);
	gtk_grid_attach(GTK_GRID(athleteList), athleteListOperator, 500, 40, 100, 40);

	//设置滚动窗口
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 220);

	//设置列表项的grid布局
	itemGrid = gtk_grid_new();

	//通过for循环，添加列表项
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

	//将列表项grid布局添加到scrolled窗口中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);
	gtk_grid_attach(GTK_GRID(athleteList), scrolledWindow, 0, 80, 600, 220);

	//设置返回按钮
	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 200, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(goBacktoReferee), NULL);

	//得到fixed布局，并把控件部署上
	gtk_fixed_put(GTK_FIXED(fixed), athleteList, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 300, 520);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}