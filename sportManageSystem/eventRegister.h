#include <gtk\gtk.h>

GtkWidget *nameInput7;
GtkWidget *timeInput7;
GtkWidget *placeInput7;
GtkWidget *introInput7;
GtkWidget *rulesInput7;

void eventRegister_to_manager(){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	manager();
}


void show_inputEventInfo()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("请至少输入名称和地点"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

void eventRegister_to_eventInfoManage(){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(nameInput7))), "") == 0  || strcmp(__T(gtk_entry_get_text(GTK_ENTRY(placeInput7))), "") == 0)	{
		//对话框：提示补全信息：至少要有名称、时间和地点
		show_inputEventInfo();
	}
	else{
		eventInfo info = {};
		strcpy_s(info.name, __T(gtk_entry_get_text(GTK_ENTRY(nameInput7))));
		strcpy_s(info.place, __T(gtk_entry_get_text(GTK_ENTRY(placeInput7))));
		strcpy_s(info.rule, __T(getTextFromTextview(GTK_TEXT_VIEW(rulesInput7))));
		strcpy_s(info.intro, __T(getTextFromTextview(GTK_TEXT_VIEW(introInput7))));
		eventSet++;
		info.id = eventSet;
		info.participantSize = 0;

		eventNode *p = makeEventNode(info);
		addEventNode(eventlist, p);

		gtk_container_remove(GTK_CONTAINER(window), fixed);
		eventInfoManage();
	}
}

void eventRegisterCancel(){

	gtk_container_remove(GTK_CONTAINER(window), fixed);
	eventInfoManage();
}


void eventRegister(){
	//定义相关控件，窗口:window，背景图:bgImage,Logo:logo,fixed布局:fixed，其他的就那些了
	GtkWidget *nameLabel;
	GtkWidget *timeLabel;
	GtkWidget *placeLabel;
	GtkWidget *introLabel;
	GtkWidget *rulesLabel;
	GtkWidget *finish;
	GtkWidget *cancel;
	GtkWidget *scrolledWindow1;
	GtkWidget *scrolledWindow2;


	//以下控件的设置方法相同，先得到控件，然后设置大小


	nameLabel = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 80, 40);

	nameInput7 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput7), 200, 40);


	placeLabel = gtk_label_new(_T("地点"));
	gtk_widget_set_size_request(GTK_WIDGET(placeLabel), 80, 40);

	placeInput7 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(placeInput7), 200, 40);


	introLabel = gtk_label_new(_T("简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introLabel), 280, 40);

	introInput7 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introInput7), 280, 120);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introInput7), GTK_WRAP_CHAR);


	rulesLabel = gtk_label_new(_T("规则"));
	gtk_widget_set_size_request(GTK_WIDGET(rulesLabel), 280, 40);

	rulesInput7 = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(rulesInput7), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(rulesInput7), 280, 260);



	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("取消"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(eventRegisterCancel), NULL);

	finish = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(finish), _T("完成"));
	gtk_widget_set_size_request(GTK_WIDGET(finish), 220, 40);
	g_signal_connect_swapped(G_OBJECT(finish), "clicked", G_CALLBACK(eventRegister_to_eventInfoManage), NULL);


	//新建一个scrolled组件
	scrolledWindow1 = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow1), 280, 160);

	//新建一个scrolled组件
	scrolledWindow2 = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow2), 280, 260);


	//得到fixed布局，并把控件部署上去
	fixed = gtk_fixed_new();
	initialWindow(fixed);




	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput7, 180, 180);




	gtk_fixed_put(GTK_FIXED(fixed), placeLabel, 100, 230);
	gtk_fixed_put(GTK_FIXED(fixed), placeInput7, 180, 230);

	gtk_fixed_put(GTK_FIXED(fixed), introLabel, 100, 280);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow1, 100, 320);

	gtk_fixed_put(GTK_FIXED(fixed), rulesLabel, 420, 180);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow2, 420, 220);

	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), finish, 440, 520);

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow1), introInput7);
	gtk_container_add(GTK_CONTAINER(scrolledWindow2), rulesInput7);


	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);
}