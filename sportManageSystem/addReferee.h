#ifndef __REFEREE_REGISTRATION_H__
#define __REFEREE_REGISTRATION_H__

#include <gtk/gtk.h>
GtkWidget *nameInput10;
GtkWidget *contactInput10;
GtkWidget *introductionInput10;

void show_inputRefereeName()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("请输入姓名"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}


void addReferee_to_refereeM(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_RIM_window();
}

//按钮"returnbn"的回调函数
void addReferee_to_refereeManage(GtkWidget *widget, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(nameInput10))), "") == 0){
		//给出提示：必须输入姓名
		show_inputRefereeName();
	}
	else{
		strcpy_s(MrefereeRegister->refereeInfomation.refereeName, __T(gtk_entry_get_text(GTK_ENTRY(nameInput10))));
		strcpy_s(MrefereeRegister->refereeInfomation.refereeContact, __T(gtk_entry_get_text(GTK_ENTRY(contactInput10))));
		strcpy_s(MrefereeRegister->refereeInfomation.refereeIntro, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput10))));
		addRefereeNode(refereelist, MrefereeRegister);


		gtk_container_remove(GTK_CONTAINER(window), fixed);
		create_RIM_window();
	}
}

void addReferee(){

	//定义相关控件
	GtkWidget *nameLabel;
	GtkWidget *contactLabel;
	GtkWidget *introductionLabel;
	GtkWidget *done;
	GtkWidget *returnbn;
	GtkWidget *scrolledWindow;

	//重新生成fixed布局和初始化window
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//以下控件的设置方法相同，先得到控件，然后设置大小
	nameLabel = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	nameInput10 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput10), 400, 40);

	contactLabel = gtk_label_new(_T("联系方式"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 200, 40);

	contactInput10 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput10), 400, 40);

	introductionLabel = gtk_label_new(_T("个人简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	introductionInput10 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput10), 600, 100);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput10), GTK_WRAP_CHAR);


	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 120, 40);
	//为"returnbn"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(addReferee_to_refereeM), NULL);

	done = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(done), _T("完成"));
	gtk_widget_set_size_request(GTK_WIDGET(done), 120, 40);
	g_signal_connect(G_OBJECT(done), "clicked", G_CALLBACK(addReferee_to_refereeManage), NULL);

	//新建一个scrolled组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 100);


	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput10, 300, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput10, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), done, 440, 520);

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput10);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}

#endif