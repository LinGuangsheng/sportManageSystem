#include <gtk\gtk.h>
void show_isLeader()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("请填写领队账户"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));

	gint response =  gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//这里写gettext代码
		
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

	//领队
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
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("确认删除该单位？"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));


	gint response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//这里写gettext代码
		deleteUnit(button, data);
		gtk_widget_destroy(dialog);

	}

}

void instituteManage(){

	//定义整个表格
	GtkWidget *instituteList;
	//定义表格的标题
	GtkWidget *instituteListTitle;
	//定义标题栏的第一项：名称
	GtkWidget *instituteListName;
	//定义标题栏的第二项：参加项目数
	GtkWidget *instituteListItemNum;
	//定义标题栏的第三项：选手数
	GtkWidget *instituteListXSN;
	//定义标题栏的第四项：操作
	GtkWidget *instituteListOperator;
	//定义grid布局，存放列表项，并放进scroll中
	GtkWidget *itemGrid;

	//定义组件：新增参赛单位
	GtkWidget *addNew;
	//定义组件：返回
	GtkWidget *return_;

	//定义滚动窗口
	GtkWidget *scrolledWindow;

	//得到fixed布局，并初始化窗口
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//设置一个grid布局，用于存放整个列表
	instituteList = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(instituteList), 600, 300);

	//设置表格的各种组件：标题，标题栏（4个组件）
	instituteListTitle = gtk_label_new(_T("参赛单位列表"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListTitle), 600, 40);
	gtk_grid_attach(GTK_GRID(instituteList), instituteListTitle, 0, 0, 600, 40);

	instituteListName = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListName), 195, 40);
	gtk_grid_attach(GTK_GRID(instituteList), instituteListName, 0, 40, 195, 40);

	instituteListItemNum = gtk_label_new(_T("选手数"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListItemNum), 195, 40);
	gtk_grid_attach(GTK_GRID(instituteList), instituteListItemNum, 195, 40, 195, 40);


	instituteListOperator = gtk_label_new(_T("操作"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListOperator), 210, 40);
	gtk_grid_attach(GTK_GRID(instituteList), instituteListOperator, 390, 40, 210, 40);

	//设置scroll组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 220);

	//新建一个gred布局，用于存放列表项
	itemGrid = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(itemGrid), 600, 40);

	//通过循环，将列表项添加进itemGrid
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

		/*GtkWidget *instituteListXSN_i = gtk_label_new(_T("暂时"));
		gtk_widget_set_size_request(GTK_WIDGET(instituteListXSN_i), 130, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), instituteListXSN_i, 260, i * 40, 130, 40);*/

		GtkWidget *lookChange = gtk_button_new_with_label(_T("查看/修改"));
		gtk_widget_set_size_request(GTK_WIDGET(lookChange), 105, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), lookChange, 390, i * 40, 105, 40);
		//g_signal_connect_swapped(G_OBJECT(lookChange), "clicked", G_CALLBACK(instituteManage_to_checkInstitute), NULL);
		g_signal_connect(G_OBJECT(lookChange), "clicked", G_CALLBACK(instituteManage_to_changeInstitute), head);

		GtkWidget *deletes = gtk_button_new_with_label(_T("删除"));
		gtk_widget_set_size_request(GTK_WIDGET(deletes), 105, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), deletes, 495, i * 40, 105, 40);
		g_signal_connect(G_OBJECT(deletes), "clicked", G_CALLBACK(show_deleteUnitConfirm), head);

	}

	//将itemGrid添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);

	//将scroll组件添加到表格中
	gtk_grid_attach(GTK_GRID(instituteList), scrolledWindow, 0, 80, 600, 220);

	//设置组件：新增参赛单位、返回
	addNew = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(addNew), _T("新增参赛单位"));
	gtk_widget_set_size_request(GTK_WIDGET(addNew), 220, 40);
	g_signal_connect_swapped(G_OBJECT(addNew), "clicked", G_CALLBACK(instituteManage_to_leaderRegister), NULL);

	return_ = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(return_), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(return_), 220, 40);
	g_signal_connect_swapped(G_OBJECT(return_), "clicked", G_CALLBACK(instituteManage_to_manage), NULL);

	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), instituteList, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), addNew, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), return_, 440, 520);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}