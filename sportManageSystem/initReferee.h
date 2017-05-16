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
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("������������Ϣ"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("�޸�ʧ��"));

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
			GTK_BUTTONS_OK, _T("�޸ĳɹ�"), "title");

		gtk_window_set_title(GTK_WINDOW(dialog), _T("��ʾ"));

		gtk_dialog_run(GTK_DIALOG(dialog));

		gtk_widget_destroy(dialog);
	}
}

void show_completeInfo(){
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("��������������Ϣ"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));

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
		GTK_BUTTONS_OK, _T("�޸�����"), "title");

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
	label = gtk_label_new_with_mnemonic(_T("ԭ����"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 0, 1, 1);
	local_entry1 = gtk_entry_new();
	//gtk_entry_set_text(GTK_ENTRY(local_entry1), gtk_entry_get_text(GTK_ENTRY(entry1)));
	gtk_entry_set_text(GTK_ENTRY(local_entry1), "");

	gtk_grid_attach(GTK_GRID(table), local_entry1, 1, 0, 1, 1);
	gtk_entry_set_visibility(GTK_ENTRY(local_entry1), FALSE);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_entry1);

	//�ڶ���
	label = gtk_label_new_with_mnemonic(_T("������"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 1, 1, 1);

	local_entry2 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(local_entry2), "");
	gtk_entry_set_visibility(GTK_ENTRY(local_entry2), FALSE);
	gtk_grid_attach(GTK_GRID(table), local_entry2, 1, 1, 1, 1);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_entry2);

	//������
	label = gtk_label_new_with_mnemonic(_T("ȷ��"));
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
				//��ʾǰ�����벻һ��
				show_changeFailed();

				//gtk_widget_destroy(dialog);
			}
		}
		else{
			//��ʾԭ�������
			show_changeFailed();

			//gtk_widget_destroy(dialog);
		}

		//����дgettext����
	}

	gtk_widget_destroy(dialog);
}

void Rshow_changeFailed()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("������������������"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("�޸�ʧ��"));


	gint response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//����дgettext����

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
		GTK_BUTTONS_OK, _T("�Ǽǳɼ�"), "title");

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

	label = gtk_label_new_with_mnemonic(_T("����ѡ��"));
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

	//�ڶ���
	label = gtk_label_new_with_mnemonic(_T("�ɼ�"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 1, 1, 1);

	local_score_entry2 = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(local_score_entry2), "");
	gtk_grid_attach(GTK_GRID(table), local_score_entry2, 1, 1, 1, 1);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_score_entry2);

	//������
	label = gtk_label_new_with_mnemonic(_T("����"));
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
			// ��ʾ��������
			show_completeInfo();
		}
	}

	gtk_widget_destroy(dialog);
}
void initList(GtkWidget *fixed1){

	//������ؿؼ�������:window������ͼ:bgImage,Logo:logo,fixed����:fixed�������ľ���Щ��


	GtkWidget *facultyList;

	GtkWidget *facultyListTitle;
	GtkWidget *facultyListEventName;
	GtkWidget *facultyListItemNum;
	GtkWidget *facultyListTime;
	GtkWidget *facultyListOperator;

	GtkWidget *addNew;
	GtkWidget *cancel;

	GtkWidget *scrolledWindow;


	//�½�һ��gred���֣����ڴ���������
	facultyList = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(facultyList), 200, 300);

	facultyListEventName = gtk_label_new(_T("��Ŀ"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListEventName), 50, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListEventName, 400, 40, 50, 40);


	facultyListOperator = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListOperator), 120, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListOperator, 450, 40, 120, 40);


	//�½�һ��scrolled���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 200, 170);
	//�½�һ��gred���֣����ڴ���б���
	GtkWidget *itemGrid = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(itemGrid), 200, 40);
	//ͨ��ѭ�������б�����ӽ�itemGrid
	baseNode *head = getBaseListHead(referee_node->eventList);
	for (int i = 0; i < referee_node->eventList->size; i++){
		head = head->next;
		eventNode *referee_event = getEventNodeByID(eventlist, head->id);
		GtkWidget *facultyListEventName_i = gtk_label_new(_T(referee_event->eventInfomation.name));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListEventName_i), 50, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListEventName_i, 0, i * 40, 130, 40);


		GtkWidget *changeScore = gtk_button_new_with_label(_T("�Ǽ�"));
		gtk_widget_set_size_request(GTK_WIDGET(changeScore), 50, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), changeScore, 150, i * 40, 50, 40);
		g_signal_connect(G_OBJECT(changeScore), "clicked", G_CALLBACK(setEventScore), referee_event);

		GtkWidget *setScore = gtk_button_new_with_label(_T("�鿴"));
		gtk_widget_set_size_request(GTK_WIDGET(setScore), 50, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), setScore, 500, i * 40, 50, 40);
		g_signal_connect(G_OBJECT(setScore), "clicked", G_CALLBACK(checkRScore), referee_event);
		//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolledWindow), itemGrid);
		//gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);
	}

	//��itemGrid��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);

	gtk_grid_attach(GTK_GRID(facultyList), scrolledWindow, 0, 80, 600, 220);

	//�õ�fixed���֣����ѿؼ�������ȥ


	gtk_fixed_put(GTK_FIXED(fixed1), facultyList, 560, 240);

}

