#include <gtk\gtk.h>

GtkWidget *playerSelect;

void playerManage_to_addPlayer(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	Ucreate_registration_window();
}

void show_chooseAthlete()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("请选择选手"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));

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
			//弹出框
			GtkWidget *dialog;

			dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
				GTK_BUTTONS_OK, _T("请选择选手"), "title");

			gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));

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
	//弹出框
	GtkWidget *dialog;
	gchar *test = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(playerSelect));
	if (test == NULL){
		printf("HERE");
		show_chooseAthlete();
	}
	else{
		dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK, _T("确认删除该选手？"), "title");

		gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));


		gint response = gtk_dialog_run(GTK_DIALOG(dialog));
		if (response == GTK_RESPONSE_OK)
		{
			printf("clicked");
			//这里写gettext代码
			deleteParticipant(button, data);
			gtk_widget_destroy(dialog);

		}
	}

}
void playerManage(){


	//定义相关控件，窗口:window，背景图:bgImage,Logo:logo,fixed布局:fixed，其他的就那些了
	GtkWidget *playerLabel;
	GtkWidget *playerListLabel;
	GtkWidget *playerDelete;
	GtkWidget *playerInfoChange;
	GtkWidget *addPlayer;

	GtkWidget *retur;






	//以下控件的设置方法相同，先得到控件，然后设置大小



	playerLabel = gtk_label_new(_T("选手："));
	gtk_widget_set_size_request(GTK_WIDGET(playerLabel), 60, 40);



	//ComboBox控件
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
	gtk_button_set_label(GTK_BUTTON(playerInfoChange), _T("更改信息"));
	gtk_widget_set_size_request(GTK_WIDGET(playerInfoChange), 200, 60);
	g_signal_connect(G_OBJECT(playerInfoChange), "clicked", G_CALLBACK(playerManage_to_playerInfoChange), NULL);


	playerDelete = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(playerDelete), _T("删除选手"));
	gtk_widget_set_size_request(GTK_WIDGET(playerDelete), 200, 60);
	g_signal_connect(G_OBJECT(playerDelete), "clicked", G_CALLBACK(show_leaderDeletePlayerConfirm), NULL);

	addPlayer = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(addPlayer), _T("新增选手"));
	gtk_widget_set_size_request(GTK_WIDGET(addPlayer), 440, 60);
	g_signal_connect(G_OBJECT(addPlayer), "clicked", G_CALLBACK(playerManage_to_addPlayer), NULL);

	retur = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(retur), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(retur), 220, 40);
	g_signal_connect(G_OBJECT(retur), "clicked", G_CALLBACK(playerManage_to_leader), NULL);






	//新建一个scrolled组件
	//得到fixed布局，并把控件部署上去
	fixed = gtk_fixed_new();
	initialWindow(fixed);


	gtk_fixed_put(GTK_FIXED(fixed), playerLabel, 170, 200);
	gtk_fixed_put(GTK_FIXED(fixed), playerSelect, 250, 200);


	gtk_fixed_put(GTK_FIXED(fixed), playerInfoChange, 170, 290);
	gtk_fixed_put(GTK_FIXED(fixed), playerDelete, 410, 290);
	gtk_fixed_put(GTK_FIXED(fixed), addPlayer, 170, 380);
	gtk_fixed_put(GTK_FIXED(fixed), retur, 300, 520);



	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);
}
