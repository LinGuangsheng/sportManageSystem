#include <gtk\gtk.h>

GtkWidget *nameInput7;
GtkWidget *timeInput7;
GtkWidget *placeInput7;
GtkWidget *introInput7;
GtkWidget *rulesInput7;

void eventRegister_to_manager(){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	manager();
}


void show_inputEventInfo()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("�������������ƺ͵ص�"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

void eventRegister_to_eventInfoManage(){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(nameInput7))), "") == 0  || strcmp(__T(gtk_entry_get_text(GTK_ENTRY(placeInput7))), "") == 0)	{
		//�Ի�����ʾ��ȫ��Ϣ������Ҫ�����ơ�ʱ��͵ص�
		show_inputEventInfo();
	}
	else{
		eventInfo info = {};
		strcpy_s(info.name, __T(gtk_entry_get_text(GTK_ENTRY(nameInput7))));
		strcpy_s(info.place, __T(gtk_entry_get_text(GTK_ENTRY(placeInput7))));
		strcpy_s(info.rule, __T(getTextFromTextview(GTK_TEXT_VIEW(rulesInput7))));
		strcpy_s(info.intro, __T(getTextFromTextview(GTK_TEXT_VIEW(introInput7))));
		eventSet++;
		info.id = eventSet;
		info.participantSize = 0;

		eventNode *p = makeEventNode(info);
		addEventNode(eventlist, p);

		gtk_container_remove(GTK_CONTAINER(window), fixed);
		eventInfoManage();
	}
}

void eventRegisterCancel(){

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	eventInfoManage();
}


void eventRegister(){
	//������ؿؼ�������:window������ͼ:bgImage,Logo:logo,fixed����:fixed�������ľ���Щ��
	GtkWidget *nameLabel;
	GtkWidget *timeLabel;
	GtkWidget *placeLabel;
	GtkWidget *introLabel;
	GtkWidget *rulesLabel;
	GtkWidget *finish;
	GtkWidget *cancel;
	GtkWidget *scrolledWindow1;
	GtkWidget *scrolledWindow2;


	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С


	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 80, 40);

	nameInput7 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput7), 200, 40);


	placeLabel = gtk_label_new(_T("�ص�"));
	gtk_widget_set_size_request(GTK_WIDGET(placeLabel), 80, 40);

	placeInput7 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(placeInput7), 200, 40);


	introLabel = gtk_label_new(_T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(introLabel), 280, 40);

	introInput7 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introInput7), 280, 120);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introInput7), GTK_WRAP_CHAR);


	rulesLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(rulesLabel), 280, 40);

	rulesInput7 = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(rulesInput7), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(rulesInput7), 280, 260);



	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("ȡ��"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(eventRegisterCancel), NULL);

	finish = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(finish), _T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(finish), 220, 40);
	g_signal_connect_swapped(G_OBJECT(finish), "clicked", G_CALLBACK(eventRegister_to_eventInfoManage), NULL);


	//�½�һ��scrolled���
	scrolledWindow1 = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow1), 280, 160);

	//�½�һ��scrolled���
	scrolledWindow2 = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow2), 280, 260);


	//�õ�fixed���֣����ѿؼ�������ȥ
	fixed = gtk_fixed_new();
	initialWindow(fixed);




	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput7, 180, 180);




	gtk_fixed_put(GTK_FIXED(fixed), placeLabel, 100, 230);
	gtk_fixed_put(GTK_FIXED(fixed), placeInput7, 180, 230);

	gtk_fixed_put(GTK_FIXED(fixed), introLabel, 100, 280);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow1, 100, 320);

	gtk_fixed_put(GTK_FIXED(fixed), rulesLabel, 420, 180);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow2, 420, 220);

	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), finish, 440, 520);

	//��textView��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow1), introInput7);
	gtk_container_add(GTK_CONTAINER(scrolledWindow2), rulesInput7);


	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//��ʾ
	gtk_widget_show_all(window);
}