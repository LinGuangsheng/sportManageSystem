#include<gtk\gtk.h>
#include<stdlib.h>
//void initReferee_to_initsetScore(GtkWidget *button, gpointer data){
//	gtk_container_remove(GTK_CONTAINER(window), fixed);
//	initSetScroeWindow();
//}
GtkWidget *referee_nameInput;
GtkWidget *referee_phoneNumInput;
GtkWidget *referee_personalIntrInput;


void gotoCheckSM(){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	RcheckWindow();
}

void checkRScore(GtkWidget *button, gpointer data){
	Revent = (eventNode*)data;
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	checkScore();
}

void show_refereeChangeFailed()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("请完整输入信息"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("修改失败"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}
void setInfoAction(GtkWidget *button, gpointer data){

	char *name = __T(gtk_entry_get_text(GTK_ENTRY(referee_nameInput)));
	char *contact = __T(gtk_entry_get_text(GTK_ENTRY(referee_nameInput)));
	if ((strcmp(name, "") == 0) || ((strcmp(contact, "") == 0))){
		show_refereeChangeFailed();
	}

	else {
		strcpy_s(referee_node->refereeInfomation.refereeName, __T(gtk_entry_get_text(GTK_ENTRY(referee_nameInput))));
		strcpy_s(referee_node->refereeInfomation.refereeContact, __T(gtk_entry_get_text(GTK_ENTRY(referee_nameInput))));
		strcpy_s(referee_node->refereeInfomation.refereeIntro, __T(getTextFromTextview(GTK_TEXT_VIEW(referee_personalIntrInput))));
		GtkWidget *dialog;

		dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK, _T("修改成功"), "title");

		gtk_window_set_title(GTK_WINDOW(dialog), _T("提示"));

		gtk_dialog_run(GTK_DIALOG(dialog));

		gtk_widget_destroy(dialog);
	}
}

void show_completeInfo(){
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("请输入完整的信息"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}


void refereePasswordChange(GtkButton *button, gpointer   user_data)
{
	GtkWidget *content_area;
	GtkWidget *dialog;
	GtkWidget *hbox;
	GtkWidget *image;
	GtkWidget *table;
	GtkWidget *local_entry1;
	GtkWidget *local_entry2;
	GtkWidget *local_entry3;
	GtkWidget *label;
	gint response;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("修改密码"), "title");

	content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 8);
	gtk_container_set_border_width(GTK_CONTAINER(hbox), 8);
	gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

	//image = gtk_image_new_from_icon_name("dialog-question", GTK_ICON_SIZE_DIALOG);
	//gtk_box_pack_start(GTK_BOX(hbox), image, FALSE, FALSE, 0);

	table = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(table), 4);
	gtk_grid_set_column_spacing(GTK_GRID(table), 4);
	gtk_box_pack_start(GTK_BOX(hbox), table, TRUE, TRUE, 0);
	label = gtk_label_new_with_mnemonic(_T("原密码"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 0, 1, 1);
	local_entry1 = gtk_entry_new();
	//gtk_entry_set_text(GTK_ENTRY(local_entry1), gtk_entry_get_text(GTK_ENTRY(entry1)));
	gtk_entry_set_text(GTK_ENTRY(local_entry1), "");

	gtk_grid_attach(GTK_GRID(table), local_entry1, 1, 0, 1, 1);
	gtk_entry_set_visibility(GTK_ENTRY(local_entry1), FALSE);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_entry1);

	//第二个
	label = gtk_label_new_with_mnemonic(_T("新密码"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 1, 1, 1);

	local_entry2 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(local_entry2), "");
	gtk_entry_set_visibility(GTK_ENTRY(local_entry2), FALSE);
	gtk_grid_attach(GTK_GRID(table), local_entry2, 1, 1, 1, 1);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_entry2);

	//第三个
	label = gtk_label_new_with_mnemonic(_T("确认"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 2, 1, 1);

	local_entry3 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(local_entry3), "");
	gtk_entry_set_visibility(GTK_ENTRY(local_entry3), FALSE);
	gtk_grid_attach(GTK_GRID(table), local_entry3, 1, 2, 1, 1);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_entry3);

	gtk_widget_show_all(hbox);
	response = gtk_dialog_run(GTK_DIALOG(dialog));

	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		printf("clicked");
		accountNode *account = getAccountNodeByID(accountlist, referee_node->refereeInfomation.id);
		if (strcmp(account->account.passwd, gtk_entry_get_text(GTK_ENTRY(local_entry1))) == 0){
			if (strcmp(gtk_entry_get_text(GTK_ENTRY(local_entry2)), gtk_entry_get_text(GTK_ENTRY(local_entry3))) == 0){
				strcpy_s(account->account.passwd, gtk_entry_get_text(GTK_ENTRY(local_entry2)));
			}
			else{
				//提示前后输入不一致
				show_changeFailed();

				//gtk_widget_destroy(dialog);
			}
		}
		else{
			//提示原密码村务
			show_changeFailed();

			//gtk_widget_destroy(dialog);
		}

		//这里写gettext代码
	}

	gtk_widget_destroy(dialog);
}

