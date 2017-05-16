#include <gtk\gtk.h>

GtkWidget *nameInput5;
GtkWidget *gradeAndMajorInput5;
GtkWidget *contactInput5;
GtkWidget *introductionInput5;
 // 弹出对话框
void feedbackWindow(GtkWidget *button, gpointer   user_data)
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
		GTK_BUTTONS_OK, _T("提示"), "title");

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
		if (getEventDetailNodeByID(MpartNode->eventList, node->eventInfomation.id) == NULL&&flag){
			gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), "1", _T(node->eventInfomation.name));
			Aflag = 1;
		}
	}

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
				eventDetailNode *eventDB = getEventDetailListHead(MpartNode->eventList);
				for (int i = 0; i < MpartNode->eventList->size; i++){
					eventDB = eventDB->next;
					eventNode *e = getEventNodeByID(eventlist, eventDB->eventDetail.id);
					if (e->eventInfomation.timeNum == eventN->eventInfomation.timeNum){
						F = 0;
					}
				}

				if (F){
					addEventParticipantByID(eventlist, eventN->eventInfomation.id, MpartNode->participantInfomation.id);
					eventDetail eventD = { eventN->eventInfomation.id, "", 0, eventN->eventInfomation.addSize };
					addParticipantEventByID(parlist, MpartNode->participantInfomation.id, eventD);
				}
				else{
					//提示时间冲突
					timeCrash();
				}
			}
		}
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		changeAthlete();
	}

	gtk_widget_destroy(dialog);
}

//从选手信息的修改界面到选手列表界面
void changeAthlete_to_changeInstituteAthlete(GtkWidget *button, gpointer data){

	strcpy_s(MpartNode->participantInfomation.name, __T(gtk_entry_get_text(GTK_ENTRY(nameInput5))));
	strcpy_s(MpartNode->participantInfomation.gradeMajor, __T(gtk_entry_get_text(GTK_ENTRY(gradeAndMajorInput5))));
	strcpy_s(MpartNode->participantInfomation.contact, __T(gtk_entry_get_text(GTK_ENTRY(contactInput5))));
	strcpy_s(MpartNode->participantInfomation.intro, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput5))));

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	changeInstituteAthlete();
}

void changeAthlete_cancel(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	changeInstituteAthlete();
}

void participantDeleteEvent(GtkWidget *button, gpointer data){
	//给个删除提示
	eventNode *deEvent = (eventNode*)data;
	long eventID = deEvent->eventInfomation.id;
	long participantID = MpartNode->participantInfomation.id;
	deleteParticipantEventByID(parlist, participantID, eventID);
	deletEeventParticipantByID(eventlist, eventID, participantID);

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	changeAthlete();
}

void show_deleteAthleteUnitConfirm(GtkWidget *button, gpointer data)
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
		participantDeleteEvent(button, data);
		gtk_widget_destroy(dialog);

	}

}

void addNewEvent(GtkWidget *button, gpointer data){
	//已有项目排除掉
	feedbackWindow(button,data);
}


