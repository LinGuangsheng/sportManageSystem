#ifndef __ADMINISTRATOR_REGISTRATION_H__
#define __ADMINISTRATOR_REGISTRATION_H__

#include <gtk/gtk.h>



typedef struct adminRegistration{
	GtkWidget *nameInput;
	GtkWidget *contactInput;
	GtkWidget *introductionInput;
};

adminRegistration adminRegistrationWidget;

// ��ť"returnbn"�Ļص�����
void AR_to_R(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_registration_window();
}
// ��ť"done"�Ļص�����
void cb_doneAdmin(GtkWidget *widget, gpointer data){
	const gchar *getAdminName = gtk_entry_get_text(GTK_ENTRY(adminRegistrationWidget.nameInput));
	const gchar *getAdminContact = gtk_entry_get_text(GTK_ENTRY(adminRegistrationWidget.contactInput));
	const gchar *getAdminIntroduction = gtk_entry_get_text(GTK_ENTRY(adminRegistrationWidget.introductionInput));
	Manager m = { *__T(getAdminName), *__T(getAdminContact), *__T(getAdminIntroduction)};

}


void create_AR_window(){

	//������ؿؼ�
	GtkWidget *nameLabel;
	GtkWidget *contactLabel;
	GtkWidget *introductionLabel;
	GtkWidget *done;
	GtkWidget *returnbn;

	//��������fixed���ֺͳ�ʼ��window
	fixed = gtk_fixed_new();
	initialWindow();


	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	adminRegistrationWidget.nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(adminRegistrationWidget.nameInput), 400, 40);

	contactLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 200, 40);

	adminRegistrationWidget.contactInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(adminRegistrationWidget.contactInput), 400, 40);

	introductionLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	adminRegistrationWidget.introductionInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(adminRegistrationWidget.introductionInput), 600, 100);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 120, 40);
	//Ϊ"returnbn"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(AR_to_R), NULL);

	done = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(done), _T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(done), 120, 40);
	//Ϊ"done"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(done), "clicked", G_CALLBACK(cb_doneAdmin), &adminRegistrationWidget);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), adminRegistrationWidget.nameInput, 300, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), adminRegistrationWidget.contactInput, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), adminRegistrationWidget.introductionInput, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), done, 440, 520);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}

#endif