void Rshow_changeFailed()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("输入有误，请重新输入"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("修改失败"));


	gint response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//这里写gettext代码

		gtk_widget_destroy(dialog);
	}

}




void setEventScore(GtkWidget *button, gpointer data){
	GtkWidget *content_area;
	GtkWidget *dialog;
	GtkWidget *hbox;
	GtkWidget *image;
	GtkWidget *table;
	GtkWidget *local_combox;
	GtkWidget *local_score_entry2;
	GtkWidget *local_rank_entry3;
	GtkWidget *label;
	gint response;
	eventNode *event = (eventNode*)data;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("登记成绩"), "title");

	content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 8);
	gtk_container_set_border_width(GTK_CONTAINER(hbox), 8);
	gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

	//image = gtk_image_new_from_icon_name("dialog-question", GTK_ICON_SIZE_DIALOG);
	//gtk_box_pack_start(GTK_BOX(hbox), image, FALSE, FALSE, 0);

	table = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(table), 4);
	gtk_grid_set_column_spacing(GTK_GRID(table), 4);
	gtk_box_pack_start(GTK_BOX(hbox), table, TRUE, TRUE, 0);

	label = gtk_label_new_with_mnemonic(_T("参赛选手"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 0, 1, 1);
	local_combox = gtk_combo_box_text_new();
	int flag = 0;
	baseNode *head = event->participantList->head;
	for (int i = 0; i < event->participantList->size; i++){
		head = head->next;
		participantNode *part_node = getParticipantNodeByID(parlist, head->id);
		eventDetailNode *par_node = getEventDetailNodeByID(part_node->eventList, event->eventInfomation.id);
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(local_combox), _T(part_node->participantInfomation.name));
	}


	gtk_grid_attach(GTK_GRID(table), local_combox, 1, 0, 1, 1);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_combox);

	//第二个
	label = gtk_label_new_with_mnemonic(_T("成绩"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 1, 1, 1);

	local_score_entry2 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(local_score_entry2), "");
	gtk_grid_attach(GTK_GRID(table), local_score_entry2, 1, 1, 1, 1);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_score_entry2);

	//第三个
	label = gtk_label_new_with_mnemonic(_T("排名"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 2, 1, 1);

	local_rank_entry3 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(local_rank_entry3), "");
	gtk_grid_attach(GTK_GRID(table), local_rank_entry3, 1, 2, 1, 1);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_rank_entry3);

	gtk_widget_show_all(hbox);
	response = gtk_dialog_run(GTK_DIALOG(dialog));

	if (response == GTK_RESPONSE_OK)
	{
		char *name = __T(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(local_combox)));
		char *score = __T(gtk_entry_get_text(GTK_ENTRY(local_score_entry2)));
		char *rank = __T(gtk_entry_get_text(GTK_ENTRY(local_rank_entry3)));
		if ((name != NULL) && (strcmp(score, "") != 0) && (strcmp(rank, "") != 0)){
			participantNode *p_node = getParticipantNodeByName(parlist, name);
			eventDetailNode *par_node = getEventDetailNodeByID(p_node->eventList, event->eventInfomation.id);
			strcpy_s(par_node->eventDetail.eventScore, __T(gtk_entry_get_text(GTK_ENTRY(local_score_entry2))));
			par_node->eventDetail.eventRank = atoi(gtk_entry_get_text(GTK_ENTRY(local_rank_entry3)));
		}
		else{
			// 提示完整输入
			show_completeInfo();
		}
	}

	gtk_widget_destroy(dialog);
}
void initList(GtkWidget *fixed1){

	//定义相关控件，窗口:window，背景图:bgImage,Logo:logo,fixed布局:fixed，其他的就那些了


	GtkWidget *facultyList;

	GtkWidget *facultyListTitle;
	GtkWidget *facultyListEventName;
	GtkWidget *facultyListItemNum;
	GtkWidget *facultyListTime;
	GtkWidget *facultyListOperator;

	GtkWidget *addNew;
	GtkWidget *cancel;

	GtkWidget *scrolledWindow;


	//新建一个gred布局，用于存放整个表格
	facultyList = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(facultyList), 200, 300);

	facultyListEventName = gtk_label_new(_T("项目"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListEventName), 50, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListEventName, 400, 40, 50, 40);


	facultyListOperator = gtk_label_new(_T("操作"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListOperator), 120, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListOperator, 450, 40, 120, 40);


	//新建一个scrolled组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 200, 170);
	//新建一个gred布局，用于存放列表项
	GtkWidget *itemGrid = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(itemGrid), 200, 40);
	//通过循环，将列表项添加进itemGrid
	baseNode *head = getBaseListHead(referee_node->eventList);
	for (int i = 0; i < referee_node->eventList->size; i++){
		head = head->next;
		eventNode *referee_event = getEventNodeByID(eventlist, head->id);
		GtkWidget *facultyListEventName_i = gtk_label_new(_T(referee_event->eventInfomation.name));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListEventName_i), 50, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListEventName_i, 0, i * 40, 130, 40);


		GtkWidget *changeScore = gtk_button_new_with_label(_T("登记"));
		gtk_widget_set_size_request(GTK_WIDGET(changeScore), 50, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), changeScore, 150, i * 40, 50, 40);
		g_signal_connect(G_OBJECT(changeScore), "clicked", G_CALLBACK(setEventScore), referee_event);

		GtkWidget *setScore = gtk_button_new_with_label(_T("查看"));
		gtk_widget_set_size_request(GTK_WIDGET(setScore), 50, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), setScore, 500, i * 40, 50, 40);
		g_signal_connect(G_OBJECT(setScore), "clicked", G_CALLBACK(checkRScore), referee_event);
		//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolledWindow), itemGrid);
		//gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);
	}

	//将itemGrid添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);

	gtk_grid_attach(GTK_GRID(facultyList), scrolledWindow, 0, 80, 600, 220);

	//得到fixed布局，并把控件部署上去


	gtk_fixed_put(GTK_FIXED(fixed1), facultyList, 560, 240);

}

