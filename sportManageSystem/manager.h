#include <gtk\gtk.h>

// 
GtkWidget *managerNameInput;
GtkWidget *managerContactInput;
GtkWidget *managerIntroductionInput;

void manager_to_eventInfoManage(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	eventInfoManage();
}


void manage_to_instituteManage(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	instituteManage();
}

void manager_to_smInfoManage(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	smInfoManage();
}

void manager_to_create_RIM_window(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_RIM_window();
}
void show_managerChangeFailed()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("������������Ϣ"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("�޸�ʧ��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}


void saveManagerInformation(GtkWidget *button, gpointer data){
	char *name = NULL;
	name = __T(gtk_entry_get_text(GTK_ENTRY(managerNameInput)));
	char *contact = NULL;
	contact = __T(gtk_entry_get_text(GTK_ENTRY(managerContactInput)));
	if ((strcmp(name, "") != 0) && ((strcmp(contact, "") != 0))){
		printf("%s", &name);
		printf("%s", &contact);

		strcpy_s(m.name, __T(gtk_entry_get_text(GTK_ENTRY(managerNameInput))));
		strcpy_s(m.contact, __T(gtk_entry_get_text(GTK_ENTRY(managerContactInput))));
		strcpy_s(m.intro, __T(getTextFromTextview(GTK_TEXT_VIEW(managerIntroductionInput))));

		//����ɹ�������ʾ

		//������
		GtkWidget *dialog;

		dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK, _T("����ɹ�"), "title");

		gtk_window_set_title(GTK_WINDOW(dialog), _T("��ʾ"));

		gtk_dialog_run(GTK_DIALOG(dialog));

		gtk_widget_destroy(dialog);
	}
	else{
		show_managerChangeFailed();
	}
}



void managerPasswordChange(GtkButton *button, gpointer   user_data)
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
	gtk_entry_set_visibility(GTK_ENTRY(local_entry1), FALSE);

	gtk_grid_attach(GTK_GRID(table), local_entry1, 1, 0, 1, 1);
	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_entry1);

	//�ڶ���
	label = gtk_label_new_with_mnemonic(_T("������"));
	gtk_grid_attach(GTK_GRID(table), label, 0, 1, 1, 1);

	local_entry2 = gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(local_entry2), FALSE);
	gtk_entry_set_text(GTK_ENTRY(local_entry2), "");
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
		if (strcmp(managerAccount->account.passwd, gtk_entry_get_text(GTK_ENTRY(local_entry1))) == 0){
			if (strcmp(gtk_entry_get_text(GTK_ENTRY(local_entry2)), gtk_entry_get_text(GTK_ENTRY(local_entry3))) == 0){
				strcpy_s(managerAccount->account.passwd, gtk_entry_get_text(GTK_ENTRY(local_entry2)));
			}
			else{
				Mshow_changeFailed();
			}
		}
		else{
			Mshow_changeFailed();
		}
		//������
	}

	gtk_widget_destroy(dialog);
}

void Mshow_changeFailed()
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
void manager(){

	//������ؿؼ�������:window������ͼ:bgImage,Logo:logo,fixed����:fixed�������ľ���Щ��
	GtkWidget *nameLabel;
	GtkWidget *contactLabel;
	GtkWidget *introductionLabel;
	GtkWidget *exitButton;
	GtkWidget *checkInformation;
	GtkWidget *sportsMeetingInfoManageButton;
	GtkWidget *eventInfoManageButton;
	GtkWidget *unitInfoManageButton;
	GtkWidget *judgeInfoManageButton;
	GtkWidget *managerChangePasswordButton;
	GtkWidget *scrolledWindow;


	fixed = gtk_fixed_new();
	initialWindow(fixed);


	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);


	managerNameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(managerNameInput), 255, 40);
	gtk_entry_set_text(GTK_ENTRY(managerNameInput), _T(m.name));

	contactLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 100, 40);

	managerContactInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(managerContactInput), 255, 40);
	gtk_entry_set_text(GTK_ENTRY(managerContactInput), _T(m.contact));

	introductionLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 375, 40);

	managerIntroductionInput = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(managerIntroductionInput), GTK_WRAP_CHAR);

	gtk_widget_set_size_request(GTK_WIDGET(managerIntroductionInput), 375, 120);


	setTextToTextview(GTK_TEXT_VIEW(managerIntroductionInput), (m.intro));

	exitButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(exitButton), _T("������Ϣ"));
	gtk_widget_set_size_request(GTK_WIDGET(exitButton), 180, 60);
	g_signal_connect(G_OBJECT(exitButton), "clicked", G_CALLBACK(saveManagerInformation), NULL);


	managerChangePasswordButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(managerChangePasswordButton), _T("�޸�����"));
	gtk_widget_set_size_request(GTK_WIDGET(managerChangePasswordButton), 180, 60);
	g_signal_connect(G_OBJECT(managerChangePasswordButton), "clicked", G_CALLBACK(managerPasswordChange), NULL);


	sportsMeetingInfoManageButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(sportsMeetingInfoManageButton), _T("�˶�����Ϣ����"));
	gtk_widget_set_size_request(GTK_WIDGET(sportsMeetingInfoManageButton), 180, 60);
	g_signal_connect(G_OBJECT(sportsMeetingInfoManageButton), "clicked", G_CALLBACK(manager_to_smInfoManage), NULL);


	eventInfoManageButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(eventInfoManageButton), _T("�˶�����Ŀ��Ϣ����"));
	gtk_widget_set_size_request(GTK_WIDGET(eventInfoManageButton), 180, 60);
	g_signal_connect(G_OBJECT(eventInfoManageButton), "clicked", G_CALLBACK(manager_to_eventInfoManage), NULL);


	unitInfoManageButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(unitInfoManageButton), _T("������λ��Ϣ����"));
	gtk_widget_set_size_request(GTK_WIDGET(unitInfoManageButton), 180, 60);
	g_signal_connect(G_OBJECT(unitInfoManageButton), "clicked", G_CALLBACK(manage_to_instituteManage), NULL);


	judgeInfoManageButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(judgeInfoManageButton), _T("����Ա��Ϣ����"));
	gtk_widget_set_size_request(GTK_WIDGET(judgeInfoManageButton), 180, 60);
	g_signal_connect(G_OBJECT(judgeInfoManageButton), "clicked", G_CALLBACK(manager_to_create_RIM_window), NULL);


	//�½�һ��scrolled���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 375, 120);
	gtk_container_add(GTK_CONTAINER(scrolledWindow), managerIntroductionInput);
	//�õ�fixed���֣����ѿؼ�������ȥ



	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), managerNameInput, 220, 180);

	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), managerContactInput, 220, 240);

	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);

	gtk_fixed_put(GTK_FIXED(fixed), exitButton, 100, 500);
	gtk_fixed_put(GTK_FIXED(fixed), managerChangePasswordButton, 301, 500);
	gtk_fixed_put(GTK_FIXED(fixed), sportsMeetingInfoManageButton, 500, 180);
	gtk_fixed_put(GTK_FIXED(fixed), eventInfoManageButton, 500, 260);
	gtk_fixed_put(GTK_FIXED(fixed), unitInfoManageButton, 500, 340);
	gtk_fixed_put(GTK_FIXED(fixed), judgeInfoManageButton, 500, 420);


	//��textView��ӵ�scrolled������


	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//��ʾ
	gtk_widget_show_all(window);
}