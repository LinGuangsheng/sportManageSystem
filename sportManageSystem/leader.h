#include <gtk\gtk.h>

GtkWidget *nameInput22;
GtkWidget *contactInput22;
GtkWidget *introductionInput22;


void leader_to_playerManage(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	playerManage();
}
void leader_to_teamInfoChange(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	teamInfoChange();
}
void leader_to_teamPerformanceCheck(GtkWidget *button, gpointer data){
	printf("hereeeee");
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	teamPerformanceCheck();
}

void leader_to_checkSM(GtkWidget *button, gpointer data){
	printf("hereeeee");
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	UcheckWindow();
}

void show_leaderChangeFailed()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("������������Ϣ"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("�޸�ʧ��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

//дһ���ص������������Ի����޸ĳɹ�
void callBack_(GtkWidget *button, gpointer data){
	char *name = __T(gtk_entry_get_text(GTK_ENTRY(nameInput22)));
	char *contact = __T(gtk_entry_get_text(GTK_ENTRY(contactInput22)));
	if ((strcmp(name, "") != 0) && ((strcmp(contact, "") != 0))){
		strcpy_s(unit_node->unitInfomation.leaderName, __T(gtk_entry_get_text(GTK_ENTRY(nameInput22))));
		strcpy_s(unit_node->unitInfomation.leaderContact, __T(gtk_entry_get_text(GTK_ENTRY(contactInput22))));
		strcpy_s(unit_node->unitInfomation.leaderIntro, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput22))));

		//������
		GtkWidget *dialog;

		dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK, _T("�޸ĳɹ�"), "title");

		gtk_window_set_title(GTK_WINDOW(dialog), _T("��ʾ"));

		gtk_dialog_run(GTK_DIALOG(dialog));

		gtk_widget_destroy(dialog);
	}
	else show_leaderChangeFailed();
}


void leaderPasswordChange(GtkButton *button, gpointer   user_data)
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
	gtk_entry_set_visibility(GTK_ENTRY(local_entry1), FALSE);

	//gtk_entry_set_text(GTK_ENTRY(local_entry1), gtk_entry_get_text(GTK_ENTRY(entry1)));
	gtk_entry_set_text(GTK_ENTRY(local_entry1), "");

	gtk_grid_attach(GTK_GRID(table), local_entry1, 1, 0, 1, 1);
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
		accountNode *account = getAccountNodeByID(accountlist, unit_node->unitInfomation.id);
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

void show_changeFailed()
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
void leader(){
	GtkWidget *nameLabel;
	GtkWidget *contactLabel;
	GtkWidget *introductionLabel;
	GtkWidget *changeButton;
	GtkWidget *pwChange;
	GtkWidget *playerManage;
	GtkWidget *teamPerformanceCheck;
	GtkWidget *teamInfoChange;
	GtkWidget *smInfoCheck;
	GtkWidget *scrolledWindow;

	//���ô��ڣ�����ʹ�С

	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);


	nameInput22 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput22), 255, 40);
	gtk_entry_set_text(GTK_ENTRY(nameInput22), _T(unit_node->unitInfomation.leaderName));

	contactLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 100, 40);

	contactInput22 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput22), 255, 40);
	gtk_entry_set_text(GTK_ENTRY(contactInput22), _T(unit_node->unitInfomation.leaderContact));


	introductionLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 375, 40);

	introductionInput22 = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput22), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput22), 375, 120);
	setTextToTextview(GTK_TEXT_VIEW(introductionInput22), unit_node->unitInfomation.leaderIntro);

	//�½�һ��scrolled���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 375, 120);


	changeButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(changeButton), _T("�޸ĸ�����Ϣ"));
	gtk_widget_set_size_request(GTK_WIDGET(changeButton), 180, 60);
	//�����޸ĳɹ��Ի���ĺ���
	g_signal_connect(G_OBJECT(changeButton), "clicked", G_CALLBACK(callBack_), NULL);

	pwChange = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(pwChange), _T("�޸�����"));
	gtk_widget_set_size_request(GTK_WIDGET(pwChange), 180, 60);
	g_signal_connect(G_OBJECT(pwChange), "clicked", G_CALLBACK(leaderPasswordChange), NULL);


	playerManage = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(playerManage), _T("ѡ�ֹ���"));
	gtk_widget_set_size_request(GTK_WIDGET(playerManage), 180, 60);
	g_signal_connect(G_OBJECT(playerManage), "clicked", G_CALLBACK(leader_to_playerManage), NULL);


	teamPerformanceCheck = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(teamPerformanceCheck), _T("�鿴����ɼ�"));
	gtk_widget_set_size_request(GTK_WIDGET(teamPerformanceCheck), 180, 60);
	g_signal_connect(G_OBJECT(teamPerformanceCheck), "clicked", G_CALLBACK(leader_to_teamPerformanceCheck), NULL);

	teamInfoChange = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(teamInfoChange), _T("�޸Ķ�����Ϣ"));
	gtk_widget_set_size_request(GTK_WIDGET(teamInfoChange), 180, 60);
	g_signal_connect(G_OBJECT(teamInfoChange), "clicked", G_CALLBACK(leader_to_teamInfoChange), NULL);


	smInfoCheck = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(smInfoCheck), _T("�鿴�˶�����Ϣ"));
	gtk_widget_set_size_request(GTK_WIDGET(smInfoCheck), 180, 60);
	g_signal_connect(G_OBJECT(smInfoCheck), "clicked", G_CALLBACK(leader_to_checkSM), NULL);

	//�õ�fixed���֣����ѿؼ�������ȥ
	fixed = gtk_fixed_new();
	initialWindow(fixed);


	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput22, 220, 180);

	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput22, 220, 240);

	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);


	gtk_fixed_put(GTK_FIXED(fixed), changeButton, 200, 500);
	gtk_fixed_put(GTK_FIXED(fixed), pwChange, 500, 500);
	gtk_fixed_put(GTK_FIXED(fixed), playerManage, 500, 180);
	gtk_fixed_put(GTK_FIXED(fixed), teamPerformanceCheck, 500, 260);
	gtk_fixed_put(GTK_FIXED(fixed), teamInfoChange, 500, 340);
	gtk_fixed_put(GTK_FIXED(fixed), smInfoCheck, 500, 420);


	//��textView��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput22);


	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//��ʾ
	gtk_widget_show_all(window);
}
