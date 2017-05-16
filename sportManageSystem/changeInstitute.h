#include <gtk\gtk.h>

GtkWidget *nameInput3;
GtkWidget *sloganInput3;
GtkWidget *introductionInput3;


//从参赛单位修改（基本信息）界面跳转到参赛单位管理界面

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

//从参赛单位修改（基本信息）界面跳转到领队信息修改界面
void changeInstitute_to_changeLeader(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	changeLeader();
}

//从参赛单位修改（基本信息）界面跳转到参赛单位选手信息修改界面（列表）
void changeInstitute_to_changeInstituteAthlete(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	changeInstituteAthlete();
}


//参赛单位信息修改界面（基本信息）
void changeInstitute(){

	//定义相关组件

	GtkWidget *scrolledWindow;

	//定义姓名的label和entry
	GtkWidget *nameLabel;

	//定义口号的label和entry
	GtkWidget *sloganLabel;

	//定义简介的label和entry
	GtkWidget *introductionLabel;

	//定义返回和确认按钮
	GtkWidget *cancel;
	GtkWidget *confirm;

	//定义修改领队信息和修改选手信息按钮
	GtkWidget *changeLeader;
	GtkWidget *changeAthlete;

	//重新生成fixed布局和初始化window
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//生产返回和完成按钮
	cancel = gtk_button_new_with_label(_T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(changeInstitute_cancel), NULL);

	confirm = gtk_button_new_with_label(_T("完成"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 220, 40);
	g_signal_connect_swapped(G_OBJECT(confirm), "clicked", G_CALLBACK(changeInstitute_to_instituteManage), NULL);

	//生产名称的label和entry
	nameLabel = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	nameInput3 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput3), 480, 40);
	gtk_entry_set_text(GTK_ENTRY(nameInput3), _T(MunitNode->unitInfomation.unitName));

	//生产口号的label和entry
	sloganLabel = gtk_label_new(_T("口号"));
	gtk_widget_set_size_request(GTK_WIDGET(sloganLabel), 100, 40);

	sloganInput3 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(sloganInput3), 480, 40);
	gtk_entry_set_text(GTK_ENTRY(sloganInput3), _T(MunitNode->unitInfomation.unitSolgan));

	//生成简介的label和entry
	introductionLabel = gtk_label_new(_T("简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 280, 40);

	introductionInput3 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput3), 280, 100);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput3), GTK_WRAP_CHAR);
	setTextToTextview(GTK_TEXT_VIEW(introductionInput3), MunitNode->unitInfomation.unitIntroduction);

	//生成修改领队信息和修改选手信息的button
	changeLeader = gtk_button_new_with_label(_T("修改领队信息"));
	gtk_widget_set_size_request(GTK_WIDGET(changeLeader), 250, 40);
	g_signal_connect_swapped(G_OBJECT(changeLeader), "clicked", G_CALLBACK(changeInstitute_to_changeLeader), NULL);

	changeAthlete = gtk_button_new_with_label(_T("修改选手信息"));
	gtk_widget_set_size_request(GTK_WIDGET(changeAthlete), 250, 40);
	g_signal_connect_swapped(G_OBJECT(changeAthlete), "clicked", G_CALLBACK(changeInstitute_to_changeInstituteAthlete), NULL);

	//新建一个scrolled组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 280, 100);

	//将各组件添加到fixed布局上
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

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput3);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}