void initReferee(){
	//������ؿؼ�������:window������ͼ:bgImage,Logo:logo,fixed����:fixed�������ľ���Щ��
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
	//���ô��ڣ�����ʹ�С
	font = pango_font_description_from_string("Sans");
	pango_font_description_set_size(font, 20);
	/*����gtk_window_set_icon() ��Ϊ��������ͼ���õģ�����create_pixbuf�������Զ���ģ�Ŀ���Ǵ�һ��ͼƬ�л�ȡ��Ϣ�õ�pixbuf��*/
	gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("logo.png"));
	fixed = gtk_fixed_new();
	initialWindow(fixed);
	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	referee_nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(referee_nameInput), 340, 30);
	gtk_entry_set_text(GTK_ENTRY(referee_nameInput), _T(referee_node->refereeInfomation.refereeName));

	phoneNumLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(phoneNumLabel), 200, 40);

	referee_phoneNumInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(referee_phoneNumInput), 340, 30);
	gtk_entry_set_text(GTK_ENTRY(referee_phoneNumInput), _T(referee_node->refereeInfomation.refereeContact));

	refereeLabel = gtk_label_new(_T("����Ա"));
	gtk_widget_set_size_request(GTK_WIDGET(refereeLabel), 160, 40);


	//
	checkSmInfo36 = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(checkSmInfo36), _T("�鿴�˶�����Ϣ"));
	gtk_widget_set_size_request(GTK_WIDGET(checkSmInfo36), 120, 40);
	g_signal_connect(G_OBJECT(checkSmInfo36), "clicked", G_CALLBACK(gotoCheckSM), NULL);



	personalIntrLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(personalIntrLabel), 200, 40);

	referee_personalIntrInput = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(referee_personalIntrInput), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(referee_personalIntrInput), 400, 140);
	setTextToTextview(GTK_TEXT_VIEW(referee_personalIntrInput), referee_node->refereeInfomation.refereeIntro);

	watchGameLabel = gtk_label_new(_T("������Ŀ"));
	gtk_widget_set_size_request(GTK_WIDGET(watchGameLabel), 100, 40);

	setInfo = gtk_button_new();
	//	gtk_button_set_relief(GTK_BUTTON(setInfo), GTK_RELIEF_NONE);//͸������
	gtk_button_set_label(GTK_BUTTON(setInfo), _T("�޸ĸ�����Ϣ"));
	gtk_widget_set_size_request(GTK_WIDGET(setInfo), 180, 40);
	g_signal_connect(G_OBJECT(setInfo), "clicked", G_CALLBACK(setInfoAction), NULL);

	setPassword = gtk_button_new();
	//	gtk_button_set_relief(GTK_BUTTON(setPassword), GTK_RELIEF_NONE);//͸������
	gtk_button_set_label(GTK_BUTTON(setPassword), _T("�޸�����"));
	gtk_widget_set_size_request(GTK_WIDGET(setPassword), 180, 40);
	g_signal_connect(G_OBJECT(setPassword), "clicked", G_CALLBACK(refereePasswordChange), NULL);

	//�õ�fixed���֣����ѿؼ�������ȥ
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
	//�����ּ��ص�������

	gtk_container_add(GTK_CONTAINER(window), fixed);
	//��ʾ
	gtk_widget_show_all(window);
}