void initReferee(){
	//定义相关控件，窗口:window，背景图:bgImage,Logo:logo,fixed布局:fixed，其他的就那些了
	GtkWidget *nameLabel;
	GtkWidget *phoneNumLabel;
	GtkWidget *personalIntrLabel;
	GtkWidget *refereeLabel;
	GtkWidget *setInfo;
	GtkWidget *checkSmInfo36;
	GtkWidget *watchGameLabel;
	GtkWidget *cancel;
	GtkWidget *setPassword;
	PangoFontDescription *font;
	//设置窗口，辩题和大小
	font = pango_font_description_from_string("Sans");
	pango_font_description_set_size(font, 20);
	/*函数gtk_window_set_icon() 是为窗口设置图标用的，函数create_pixbuf是我们自定义的，目的是从一个图片中获取信息得到pixbuf。*/
	gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("logo.png"));
	fixed = gtk_fixed_new();
	initialWindow(fixed);
	//以下控件的设置方法相同，先得到控件，然后设置大小
	nameLabel = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	referee_nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(referee_nameInput), 340, 30);
	gtk_entry_set_text(GTK_ENTRY(referee_nameInput), _T(referee_node->refereeInfomation.refereeName));

	phoneNumLabel = gtk_label_new(_T("联系方式"));
	gtk_widget_set_size_request(GTK_WIDGET(phoneNumLabel), 200, 40);

	referee_phoneNumInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(referee_phoneNumInput), 340, 30);
	gtk_entry_set_text(GTK_ENTRY(referee_phoneNumInput), _T(referee_node->refereeInfomation.refereeContact));

	refereeLabel = gtk_label_new(_T("裁判员"));
	gtk_widget_set_size_request(GTK_WIDGET(refereeLabel), 160, 40);


	//
	checkSmInfo36 = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(checkSmInfo36), _T("查看运动会信息"));
	gtk_widget_set_size_request(GTK_WIDGET(checkSmInfo36), 120, 40);
	g_signal_connect(G_OBJECT(checkSmInfo36), "clicked", G_CALLBACK(gotoCheckSM), NULL);



	personalIntrLabel = gtk_label_new(_T("个人简介"));
	gtk_widget_set_size_request(GTK_WIDGET(personalIntrLabel), 200, 40);

	referee_personalIntrInput = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(referee_personalIntrInput), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(referee_personalIntrInput), 400, 140);
	setTextToTextview(GTK_TEXT_VIEW(referee_personalIntrInput), referee_node->refereeInfomation.refereeIntro);

	watchGameLabel = gtk_label_new(_T("负责项目"));
	gtk_widget_set_size_request(GTK_WIDGET(watchGameLabel), 100, 40);

	setInfo = gtk_button_new();
	//	gtk_button_set_relief(GTK_BUTTON(setInfo), GTK_RELIEF_NONE);//透明背景
	gtk_button_set_label(GTK_BUTTON(setInfo), _T("修改个人信息"));
	gtk_widget_set_size_request(GTK_WIDGET(setInfo), 180, 40);
	g_signal_connect(G_OBJECT(setInfo), "clicked", G_CALLBACK(setInfoAction), NULL);

	setPassword = gtk_button_new();
	//	gtk_button_set_relief(GTK_BUTTON(setPassword), GTK_RELIEF_NONE);//透明背景
	gtk_button_set_label(GTK_BUTTON(setPassword), _T("修改密码"));
	gtk_widget_set_size_request(GTK_WIDGET(setPassword), 180, 40);
	g_signal_connect(G_OBJECT(setPassword), "clicked", G_CALLBACK(refereePasswordChange), NULL);

	//得到fixed布局，并把控件部署上去
	fixed = gtk_fixed_new();
	//logo&background
	initialWindow(fixed);
	initList(fixed);

	gtk_fixed_put(GTK_FIXED(fixed), refereeLabel, 320, 110);

	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 20, 180);
	gtk_fixed_put(GTK_FIXED(fixed), referee_nameInput, 150, 182);

	gtk_fixed_put(GTK_FIXED(fixed), phoneNumLabel, 20, 230);
	gtk_fixed_put(GTK_FIXED(fixed), referee_phoneNumInput, 150, 232);

	gtk_fixed_put(GTK_FIXED(fixed), personalIntrLabel, 180, 270);
	gtk_fixed_put(GTK_FIXED(fixed), referee_personalIntrInput, 90, 310);

	gtk_fixed_put(GTK_FIXED(fixed), setInfo, 100, 500);
	gtk_fixed_put(GTK_FIXED(fixed), setPassword, 300, 500);
	gtk_fixed_put(GTK_FIXED(fixed), watchGameLabel, 590, 215);
	gtk_fixed_put(GTK_FIXED(fixed), checkSmInfo36, 575, 175);
	//将布局加载到窗口上

	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);
}
