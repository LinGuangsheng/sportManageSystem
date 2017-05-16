
#include <gtk/gtk.h>
#include <string.h>


GtkWidget *userInput12;
GtkWidget *passwdInput12;

// ��ť"cancel"�Ļص�����
void refereeR_cancel(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_RIM_window();
}

void show_refereeAccountExist()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("���û����Ѵ��ڣ������"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��ʧ��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

void show_inputRefereeAccount()
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
void refereeR_next(GtkWidget *widget, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(userInput12))), "") == 0 || strcmp(__T(gtk_entry_get_text(GTK_ENTRY(passwdInput12))), "") == 0){
		//�����˵ĶԻ���
		show_inputRefereeAccount();
	}
	else if (getAccountNodeByName(accountlist, __T(gtk_entry_get_text(GTK_ENTRY(userInput12)))) != NULL){
		//�����˺��Ѿ����ڵ���ʾ
		show_refereeAccountExist();
	}
	else{
		accountSet = accountSet + 1;
		refereeInfo referee = {};
		MrefereeRegister = makeRefereeNode(referee);
		accountInfo account = {};
		MrefereeAccount = makeAccountNode(account);
		MrefereeRegister->refereeInfomation.id = (long)accountSet;
		MrefereeAccount->account.id = (long)accountSet;
		strcpy_s(MrefereeAccount->account.name, __T(gtk_entry_get_text(GTK_ENTRY(userInput12))));
		strcpy_s(MrefereeAccount->account.passwd, __T(gtk_entry_get_text(GTK_ENTRY(passwdInput12))));
		MrefereeAccount->account.type = 2;
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		addReferee();
	}
}


void create_refereeRegistration_window(){

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

	userInput12 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(userInput12), 300, 40);

	passwdLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(passwdLabel), 200, 40);

	passwdInput12 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(passwdInput12), 300, 40);
	gtk_entry_set_visibility(GTK_ENTRY(passwdInput12), FALSE);



	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("ȡ��"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 120, 40);
	//Ϊ"cancel"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(refereeR_cancel), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("��һ��"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 120, 40);
	//Ϊ"next"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(refereeR_next), NULL);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), userLabel, 150, 240);
	gtk_fixed_put(GTK_FIXED(fixed), userInput12, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), passwdLabel, 150, 340);
	gtk_fixed_put(GTK_FIXED(fixed), passwdInput12, 300, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);


	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}