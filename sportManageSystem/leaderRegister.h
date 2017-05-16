#include <gtk\gtk.h>

GtkWidget *nameInput8;
GtkWidget *contactInput8;
GtkWidget *introductionInput8;
//�����ע�������ת��������λע�����


void show_inputLeaderName()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("����������"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

void leaderRegister_to_instituteRegister(GtkWidget *button, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(nameInput8))), "") == 0){
		//��ʾ������������
		show_inputLeaderName();
	}
	else{
		strcpy_s(MunitRegisterNode->unitInfomation.leaderName, __T(gtk_entry_get_text(GTK_ENTRY(nameInput8))));
		strcpy_s(MunitRegisterNode->unitInfomation.leaderContact, __T(gtk_entry_get_text(GTK_ENTRY(contactInput8))));
		strcpy_s(MunitRegisterNode->unitInfomation.leaderIntro, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput8))));
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		instituteRegister();
	}
}

//�����ע�������ת��������λ�������
void leaderRegister_to_instituteManage(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	instituteManage();
}

//���ע�����
void leaderRegister(){

	//����������
	GtkWidget *scrolledWindow;

	//����������label��entry
	GtkWidget *nameLabel;

	//������ϵ��ʽ��label��entry
	GtkWidget *contactLabel;

	//�������label��entry
	GtkWidget *introductionLabel;

	//���巵�غ�ȷ�ϰ�ť
	GtkWidget *cancel;
	GtkWidget *confirm;

	//�õ�fixed���֣�����ʼ������
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//���÷��غ�ȷ�ϰ�ť
	cancel = gtk_button_new_with_label(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(leaderRegister_to_instituteManage), NULL);

	confirm = gtk_button_new_with_label(_T("��һ��"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 220, 40);
	g_signal_connect_swapped(G_OBJECT(confirm), "clicked", G_CALLBACK(leaderRegister_to_instituteRegister), NULL);

	//����������label��entry
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	nameInput8 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput8), 480, 40);

	//������ϵ��ʽ��label��entry
	contactLabel = gtk_label_new(_T("��ϵ��ʽ"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 100, 40);

	contactInput8 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput8), 480, 40);

	//���ø��˼���label��textview
	introductionLabel = gtk_label_new(_T("���˼��"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	introductionInput8 = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput8), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput8), 600, 100);

	//�½�һ��scrolled���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 100);

	//�����������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput8, 220, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput8, 220, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), confirm, 440, 520);


	//��textView��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput8);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}
