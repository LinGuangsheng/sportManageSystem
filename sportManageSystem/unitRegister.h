
#include <gtk/gtk.h>


GtkWidget *nameInput15;
GtkWidget *sloganInput15;
GtkWidget *introductionInput15;

void show_inputUnitRegisterName()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("�������Ŷ�����"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

// ��ť"cancel"�Ļص�����
void UR_to_LR(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_LR_window();
}

// ��ť"returnbn"�Ļص�����
void UR_to_Login(GtkWidget *widget, gpointer data){

	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(nameInput15))), "") == 0){
		//��ʾ������������
		show_inputUnitRegisterName();
	}
	else{

		strcpy_s(Runit->unitInfomation.unitName, __T(gtk_entry_get_text(GTK_ENTRY(nameInput15))));
		strcpy_s(Runit->unitInfomation.unitSolgan, __T(gtk_entry_get_text(GTK_ENTRY(sloganInput15))));

		strcpy_s(Runit->unitInfomation.unitIntroduction, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput15))));

		addUnitNode(unitlist, Runit);
		addAccountNode(accountlist, Raccount);

		gtk_container_remove(GTK_CONTAINER(window), fixed);
		initLoginWindow();
	}
}

void create_UR(){

	//������ؿؼ�
	GtkWidget *nameLabel;
	GtkWidget *sloganLabel;
	GtkWidget *introductionLabel;
	GtkWidget *next;
	GtkWidget *returnbn;

	//��������fixed���ֺͳ�ʼ��window
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	nameLabel = gtk_label_new(_T("�Ŷ�����"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	nameInput15 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput15), 400, 40);

	sloganLabel = gtk_label_new(_T("�ں�"));
	gtk_widget_set_size_request(GTK_WIDGET(sloganLabel), 200, 40);

	sloganInput15 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(sloganInput15), 400, 40);

	introductionLabel = gtk_label_new(_T("���"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	introductionInput15 = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput15), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput15), 600, 100);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 180, 40);
	//Ϊ"returnbn"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(UR_to_LR), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("��һ��"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 180, 40);
	//Ϊ"next"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(UR_to_Login), NULL);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput15, 300, 180);
	gtk_fixed_put(GTK_FIXED(fixed), sloganLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), sloganInput15, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), introductionInput15, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);

	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}