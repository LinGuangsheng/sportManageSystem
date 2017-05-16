#ifndef __REFEREEINFOMANAGE_H__
#define __REFEREEINFOMANAGE_H__

#include <gtk/gtk.h>

//void RIM_to_CRI(GtkWidget *widget, gpointer data){
//	gtk_container_remove(GTK_CONTAINER(window), fixed);
//	create_CRI_window();
//}


void RIM_to_CkRI(GtkWidget *widget, gpointer data){
	Mreferee = (refereeNode*)data;
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_CkRI_window();
}

void RIM_to_Manage(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	manager();
}

void RIM_to_addReferee(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_refereeRegistration_window();
}

void deleteReferee(GtkWidget *widget, gpointer data){

	Mreferee = (refereeNode*)data;

	deleteAccountNodeByID(accountlist, Mreferee->refereeInfomation.id);
	deleteRefereeNodeByID(refereelist, Mreferee->refereeInfomation.id);

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_RIM_window();
}

void show_deleteRefereeConfirm(GtkWidget *button, gpointer data)
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("ȷ��ɾ���ò��У�"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));


	gint response = gtk_dialog_run(GTK_DIALOG(dialog));
	if (response == GTK_RESPONSE_OK)
	{
		printf("clicked");
		//����дgettext����
		deleteReferee(button, data);
		gtk_widget_destroy(dialog);

	}

}

void create_RIM_window(){

	//������ؿؼ�
	GtkWidget *gridTable;
	GtkWidget *newUnit;
	GtkWidget *returnbn;


	//��������fixed���ֺͳ�ʼ��window
	fixed = gtk_fixed_new();
	initialWindow(fixed);


	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	newUnit = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(newUnit), _T("��������"));
	gtk_widget_set_size_request(GTK_WIDGET(newUnit), 220, 40);
	g_signal_connect(G_OBJECT(newUnit), "clicked", G_CALLBACK(RIM_to_addReferee), NULL);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 220, 40);
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(RIM_to_Manage), NULL);


	GtkWidget	*scrolledWin = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWin), 600, 300);

	//grid�����б�
	gridTable = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(gridTable), 600, 300);
	GtkWidget *tableTitle = gtk_label_new(_T("����Ա�б�"));
	gtk_widget_set_size_request(GTK_WIDGET(tableTitle), 600, 40);

	GtkWidget *tableName = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(tableName), 200, 40);

	GtkWidget *tableNum = gtk_label_new(_T("������Ŀ��"));
	gtk_widget_set_size_request(GTK_WIDGET(tableNum), 190, 40);

	GtkWidget *tableOperate = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(tableOperate), 210, 40);

	gtk_grid_attach(GTK_GRID(gridTable), tableTitle, 0, 0, 600, 40);
	gtk_grid_attach(GTK_GRID(gridTable), tableName, 0, 40, 200, 40);
	gtk_grid_attach(GTK_GRID(gridTable), tableNum, 200, 40, 190, 40);
	gtk_grid_attach(GTK_GRID(gridTable), tableOperate, 390, 40, 210, 40);

	refereeNode *rNode = getRefereeHead(refereelist);
	for (int i = 0; i < refereelist->size; i++){
		rNode = rNode->next;
		GtkWidget *tableName_ = gtk_label_new(_T(rNode->refereeInfomation.refereeName));
		gtk_widget_set_size_request(GTK_WIDGET(tableName_), 200, 40);

		char tem[200];
		_itoa_s(rNode->refereeInfomation.eventSize, tem, 10);
		GtkWidget *tableNum_ = gtk_label_new(_T(tem));
		gtk_widget_set_size_request(GTK_WIDGET(tableNum_), 190, 40);

		GtkWidget *tableOperate_1 = gtk_button_new_with_label(_T("�鿴/�޸�"));
		gtk_widget_set_size_request(GTK_WIDGET(tableOperate_1), 105, 40);
		g_signal_connect(G_OBJECT(tableOperate_1), "clicked", G_CALLBACK(RIM_to_CkRI), rNode);
		//GtkWidget *tableOperate_2 = gtk_button_new_with_label(_T("�޸�"));
		//g_signal_connect(G_OBJECT(tableOperate_2), "clicked", G_CALLBACK(RIM_to_CRI), NULL);
		//gtk_widget_set_size_request(GTK_WIDGET(tableOperate_2), 70, 40);
		GtkWidget *tableOperate_3 = gtk_button_new_with_label(_T("ɾ��"));
		gtk_widget_set_size_request(GTK_WIDGET(tableOperate_3), 105, 40);
		g_signal_connect(G_OBJECT(tableOperate_3), "clicked", G_CALLBACK(show_deleteRefereeConfirm), rNode);


		gtk_grid_attach(GTK_GRID(gridTable), tableName_, 0, 40 * i + 80, 200, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableNum_, 200, 40 * i + 80, 190, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableOperate_1, 390, 40 * i + 80, 105, 40);
		//gtk_grid_attach(GTK_GRID(gridTable), tableOperate_2, 460, 40 * i + 80, 70, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableOperate_3, 495, 40 * i + 80, 105, 40);

	}


	//���������ӵ�fixed������
	gtk_container_add(GTK_CONTAINER(scrolledWin), gridTable);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWin, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), newUnit, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 440, 520);



	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}

#endif