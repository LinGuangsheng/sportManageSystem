
#include <gtk/gtk.h>

GtkWidget *nameInput14;
GtkWidget *contactInput14;
GtkWidget *introductionInput14;
GtkWidget *gradeMajorInput14;
GtkWidget *unitInput14;
GtkWidget *genderComboBox;

// ��ť"returnbn"�Ļص�����
void RAcancel(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	registration();
}

void RAconfirm(GtkWidget *widget, gpointer data){
	gchar *test = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(unitInput14));
	gchar *gender = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(genderComboBox));

	if (test == NULL){
		//�Ի�����ʾ����
	}
	else{
		//�ж��Ա�
		unitNode *unit = getUnitNodeByName(unitlist, __T(test));
		accountSet = accountSet + 1;
		Raccount->account.id = accountSet;
		Raccount->account.type = 3;
		Rparticipant = makeParticipantNode({});
		Rparticipant->participantInfomation.id = accountSet;

		Rparticipant->participantInfomation.unitID = unit->unitInfomation.id;

		strcpy_s(Rparticipant->participantInfomation.name, __T(gtk_entry_get_text(GTK_ENTRY(nameInput14))));
		strcpy_s(Rparticipant->participantInfomation.contact, __T(gtk_entry_get_text(GTK_ENTRY(contactInput14))));
		strcpy_s(Rparticipant->participantInfomation.gradeMajor, __T(gtk_entry_get_text(GTK_ENTRY(gradeMajorInput14))));

		strcpy_s(Rparticipant->participantInfomation.intro, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput14))));

		if (strcmp(__T(gender), "��") == 0){
			Rparticipant->participantInfomation.gender = 0;
		}
		else{
			Rparticipant->participantInfomation.gender = 1;
		}

		addAccountNode(accountlist, Raccount);
		addParticipantNode(parlist, Rparticipant);
		addUnitParticipantByID(unitlist, unit->unitInfomation.id, Rparticipant->participantInfomation.id);

		gtk_container_remove(GTK_CONTAINER(window), fixed);
		initLoginWindow();
	}

}

void create_AtR_window(){

	//������ؿؼ�
	GtkWidget *nameLabel;
	GtkWidget *contactLabel;
	GtkWidget *introductionLabel;
	GtkWidget *gradeMajorLabel;
	GtkWidget *unitLabel;
	GtkWidget *done;
	GtkWidget *returnbn;
	GtkWidget *genderLabel;

	//��������fixed���ֺͳ�ʼ��window
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	nameInput14 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput14), 160, 40);

	gradeMajorLabel = gtk_label_new(_T("�꼶רҵ"));
	gtk_widget_set_size_request(GTK_WIDGET(gradeMajorLabel), 100, 40);

	gradeMajorInput14 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(gradeMajorInput14), 160, 40);

	contactLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 100, 40);

	contactInput14 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput14), 160, 40);

	unitLabel = gtk_label_new(_T("������λ"));
	gtk_widget_set_size_request(GTK_WIDGET(unitLabel), 100, 40);

	unitInput14 = gtk_combo_box_text_new();
	gtk_widget_set_size_request(GTK_WIDGET(unitInput14), 160, 40);

	unitNode *unitH = getUnitHead(unitlist);
	for (int i = 0; i < unitlist->size; i++) {
		unitH = unitH->next;
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(unitInput14), _T(unitH->unitInfomation.unitName));
	}
	gtk_combo_box_set_active(GTK_COMBO_BOX(unitInput14), 0);

	genderLabel = gtk_label_new(_T("�Ա�"));
	gtk_widget_set_size_request(GTK_WIDGET(genderLabel), 100, 40);

	genderComboBox = gtk_combo_box_text_new();
	gtk_widget_set_size_request(GTK_WIDGET(genderComboBox), 170, 40);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(genderComboBox), _T("��"));
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(genderComboBox), _T("Ů"));
	gtk_combo_box_set_active(GTK_COMBO_BOX(genderComboBox), 0);

	introductionLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 300, 40);

	introductionInput14 = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput14), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput14), 300, 220);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 180, 40);
	//Ϊ"returnbn"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(RAcancel), NULL);

	done = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(done), _T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(done), 180, 40);
	g_signal_connect(G_OBJECT(done), "clicked", G_CALLBACK(RAconfirm), NULL);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput14, 220, 180);
	gtk_fixed_put(GTK_FIXED(fixed), genderLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), genderComboBox, 220, 240);
	gtk_fixed_put(GTK_FIXED(fixed), gradeMajorLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), gradeMajorInput14, 220, 300);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 360);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput14, 220, 360);
	gtk_fixed_put(GTK_FIXED(fixed), unitLabel, 100, 420);
	gtk_fixed_put(GTK_FIXED(fixed), unitInput14, 220, 420);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 420, 180);
	gtk_fixed_put(GTK_FIXED(fixed), introductionInput14, 420, 240);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), done, 440, 520);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}
