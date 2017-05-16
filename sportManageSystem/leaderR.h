#include <gtk/gtk.h>


GtkWidget *nameInput16;
GtkWidget *contactInput16;
GtkWidget *introductionInput16;


// 按钮"returnbn"的回调函数
void LR_to_R(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	registration();
}

// 按钮"next"的回调函数
void LR_to_UR(GtkWidget *widget, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(nameInput16))), "") == 0){
		//提示必须输入姓名
		show_inputLeaderName();
	}
	else{
		accountSet = accountSet + 1;
		Raccount->account.id = accountSet;
		Raccount->account.type = 1;
		Runit = makeUnitNode({});
		Runit->unitInfomation.id = accountSet;

		strcpy_s(Runit->unitInfomation.leaderName, __T(gtk_entry_get_text(GTK_ENTRY(nameInput16))));
		strcpy_s(Runit->unitInfomation.leaderContact, __T(gtk_entry_get_text(GTK_ENTRY(contactInput16))));

		strcpy_s(Runit->unitInfomation.leaderIntro, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput16))));

		gtk_container_remove(GTK_CONTAINER(window), fixed);
		create_UR();
	}
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
	initialWindow(fixed);

	//以下控件的设置方法相同，先得到控件，然后设置大小
	nameLabel = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 200, 40);

	nameInput16 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput16), 400, 40);

	contactLabel = gtk_label_new(_T("联系方式"));
	gtk_widget_set_size_request(GTK_WIDGET(contactLabel), 200, 40);

	contactInput16 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(contactInput16), 400, 40);

	introductionLabel = gtk_label_new(_T("个人简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	introductionInput16 = gtk_text_view_new();
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput16), GTK_WRAP_CHAR);
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput16), 600, 100);

	returnbn = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(returnbn), _T("返回"));
	gtk_widget_set_size_request(GTK_WIDGET(returnbn), 180, 40);
	//为"returnbn"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(returnbn), "clicked", G_CALLBACK(LR_to_R), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("下一步"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 180, 40);
	//为"next"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(LR_to_UR), NULL);

	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput16, 300, 180);
	gtk_fixed_put(GTK_FIXED(fixed), contactLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), contactInput16, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), introductionInput16, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), returnbn, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}