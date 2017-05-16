#include <gtk\gtk.h>


GtkWidget *nameInput1;
GtkWidget *timeInput1;
GtkWidget *placeInput1;
GtkWidget *hostInput1;
GtkWidget *sportsMeetingIntroInput1;



void makeedBook(){
	int k = 0;
	eventNode *elistTest1 = getEventHead(eventlist);
	elistTest1 = elistTest1->next;
	if (elistTest1->eventInfomation.timeNum == 0)
	{
		k += 20;
		elistTest1->eventInfomation.timeNum = k;
		eventNode *elistTest2 = getEventHead(eventlist);
		for (int i = 0; i < eventlist->size; i++)
		{
			elistTest2 = elistTest2->next;
			if (elistTest2->eventInfomation.timeNum == 0 && strcmp(elistTest1->eventInfomation.place, elistTest2->eventInfomation.place) != 0)
			{
				elistTest2->eventInfomation.timeNum = elistTest1->eventInfomation.timeNum;
			}
			else if (elistTest2->eventInfomation.timeNum == 0 && strcmp(elistTest1->eventInfomation.place, elistTest2->eventInfomation.place) == 0)
			{
				k += 20;
				elistTest2->eventInfomation.timeNum = k;
			}
		}
	}
	eventNode *elistTest3 = getEventHead(eventlist);
	for (int i = 0; i < eventlist->size; i++){
		int count = 0;
		elistTest3 = elistTest3->next;
		eventNode *elistTest4 = getEventHead(eventlist);
		for (int i = 0; i < eventlist->size; i++)
		{
			elistTest4 = elistTest4->next;
			if (elistTest3->eventInfomation.timeNum == elistTest4->eventInfomation.timeNum)
			{
				count += 1;
				if (count > 3)
				{
					elistTest4->eventInfomation.timeNum = elistTest4->eventInfomation.timeNum + 20;
					if (elistTest3->eventInfomation.timeNum == elistTest4->eventInfomation.timeNum && strcmp(elistTest3->eventInfomation.place, elistTest4->eventInfomation.place) == 0)
					{
						elistTest4->eventInfomation.timeNum = elistTest4->eventInfomation.timeNum + 20;
					}
				}
			}
		}
	}


	eventNode *elistTestLast = getEventHead(eventlist);
	int x, y, z;

	for (int j = 0; j < eventlist->size; j++){
		elistTestLast = elistTestLast->next;
		if (strcmp(elistTestLast->eventInfomation.name, _T("男子400米决赛")) == 0 || strcmp(elistTestLast->eventInfomation.name, _T("女子400米决赛")))
		{
			printf("%s     %d\n", elistTestLast->eventInfomation.name, elistTestLast->eventInfomation.timeNum);
		}
		if (elistTestLast->eventInfomation.timeNum <= 120)
		{
			z = 1;
			x = 14 + elistTestLast->eventInfomation.timeNum / 60;
			char tem[200] = "";
			char tem2[20] = "";
			strcat_s(tem, "第");
			_itoa_s(z, tem2, 10);
			strcat_s(tem, tem2);
			strcat_s(tem, "天");
			_itoa_s(x, tem2, 10);
			strcat_s(tem, tem2);
			strcat_s(tem, "：");
			_itoa_s(elistTestLast->eventInfomation.timeNum % 60, tem2, 10);
			strcat_s(tem, tem2);
			if (elistTestLast->eventInfomation.timeNum % 60 == 0){
				strcat_s(tem, "0");
			}

			strcpy_s(elistTestLast->eventInfomation.time, tem);

		}
		else{
			z = 2;
			if (elistTestLast->eventInfomation.timeNum<200)
			{
				x = 9 + (elistTestLast->eventInfomation.timeNum - 120) / 60;
				char tem[200] = "";
				char tem2[20] = "";
				strcat_s(tem, "第");
				_itoa_s(z, tem2, 10);
				strcat_s(tem, tem2);
				strcat_s(tem, "天");
				_itoa_s(x, tem2, 10);
				strcat_s(tem, tem2);
				strcat_s(tem, "：");
				_itoa_s(elistTestLast->eventInfomation.timeNum % 60, tem2, 10);
				strcat_s(tem, tem2);
				if (elistTestLast->eventInfomation.timeNum % 60 == 0){
					strcat_s(tem, "0");
				}

				strcpy_s(elistTestLast->eventInfomation.time, tem);
			}
			else
			{
				x = 14 + (elistTestLast->eventInfomation.timeNum - 180) / 60;
				char tem[200] = "";
				char tem2[20] = "";
				strcat_s(tem, "第");
				_itoa_s(z, tem2, 10);
				strcat_s(tem, tem2);
				strcat_s(tem, "天");
				_itoa_s(x, tem2, 10);
				strcat_s(tem, tem2);
				strcat_s(tem, "：");
				_itoa_s(elistTestLast->eventInfomation.timeNum % 60, tem2, 10);
				strcat_s(tem, tem2);
				if (elistTestLast->eventInfomation.timeNum % 60 == 0){
					strcat_s(tem, "0");
				}

				strcpy_s(elistTestLast->eventInfomation.time, tem);
			}

		}
	}

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	McheckWindow();
}

