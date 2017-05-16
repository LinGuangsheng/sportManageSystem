#include <gtk\gtk.h>

void McheckWindow_to_manager(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	smInfoManage();
}


void relaeseBook(GtkWidget *button, gpointer data){
	flag = 1;
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	smInfoManage();
}

void veryImportant(GtkWidget *button, gpointer data){
	GtkWidget *content_area;
	GtkWidget *dialog;
	GtkWidget *hbox;
	GtkWidget *image;
	GtkWidget *table;
	GtkWidget *local_entry1;
	GtkWidget *local_entry2;
	GtkWidget *label;
	gint response;

	dialog = gtk_dialog_new_with_buttons(_T("警告"),
		GTK_WINDOW(window),
		GTK_DIALOG_DESTROY_WITH_PARENT,
		("_OK"),
		GTK_RESPONSE_OK,
		"_Cancel",
		GTK_RESPONSE_CANCEL,
		NULL);

	content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 8);
	gtk_container_set_border_width(GTK_CONTAINER(hbox), 8);
	gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

	image = gtk_image_new_from_icon_name("dialog-warning", GTK_ICON_SIZE_DIALOG);
	gtk_box_pack_start(GTK_BOX(hbox), image, FALSE, FALSE, 0);

	table = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(table), 4);
	gtk_grid_set_column_spacing(GTK_GRID(table), 4);
	gtk_box_pack_start(GTK_BOX(hbox), table, TRUE, TRUE, 0);
	label = gtk_label_new_with_mnemonic(_T("一经发布，不可修改"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 0.5, 1, 1);
	local_entry1 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(local_entry1), " ");
	//(GTK_GRID(table), local_entry1, 1, 0, 1, 1);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_entry1);

	label = gtk_label_new_with_mnemonic("E_ntry 2");
	//gtk_grid_attach(GTK_GRID(table), label, 0, 1, 1, 1);

	local_entry2 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(local_entry2), " ");
	//gtk_grid_attach(GTK_GRID(table), local_entry2, 1, 1, 1, 1);
	//gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_entry2);

	gtk_widget_show_all(hbox);
	response = gtk_dialog_run(GTK_DIALOG(dialog));

	if (response == GTK_RESPONSE_OK)
	{
		relaeseBook(button, data);
	}

	gtk_widget_destroy(dialog);
}

