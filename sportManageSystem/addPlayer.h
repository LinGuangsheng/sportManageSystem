#include <gtk\gtk.h>

GtkWidget *naInput;
GtkWidget *maInput;
GtkWidget *coInput;
GtkWidget *inInput;
GtkWidget *addPlayerGenderComboBox;

void Ushow_inputEventInfo()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("��������������"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

void addPlayer_to_playerManage(GtkWidget *button, gpointer data){
	gchar *gender = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(addPlayerGenderComboBox));

	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(naInput))), "") == 0)	{
		//�Ի�����ʾ��ȫ��Ϣ������Ҫ�����ơ�ʱ��͵ص�
		Ushow_inputEventInfo();
	}
	else{

		//�ж��Ա�

		strcpy_s(participantRegister->participantInfomation.contact, __T(gtk_entry_get_text(GTK_ENTRY(coInput))));
		strcpy_s(participantRegister->participantInfomation.name, __T(gtk_entry_get_text(GTK_ENTRY(naInput))));
		strcpy_s(participantRegister->participantInfomation.gradeMajor, __T(gtk_entry_get_text(GTK_ENTRY(maInput))));
		strcpy_s(participantRegister->participantInfomation.intro, __T(getTextFromTextview(GTK_TEXT_VIEW(inInput))));

		participantRegister->participantInfomation.eventSize = 0;
		participantRegister->participantInfomation.unitID = unit_node->unitInfomation.id;

		if (strcmp(__T(gender), "��") == 0){
			participantRegister->participantInfomation.gender = 0;
		}
		else{
			participantRegister->participantInfomation.gender = 1;
		}

		addAccountNode(accountlist, accountR);
		addParticipantNode(parlist, participantRegister);
		addUnitParticipantByID(unitlist, unit_node->unitInfomation.id, participantRegister->participantInfomation.id);


		gtk_container_remove(GTK_CONTAINER(window), fixed);
		playerManage();
	}
}


void addPlayer_cancel_playManager(GtkWidget *button, gpointer data){

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	playerManage();
}

void testZZ(GtkWidget *button, gpointer data){
	eventNode *head = (eventNode*)data;
	//head = head->next;
	printf("%p\n", head);
	printf("%s\n", head->eventInfomation.name);
}

void addPlayer(){
	GtkWidget *nameLabel;
	GtkWidget *majorLabel;
	GtkWidget *contactLabel;
	GtkWidget *introLabel;
	GtkWidget *backButton;
	GtkWidget *genderLabel;
	GtkWidget *finish;
	GtkWidget *cancel;

	//���ô��ڣ�����ʹ�С
	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С


	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 80, 40);

	naInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(naInput), 200, 40);

	majorLabel = gtk_label_new(_T("�꼶רҵ"));
	gtk_widget_set_size_request(GTK_WIDGET(majorLabel), 80, 40);

	maInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(maInput), 200, 40);

	contactLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 80, 40);

	coInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(coInput), 200, 40);


	introLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(introLabel), 280, 40);

	inInput = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(inInput), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(inInput), 280, 252);

	genderLabel = gtk_label_new(_T("�Ա�"));
	gtk_widget_set_size_request(GTK_WIDGET(genderLabel), 80, 40);

	addPlayerGenderComboBox = gtk_combo_box_text_new();
	gtk_widget_set_size_request(GTK_WIDGET(addPlayerGenderComboBox), 200, 40);
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(addPlayerGenderComboBox), _T("��"));
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(addPlayerGenderComboBox), _T("Ů"));
	gtk_combo_box_set_active(GTK_COMBO_BOX(addPlayerGenderComboBox), 0);



	eventNode *head = getEventHead(eventlist);
	head = head->next;
	printf("%p\n", head);
	printf("%s\n", head->eventInfomation.name);

	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("ȡ��"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(addPlayer_cancel_playManager), NULL);

	finish = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(finish), _T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(finish), 220, 40);
	g_signal_connect(G_OBJECT(finish), "clicked", G_CALLBACK(addPlayer_to_playerManage), NULL);

	//�õ�fixed���֣����ѿؼ�������ȥ
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	gtk_fixed_put(GTK_FIXED(fixed), bgImage, 0, 0);

	gtk_fixed_put(GTK_FIXED(fixed), logo, 320, 30);


	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), naInput, 180, 180);

	gtk_fixed_put(GTK_FIXED(fixed), genderLabel, 100, 250);
	gtk_fixed_put(GTK_FIXED(fixed), addPlayerGenderComboBox, 180, 250);

	gtk_fixed_put(GTK_FIXED(fixed), majorLabel, 100, 320);
	gtk_fixed_put(GTK_FIXED(fixed), maInput, 180, 320);

	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 390);
	gtk_fixed_put(GTK_FIXED(fixed), coInput, 180, 390);

	gtk_fixed_put(GTK_FIXED(fixed), introLabel, 400, 140);
	gtk_fixed_put(GTK_FIXED(fixed), inInput, 400, 180);


	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), finish, 440, 520);


	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//��ʾ
	gtk_widget_show_all(window);
}
