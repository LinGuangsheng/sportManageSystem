
#include <gtk\gtk.h>

GtkWidget *nameInput4;
GtkWidget *contactInput4;
GtkWidget *introductionInput4;

//�������Ϣ�޸Ľ�����ת��������λ��Ϣ�޸Ľ���
void changeLeader_to_changeInstitute(GtkWidget *button, gpointer data){
	strcpy_s(MunitNode->unitInfomation.leaderName, __T(gtk_entry_get_text(GTK_ENTRY(nameInput4))));
	strcpy_s(MunitNode->unitInfomation.leaderContact, __T(gtk_entry_get_text(GTK_ENTRY(contactInput4))));
	strcpy_s(MunitNode->unitInfomation.leaderIntro, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput4))));
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	changeInstitute();
}

void  changeLeader_cancel(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	changeInstitute();
}

//�����Ϣ�޸Ľ���
void changeLeader(){

	//����������

	GtkWidget *scrolledWindow;

	//�������Ƶ�label��entry
	GtkWidget *nameLabel;

	//������ϵ��ʽ��label��entry
	GtkWidget *contactLabel;

	//�������label��entry
	GtkWidget *introductionLabel;

	//���巵�غ�ȷ����ť
	GtkWidget *cancel;
	GtkWidget *confirm;

	//�õ�fixed���֣�����ʼ������
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//���÷��غ�ȷ����ť
	cancel = gtk_button_new_with_label(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(changeLeader_cancel), NULL);

	confirm = gtk_button_new_with_label(_T("ȷ��"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 220, 40);
	g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(changeLeader_to_changeInstitute), NULL);

	//�������Ƶ�label��entry
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	nameInput4 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput4), 480, 40);
	gtk_entry_set_text(GTK_ENTRY(nameInput4), _T(MunitNode->unitInfomation.leaderName));

	//������ϵ��ʽ��label��entry
	contactLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 100, 40);

	contactInput4 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput4), 480, 40);
	gtk_entry_set_text(GTK_ENTRY(contactInput4), _T(MunitNode->unitInfomation.leaderContact));

	//���ü���label��textview
	introductionLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	introductionInput4 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput4), 600, 100);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput4), GTK_WRAP_CHAR);
	setTextToTextview(GTK_TEXT_VIEW(introductionInput4), MunitNode->unitInfomation.leaderIntro);

	//�½�һ��scrolled���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 100);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput4, 220, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput4, 220, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), confirm, 440, 520);

	//��textView��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput4);


	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}