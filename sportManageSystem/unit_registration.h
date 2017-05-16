#ifndef __UNIT_REGISTRATION_H__
#define __UNIT_REGISTRATION_H__

#include <gtk/gtk.h>

typedef struct unitRegistration{
	GtkWidget *nameInput;
	GtkWidget *sloganInput;
	GtkWidget *introductionInput;
};

unitRegistration unitRegistrationWidget;

// 按钮"returnbn"的回调函数
void UR_to_LR(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_LR_window();
}
// 按钮"next"的回调函数
void cb_nextUnit(GtkWidget *widget, gpointer data){
	const gchar *getUnitName = gtk_entry_get_text(GTK_ENTRY(unitRegistrationWidget.nameInput));
	const gchar *getUnitSloganInput = gtk_entry_get_text(GTK_ENTRY(unitRegistrationWidget.sloganInput));
	const gchar *getUnitIntroduction = gtk_entry_get_text(GTK_ENTRY(unitRegistrationWidget.introductionInput));

	unitList *unitList = initUnitList();
	unitInfo unit = { "", "", "", *__T(getUnitName), *__T(getUnitSloganInput), *__T(getUnitIntroduction), 0, 0 };
	unitNode *unitNode = makeUnitNode(unit);
	addUnitNode(unitList, unitNode);
}

void create_UR_window(){

	//定义相关控件
	GtkWidget *nameLabel;
	GtkWidget *sloganLabel;
	GtkWidget *introductionLabel;
	GtkWidget *next;
	GtkWidget *returnbn;

	//重新生成fixed布局和初始化window
	fixed = gtk_fixed_new();
	initialWindow();

	//以下控件的设置方法相同，先得到控件，然后设置大小
	nameLabel = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	unitRegistrationWidget.nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(unitRegistrationWidget.nameInput), 400, 40);

	sloganLabel = gtk_label_new(_T("口号"));
	gtk_widget_set_size_request(GTK_WIDGET(sloganLabel), 200, 40);

	unitRegistrationWidget.sloganInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(unitRegistrationWidget.sloganInput), 400, 40);

	introductionLabel = gtk_label_new(_T("简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	unitRegistrationWidget.introductionInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(unitRegistrationWidget.introductionInput), 600, 100);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 120, 40);
	//为"returnbn"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(UR_to_LR), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("下一步"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 120, 40);
	//为"next"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(cb_nextUnit), &unitRegistrationWidget);

	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), unitRegistrationWidget.nameInput, 300, 180);
	gtk_fixed_put(GTK_FIXED(fixed), sloganLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), unitRegistrationWidget.sloganInput, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), unitRegistrationWidget.introductionInput, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}

#endif