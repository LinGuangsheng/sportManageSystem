#ifndef __LEADER_REGISTRATION_H__
#define __LEADER_REGISTRATION_H__

#include <gtk/gtk.h>


typedef struct leaderRegistration{
	GtkWidget *nameInput;
	GtkWidget *contactInput;
	GtkWidget *introductionInput;
};

leaderRegistration leaderRegistrationWidget;


// 按钮"returnbn"的回调函数
void LR_to_R(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_registration_window();
}

// 按钮"next"的回调函数
void LR_to_UR(GtkWidget *widget, gpointer data){
	const gchar *getLeaderName = gtk_entry_get_text(GTK_ENTRY(leaderRegistrationWidget.nameInput));
	const gchar *getLeaderContact = gtk_entry_get_text(GTK_ENTRY(leaderRegistrationWidget.contactInput));
	const gchar *getLeaderIntroduction = gtk_entry_get_text(GTK_ENTRY(leaderRegistrationWidget.introductionInput));

	unitList *unitList = initUnitList();
	unitInfo unit = { *__T(getLeaderName), *__T(getLeaderIntroduction), *__T(getLeaderContact), *__T(getLeaderName), *__T(getLeaderIntroduction), *__T(getLeaderContact), 0, 0 };
	unitNode *unitNode = makeUnitNode(unit);
	addUnitNode(unitList, unitNode);

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_UR_window();
}

void create_LR_window(){

	//定义相关控件
	GtkWidget *nameLabel;
	GtkWidget *contactLabel;
	GtkWidget *introductionLabel;
	GtkWidget *next;
	GtkWidget *returnbn;

	//重新生成fixed布局和初始化window
	fixed = gtk_fixed_new();
	initialWindow();

	//以下控件的设置方法相同，先得到控件，然后设置大小
	nameLabel = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	leaderRegistrationWidget.nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(leaderRegistrationWidget.nameInput), 400, 40);

	contactLabel = gtk_label_new(_T("联系方式"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 200, 40);

	leaderRegistrationWidget.contactInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(leaderRegistrationWidget.contactInput), 400, 40);

	introductionLabel = gtk_label_new(_T("个人简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	leaderRegistrationWidget.introductionInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(leaderRegistrationWidget.introductionInput), 600, 100);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 120, 40);
	//为"returnbn"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(LR_to_R), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("下一步"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 120, 40);
	//为"next"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(LR_to_UR), NULL);

	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), leaderRegistrationWidget.nameInput, 300, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), leaderRegistrationWidget.contactInput, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), leaderRegistrationWidget.introductionInput, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}

#endif