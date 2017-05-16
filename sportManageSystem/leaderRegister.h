#include <gtk\gtk.h>

GtkWidget *nameInput8;
GtkWidget *contactInput8;
GtkWidget *introductionInput8;
//从领队注册界面跳转到参赛单位注册界面


void show_inputLeaderName()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("请输入姓名"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

void leaderRegister_to_instituteRegister(GtkWidget *button, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(nameInput8))), "") == 0){
		//提示必须输入姓名
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

//从领队注册界面跳转到参赛单位管理界面
void leaderRegister_to_instituteManage(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	instituteManage();
}

//领队注册界面
void leaderRegister(){

	//定义相关组件
	GtkWidget *scrolledWindow;

	//定义姓名的label和entry
	GtkWidget *nameLabel;

	//定义联系方式的label和entry
	GtkWidget *contactLabel;

	//定义简介的label和entry
	GtkWidget *introductionLabel;

	//定义返回和确认按钮
	GtkWidget *cancel;
	GtkWidget *confirm;

	//得到fixed布局，并初始化窗口
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//设置返回和确认按钮
	cancel = gtk_button_new_with_label(_T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(leaderRegister_to_instituteManage), NULL);

	confirm = gtk_button_new_with_label(_T("下一步"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 220, 40);
	g_signal_connect_swapped(G_OBJECT(confirm), "clicked", G_CALLBACK(leaderRegister_to_instituteRegister), NULL);

	//设置姓名的label和entry
	nameLabel = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	nameInput8 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput8), 480, 40);

	//设置联系方式的label和entry
	contactLabel = gtk_label_new(_T("联系方式"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 100, 40);

	contactInput8 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput8), 480, 40);

	//设置个人简介的label和textview
	introductionLabel = gtk_label_new(_T("个人简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	introductionInput8 = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput8), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput8), 600, 100);

	//新建一个scrolled组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 100);

	//将各种组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput8, 220, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput8, 220, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), confirm, 440, 520);


	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput8);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}
