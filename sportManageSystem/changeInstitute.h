#include <gtk\gtk.h>

GtkWidget *nameInput3;
GtkWidget *sloganInput3;
GtkWidget *introductionInput3;


//�Ӳ�����λ�޸ģ�������Ϣ��������ת��������λ�������

void changeInstitute_cancel(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	instituteManage();
}

void changeInstitute_to_instituteManage(GtkWidget *button, gpointer data){
	strcpy_s(MunitNode->unitInfomation.unitName, __T(gtk_entry_get_text(GTK_ENTRY(nameInput3))));
	strcpy_s(MunitNode->unitInfomation.unitSolgan, __T(gtk_entry_get_text(GTK_ENTRY(sloganInput3))));
	strcpy_s(MunitNode->unitInfomation.unitIntroduction, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput3))));

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	instituteManage();
}

//�Ӳ�����λ�޸ģ�������Ϣ��������ת�������Ϣ�޸Ľ���
void changeInstitute_to_changeLeader(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	changeLeader();
}

//�Ӳ�����λ�޸ģ�������Ϣ��������ת��������λѡ����Ϣ�޸Ľ��棨�б�
void changeInstitute_to_changeInstituteAthlete(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	changeInstituteAthlete();
}


//������λ��Ϣ�޸Ľ��棨������Ϣ��
void changeInstitute(){

	//����������

	GtkWidget *scrolledWindow;

	//����������label��entry
	GtkWidget *nameLabel;

	//����ںŵ�label��entry
	GtkWidget *sloganLabel;

	//�������label��entry
	GtkWidget *introductionLabel;

	//���巵�غ�ȷ�ϰ�ť
	GtkWidget *cancel;
	GtkWidget *confirm;

	//�����޸������Ϣ���޸�ѡ����Ϣ��ť
	GtkWidget *changeLeader;
	GtkWidget *changeAthlete;

	//��������fixed���ֺͳ�ʼ��window
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//�������غ���ɰ�ť
	cancel = gtk_button_new_with_label(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(changeInstitute_cancel), NULL);

	confirm = gtk_button_new_with_label(_T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 220, 40);
	g_signal_connect_swapped(G_OBJECT(confirm), "clicked", G_CALLBACK(changeInstitute_to_instituteManage), NULL);

	//�������Ƶ�label��entry
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	nameInput3 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput3), 480, 40);
	gtk_entry_set_text(GTK_ENTRY(nameInput3), _T(MunitNode->unitInfomation.unitName));

	//�����ںŵ�label��entry
	sloganLabel = gtk_label_new(_T("�ں�"));
	gtk_widget_set_size_request(GTK_WIDGET(sloganLabel), 100, 40);

	sloganInput3 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(sloganInput3), 480, 40);
	gtk_entry_set_text(GTK_ENTRY(sloganInput3), _T(MunitNode->unitInfomation.unitSolgan));

	//���ɼ���label��entry
	introductionLabel = gtk_label_new(_T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 280, 40);

	introductionInput3 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput3), 280, 100);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput3), GTK_WRAP_CHAR);
	setTextToTextview(GTK_TEXT_VIEW(introductionInput3), MunitNode->unitInfomation.unitIntroduction);

	//�����޸������Ϣ���޸�ѡ����Ϣ��button
	changeLeader = gtk_button_new_with_label(_T("�޸������Ϣ"));
	gtk_widget_set_size_request(GTK_WIDGET(changeLeader), 250, 40);
	g_signal_connect_swapped(G_OBJECT(changeLeader), "clicked", G_CALLBACK(changeInstitute_to_changeLeader), NULL);

	changeAthlete = gtk_button_new_with_label(_T("�޸�ѡ����Ϣ"));
	gtk_widget_set_size_request(GTK_WIDGET(changeAthlete), 250, 40);
	g_signal_connect_swapped(G_OBJECT(changeAthlete), "clicked", G_CALLBACK(changeInstitute_to_changeInstituteAthlete), NULL);

	//�½�һ��scrolled���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 280, 100);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput3, 220, 180);
	gtk_fixed_put(GTK_FIXED(fixed), sloganLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), sloganInput3, 220, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), confirm, 440, 520);
	gtk_fixed_put(GTK_FIXED(fixed), changeLeader, 440, 340);
	gtk_fixed_put(GTK_FIXED(fixed), changeAthlete, 440, 400);

	//��textView��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput3);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}

