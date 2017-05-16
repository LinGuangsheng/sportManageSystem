#include <gtk\gtk.h>


GtkWidget *nameInput9;
GtkWidget *sloganInput9;
GtkWidget *introductionInput9;

void show_inputUnitName()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("�����������λ����"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}


//�Ӳ�����λע�������ת��������λ�������
void instituteRegister_to_instituteManage(GtkWidget *button, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(nameInput9))), "") == 0){
		//��ʾ�������������λ������
		show_inputUnitName();
	}
	else{
		strcpy_s(MunitRegisterNode->unitInfomation.unitName, __T(gtk_entry_get_text(GTK_ENTRY(nameInput9))));
		strcpy_s(MunitRegisterNode->unitInfomation.unitSolgan, __T(gtk_entry_get_text(GTK_ENTRY(sloganInput9))));
		strcpy_s(MunitRegisterNode->unitInfomation.unitIntroduction, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput9))));
		addAccountNode(accountlist, MunitAccount);
		addUnitNode(unitlist, MunitRegisterNode);
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		instituteManage();
	}
}

//�Ӳ�����λע�������ת�����ע�����
void instituteRegister_to_leaderRegister(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	leaderRegister();
}

//������λע�����
void instituteRegister(){

	//����������

	GtkWidget *scrolledWindow;

	//�������Ƶ�label��entry
	GtkWidget *nameLabel;

	//����ںŵ�label��entry
	GtkWidget *sloganLabel;

	//�������label��entry
	GtkWidget *introductionLabel;

	//����ȷ���ͷ��ذ�ť
	GtkWidget *cancel;
	GtkWidget *confirm;


	//�õ�fixed���֣�����ʼ������
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//���÷��غ�ȷ����ť
	cancel = gtk_button_new_with_label(_T("��һ��"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(instituteRegister_to_leaderRegister), NULL);

	confirm = gtk_button_new_with_label(_T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 220, 40);
	g_signal_connect_swapped(G_OBJECT(confirm), "clicked", G_CALLBACK(instituteRegister_to_instituteManage), NULL);

	//�������Ƶ�label��entry
	nameLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	nameInput9 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput9), 480, 40);

	//���ÿںŵ�label��entry
	sloganLabel = gtk_label_new(_T("�ں�"));
	gtk_widget_set_size_request(GTK_WIDGET(sloganLabel), 100, 40);

	sloganInput9 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(sloganInput9), 480, 40);

	//���ü���label��entry
	introductionLabel = gtk_label_new(_T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	introductionInput9 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput9), 600, 100);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput9), GTK_WRAP_CHAR);


	//�½�һ��scrolled���
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 100);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput9, 220, 180);
	gtk_fixed_put(GTK_FIXED(fixed), sloganLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), sloganInput9, 220, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), confirm, 440, 520);

	//��textView��ӵ�scrolled������
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput9);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}
