#ifndef __UNIT_REGISTRATION_H__
#define __UNIT_REGISTRATION_H__

#include <gtk/gtk.h>

typedef struct unitRegistration{
	GtkWidget *nameInput;
	GtkWidget *sloganInput;
	GtkWidget *introductionInput;
};

unitRegistration unitRegistrationWidget;

// ��ť"returnbn"�Ļص�����
void UR_to_LR(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_LR_window();
}
// ��ť"next"�Ļص�����
void cb_nextUnit(GtkWidget *widget, gpointer data){
	const gchar *getUnitName = gtk_entry_get_text(GTK_ENTRY(unitRegistrationWidget.nameInput));
	const gchar *getUnitSloganInput = gtk_entry_get_text(GTK_ENTRY(unitRegistrationWidget.sloganInput));
	const gchar *getUnitIntroduction = gtk_entry_get_text(GTK_ENTRY(unitRegistrationWidget.introductionInput));

	unitList *unitList = initUnitList();
	unitInfo unit = { "", "", "", *__T(getUnitName), *__T(getUnitSloganInput), *__T(getUnitIntroduction), 0, 0 };
	unitNode *unitNode = makeUnitNode(unit);
	addUnitNode(unitList, unitNode);
}

void create_UR_window(){

	//������ؿؼ�
	GtkWidget *nameLabel;
	GtkWidget *sloganLabel;
	GtkWidget *introductionLabel;
	GtkWidget *next;
	GtkWidget *returnbn;

	//��������fixed���ֺͳ�ʼ��window
	fixed = gtk_fixed_new();
	initialWindow();

	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	unitRegistrationWidget.nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(unitRegistrationWidget.nameInput), 400, 40);

	sloganLabel = gtk_label_new(_T("�ں�"));
	gtk_widget_set_size_request(GTK_WIDGET(sloganLabel), 200, 40);

	unitRegistrationWidget.sloganInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(unitRegistrationWidget.sloganInput), 400, 40);

	introductionLabel = gtk_label_new(_T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	unitRegistrationWidget.introductionInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(unitRegistrationWidget.introductionInput), 600, 100);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 120, 40);
	//Ϊ"returnbn"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(UR_to_LR), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("��һ��"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 120, 40);
	//Ϊ"next"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(cb_nextUnit), &unitRegistrationWidget);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), unitRegistrationWidget.nameInput, 300, 180);
	gtk_fixed_put(GTK_FIXED(fixed), sloganLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), unitRegistrationWidget.sloganInput, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), unitRegistrationWidget.introductionInput, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}

#endif