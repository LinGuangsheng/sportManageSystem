#ifndef __LEADER_REGISTRATION_H__
#define __LEADER_REGISTRATION_H__

#include <gtk/gtk.h>


typedef struct leaderRegistration{
	GtkWidget *nameInput;
	GtkWidget *contactInput;
	GtkWidget *introductionInput;
};

leaderRegistration leaderRegistrationWidget;


// ��ť"returnbn"�Ļص�����
void LR_to_R(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_registration_window();
}

// ��ť"next"�Ļص�����
void LR_to_UR(GtkWidget *widget, gpointer data){
	const gchar *getLeaderName = gtk_entry_get_text(GTK_ENTRY(leaderRegistrationWidget.nameInput));
	const gchar *getLeaderContact = gtk_entry_get_text(GTK_ENTRY(leaderRegistrationWidget.contactInput));
	const gchar *getLeaderIntroduction = gtk_entry_get_text(GTK_ENTRY(leaderRegistrationWidget.introductionInput));

	unitList *unitList = initUnitList();
	unitInfo unit = { *__T(getLeaderName), *__T(getLeaderIntroduction), *__T(getLeaderContact), *__T(getLeaderName), *__T(getLeaderIntroduction), *__T(getLeaderContact), 0, 0 };
	unitNode *unitNode = makeUnitNode(unit);
	addUnitNode(unitList, unitNode);

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_UR_window();
}

void create_LR_window(){

	//������ؿؼ�
	GtkWidget *nameLabel;
	GtkWidget *contactLabel;
	GtkWidget *introductionLabel;
	GtkWidget *next;
	GtkWidget *returnbn;

	//��������fixed���ֺͳ�ʼ��window
	fixed = gtk_fixed_new();
	initialWindow();

	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	leaderRegistrationWidget.nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(leaderRegistrationWidget.nameInput), 400, 40);

	contactLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 200, 40);

	leaderRegistrationWidget.contactInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(leaderRegistrationWidget.contactInput), 400, 40);

	introductionLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	leaderRegistrationWidget.introductionInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(leaderRegistrationWidget.introductionInput), 600, 100);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 120, 40);
	//Ϊ"returnbn"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(LR_to_R), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("��һ��"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 120, 40);
	//Ϊ"next"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(LR_to_UR), NULL);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), leaderRegistrationWidget.nameInput, 300, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), leaderRegistrationWidget.contactInput, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), leaderRegistrationWidget.introductionInput, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}

#endif