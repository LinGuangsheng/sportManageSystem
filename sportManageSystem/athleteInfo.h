#include<gtk\gtk.h>

GtkWidget *intcInput;
GtkWidget *nPInput;
GtkWidget *grade_majorInput;
GtkWidget *phoneInput;
GtkWidget *unitCombox;
GtkWidget *athleteGenderComboBox;

void athleteInfo_to_itemInfo(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	initItemInfo();
}

void athleteInfo_to_checkSM(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	AcheckWindow();
}

void athletePasswordChange(GtkButton *button, gpointer   user_data)
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
		accountNode *account = getAccountNodeByID(accountlist, par_node->participantInfomation.id);
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

void Ashow_changeFailed()
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
void show_athleteChangeFailed()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("������������Ϣ"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("�޸�ʧ��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

//setData�����Ի����޸ĳɹ�
void setData(GtkWidget *button, gpointer data){
	char *name = __T(gtk_entry_get_text(GTK_ENTRY(nPInput)));
	char *major = __T(gtk_entry_get_text(GTK_ENTRY(grade_majorInput)));
	char *contact = __T(gtk_entry_get_text(GTK_ENTRY(phoneInput)));

	if ((strcmp(name, "") != 0) && ((strcmp(contact, "") != 0)) && ((strcmp(major, "") != 0))){

		strcpy_s(par_node->participantInfomation.gradeMajor, __T(gtk_entry_get_text(GTK_ENTRY(grade_majorInput))));
		strcpy_s(par_node->participantInfomation.name, __T(gtk_entry_get_text(GTK_ENTRY(nPInput))));
		strcpy_s(par_node->participantInfomation.contact, __T(gtk_entry_get_text(GTK_ENTRY(phoneInput))));
		strcpy_s(par_node->participantInfomation.intro, __T(getTextFromTextview(GTK_TEXT_VIEW(intcInput))));

		if (strcmp(__T(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(athleteGenderComboBox))), "��")==0){
			par_node->participantInfomation.gender = 0;
		}
		else{
			par_node->participantInfomation.gender = 1;
		}

		//������
		GtkWidget *dialog;

		dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK, _T("�޸ĳɹ�"), "title");

		gtk_window_set_title(GTK_WINDOW(dialog), _T("�޸ĳɹ�"));

		gtk_dialog_run(GTK_DIALOG(dialog));

		gtk_widget_destroy(dialog);
	}
	else show_athleteChangeFailed();

}


