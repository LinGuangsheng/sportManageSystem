#ifndef __REFEREE_REGISTRATION_H__
#define __REFEREE_REGISTRATION_H__

#include <gtk/gtk.h>

typedef struct refereeRegistration{
	GtkWidget *nameInput;
	GtkWidget *contactInput;
	GtkWidget *introductionInput;
};

refereeRegistration refereeRegistrationWidget;

// 按钮"returnbn"的回调函数
void RR_to_R(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_registration_window();
}
// 按钮"done"的回调函数
void cb_doneReferee(GtkWidget *widget, gpointer data){
	const gchar *getRefereeName = gtk_entry_get_text(GTK_ENTRY(refereeRegistrationWidget.nameInput));
	const gchar *getRefereeContact = gtk_entry_get_text(GTK_ENTRY(refereeRegistrationWidget.contactInput));
	const gchar *getRefereeIntroduction = gtk_entry_get_text(GTK_ENTRY(refereeRegistrationWidget.introductionInput));
	refereeList *refereeList = initRefereeList();
	refereeInfo referee = { *__T(getRefereeName), *__T(getRefereeIntroduction), *__T(getRefereeContact), 0, 0 };
	refereeNode *refereeNode = makeRefereeNode(referee);
	addRefereeNode(refereeList, refereeNode);
}

void create_RR_window(){

	//定义相关控件
	GtkWidget *nameLabel;
	GtkWidget *contactLabel;
	GtkWidget *introductionLabel;
	GtkWidget *done;
	GtkWidget *returnbn;

	//重新生成fixed布局和初始化window
	fixed = gtk_fixed_new();
	initialWindow();

	//以下控件的设置方法相同，先得到控件，然后设置大小
	nameLabel = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	refereeRegistrationWidget.nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(refereeRegistrationWidget.nameInput), 400, 40);

	contactLabel = gtk_label_new(_T("联系方式"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 200, 40);

	refereeRegistrationWidget.contactInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(refereeRegistrationWidget.contactInput), 400, 40);

	introductionLabel = gtk_label_new(_T("个人简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	refereeRegistrationWidget.introductionInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(refereeRegistrationWidget.introductionInput), 600, 100);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 120, 40);
	//为"returnbn"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(RR_to_R), NULL);

	done = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(done), _T("完成"));
	gtk_widget_set_size_request(GTK_WIDGET(done), 120, 40);
	//为"done"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(done), "clicked", G_CALLBACK(cb_doneReferee), &refereeRegistrationWidget);

	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), refereeRegistrationWidget.nameInput, 300, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), refereeRegistrationWidget.contactInput, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), refereeRegistrationWidget.introductionInput, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), done, 440, 520);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}

#endif