
#include <gtk/gtk.h>

GtkWidget *nameInput17;
GtkWidget *contactInput17;
GtkWidget *introductionInput17;


// ��ť"returnbn"�Ļص�����
void RR_to_R(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	registration();
}

// ��ť"done"�Ļص�����
void RR_to_Login(GtkWidget *widget, gpointer data){

	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(nameInput17))), "") == 0){
		//��ʾ������������
		show_inputRefereeName();
	}
	else{
		accountSet = accountSet + 1;
		Raccount->account.id = accountSet;
		Raccount->account.type = 2;
		Rreferee = makeRefereeNode({});
		Rreferee->refereeInfomation.id = accountSet;

		strcpy_s(Rreferee->refereeInfomation.refereeName, __T(gtk_entry_get_text(GTK_ENTRY(nameInput17))));
		strcpy_s(Rreferee->refereeInfomation.refereeContact, __T(gtk_entry_get_text(GTK_ENTRY(contactInput17))));

		strcpy_s(Rreferee->refereeInfomation.refereeIntro, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput17))));

		addAccountNode(accountlist, Raccount);
		addRefereeNode(refereelist, Rreferee);


		gtk_container_remove(GTK_CONTAINER(window), fixed);
		initLoginWindow();
	}
}

void create_RR_window(){

	//������ؿؼ�
	GtkWidget *nameLabel;
	GtkWidget *contactLabel;
	GtkWidget *introductionLabel;
	GtkWidget *done;
	GtkWidget *returnbn;

	//��������fixed���ֺͳ�ʼ��window
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	nameInput17 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput17), 400, 40);

	contactLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 200, 40);

	contactInput17 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput17), 400, 40);

	introductionLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	introductionInput17 = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput17), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput17), 600, 100);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 180, 40);
	//Ϊ"returnbn"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(RR_to_R), NULL);

	done = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(done), _T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(done), 180, 40);
	//Ϊ"done"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(done), "clicked", G_CALLBACK(RR_to_Login), NULL);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput17, 300, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput17, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), introductionInput17, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), done, 440, 520);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}
