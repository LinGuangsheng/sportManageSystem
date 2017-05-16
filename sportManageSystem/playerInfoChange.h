#include <gtk\gtk.h>

GtkWidget *nInput;
GtkWidget *majorInput;
GtkWidget *contactInput;
GtkWidget *introductionInput;
GtkWidget *playerInfoChangeGenderComboBox;
void playerInfoChange_to_playerManage(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	playerManage();
}

void playerInfoChangeCommit(GtkWidget *button, gpointer data){
	strcpy_s(participant->participantInfomation.name, __T(gtk_entry_get_text(GTK_ENTRY(nInput))));
	strcpy_s(participant->participantInfomation.gradeMajor, __T(gtk_entry_get_text(GTK_ENTRY(majorInput))));
	strcpy_s(participant->participantInfomation.contact, __T(gtk_entry_get_text(GTK_ENTRY(contactInput))));
	strcpy_s(participant->participantInfomation.intro, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput))));
	if (strcmp(__T(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(playerInfoChangeGenderComboBox))), "��")){
		participant->participantInfomation.gender = 0;
	}
	else{
		participant->participantInfomation.gender = 1;
	}
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	playerManage();
}



void playerInfoChange(){
	GtkWidget *nameLabel;
	GtkWidget *majorLabel;
	GtkWidget *contactLabel;
	GtkWidget *introLabel;
	GtkWidget *finish;
	GtkWidget *cancel;
	GtkWidget *scrolledWindow;
	GtkWidget *genderLabel;

	//���ô��ڣ�����ʹ�С
	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С

	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 80, 40);

	nInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nInput), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(nInput), _T(participant->participantInfomation.name));

	genderLabel = gtk_label_new(_T("�Ա�"));
	gtk_widget_set_size_request(GTK_WIDGET(genderLabel), 80, 40);

	playerInfoChangeGenderComboBox = gtk_combo_box_text_new();
	gtk_widget_set_size_request(GTK_WIDGET(playerInfoChangeGenderComboBox), 200, 40);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(playerInfoChangeGenderComboBox), _T("��"));
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(playerInfoChangeGenderComboBox), _T("Ů"));
	if (participant->participantInfomation.gender == 0){
		gtk_combo_box_set_active(GTK_COMBO_BOX(playerInfoChangeGenderComboBox), 0);
	}
	else{
		gtk_combo_box_set_active(GTK_COMBO_BOX(playerInfoChangeGenderComboBox), 1);
	}

	majorLabel = gtk_label_new(_T("�꼶רҵ"));
	gtk_widget_set_size_request(GTK_WIDGET(majorLabel), 80, 40);

	majorInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(majorInput), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(majorInput), _T(participant->participantInfomation.gradeMajor));

	contactLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 80, 40);

	contactInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput), 200, 40);
	gtk_entry_set_text(GTK_ENTRY(contactInput), _T(participant->participantInfomation.contact));


	introLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(introLabel), 280, 40);

	introductionInput = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput), 280, 252);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput), GTK_WRAP_CHAR);

	setTextToTextview(GTK_TEXT_VIEW(introductionInput), participant->participantInfomation.intro);

	//�½�һ��scrolled���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 280, 252);





	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("ȡ��"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(playerInfoChange_to_playerManage), NULL);

	finish = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(finish), _T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(finish), 220, 40);
	g_signal_connect(G_OBJECT(finish), "clicked", G_CALLBACK(playerInfoChangeCommit), NULL);

	//�õ�fixed���֣����ѿؼ�������ȥ
	fixed = gtk_fixed_new();
	initialWindow(fixed);



	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 230);
	gtk_fixed_put(GTK_FIXED(fixed), nInput, 180, 230);

	gtk_fixed_put(GTK_FIXED(fixed), genderLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), playerInfoChangeGenderComboBox, 180, 300);

	gtk_fixed_put(GTK_FIXED(fixed), majorLabel, 100, 370);
	gtk_fixed_put(GTK_FIXED(fixed), majorInput, 180, 370);

	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 440);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput, 180, 440);

	gtk_fixed_put(GTK_FIXED(fixed), introLabel, 400, 190);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 400, 230);


	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), finish, 440, 520);

	//��textView��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput);


	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//��ʾ
	gtk_widget_show_all(window);
}
