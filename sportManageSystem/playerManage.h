#include <gtk\gtk.h>

GtkWidget *playerSelect;

void playerManage_to_addPlayer(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	Ucreate_registration_window();
}

void show_chooseAthlete()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("��ѡ��ѡ��"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}


void playerManage_to_playerInfoChange(GtkWidget *button, gpointer data){
	gchar *test = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(playerSelect));
	if (test == NULL){
		show_chooseAthlete();
	}
	else{
		participant = getParticipantNodeByName(parlist, __T(test));
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		playerInfoChange();
	}
}
void playerManage_to_leader(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	leader();
}

void deleteParticipant(GtkWidget *button, gpointer data){
	gchar *test = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(playerSelect));
	if (test == NULL){
		printf("HERE");
		show_chooseAthlete();
		{
			//������
			GtkWidget *dialog;

			dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
				GTK_BUTTONS_OK, _T("��ѡ��ѡ��"), "title");

			gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));

			gtk_dialog_run(GTK_DIALOG(dialog));

			gtk_widget_destroy(dialog);
		}
	}
	else{
		participant = getParticipantNodeByName(parlist, __T(test));

		eventDetailNode *event = getEventDetailListHead(participant->eventList);
		for (int i = 0; i < participant->eventList->size; i++){
			event = event->next;
			deletEeventParticipantByID(eventlist, event->eventDetail.id, participant->participantInfomation.id);
		}
		deleteAccountNodeByID(accountlist, participant->participantInfomation.id);
		deleteUnitParticipantByID(unitlist, unit_node->unitInfomation.id, participant->participantInfomation.id);
		deleteParticipantNodeByID(parlist, participant->participantInfomation.id);

		gtk_container_remove(GTK_CONTAINER(window), fixed);
		playerManage();
	}
}

void show_leaderDeletePlayerConfirm(GtkWidget *button, gpointer data)
{
	//������
	GtkWidget *dialog;
	gchar *test = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(playerSelect));
	if (test == NULL){
		printf("HERE");
		show_chooseAthlete();
	}
	else{
		dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK, _T("ȷ��ɾ����ѡ�֣�"), "title");

		gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));


		gint response = gtk_dialog_run(GTK_DIALOG(dialog));
		if (response == GTK_RESPONSE_OK)
		{
			printf("clicked");
			//����дgettext����
			deleteParticipant(button, data);
			gtk_widget_destroy(dialog);

		}
	}

}
void playerManage(){


	//������ؿؼ�������:window������ͼ:bgImage,Logo:logo,fixed����:fixed�������ľ���Щ��
	GtkWidget *playerLabel;
	GtkWidget *playerListLabel;
	GtkWidget *playerDelete;
	GtkWidget *playerInfoChange;
	GtkWidget *addPlayer;

	GtkWidget *retur;






	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С



	playerLabel = gtk_label_new(_T("ѡ�֣�"));
	gtk_widget_set_size_request(GTK_WIDGET(playerLabel), 60, 40);



	//ComboBox�ؼ�
	playerSelect = gtk_combo_box_text_new();
	gtk_widget_set_size_request(GTK_WIDGET(playerSelect), 330, 40);

	baseNode *headNode = getBaseListHead(unit_node->participantList);
	printf("%d\n", unit_node->unitInfomation.participantSize);
	for (int i = 0; i < unit_node->participantList->size; i++){
		headNode = headNode->next;
		participantNode *tem = getParticipantNodeByID(parlist, headNode->id);
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(playerSelect), _T(tem->participantInfomation.name));
	}



	playerInfoChange = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(playerInfoChange), _T("������Ϣ"));
	gtk_widget_set_size_request(GTK_WIDGET(playerInfoChange), 200, 60);
	g_signal_connect(G_OBJECT(playerInfoChange), "clicked", G_CALLBACK(playerManage_to_playerInfoChange), NULL);


	playerDelete = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(playerDelete), _T("ɾ��ѡ��"));
	gtk_widget_set_size_request(GTK_WIDGET(playerDelete), 200, 60);
	g_signal_connect(G_OBJECT(playerDelete), "clicked", G_CALLBACK(show_leaderDeletePlayerConfirm), NULL);

	addPlayer = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(addPlayer), _T("����ѡ��"));
	gtk_widget_set_size_request(GTK_WIDGET(addPlayer), 440, 60);
	g_signal_connect(G_OBJECT(addPlayer), "clicked", G_CALLBACK(playerManage_to_addPlayer), NULL);

	retur = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(retur), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(retur), 220, 40);
	g_signal_connect(G_OBJECT(retur), "clicked", G_CALLBACK(playerManage_to_leader), NULL);






	//�½�һ��scrolled���
	//�õ�fixed���֣����ѿؼ�������ȥ
	fixed = gtk_fixed_new();
	initialWindow(fixed);


	gtk_fixed_put(GTK_FIXED(fixed), playerLabel, 170, 200);
	gtk_fixed_put(GTK_FIXED(fixed), playerSelect, 250, 200);


	gtk_fixed_put(GTK_FIXED(fixed), playerInfoChange, 170, 290);
	gtk_fixed_put(GTK_FIXED(fixed), playerDelete, 410, 290);
	gtk_fixed_put(GTK_FIXED(fixed), addPlayer, 170, 380);
	gtk_fixed_put(GTK_FIXED(fixed), retur, 300, 520);



	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//��ʾ
	gtk_widget_show_all(window);
}
