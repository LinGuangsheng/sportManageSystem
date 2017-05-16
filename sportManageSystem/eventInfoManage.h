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
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("确认删除该项目？"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));


	gint response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//这里写gettext代码
		deleteEvent(button, data);
		gtk_widget_destroy(dialog);

	}

}


void eventInfoManage(){
	//定义相关控件，窗口:window，背景图:bgImage,Logo:logo,fixed布局:fixed，其他的就那些了

	GtkWidget *finish;
	GtkWidget *cancel;



	GtkWidget *facultyList;

	GtkWidget *facultyListTitle;
	GtkWidget *facultyListName;
	GtkWidget *facultyListItemNum;
	GtkWidget *facultyListXSN;
	GtkWidget *facultyListOperator;
	GtkWidget *scrolledWindow;





	//以下控件的设置方法相同，先得到控件，然后设置大小




	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("新增项目"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(eventInfoManage_to_eventRegister), NULL);
	if (flag){
		gtk_widget_set_sensitive(GTK_WIDGET(cancel), FALSE);
	}


	finish = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(finish), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(finish), 220, 40);
	g_signal_connect_swapped(G_OBJECT(finish), "clicked", G_CALLBACK(eventInfoManage_to_manager), NULL);


	facultyList = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(facultyList), 600, 300);

	facultyListTitle = gtk_label_new(_T("运动会项目列表"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListTitle), 600, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListTitle, 0, 0, 600, 40);

	facultyListName = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListName), 130, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListName, 0, 40, 130, 40);

	facultyListItemNum = gtk_label_new(_T("时间"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListItemNum), 130, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListItemNum, 130, 40, 130, 40);

	facultyListXSN = gtk_label_new(_T("地点"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListXSN), 130, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListXSN, 260, 40, 130, 40);

	facultyListOperator = gtk_label_new(_T("操作"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListOperator), 210, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListOperator, 390, 40, 210, 40);


	//新建一个scrolled组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 220);
	//新建一个gred布局，用于存放列表项
	GtkWidget *itemGrid = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(itemGrid), 600, 40);
	//通过循环，将列表项添加进itemGrid

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

		GtkWidget *lookChange = gtk_button_new_with_label(_T("查看/修改"));
		gtk_widget_set_size_request(GTK_WIDGET(lookChange), 105, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), lookChange, 390, i * 40, 105, 40);
		//g_signal_connect(G_OBJECT(lookChange), "clicked", G_CALLBACK(eventInfoManage_to_eventCheck), head);
		g_signal_connect(G_OBJECT(lookChange), "clicked", G_CALLBACK(eventInfoManage_to_eventInfoChange), head);



		GtkWidget *deletes = gtk_button_new_with_label(_T("删除"));
		gtk_widget_set_size_request(GTK_WIDGET(deletes), 105, 40);
		g_signal_connect(G_OBJECT(deletes), "clicked", G_CALLBACK(show_deleteEventConfirm), head);


		gtk_grid_attach(GTK_GRID(itemGrid), deletes, 495, i * 40, 105, 40);
		//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolledWindow), itemGrid);
		//gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);
	}

	//将itemGrid添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);

	gtk_grid_attach(GTK_GRID(facultyList), scrolledWindow, 0, 80, 600, 220);

	//得到fixed布局，并把控件部署上去
	fixed = gtk_fixed_new();
	initialWindow(fixed);




	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), finish, 440, 520);

	gtk_fixed_put(GTK_FIXED(fixed), facultyList, 100, 180);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);
}