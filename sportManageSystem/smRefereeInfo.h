#ifndef __SETREFEREEINFO_H__
#define __SETREFEREEINFO_H__

#include <gtk/gtk.h>

void SRI_to_RIM(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_RIM_window();
}

void create_SRI_window(){

	//定义相关控件
	GtkWidget *nameLabel;
	GtkWidget *nameInput;
	GtkWidget *contactLabel;
	GtkWidget *contactInput;
	GtkWidget *introductionLabel;
	GtkWidget *introductionInput;
	GtkWidget *projectLabel;
	GtkWidget *gridTable;
	GtkWidget *done;
	GtkWidget *returnbn;
	GtkWidget *arrangebn;
	GtkWidget *scrolledWindow;

	//重新生成fixed布局和初始化window
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//以下控件的设置方法相同，先得到控件，然后设置大小
	nameLabel = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput), 180, 40);

	contactLabel = gtk_label_new(_T("联系方式"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 100, 40);

	contactInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput), 180, 40);

	introductionLabel = gtk_label_new(_T("个人简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 280, 40);

	introductionInput = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput), GTK_WRAP_CHAR);

	gtk_widget_set_size_request(GTK_WIDGET(introductionInput), 280, 140);

	//新建一个scrolled组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 280, 140);

	projectLabel = gtk_label_new(_T("负责项目"));
	gtk_widget_set_size_request(GTK_WIDGET(projectLabel), 280, 40);

	//grid布局列表
	gridTable = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(gridTable), 280, 205);
	for (int i = 0; i < 4; i++){
		GtkWidget *tableName_ = gtk_label_new(_T("XM0"));
		gtk_widget_set_size_request(GTK_WIDGET(tableName_), 280, 40);
		gtk_grid_attach(GTK_GRID(gridTable), tableName_, 0, 40 * i + 80, 280, 40);

	}

	arrangebn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(arrangebn), _T("安排项目"));
	gtk_widget_set_size_request(GTK_WIDGET(arrangebn), 220, 40);

	done = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(done), _T("确定"));
	gtk_widget_set_size_request(GTK_WIDGET(done), 220, 40);
	//为"done"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(done), "clicked", G_CALLBACK(SRI_to_RIM), NULL);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 220, 40);
	//为"returnbn"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(SRI_to_RIM), NULL);

	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput, 200, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput, 200, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), projectLabel, 420, 180);
	gtk_fixed_put(GTK_FIXED(fixed), gridTable, 420, 230);
	gtk_fixed_put(GTK_FIXED(fixed), arrangebn, 440, 440);
	gtk_fixed_put(GTK_FIXED(fixed), done, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 440, 520);

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput);


	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}

#endif