void smInfoManage_to_manager(){
	strcpy_s(sInfo.name, __T(gtk_entry_get_text(GTK_ENTRY(nameInput1))));
	strcpy_s(sInfo.host, __T(gtk_entry_get_text(GTK_ENTRY(hostInput1))));
	strcpy_s(sInfo.place, __T(gtk_entry_get_text(GTK_ENTRY(placeInput1))));
	strcpy_s(sInfo.time, __T(gtk_entry_get_text(GTK_ENTRY(timeInput1))));
	strcpy_s(sInfo.introduction, __T(getTextFromTextview(GTK_TEXT_VIEW(sportsMeetingIntroInput1))));

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	manager();
}

void checkWindow_to_manager(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	manager();
}

long calScore(int rank){
	switch (rank)
	{
	case 1: return 8;
	case 2: return 7;
	case 3: return 6;
	case 4: return 5;
	case 5: return 4;
	case 6: return 3;
	case 7: return 2;
	case 8: return 1;
	default:return 0;
		break;
	}
}
void smInfoManage(){
	//定义相关控件，窗口:window，背景图:bgImage,Logo:logo,fixed布局:fixed，其他的就那些了

	GtkWidget *scrolledWindow2;
	int high;

	//设置窗口，辩题和大小



	GtkWidget *nameLabel = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 80, 40);

	nameInput1 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput1), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(nameInput1), _T(sInfo.name));

	GtkWidget *timeLabel = gtk_label_new(_T("时间"));
	gtk_widget_set_size_request(GTK_WIDGET(timeLabel), 80, 40);

	timeInput1 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(timeInput1), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(timeInput1), _T(sInfo.time));

	GtkWidget *placeLabel = gtk_label_new(_T("地点"));
	gtk_widget_set_size_request(GTK_WIDGET(placeLabel), 80, 40);

	placeInput1 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(placeInput1), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(placeInput1), _T(sInfo.place));

	GtkWidget *hostLabel = gtk_label_new(_T("主办方"));
	gtk_widget_set_size_request(GTK_WIDGET(hostLabel), 80, 40);

	hostInput1 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(hostInput1), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(hostInput1), _T(sInfo.host));



	GtkWidget *introductionLabel = gtk_label_new(_T("运动会简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 260, 40);

	sportsMeetingIntroInput1 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(sportsMeetingIntroInput1), 260, 160);
	setTextToTextview(GTK_TEXT_VIEW(sportsMeetingIntroInput1), sInfo.introduction);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(sportsMeetingIntroInput1), GTK_WRAP_CHAR);

	//新建一个scrolled组件
	scrolledWindow2 = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow2), 260, 160);

	fixed = gtk_fixed_new();
	initialWindow(fixed);



	GtkWidget *fixedSub = gtk_fixed_new();



	//项目列表
	GtkWidget *gridTable = gtk_grid_new();

	GtkWidget *tableTitle = gtk_label_new(_T("项目列表"));
	gtk_widget_set_size_request(GTK_WIDGET(tableTitle), 600, 40);

	GtkWidget *tableTime = gtk_label_new(_T("项目时间"));
	gtk_widget_set_size_request(GTK_WIDGET(tableTime), 170, 40);

	GtkWidget *tableName = gtk_label_new(_T("项目名称"));
	gtk_widget_set_size_request(GTK_WIDGET(tableName), 170, 40);

	GtkWidget *tablePlace = gtk_label_new(_T("项目地点"));
	gtk_widget_set_size_request(GTK_WIDGET(tablePlace), 170, 40);

	GtkWidget *tableNum = gtk_label_new(_T("参加人数"));
	gtk_widget_set_size_request(GTK_WIDGET(tableNum), 90, 40);

	gtk_grid_attach(GTK_GRID(gridTable), tableTitle, 0, 0, 600, 40);
	gtk_grid_attach(GTK_GRID(gridTable), tableName, 0, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(gridTable), tableTime, 170, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(gridTable), tablePlace, 340, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(gridTable), tableNum, 510, 40, 90, 40);

	eventNode *head = getEventHead(eventlist);
	for (int i = 0; i < eventlist->size; i++){
		head = head->next;
		GtkWidget *tableTime_ = gtk_label_new(_T(head->eventInfomation.time));
		gtk_widget_set_size_request(GTK_WIDGET(tableTime_), 170, 40);

		GtkWidget *tableName_ = gtk_label_new(_T(head->eventInfomation.name));
		gtk_widget_set_size_request(GTK_WIDGET(tableName_), 170, 40);

		GtkWidget *tablePlace_ = gtk_label_new(_T(head->eventInfomation.place));
		gtk_widget_set_size_request(GTK_WIDGET(tablePlace_), 170, 40);


		char tem[200];
		_itoa_s(head->eventInfomation.participantSize, tem, 10);
		GtkWidget *tableNum_ = gtk_label_new(_T(tem));
		gtk_widget_set_size_request(GTK_WIDGET(tableNum_), 90, 40);



		gtk_grid_attach(GTK_GRID(gridTable), tableName_, 0, 40 * i + 80, 170, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableTime_, 170, 40 * i + 80, 170, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tablePlace_, 340, 40 * i + 80, 170, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableNum_, 510, 40 * i + 80, 90, 40);

		high = 40 * i + 160;

	}


	//参赛单位列表
	GtkWidget *gridTable2 = gtk_grid_new();

	GtkWidget *tableTitle1 = gtk_label_new(_T("参赛单位列表"));
	gtk_widget_set_size_request(GTK_WIDGET(tableTitle1), 600, 40);

	GtkWidget *tableTime1 = gtk_label_new(_T("领队名称"));
	gtk_widget_set_size_request(GTK_WIDGET(tableTime1), 120, 40);

	GtkWidget *tableName1 = gtk_label_new(_T("单位名称"));
	gtk_widget_set_size_request(GTK_WIDGET(tableName1), 120, 40);

	GtkWidget *tableNum1 = gtk_label_new(_T("参加人数"));
	gtk_widget_set_size_request(GTK_WIDGET(tableNum1), 120, 40);

	GtkWidget *tableRank1 = gtk_label_new(_T("排名"));
	gtk_widget_set_size_request(GTK_WIDGET(tableRank1), 120, 40);

	GtkWidget *tableScore1 = gtk_label_new(_T("积分"));
	gtk_widget_set_size_request(GTK_WIDGET(tableScore1), 120, 40);

	gtk_grid_attach(GTK_GRID(gridTable2), tableTitle1, 0, 0, 600, 40);
	gtk_grid_attach(GTK_GRID(gridTable2), tableName1, 0, 40, 120, 40);
	gtk_grid_attach(GTK_GRID(gridTable2), tableTime1, 120, 40, 120, 40);
	gtk_grid_attach(GTK_GRID(gridTable2), tableNum1, 240, 40, 120, 40);
	gtk_grid_attach(GTK_GRID(gridTable2), tableScore1, 360, 40, 120, 40);
	gtk_grid_attach(GTK_GRID(gridTable2), tableRank1, 480, 40, 120, 40);

	unitNode *uHead = getUnitHead(unitlist);
	for (int i = 0; i < unitlist->size; i++){
		uHead = uHead->next;
		long score = 0;
		baseNode *b_node = uHead->participantList->head;
		for (int j = 0; j < uHead->participantList->size; j++){
			b_node = b_node->next;
			participantNode *part_node = getParticipantNodeByID(parlist, b_node->id);
			eventDetailNode *ed_node = part_node->eventList->head;
			for (int k = 0; k < part_node->eventList->size; k++){
				ed_node = ed_node->next;
				score += calScore(ed_node->eventDetail.eventRank);
			}
		}
		uHead->unitInfomation.score = score;
	}
	unitNode *uHead1 = getUnitHead(unitlist);
	for (int i = 0; i<unitlist->size; i++){
		uHead1 = uHead1->next;
		uHead1->unitInfomation.rank = 0;
	}
	long index = unitlist->size;
	long min = 9999;
	while (index > 0){
		char unitname29[200] = "";
		uHead1 = getUnitHead(unitlist);
		long min1 = 999999;
		if (min1 == min)break;
		for (int i = 0; i < unitlist->size; i++){
			uHead1 = uHead1->next;
			if (uHead1->unitInfomation.rank == 0){
				//uHead1->unitInfomation.rank == 0
				if (min1>uHead1->unitInfomation.score){
					min1 = uHead1->unitInfomation.score;
					strcpy_s(unitname29, uHead1->unitInfomation.unitName);
				}
			}
		}
		unitNode *node = getUnitNodeByName(unitlist, unitname29);
		if (node != NULL){
			node->unitInfomation.rank = index;
			min = min1;
			index--;
		}
	}
	long MBflag = 1;
	long FalseMBflag = 1;
	while (MBflag <= unitlist->size){
		unitNode *uHead2 = getUnitHead(unitlist);
		for (int i = 0; i < unitlist->size; i++){
			uHead2 = uHead2->next;
			if (uHead2->unitInfomation.rank == MBflag){
				GtkWidget *tableTime1_ = gtk_label_new(_T(uHead2->unitInfomation.leaderName));
				gtk_widget_set_size_request(GTK_WIDGET(tableTime1_), 120, 40);

				GtkWidget *tableName1_ = gtk_label_new(_T(uHead2->unitInfomation.unitName));
				gtk_widget_set_size_request(GTK_WIDGET(tableName1_), 120, 40);

				char tem2[200];
				_itoa_s(uHead2->unitInfomation.participantSize, tem2, 10);
				GtkWidget *tableNum1_ = gtk_label_new(_T(tem2));
				gtk_widget_set_size_request(GTK_WIDGET(tableNum1_), 120, 40);
				char tem3[200];
				_itoa_s(uHead2->unitInfomation.score, tem3, 10);
				GtkWidget *tableScore1_ = gtk_label_new(_T(tem3));
				gtk_widget_set_size_request(GTK_WIDGET(tableScore1_), 120, 40);

				char tem4[200];
				_itoa_s(uHead2->unitInfomation.rank, tem4, 10);
				GtkWidget *tableRank1_ = gtk_label_new(_T(tem4));
				gtk_widget_set_size_request(GTK_WIDGET(tableRank1_), 120, 40);

				gtk_grid_attach(GTK_GRID(gridTable2), tableName1_, 0, 40 * (FalseMBflag - 1) + 80, 120, 40);
				gtk_grid_attach(GTK_GRID(gridTable2), tableTime1_, 120, 40 * (FalseMBflag - 1) + 80, 120, 40);
				gtk_grid_attach(GTK_GRID(gridTable2), tableNum1_, 240, 40 * (FalseMBflag - 1) + 80, 120, 40);
				gtk_grid_attach(GTK_GRID(gridTable2), tableScore1_, 360, 40 * (FalseMBflag - 1) + 80, 120, 40);
				gtk_grid_attach(GTK_GRID(gridTable2), tableRank1_, 480, 40 * (FalseMBflag - 1) + 80, 120, 40);
				FalseMBflag++;
			}
		}
		MBflag++;
	}



	GtkWidget *cancel = gtk_button_new_with_label(_T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 180, 40);
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(checkWindow_to_manager), NULL);

	GtkWidget *makeBook = gtk_button_new_with_label(_T("安排秩序册"));
	gtk_widget_set_size_request(GTK_WIDGET(makeBook), 180, 40);
	g_signal_connect(G_OBJECT(makeBook), "clicked", G_CALLBACK(makeedBook), NULL);


	GtkWidget *confirm = gtk_button_new_with_label(_T("确定"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 180, 40);
	g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(smInfoManage_to_manager), NULL);




	gtk_fixed_put(GTK_FIXED(fixedSub), nameLabel, 25, 20);
	gtk_fixed_put(GTK_FIXED(fixedSub), nameInput1, 110, 20);
	gtk_fixed_put(GTK_FIXED(fixedSub), hostLabel, 25, 80);
	gtk_fixed_put(GTK_FIXED(fixedSub), hostInput1, 110, 80);
	gtk_fixed_put(GTK_FIXED(fixedSub), timeLabel, 25, 140);
	gtk_fixed_put(GTK_FIXED(fixedSub), timeInput1, 110, 140);
	gtk_fixed_put(GTK_FIXED(fixedSub), placeLabel, 25, 200);
	gtk_fixed_put(GTK_FIXED(fixedSub), placeInput1, 110, 200);

	gtk_fixed_put(GTK_FIXED(fixedSub), introductionLabel, 325, 20);
	gtk_fixed_put(GTK_FIXED(fixedSub), scrolledWindow2, 325, 80);
	gtk_fixed_put(GTK_FIXED(fixedSub), gridTable, 0, 260);
	gtk_fixed_put(GTK_FIXED(fixedSub), gridTable2, 0, high + 260);

	GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolled), 600, 300);
	gtk_container_add(GTK_CONTAINER(scrolled), fixedSub);


	gtk_fixed_put(GTK_FIXED(fixed), scrolled, 100, 180);


	gtk_fixed_put(GTK_FIXED(fixed), cancel, 100, 520);

	gtk_fixed_put(GTK_FIXED(fixed), makeBook, 310, 520);

	gtk_fixed_put(GTK_FIXED(fixed), confirm, 520, 520);





	//gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	//gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow2), sportsMeetingIntroInput1);

	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);
}