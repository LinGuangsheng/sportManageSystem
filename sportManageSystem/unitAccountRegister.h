#ifndef __REGISTRATION_H__
#define __REGISTRATION_H__

#include <gtk/gtk.h>
#include <string.h>


GtkWidget *userInput11;
GtkWidget *passwdInput11;

// ��ť"cancel"�Ļص�����
void cb_cancel(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	instituteManage();
}
void show_unitAccountExist()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("���û����Ѵ��ڣ������"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��ʧ��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}


void show_inputUnitAccount()
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
void cb_next(GtkWidget *widget, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(userInput11))), "") == 0 || strcmp(__T(gtk_entry_get_text(GTK_ENTRY(passwdInput11))), "") == 0){
		//�����˵ĶԻ���
		show_inputUnitAccount();
	}
	else if (getAccountNodeByName(accountlist, __T(gtk_entry_get_text(GTK_ENTRY(userInput11)))) != NULL){
		//�����˺��Ѿ����ڵ���ʾ
		show_unitAccountExist();
	}
	else{
		accountSet = accountSet + 1;
		unitInfo unit = {};
		MunitRegisterNode = makeUnitNode(unit);
		accountInfo account = {};
		MunitAccount = makeAccountNode(account);
		MunitRegisterNode->unitInfomation.id = (long)accountSet;
		MunitAccount->account.id = (long)accountSet;
		strcpy_s(MunitAccount->account.name, __T(gtk_entry_get_text(GTK_ENTRY(userInput11))));
		strcpy_s(MunitAccount->account.passwd, __T(gtk_entry_get_text(GTK_ENTRY(passwdInput11))));
		MunitAccount->account.type = 1;
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		leaderRegister();
	}
}


void create_registration_window(){

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

	userInput11 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(userInput11), 300, 40);

	passwdLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(passwdLabel), 200, 40);

	passwdInput11 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(passwdInput11), 300, 40);
	gtk_entry_set_visibility(GTK_ENTRY(passwdInput11), FALSE);



	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("ȡ��"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	//Ϊ"cancel"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(cb_cancel), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("��һ��"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 220, 40);
	//Ϊ"next"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(cb_next), NULL);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), userLabel, 150, 240);
	gtk_fixed_put(GTK_FIXED(fixed), userInput11, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), passwdLabel, 150, 340);
	gtk_fixed_put(GTK_FIXED(fixed), passwdInput11, 300, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);


	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}

#endif