void initAthleteInfoWindow(){
	GtkWidget *nameLabel;
	GtkWidget *genderLabel;
	GtkWidget *grade_majorLabel;
	GtkWidget *phoneLabel;
	GtkWidget *unitLabel;
	GtkWidget *intcLabel;
	GtkWidget *setPasswordButton;
	GtkWidget *setInfoButton;
	GtkWidget *seeSportItemButton;
	GtkWidget *scrolledWindow;
	GtkWidget *checkSM;


	/*����gtk_window_set_icon() ��Ϊ��������ͼ���õģ�����create_pixbuf�������Զ���ģ�Ŀ���Ǵ�һ��ͼƬ�л�ȡ��Ϣ�õ�pixbuf��*/
	gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("logo.png"));

	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 120, 40);

	genderLabel = gtk_label_new(_T("�Ա�"));
	gtk_widget_set_size_request(GTK_WIDGET(genderLabel), 120, 40);

	athleteGenderComboBox = gtk_combo_box_text_new();
	gtk_widget_set_size_request(GTK_WIDGET(athleteGenderComboBox), 255, 40);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(athleteGenderComboBox), _T("��"));
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(athleteGenderComboBox), _T("Ů"));
	if (par_node->participantInfomation.gender == 0){
		gtk_combo_box_set_active(GTK_COMBO_BOX(athleteGenderComboBox), 0);
	}
	else{
		gtk_combo_box_set_active(GTK_COMBO_BOX(athleteGenderComboBox), 1);
	}

	grade_majorLabel = gtk_label_new(_T("�꼶רҵ"));
	gtk_widget_set_size_request(GTK_WIDGET(grade_majorLabel), 120, 40);

	phoneLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(phoneLabel), 120, 40);

	unitLabel = gtk_label_new(_T("������λ"));
	gtk_widget_set_size_request(GTK_WIDGET(unitLabel), 120, 40);

	intcLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(intcLabel), 280, 40);

	intcInput = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(intcInput), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(intcInput), 280, 160);
	setTextToTextview(GTK_TEXT_VIEW(intcInput), par_node->participantInfomation.intro);


	//�½�һ��scrolled���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 380, 100);


	nPInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nPInput), 255, 40);
	gtk_entry_set_text(GTK_ENTRY(nPInput), _T(par_node->participantInfomation.name));

	grade_majorInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(grade_majorInput), 255, 40);
	gtk_entry_set_text(GTK_ENTRY(grade_majorInput), _T(par_node->participantInfomation.gradeMajor));

	phoneInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(phoneInput), 255, 40);
	gtk_entry_set_text(GTK_ENTRY(phoneInput), _T(par_node->participantInfomation.contact));

	unitCombox = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(unitCombox), 255, 40);
	unitNode *unitNode = getUnitNodeByID(unitlist, par_node->participantInfomation.unitID);
	gtk_editable_set_editable(GTK_EDITABLE(unitCombox), FALSE);
	gtk_entry_set_text(GTK_ENTRY(unitCombox), _T(unitNode->unitInfomation.unitName));



	setPasswordButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(setPasswordButton), _T("�޸�����"));
	gtk_widget_set_size_request(GTK_WIDGET(setPasswordButton), 180, 60);
	g_signal_connect(G_OBJECT(setPasswordButton), "clicked", G_CALLBACK(athletePasswordChange), NULL);

	setInfoButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(setInfoButton), _T("�޸ĸ�����Ϣ"));
	gtk_widget_set_size_request(GTK_WIDGET(setInfoButton), 180, 60);
	g_signal_connect(G_OBJECT(setInfoButton), "clicked", G_CALLBACK(setData), NULL);

	seeSportItemButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(seeSportItemButton), _T("�鿴������Ŀ"));
	gtk_widget_set_size_request(GTK_WIDGET(seeSportItemButton), 180, 60);
	g_signal_connect(G_OBJECT(seeSportItemButton), "clicked", G_CALLBACK(athleteInfo_to_itemInfo), NULL);

	checkSM = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(checkSM), _T("�鿴�˶�����Ϣ"));
	gtk_widget_set_size_request(GTK_WIDGET(checkSM), 180, 60);
	g_signal_connect(G_OBJECT(checkSM), "clicked", G_CALLBACK(athleteInfo_to_checkSM), NULL);

	//�õ�fixed���֣����ѿؼ�������ȥ
	fixed = gtk_fixed_new();
	initialWindow(fixed);
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nPInput, 220, 180);

	gtk_fixed_put(GTK_FIXED(fixed), genderLabel, 100, 230);
	gtk_fixed_put(GTK_FIXED(fixed), athleteGenderComboBox, 220, 230);

	gtk_fixed_put(GTK_FIXED(fixed), grade_majorLabel, 100, 280);
	gtk_fixed_put(GTK_FIXED(fixed), grade_majorInput, 220, 280);


	gtk_fixed_put(GTK_FIXED(fixed), phoneLabel, 100, 330);
	gtk_fixed_put(GTK_FIXED(fixed), phoneInput, 220, 330);

	gtk_fixed_put(GTK_FIXED(fixed), unitLabel, 100, 380);
	gtk_fixed_put(GTK_FIXED(fixed), intcLabel, 100, 430);
	gtk_fixed_put(GTK_FIXED(fixed), unitCombox, 220, 380);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 480);


	gtk_fixed_put(GTK_FIXED(fixed), checkSM, 500, 180);
	gtk_fixed_put(GTK_FIXED(fixed), setInfoButton, 500, 260);
	gtk_fixed_put(GTK_FIXED(fixed), setPasswordButton, 500, 340);
	gtk_fixed_put(GTK_FIXED(fixed), seeSportItemButton, 500, 420);

	//��textView��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), intcInput);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//��ʾ
	gtk_widget_show_all(window);
}