void McheckWindow(){
	GtkWidget *scrolledWindow2;
	GtkWidget *introductionInput6;
	int high;

	//设置窗口，辩题和大小



	GtkWidget *nameLabel = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 80, 40);

	GtkWidget *nameLabelText = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameLabelText), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(nameLabelText), _T(sInfo.name));
	gtk_editable_set_editable(GTK_EDITABLE(nameLabelText), FALSE);

	GtkWidget *timeLabel = gtk_label_new(_T("时间"));
	gtk_widget_set_size_request(GTK_WIDGET(timeLabel), 80, 40);

	GtkWidget *timeLabelText = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(timeLabelText), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(timeLabelText), _T(sInfo.time));
	gtk_editable_set_editable(GTK_EDITABLE(timeLabelText), FALSE);

	GtkWidget *placeLabel = gtk_label_new(_T("地点"));
	gtk_widget_set_size_request(GTK_WIDGET(placeLabel), 80, 40);

	GtkWidget *placeLabelText = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(placeLabelText), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(placeLabelText), _T(sInfo.place));
	gtk_editable_set_editable(GTK_EDITABLE(placeLabelText), FALSE);

	GtkWidget *hostLabel = gtk_label_new(_T("主办方"));
	gtk_widget_set_size_request(GTK_WIDGET(hostLabel), 80, 40);

	GtkWidget *hostLabelText = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(hostLabelText), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(hostLabelText), _T(sInfo.host));
	gtk_editable_set_editable(GTK_EDITABLE(hostLabelText), FALSE);



	GtkWidget *introductionLabel = gtk_label_new(_T("运动会简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 260, 40);

	introductionInput6 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput6), 260, 160);
	setTextToTextview(GTK_TEXT_VIEW(introductionInput6), sInfo.introduction);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput6), GTK_WRAP_CHAR);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(introductionInput6), FALSE);

	//新建一个scrolled组件
	scrolledWindow2 = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow2), 260, 160);

	fixed = gtk_fixed_new();
	initialWindow(fixed);



	GtkWidget *fixedSub = gtk_fixed_new();
	GtkWidget *comeout;


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

	eventNode *head1 = getEventHead(eventlist);
	int count = 0;
	int MAflag[2000];
	memset(MAflag, -1, sizeof(MAflag));
	while (count < eventlist->size){
		head1 = getEventHead(eventlist);
		int min = 99999;
		long test = -2;
		for (int i = 0; i < eventlist->size; i++){
			head1 = head1->next;
			if (min>head1->eventInfomation.timeNum&&MAflag[head1->eventInfomation.id]<0){
				min = head1->eventInfomation.timeNum;
				test = head1->eventInfomation.id;
			}
		}
		eventNode *e_node = getEventNodeByID(eventlist, test);
		MAflag[e_node->eventInfomation.id] = 1;
		char tem2[20];
		_itoa_s(e_node->eventInfomation.timeNum, tem2, 10);

		GtkWidget *tableTime_ = gtk_label_new(_T(e_node->eventInfomation.time));
		gtk_widget_set_size_request(GTK_WIDGET(tableTime_), 170, 40);

		GtkWidget *tableName_ = gtk_label_new(_T(e_node->eventInfomation.name));
		gtk_widget_set_size_request(GTK_WIDGET(tableName_), 170, 40);

		GtkWidget *tablePlace_ = gtk_label_new(_T(e_node->eventInfomation.place));
		gtk_widget_set_size_request(GTK_WIDGET(tablePlace_), 170, 40);


		char tem[200];
		_itoa_s(e_node->eventInfomation.participantSize, tem, 10);
		GtkWidget *tableNum_ = gtk_label_new(_T(tem));
		gtk_widget_set_size_request(GTK_WIDGET(tableNum_), 90, 40);



		gtk_grid_attach(GTK_GRID(gridTable), tableName_, 0, 40 * count + 80, 170, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableTime_, 170, 40 * count + 80, 170, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tablePlace_, 340, 40 * count + 80, 170, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableNum_, 510, 40 * count + 80, 90, 40);

		high = 40 * count + 160;
		count++;
	}

	//for (int i = 0; i < eventlist->size; i++){
	//	head = head->next;

	//	char tem2[20];
	//	_itoa_s(head->eventInfomation.timeNum, tem2, 10);

	//	GtkWidget *tableTime_ = gtk_label_new(_T(head->eventInfomation.time));
	//	gtk_widget_set_size_request(GTK_WIDGET(tableTime_), 170, 40);

	//	GtkWidget *tableName_ = gtk_label_new(_T(head->eventInfomation.name));
	//	gtk_widget_set_size_request(GTK_WIDGET(tableName_), 170, 40);

	//	GtkWidget *tablePlace_ = gtk_label_new(_T(head->eventInfomation.place));
	//	gtk_widget_set_size_request(GTK_WIDGET(tablePlace_), 170, 40);


	//	char tem[200];
	//	_itoa_s(head->eventInfomation.participantSize, tem, 10);
	//	GtkWidget *tableNum_ = gtk_label_new(_T(tem));
	//	gtk_widget_set_size_request(GTK_WIDGET(tableNum_), 90, 40);



	//	gtk_grid_attach(GTK_GRID(gridTable), tableName_, 0, 40 * i + 80, 170, 40);
	//	gtk_grid_attach(GTK_GRID(gridTable), tableTime_, 170, 40 * i + 80, 170, 40);
	//	gtk_grid_attach(GTK_GRID(gridTable), tablePlace_, 340, 40 * i + 80, 170, 40);
	//	gtk_grid_attach(GTK_GRID(gridTable), tableNum_, 510, 40 * i + 80, 90, 40);

	//	high = 40 * i + 160;

	//}


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
	long MMAflag = 1;
	long FalseMMAflag = 1;
	while (MMAflag <= unitlist->size){
		unitNode *uHead2 = getUnitHead(unitlist);
		for (int i = 0; i < unitlist->size; i++){
			uHead2 = uHead2->next;
			if (uHead2->unitInfomation.rank == MMAflag){
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

				gtk_grid_attach(GTK_GRID(gridTable2), tableName1_, 0, 40 * (FalseMMAflag - 1) + 80, 120, 40);
				gtk_grid_attach(GTK_GRID(gridTable2), tableTime1_, 120, 40 * (FalseMMAflag - 1) + 80, 120, 40);
				gtk_grid_attach(GTK_GRID(gridTable2), tableNum1_, 240, 40 * (FalseMMAflag - 1) + 80, 120, 40);
				gtk_grid_attach(GTK_GRID(gridTable2), tableScore1_, 360, 40 * (FalseMMAflag - 1) + 80, 120, 40);
				gtk_grid_attach(GTK_GRID(gridTable2), tableRank1_, 480, 40 * (FalseMMAflag - 1) + 80, 120, 40);
				FalseMMAflag++;
			}
		}
		MMAflag++;
	}



	GtkWidget *cancel = gtk_button_new_with_label(_T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 180, 40);
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(McheckWindow_to_manager), NULL);

	comeout = gtk_button_new_with_label(_T("发布秩序册"));
	gtk_widget_set_size_request(GTK_WIDGET(comeout), 180, 40);
	g_signal_connect(G_OBJECT(comeout), "clicked", G_CALLBACK(veryImportant), NULL);  //releaseBook

	//一经发布不可修改

	if (flag){
		gtk_widget_set_sensitive(GTK_WIDGET(comeout), FALSE);
	}




	gtk_fixed_put(GTK_FIXED(fixedSub), nameLabel, 25, 20);
	gtk_fixed_put(GTK_FIXED(fixedSub), nameLabelText, 110, 20);
	gtk_fixed_put(GTK_FIXED(fixedSub), hostLabel, 25, 80);
	gtk_fixed_put(GTK_FIXED(fixedSub), hostLabelText, 110, 80);
	gtk_fixed_put(GTK_FIXED(fixedSub), timeLabel, 25, 140);
	gtk_fixed_put(GTK_FIXED(fixedSub), timeLabelText, 110, 140);
	gtk_fixed_put(GTK_FIXED(fixedSub), placeLabel, 25, 200);
	gtk_fixed_put(GTK_FIXED(fixedSub), placeLabelText, 110, 200);

	gtk_fixed_put(GTK_FIXED(fixedSub), introductionLabel, 325, 20);
	gtk_fixed_put(GTK_FIXED(fixedSub), scrolledWindow2, 325, 80);
	gtk_fixed_put(GTK_FIXED(fixedSub), gridTable, 0, 260);
	gtk_fixed_put(GTK_FIXED(fixedSub), gridTable2, 0, high + 260);

	GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolled), 600, 300);
	gtk_container_add(GTK_CONTAINER(scrolled), fixedSub);


	gtk_fixed_put(GTK_FIXED(fixed), scrolled, 100, 180);


	gtk_fixed_put(GTK_FIXED(fixed), cancel, 200, 520);
	gtk_fixed_put(GTK_FIXED(fixed), comeout, 420, 520);





	//gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	//gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow2), introductionInput6);

	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);
}