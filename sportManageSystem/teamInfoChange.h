#include <gtk\gtk.h>
#include <string.h>

GtkWidget *nameInput;
GtkWidget *sloganInput;
GtkWidget *introInput;
void teamInfoChange_to_leader(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	leader();
}

void teamInfoChangeCommit(GtkWidget *button, gpointer data){
	strcpy_s(unit_node->unitInfomation.unitName, __T(gtk_entry_get_text(GTK_ENTRY(nameInput))));
	strcpy_s(unit_node->unitInfomation.unitSolgan, __T(gtk_entry_get_text(GTK_ENTRY(sloganInput))));
	strcpy_s(unit_node->unitInfomation.unitIntroduction, __T(getTextFromTextview(GTK_TEXT_VIEW(introInput))));
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	leader();
}

void teamInformChangeCancel(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	leader();
}



void teamInfoChange(){
	GtkWidget *nameLabel;
	GtkWidget *sloganLabel;
	GtkWidget *introLabel;
	GtkWidget *confirm;
	GtkWidget *cancel;
	GtkWidget *scrolledWindow;

	//设置窗口，辩题和大小
	//以下控件的设置方法相同，先得到控件，然后设置大小


	nameLabel = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 80, 40);

	nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput), 400, 40);
	gtk_entry_set_text(GTK_ENTRY(nameInput), _T(unit_node->unitInfomation.unitName));

	sloganLabel = gtk_label_new(_T("口号"));
	gtk_widget_set_size_request(GTK_WIDGET(sloganLabel), 80, 40);

	sloganInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(sloganInput), 400, 40);
	gtk_entry_set_text(GTK_ENTRY(sloganInput), _T(unit_node->unitInfomation.unitSolgan));


	introLabel = gtk_label_new(_T("简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introLabel), 80, 40);

	introInput = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introInput), 500, 120);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introInput), GTK_WRAP_CHAR);
	setTextToTextview(GTK_TEXT_VIEW(introInput), unit_node->unitInfomation.unitIntroduction);

	//新建一个scrolled组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 500, 120);



	confirm = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(confirm), _T("确定"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 220, 40);
	g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(teamInfoChangeCommit), NULL);


	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("取消"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(teamInformChangeCancel), NULL);


	//得到fixed布局，并把控件部署上去
	fixed = gtk_fixed_new();

	initialWindow(fixed);


	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 140, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput, 240, 180);


	gtk_fixed_put(GTK_FIXED(fixed), sloganLabel, 140, 230);
	gtk_fixed_put(GTK_FIXED(fixed), sloganInput, 240, 230);


	gtk_fixed_put(GTK_FIXED(fixed), introLabel, 360, 320);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 140, 360);

	gtk_fixed_put(GTK_FIXED(fixed), cancel, 100, 520);
	gtk_fixed_put(GTK_FIXED(fixed), confirm, 480, 520);

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introInput);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);
}
