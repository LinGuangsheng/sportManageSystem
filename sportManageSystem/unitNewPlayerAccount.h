

#include <gtk/gtk.h>
#include <string.h>


GtkWidget *userInput111;
GtkWidget *passwdInput111;

// ��ť"cancel"�Ļص�����
void Ucb_cancel(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	playerManage();
}
void Ushow_unitAccountExist()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("���û����Ѵ��ڣ������"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��ʧ��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}


void Ushow_inputUnitAccount()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("�������û���������"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

// ��ť"next"�Ļص�����
void Ucb_next(GtkWidget *widget, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(userInput111))), "") == 0 || strcmp(__T(gtk_entry_get_text(GTK_ENTRY(passwdInput111))), "") == 0){
		//�����˵ĶԻ���
		Ushow_inputUnitAccount();
	}
	else if (getAccountNodeByName(accountlist, __T(gtk_entry_get_text(GTK_ENTRY(userInput111)))) != NULL){
		//�����˺��Ѿ����ڵ���ʾ
		Ushow_unitAccountExist();
	}
	else{
		accountSet = accountSet + 1;
		participantInfo p = {};
		participantRegister = makeParticipantNode(p);
		accountInfo account = {};
		accountR = makeAccountNode(account);
		
		participantRegister->participantInfomation.id = (long)accountSet;
		accountR->account.id = (long)accountSet;

		strcpy_s(accountR->account.name, __T(gtk_entry_get_text(GTK_ENTRY(userInput111))));
		strcpy_s(accountR->account.passwd, __T(gtk_entry_get_text(GTK_ENTRY(passwdInput111))));

		accountR->account.type = 3;

		gtk_container_remove(GTK_CONTAINER(window), fixed);
		addPlayer();
	}
}


void Ucreate_registration_window(){

	//������ؿؼ�
	GtkWidget *userLabel;
	GtkWidget *passwdLabel;


	GtkWidget *next;
	GtkWidget *cancel;

	GtkCellRenderer *renderer;


	//��������fixed���ֺͳ�ʼ��window
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	userLabel = gtk_label_new(_T("�û���"));
	gtk_widget_set_size_request(GTK_WIDGET(userLabel), 200, 40);

	userInput111 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(userInput111), 300, 40);

	passwdLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(passwdLabel), 200, 40);

	passwdInput111 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(passwdInput111), 300, 40);
	gtk_entry_set_visibility(GTK_ENTRY(passwdInput111), FALSE);



	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("ȡ��"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	//Ϊ"cancel"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(Ucb_cancel), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("��һ��"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 220, 40);
	//Ϊ"next"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(Ucb_next), NULL);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), userLabel, 150, 240);
	gtk_fixed_put(GTK_FIXED(fixed), userInput111, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), passwdLabel, 150, 340);
	gtk_fixed_put(GTK_FIXED(fixed), passwdInput111, 300, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);


	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}
