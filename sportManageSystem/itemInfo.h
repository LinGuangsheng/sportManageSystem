#include<gtk\gtk.h>
void itemInfo_to_athleteInfo(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	initAthleteInfoWindow();
}
void timeCrash()
{
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("时间冲突"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("提示"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

void addPNewEvent(GtkWidget *button, gpointer   user_data)
{
	GtkWidget *content_area;
	GtkWidget *dialog;
	GtkWidget *hbox;
	GtkWidget *image;
	GtkWidget *table;
	GtkWidget *local_entry1;
	GtkWidget *local_entry2;
	GtkWidget *label;
	gint response;
	GtkWidget *combo;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("选择项目"), "title");

	content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 8);
	gtk_container_set_border_width(GTK_CONTAINER(hbox), 8);
	gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

	//image = gtk_image_new_from_icon_name("dialog-question", GTK_ICON_SIZE_DIALOG);
	//gtk_box_pack_start(GTK_BOX(hbox), image, FALSE, FALSE, 0);

	combo = gtk_combo_box_text_new();
	eventNode *node = getEventHead(eventlist);
	int Aflag = 0;
	for (int i = 0; i < eventlist->size; i++){
		node = node->next;
		if (getEventDetailNodeByID(par_node->eventList, node->eventInfomation.id) == NULL&&flag){
			gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), "1", _T(node->eventInfomation.name));
			Aflag = 1;
		}
	}
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo), 0);

	table = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(table), 4);
	gtk_grid_set_column_spacing(GTK_GRID(table), 4);
	gtk_box_pack_start(GTK_BOX(hbox), table, TRUE, TRUE, 0);
	label = gtk_label_new_with_mnemonic("Name");
	local_entry1 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(local_entry1), "");

	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_entry1);

	label = gtk_label_new_with_mnemonic(_T("项目"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 1, 1, 1);

	local_entry2 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(local_entry2), "");
	gtk_grid_attach(GTK_GRID(table), combo, 1, 1, 1, 1);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_entry2);

	gtk_widget_show_all(hbox);
	response = gtk_dialog_run(GTK_DIALOG(dialog));

	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//这里写gettext代码
		if (Aflag){
			gchar *c = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo));
			if (c != NULL){
				char *event = __T(c);
				eventNode *eventN = getEventNodeByName(eventlist, event);

				int F = 1;
				eventDetailNode *eventDB = getEventDetailListHead(par_node->eventList);
				for (int i = 0; i < par_node->eventList->size; i++){
					eventDB = eventDB->next;
					eventNode *e = getEventNodeByID(eventlist, eventDB->eventDetail.id);
					if (e->eventInfomation.timeNum == eventN->eventInfomation.timeNum){
						F = 0;
					}
				}

				if (F){
					addEventParticipantByID(eventlist, eventN->eventInfomation.id, par_node->participantInfomation.id);
					eventDetail eventD = { eventN->eventInfomation.id, "", 0, eventN->eventInfomation.addSize };
					addParticipantEventByID(parlist, par_node->participantInfomation.id, eventD);
				}
				else{
					//提示时间冲突
					timeCrash();
				}
			}
		}
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		initItemInfo();
	}

	gtk_widget_destroy(dialog);
}





void initItemInfo(){
	GtkWidget *facultyList;

	GtkWidget *facultyListTitle;
	GtkWidget *facultyListName;
	GtkWidget *facultyListNum;
	GtkWidget *facultyListItemNum;
	GtkWidget *facultyListXSN;
	GtkWidget *facultyListScore;
	GtkWidget *facultyListReferee;
	GtkWidget *facultyListOperator;
	GtkWidget *comeback;
	GtkWidget *scrolledWindow;
	GtkWidget *addNewEvent;
	//设置窗口，辩题和大小
	/*函数gtk_window_set_icon() 是为窗口设置图标用的，函数create_pixbuf是我们自定义的，目的是从一个图片中获取信息得到pixbuf。*/
	gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("logo.png"));
	//新建一个gred布局，用于存放整个表格
	facultyList = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(facultyList), 600, 300);

	facultyListTitle = gtk_label_new(_T("参赛项目"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListTitle), 600, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListTitle, 0, 0, 600, 40);

	facultyListName = gtk_label_new(_T("项目名称"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListName), 100, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListName, 0, 40, 100, 40);

	facultyListNum = gtk_label_new(_T("号码"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListNum), 100, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListNum, 100, 40, 100, 40);

	facultyListItemNum = gtk_label_new(_T("时间"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListItemNum), 100, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListItemNum, 200, 40, 100, 40);

	facultyListXSN = gtk_label_new(_T("场地"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListXSN), 100, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListXSN, 300, 40, 100, 40);

	facultyListScore = gtk_label_new(_T("成绩"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListScore), 100, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListScore, 400, 40, 100, 40);

	facultyListReferee = gtk_label_new(_T("排名"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListReferee), 100, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListReferee, 500, 40, 100, 40);

	//新建一个scrolled组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 220);
	//新建一个gred布局，用于存放列表项
	GtkWidget *itemGrid = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(itemGrid), 600, 40);
	//通过循环，将列表项添加进itemGrid


	eventDetailNode *head = getEventDetailListHead(par_node->eventList);
	for (int i = 0; i < par_node->eventList->size; i++){
		head = head->next;
		eventNode *event = getEventNodeByID(eventlist, head->eventDetail.id);


		GtkWidget *facultyListName_i = gtk_label_new(_T(event->eventInfomation.name));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListName_i), 100, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListName_i, 0, i * 40, 100, 40);

		char tem[20];
		_itoa_s(head->eventDetail.number, tem, 10);
		GtkWidget *facultyListNum_i = gtk_label_new(_T(tem));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListNum_i), 100, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListNum_i, 100, i * 40, 100, 40);

		GtkWidget *facultyListItemNum_i = gtk_label_new(_T(event->eventInfomation.time));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListItemNum_i), 100, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListItemNum_i, 200, i * 40, 100, 40);

		GtkWidget *facultyListItemXSN_i = gtk_label_new(_T(event->eventInfomation.place));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListItemXSN_i), 100, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListItemXSN_i, 300, i * 40, 100, 40);

		GtkWidget *facultyListScore_i = gtk_label_new(_T(head->eventDetail.eventScore));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListScore_i), 100, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListScore_i, 400, i * 40, 100, 40);

		char tem2[200];
		_itoa_s(head->eventDetail.eventRank, tem2, 10);

		GtkWidget *facultyListRank_i = gtk_label_new(_T(tem2));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListRank_i), 100, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListRank_i, 500, i * 40, 100, 40);

	}

	//将itemGrid添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);

	gtk_grid_attach(GTK_GRID(facultyList), scrolledWindow, 0, 80, 600, 220);


	comeback = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(comeback), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(comeback), 220, 40);
	g_signal_connect(G_OBJECT(comeback), "clicked", G_CALLBACK(itemInfo_to_athleteInfo), NULL);

	addNewEvent = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(addNewEvent), _T("添加新项目"));
	gtk_widget_set_size_request(GTK_WIDGET(addNewEvent), 220, 40);
	g_signal_connect(G_OBJECT(addNewEvent), "clicked", G_CALLBACK(addPNewEvent), NULL);

	//	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(), NULL);
	//得到fixed布局，并把控件部署上去
	fixed = gtk_fixed_new();
	initialWindow(fixed);
	gtk_fixed_put(GTK_FIXED(fixed), facultyList, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), comeback, 440, 520);
	gtk_fixed_put(GTK_FIXED(fixed), addNewEvent, 140, 520);
	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);




}