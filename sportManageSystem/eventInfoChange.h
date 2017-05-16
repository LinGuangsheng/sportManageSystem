#include <gtk\gtk.h>

//void eventCheck_to_manager(GtkWidget *button, gpointer data){
//	gtk_container_remove(GTK_CONTAINER(window), fixed);
//	manager();
//}
//


GtkWidget *nameInput6;
GtkWidget *placeInput6;
GtkWidget *rulesInput6;
GtkWidget *introductionInput6;

void eventCheck_to_eventInfoManage(GtkWidget *button, gpointer data){

	strcpy_s(Mevent->eventInfomation.name, __T(gtk_entry_get_text(GTK_ENTRY(nameInput6))));
	strcpy_s(Mevent->eventInfomation.place, __T(gtk_entry_get_text(GTK_ENTRY(placeInput6))));
	strcpy_s(Mevent->eventInfomation.intro, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput6))));
	strcpy_s(Mevent->eventInfomation.rule, __T(getTextFromTextview(GTK_TEXT_VIEW(rulesInput6))));

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	eventInfoManage();
}


void eventCheck_deleteParticipant(GtkWidget *button, gpointer data){
	participantNode *pNode = (participantNode*)data;
	long pID = pNode->participantInfomation.id;
	long eID = Mevent->eventInfomation.id;
	deleteParticipantEventByID(parlist, pID, eID);
	deletEeventParticipantByID(eventlist, eID, pID);
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	eventInfoChange();
}

void show_deletePlayerConfirm(GtkWidget *button, gpointer data)
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("确认删除该选手？"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));


	gint response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//这里写gettext代码
		eventCheck_deleteParticipant(button, data);
		gtk_widget_destroy(dialog);

	}

}

void eventCheck_to_eventInfoManage_cancel(GtkWidget *button, gpointer data){


	gtk_container_remove(GTK_CONTAINER(window), fixed);
	eventInfoManage();
}




