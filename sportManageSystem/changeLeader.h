
#include <gtk\gtk.h>

GtkWidget *nameInput4;
GtkWidget *contactInput4;
GtkWidget *introductionInput4;

//从领队信息修改界面跳转到参赛单位信息修改界面
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

//领队信息修改界面
void changeLeader(){

	//定义相关组件

	GtkWidget *scrolledWindow;

	//定义名称的label和entry
	GtkWidget *nameLabel;

	//定义联系方式的label和entry
	GtkWidget *contactLabel;

	//定义简介的label和entry
	GtkWidget *introductionLabel;

	//定义返回和确定按钮
	GtkWidget *cancel;
	GtkWidget *confirm;

	//得到fixed布局，并初始化窗口
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//设置返回和确定按钮
	cancel = gtk_button_new_with_label(_T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(changeLeader_cancel), NULL);

	confirm = gtk_button_new_with_label(_T("确定"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 220, 40);
	g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(changeLeader_to_changeInstitute), NULL);

	//设置名称的label和entry
	nameLabel = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	nameInput4 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput4), 480, 40);
	gtk_entry_set_text(GTK_ENTRY(nameInput4), _T(MunitNode->unitInfomation.leaderName));

	//设置联系方式的label和entry
	contactLabel = gtk_label_new(_T("联系方式"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 100, 40);

	contactInput4 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput4), 480, 40);
	gtk_entry_set_text(GTK_ENTRY(contactInput4), _T(MunitNode->unitInfomation.leaderContact));

	//设置简介的label和textview
	introductionLabel = gtk_label_new(_T("个人简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	introductionInput4 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput4), 600, 100);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput4), GTK_WRAP_CHAR);
	setTextToTextview(GTK_TEXT_VIEW(introductionInput4), MunitNode->unitInfomation.leaderIntro);

	//新建一个scrolled组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 100);

	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput4, 220, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput4, 220, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), confirm, 440, 520);

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput4);


	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}