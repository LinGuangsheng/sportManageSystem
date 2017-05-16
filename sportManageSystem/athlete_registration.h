#ifndef __ATHLETE_REGISTRATION_H__
#define __ATHLETE_REGISTRATION_H__

#include <gtk/gtk.h>

	const gchar *unitName;
	GtkWidget *unitInput;
	GtkTreeIter iterAthlete;
	GtkTreeModel *treemodelAthlete;

typedef struct athleteRegistration{
	GtkWidget *nameInput;
	GtkWidget *contactInput;
	GtkWidget *introductionInput;
	GtkWidget *gradeMajorInput;

};

athleteRegistration athleteRegistrationWidget;

// 按钮"returnbn"的回调函数
void AtR_to_R(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_registration_window();
}
// 按钮"done"的回调函数
void cb_doneAthlete(GtkWidget *widget, gpointer data){
	treemodelAthlete = gtk_combo_box_get_model(GTK_COMBO_BOX(unitInput));
	gtk_combo_box_get_active_iter(GTK_COMBO_BOX(unitInput), &iterAthlete);
	gtk_tree_model_get(treemodelAthlete, &iterAthlete, 0, &unitName, -1);

	const gchar *getAthleteName = gtk_entry_get_text(GTK_ENTRY(athleteRegistrationWidget.nameInput));
	const gchar *getAtheleteContact = gtk_entry_get_text(GTK_ENTRY(athleteRegistrationWidget.contactInput));
	const gchar *getAthleteIntroduction = gtk_entry_get_text(GTK_ENTRY(athleteRegistrationWidget.introductionInput));
	const gchar *getAthleteGradeMajor = gtk_entry_get_text(GTK_ENTRY(athleteRegistrationWidget.gradeMajorInput));

	participantList *participantList = initParticipantList();
	participantInfo participant = { *__T(getAthleteName), *__T(getAthleteIntroduction), *__T(getAthleteGradeMajor), *__T(getAtheleteContact),0,0,0 };
	participantNode *participantNode = makeParticipantNode(participant);
	addParticipantNode(participantList, participantNode);

	
}


void create_AtR_window(){

	//定义相关控件
	GtkWidget *nameLabel;
	GtkWidget *contactLabel;
	GtkWidget *introductionLabel;
	GtkWidget *gradeMajorLabel;
	GtkWidget *unitLabel;
	GtkWidget *done;
	GtkWidget *returnbn;
	GtkTreeStore *store;
	GtkCellRenderer* renderer;


	//重新生成fixed布局和初始化window
	fixed = gtk_fixed_new();
	initialWindow();

	//以下控件的设置方法相同，先得到控件，然后设置大小
	nameLabel = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	athleteRegistrationWidget.nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(athleteRegistrationWidget.nameInput), 160, 40);

	gradeMajorLabel = gtk_label_new(_T("年级专业"));
	gtk_widget_set_size_request(GTK_WIDGET(gradeMajorLabel), 100, 40);

	athleteRegistrationWidget.gradeMajorInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(athleteRegistrationWidget.gradeMajorInput), 160, 40);

	contactLabel = gtk_label_new(_T("联系方式"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 100, 40);

	athleteRegistrationWidget.contactInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(athleteRegistrationWidget.contactInput), 160, 40);

	unitLabel = gtk_label_new(_T("所属单位"));
	gtk_widget_set_size_request(GTK_WIDGET(unitLabel), 100, 40);

	//ComboBox控件
	store = gtk_tree_store_new(1, G_TYPE_STRING);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter, 0, "0", -1);
	unitInput = gtk_combo_box_new_with_model(GTK_TREE_MODEL(store));
	gtk_tree_store_set(store, &iter, 0, "1", -1);
	unitInput = gtk_combo_box_new_with_model(GTK_TREE_MODEL(store));
	renderer = gtk_cell_renderer_text_new();
	// 设置GtkTreeModel中的每一项数据如何在列表框中显示
	renderer = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(unitInput), renderer, TRUE);
	gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(unitInput), renderer, "text", 0, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(unitInput), 170, 40);

	introductionLabel = gtk_label_new(_T("个人简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 300, 40);

	athleteRegistrationWidget.introductionInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(athleteRegistrationWidget.introductionInput), 300, 160);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 120, 40);
	//为"returnbn"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(AtR_to_R), NULL);

	done = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(done), _T("完成"));
	gtk_widget_set_size_request(GTK_WIDGET(done), 120, 40);
	//为"done"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(done), "clicked", G_CALLBACK(cb_doneAthlete), &athleteRegistrationWidget);

	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), athleteRegistrationWidget.nameInput, 220, 180);
	gtk_fixed_put(GTK_FIXED(fixed), gradeMajorLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), athleteRegistrationWidget.gradeMajorInput, 220, 240);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), athleteRegistrationWidget.contactInput, 220, 300);
	gtk_fixed_put(GTK_FIXED(fixed), unitLabel, 100, 360);
	gtk_fixed_put(GTK_FIXED(fixed), unitInput, 220, 360);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 420, 180);
	gtk_fixed_put(GTK_FIXED(fixed), athleteRegistrationWidget.introductionInput, 420, 240);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), done, 440, 520);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}

#endif