//选手信息修改界面
void changeAthlete(){

	//定义相关组件

	//定义姓名的label和entry
	GtkWidget *nameLabel;

	//定义年级和专业的label和entry
	GtkWidget *gradeAndMajorLabel;

	//定义联系方式的label和entry
	GtkWidget *contactLabel;

	//定义个人简介的label和entry
	GtkWidget *introductionLabel;

	//所属单位的label和combobox
	GtkWidget *instituteLabel;
	GtkWidget *instituteInput;

	//所参加的项目的lable
	GtkWidget *listLabel;

	//定义滚动窗口
	GtkWidget *listScrolledInput;
	GtkWidget *scrolledWindow;

	//定义加入滚动窗口的grid布局
	GtkWidget *listGrid;

	//定义“新增项目”按钮
	GtkWidget *addNew;

	//定义返回和确定按钮
	GtkWidget *confirm;
	GtkWidget *cancel;


	//得到fixed布局
	fixed = gtk_fixed_new();

	initialWindow(fixed);

	//设置返回按钮，并绑定回调函数
	cancel = gtk_button_new_with_label(_T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 200, 40);
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(changeAthlete_cancel), NULL);

	confirm = gtk_button_new_with_label(_T("确定"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 200, 40);
	g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(changeAthlete_to_changeInstituteAthlete), NULL);


	//设置姓名的label和entry组件
	nameLabel = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);
	nameInput5 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput5), 160, 40);
	gtk_entry_set_text(GTK_ENTRY(nameInput5), _T(MpartNode->participantInfomation.name));

	//设置联系方式的label和entry组件
	contactLabel = gtk_label_new(_T("联系方式"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 100, 40);
	contactInput5 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput5), 160, 40);
	gtk_entry_set_text(GTK_ENTRY(contactInput5), _T(MpartNode->participantInfomation.contact));

	//设置个人简介的label和entry组件
	introductionLabel = gtk_label_new(_T("简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 280, 40);
	introductionInput5 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput5), 280, 140);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput5), GTK_WRAP_CHAR);
	setTextToTextview(GTK_TEXT_VIEW(introductionInput5), MpartNode->participantInfomation.intro);

	//设置年级专业label和entry组件
	gradeAndMajorLabel = gtk_label_new(_T("年级专业"));
	gtk_widget_set_size_request(GTK_WIDGET(gradeAndMajorLabel), 100, 40);
	gradeAndMajorInput5 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(gradeAndMajorInput5), 160, 40);
	gtk_entry_set_text(GTK_ENTRY(gradeAndMajorInput5), _T(MpartNode->participantInfomation.gradeMajor));

	//设置所属单位的label和entry组件
	instituteLabel = gtk_label_new(_T("所属单位"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteLabel), 100, 40);

	unitNode *unit = getUnitNodeByID(unitlist, MpartNode->participantInfomation.unitID);
	instituteInput = gtk_label_new(_T(unit->unitInfomation.unitName));
	gtk_widget_set_size_request(GTK_WIDGET(instituteInput), 160, 40);

	//设置参赛项目的label
	listLabel = gtk_label_new(_T("参加项目"));
	gtk_widget_set_size_request(GTK_WIDGET(listLabel), 200, 40);

	//设置新增项目按钮
	addNew = gtk_button_new_with_label(_T("新增项目"));
	gtk_widget_set_size_request(GTK_WIDGET(listLabel), 80, 40);
	g_signal_connect(G_OBJECT(addNew), "clicked", G_CALLBACK(addNewEvent), NULL);

	//生产scrolled组件
	listScrolledInput = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(listScrolledInput), 280, 140);
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 280, 140);

	//生产grid组件
	listGrid = gtk_grid_new();

	//通过for循环，将组件加入listGrid
	eventDetailNode *baseHead = getEventDetailListHead(MpartNode->eventList);
	for (int i = 0; i < MpartNode->eventList->size; i++){
		baseHead = baseHead->next;
		eventNode *eNode = getEventNodeByID(eventlist, baseHead->eventDetail.id);
		GtkWidget *project = gtk_label_new(_T(eNode->eventInfomation.name));
		gtk_widget_set_size_request(GTK_WIDGET(project), 200, 40);
		gtk_grid_attach(GTK_GRID(listGrid), project, 0, 40 * i, 200, 40);
		GtkWidget *delete_ = gtk_button_new_with_label(_T("删除"));
		gtk_widget_set_size_request(GTK_WIDGET(delete_), 80, 40);
		g_signal_connect(G_OBJECT(delete_), "clicked", G_CALLBACK(show_deleteAthleteUnitConfirm), eNode);
		gtk_grid_attach(GTK_GRID(listGrid), delete_, 200, 40 * i, 80, 40);
	}

	//将listGrid加到scrolled上
	gtk_container_add(GTK_CONTAINER(listScrolledInput), listGrid);

	//将各组件添加到fixed布局
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput5, 220, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 420, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput5, 540, 180);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);

	gtk_fixed_put(GTK_FIXED(fixed), cancel, 500, 520);
	gtk_fixed_put(GTK_FIXED(fixed), confirm, 100, 520);

	gtk_fixed_put(GTK_FIXED(fixed), gradeAndMajorLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), gradeAndMajorInput5, 220, 240);
	gtk_fixed_put(GTK_FIXED(fixed), instituteLabel, 420, 240);
	gtk_fixed_put(GTK_FIXED(fixed), instituteInput, 540, 240);
	gtk_fixed_put(GTK_FIXED(fixed), listLabel, 420, 300);
	gtk_fixed_put(GTK_FIXED(fixed), addNew, 620, 300);
	gtk_fixed_put(GTK_FIXED(fixed), listScrolledInput, 420, 340);

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput5);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}