void eventInfoChange(){
	//定义相关控件，窗口:window，背景图:bgImage,Logo:logo,fixed布局:fixed，其他的就那些了

	GtkWidget *scrolledWindow1;
	GtkWidget *scrolledWindow2;

	//设置窗口，辩题和大小



	GtkWidget *nameLabel = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 80, 40);

	nameInput6 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput6), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(nameInput6), _T(Mevent->eventInfomation.name));


	GtkWidget *placeLabel = gtk_label_new(_T("地点"));
	gtk_widget_set_size_request(GTK_WIDGET(placeLabel), 80, 40);
	placeInput6 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(placeInput6), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(placeInput6), _T(Mevent->eventInfomation.place));

	GtkWidget *rulesLabel = gtk_label_new(_T("规则"));
	gtk_widget_set_size_request(GTK_WIDGET(rulesLabel), 280, 40);

	rulesInput6 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(rulesInput6), 280, 260);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(rulesInput6), GTK_WRAP_CHAR);
	setTextToTextview(GTK_TEXT_VIEW(rulesInput6), Mevent->eventInfomation.rule);

	GtkWidget *introductionLabel = gtk_label_new(_T("简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 280, 40);

	introductionInput6 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput6), 280, 120);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput6), GTK_WRAP_CHAR);
	setTextToTextview(GTK_TEXT_VIEW(introductionInput6), Mevent->eventInfomation.intro);

	//新建一个scrolled组件
	scrolledWindow1 = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow1), 280, 220);
	scrolledWindow2 = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow2), 280, 140);

	fixed = gtk_fixed_new();
	initialWindow(fixed);


	baseNode *bHead = Mevent->participantList->head;

	GtkWidget *fixedSub = gtk_fixed_new();




	GtkWidget *gridTable = gtk_grid_new();

	GtkWidget *tableTitle = gtk_label_new(_T("参赛选手列表"));
	gtk_widget_set_size_request(GTK_WIDGET(tableTitle), 600, 40);

	GtkWidget *tableInstitute = gtk_label_new(_T("年级专业"));
	gtk_widget_set_size_request(GTK_WIDGET(tableInstitute), 170, 40);

	GtkWidget *tableName = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(tableName), 170, 40);

	GtkWidget *tableNum = gtk_label_new(_T("所属单位"));
	gtk_widget_set_size_request(GTK_WIDGET(tableNum), 170, 40);

	GtkWidget *tableOperate = gtk_label_new(_T("操作"));
	gtk_widget_set_size_request(GTK_WIDGET(tableOperate), 90, 40);

	gtk_grid_attach(GTK_GRID(gridTable), tableTitle, 0, 0, 600, 40);
	gtk_grid_attach(GTK_GRID(gridTable), tableName, 0, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(gridTable), tableInstitute, 170, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(gridTable), tableNum, 340, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(gridTable), tableOperate, 510, 40, 90, 40);


	for (int i = 0; i < Mevent->participantList->size; i++){

		bHead = bHead->next;

		participantNode *pNode = getParticipantNodeByID(parlist, bHead->id);

		GtkWidget *tableInstitute_ = gtk_label_new(_T(pNode->participantInfomation.gradeMajor));
		gtk_widget_set_size_request(GTK_WIDGET(tableInstitute_), 170, 40);

		GtkWidget *tableName_ = gtk_label_new(_T(pNode->participantInfomation.name));
		gtk_widget_set_size_request(GTK_WIDGET(tableName_), 170, 40);


		unitNode *unit = getUnitNodeByID(unitlist, pNode->participantInfomation.unitID);
		GtkWidget *tableNum_ = gtk_label_new(_T(unit->unitInfomation.unitName));
		gtk_widget_set_size_request(GTK_WIDGET(tableNum_), 170, 40);


		GtkWidget *tableOperate_ = gtk_button_new_with_label(_T("删除"));
		gtk_widget_set_size_request(GTK_WIDGET(tableOperate_), 90, 40);
		g_signal_connect(G_OBJECT(tableOperate_), "clicked", G_CALLBACK(show_deletePlayerConfirm), pNode);



		gtk_grid_attach(GTK_GRID(gridTable), tableName_, 0, 40 * i + 80, 170, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableInstitute_, 170, 40 * i + 80, 170, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableNum_, 340, 40 * i + 80, 170, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableOperate_, 510, 40 * i + 80, 90, 40);

	}



	GtkWidget *cancel = gtk_button_new_with_label(_T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 180, 40);
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(eventCheck_to_eventInfoManage_cancel), NULL);

	GtkWidget *confirm = gtk_button_new_with_label(_T("确定"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 180, 40);
	g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(eventCheck_to_eventInfoManage), NULL);




	gtk_fixed_put(GTK_FIXED(fixedSub), nameLabel, 0, 0);
	gtk_fixed_put(GTK_FIXED(fixedSub), nameInput6, 80, 0);
	gtk_fixed_put(GTK_FIXED(fixedSub), placeLabel, 0, 50);
	gtk_fixed_put(GTK_FIXED(fixedSub), placeInput6, 80, 50);
	gtk_fixed_put(GTK_FIXED(fixedSub), rulesLabel, 320, 0);
	gtk_fixed_put(GTK_FIXED(fixedSub), scrolledWindow1, 320, 40);
	gtk_fixed_put(GTK_FIXED(fixedSub), introductionLabel, 0, 90);
	gtk_fixed_put(GTK_FIXED(fixedSub), scrolledWindow2, 0, 130);
	gtk_fixed_put(GTK_FIXED(fixedSub), gridTable, 0, 260);

	GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolled), 600, 300);
	gtk_container_add(GTK_CONTAINER(scrolled), fixedSub);


	gtk_fixed_put(GTK_FIXED(fixed), scrolled, 100, 180);


	gtk_fixed_put(GTK_FIXED(fixed), cancel, 200, 520);

	gtk_fixed_put(GTK_FIXED(fixed), confirm, 420, 520);




	//gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	//gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow1), rulesInput6);
	gtk_container_add(GTK_CONTAINER(scrolledWindow2), introductionInput6);

	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);
}