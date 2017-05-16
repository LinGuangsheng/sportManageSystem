#ifndef __CHECKREFEREEINFO_H__
#define __CHECKREFEREEINFO_H__

#include <gtk/gtk.h>

GtkWidget *nameDataLabel;
GtkWidget *contactDataLabel;
GtkWidget *introductionDataView;

void refereeFeedbackWindow(GtkWidget *button, gpointer   user_data)
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
		GTK_BUTTONS_OK, _T("ѡ����Ŀ"), "title");

	content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 8);
	gtk_container_set_border_width(GTK_CONTAINER(hbox), 8);
	gtk_box_pack_start(GTK_BOX(content_area), hbox, FALSE, FALSE, 0);

	//image = gtk_image_new_from_icon_name("dialog-question", GTK_ICON_SIZE_DIALOG);
	//gtk_box_pack_start(GTK_BOX(hbox), image, FALSE, FALSE, 0);

	combo = gtk_combo_box_text_new();
	int Rflag = 0;
	eventNode *node = getEventHead(eventlist);
	for (int i = 0; i < eventlist->size; i++){
		node = node->next;
		if (getBaseNodeByID(Mreferee->eventList, node->eventInfomation.id) == NULL&&flag){
			gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), "1", _T(node->eventInfomation.name));
			Rflag = 1;
		}
	}
	gtk_combo_box_set_active(GTK_COMBO_BOX(combo), 0);
	table = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(table), 4);
	gtk_grid_set_column_spacing(GTK_GRID(table), 4);
	gtk_box_pack_start(GTK_BOX(hbox), table, TRUE, TRUE, 0);
	label = gtk_label_new_with_mnemonic("Name");
	local_entry1 = gtk_entry_new();
	//gtk_entry_set_text(GTK_ENTRY(local_entry1), gtk_entry_get_text(GTK_ENTRY(entry1)));
	gtk_entry_set_text(GTK_ENTRY(local_entry1), "");

	gtk_label_set_mnemonic_widget(GTK_LABEL(label), local_entry1);

	label = gtk_label_new_with_mnemonic(_T("��Ŀ"));
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
		if (Rflag){
		//����дgettext����
			gchar *c = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo));
			if (c != NULL){
				char *event = __T(c);
				eventNode *eventN = getEventNodeByName(eventlist, event);

				int F = 1;
				baseNode *eventDB = getBaseListHead(Mreferee->eventList);
				for (int i = 0; i < Mreferee->eventList->size; i++){
					eventDB = eventDB->next;
					eventNode *e = getEventNodeByID(eventlist, eventDB->id);
					if (e->eventInfomation.timeNum == eventN->eventInfomation.timeNum){
						F = 0;
					}
				}

				if (F){
					addRefereeEventByID(refereelist, Mreferee->refereeInfomation.id, eventN->eventInfomation.id);
				}
				else{
					//��ʾʱ���ͻ
					timeCrash();
				}

			}
		}
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		create_CkRI_window();
	}

	gtk_widget_destroy(dialog);
}

void CkRI_to_RIM(GtkWidget *widget, gpointer data){
	strcpy_s(Mreferee->refereeInfomation.refereeName, __T(gtk_entry_get_text(GTK_ENTRY(nameDataLabel))));
	strcpy_s(Mreferee->refereeInfomation.refereeContact, __T(gtk_entry_get_text(GTK_ENTRY(contactDataLabel))));
	strcpy_s(Mreferee->refereeInfomation.refereeIntro, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionDataView))));
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_RIM_window();
}


void refereeCancel(GtkWidget *widget, gpointer data){
		
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		create_RIM_window();
}


void deleteRefereeEvent(GtkWidget *widget, gpointer data){

	baseNode *node = (baseNode*)data;

	deleteRefereeEventByID(refereelist, Mreferee->refereeInfomation.id, node->id);

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_CkRI_window();
}


void show_deleteRefereeEventConfirm(GtkWidget *button, gpointer data)
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("ȷ��ɾ������Ŀ��"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));


	gint response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//����дgettext����
		deleteRefereeEvent(button, data);
		gtk_widget_destroy(dialog);

	}

}

void addRefereeEvent(GtkWidget *widget, gpointer data){
	//ȥ���ظ�ѡ��
	refereeFeedbackWindow(widget, data);
}

void create_CkRI_window(){

	//������ؿؼ�
	GtkWidget *nameLabel;
	GtkWidget *contactLabel;
	GtkWidget *introductionLabel;
	GtkWidget *projectLabel;
	GtkWidget *gridTable;
	GtkWidget *returnbn;
	GtkWidget *confirm;

	GtkWidget *scrolledWindow;

	GtkWidget *addNewEvent;


	//��������fixed���ֺͳ�ʼ��window
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	nameDataLabel = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(nameDataLabel), _T(Mreferee->refereeInfomation.refereeName));
	gtk_widget_set_size_request(GTK_WIDGET(nameDataLabel), 180, 40);


	contactLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 100, 40);

	contactDataLabel = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(contactDataLabel), _T(Mreferee->refereeInfomation.refereeContact));
	gtk_widget_set_size_request(GTK_WIDGET(contactDataLabel), 180, 40);

	introductionLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 280, 40);

	introductionDataView = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionDataView), 280, 140);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionDataView), GTK_WRAP_CHAR);

	setTextToTextview(GTK_TEXT_VIEW(introductionDataView), Mreferee->refereeInfomation.refereeIntro);

	//�½�һ��scrolled���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 280, 140);

	projectLabel = gtk_label_new(_T("������Ŀ"));
	gtk_widget_set_size_request(GTK_WIDGET(projectLabel), 180, 40);

	addNewEvent = gtk_button_new_with_label(_T("������Ŀ"));
	gtk_widget_set_size_request(GTK_WIDGET(addNewEvent), 100, 40);
	g_signal_connect(G_OBJECT(addNewEvent), "clicked", G_CALLBACK(addRefereeEvent), NULL);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 220, 40);
	//Ϊ"returnbn"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(refereeCancel), NULL);

	confirm = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(confirm), _T("ȷ��"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 220, 40);
	//Ϊ"returnbn"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(CkRI_to_RIM), NULL);


	//grid�����б�
	gridTable = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(gridTable), 280, 250);
	baseNode *rEvent = getBaseListHead(Mreferee->eventList);
	for (int i = 0; i < Mreferee->refereeInfomation.eventSize; i++){
		rEvent = rEvent->next;
		eventNode *ee = getEventNodeByID(eventlist, rEvent->id);
		printf("%s", ee->eventInfomation.name);
		GtkWidget *tableName_ = gtk_label_new(_T(ee->eventInfomation.name));
		gtk_widget_set_size_request(GTK_WIDGET(tableName_), 210, 40);

		GtkWidget *tableOperate_ = gtk_button_new_with_label(_T("ɾ��"));
		gtk_widget_set_size_request(GTK_WIDGET(tableOperate_), 70, 40);
		g_signal_connect(G_OBJECT(tableOperate_), "clicked", G_CALLBACK(show_deleteRefereeEventConfirm), rEvent);


		gtk_grid_attach(GTK_GRID(gridTable), tableName_, 0, 40 * i + 80, 210, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableOperate_, 210, 40 * i + 80, 70, 40);

	}

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameDataLabel, 200, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), contactDataLabel, 200, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), projectLabel, 420, 180);
	gtk_fixed_put(GTK_FIXED(fixed), addNewEvent, 600, 180);

	gtk_fixed_put(GTK_FIXED(fixed), gridTable, 420, 230);

	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 420, 520);
	gtk_fixed_put(GTK_FIXED(fixed), confirm, 180, 520);

	gtk_fixed_put(GTK_FIXED(fixed), gridTable, 420, 230);

	//��textView��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionDataView);



	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}

#endif