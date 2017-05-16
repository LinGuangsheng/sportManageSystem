

#include <gtk/gtk.h>
#include <string.h>


GtkWidget *userInput111;
GtkWidget *passwdInput111;

// 按钮"cancel"的回调函数
void Ucb_cancel(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	playerManage();
}
void Ushow_unitAccountExist()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("该用户名已存在，请更换"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注册失败"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}


void Ushow_inputUnitAccount()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("请输入用户名和密码"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

// 按钮"next"的回调函数
void Ucb_next(GtkWidget *widget, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(userInput111))), "") == 0 || strcmp(__T(gtk_entry_get_text(GTK_ENTRY(passwdInput111))), "") == 0){
		//出错了的对话框
		Ushow_inputUnitAccount();
	}
	else if (getAccountNodeByName(accountlist, __T(gtk_entry_get_text(GTK_ENTRY(userInput111)))) != NULL){
		//给出账号已经存在的提示
		Ushow_unitAccountExist();
	}
	else{
		accountSet = accountSet + 1;
		participantInfo p = {};
		participantRegister = makeParticipantNode(p);
		accountInfo account = {};
		accountR = makeAccountNode(account);
		
		participantRegister->participantInfomation.id = (long)accountSet;
		accountR->account.id = (long)accountSet;

		strcpy_s(accountR->account.name, __T(gtk_entry_get_text(GTK_ENTRY(userInput111))));
		strcpy_s(accountR->account.passwd, __T(gtk_entry_get_text(GTK_ENTRY(passwdInput111))));

		accountR->account.type = 3;

		gtk_container_remove(GTK_CONTAINER(window), fixed);
		addPlayer();
	}
}


void Ucreate_registration_window(){

	//定义相关控件
	GtkWidget *userLabel;
	GtkWidget *passwdLabel;


	GtkWidget *next;
	GtkWidget *cancel;

	GtkCellRenderer *renderer;


	//重新生成fixed布局和初始化window
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//以下控件的设置方法相同，先得到控件，然后设置大小
	userLabel = gtk_label_new(_T("用户名"));
	gtk_widget_set_size_request(GTK_WIDGET(userLabel), 200, 40);

	userInput111 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(userInput111), 300, 40);

	passwdLabel = gtk_label_new(_T("密码"));
	gtk_widget_set_size_request(GTK_WIDGET(passwdLabel), 200, 40);

	passwdInput111 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(passwdInput111), 300, 40);
	gtk_entry_set_visibility(GTK_ENTRY(passwdInput111), FALSE);



	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("取消"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	//为"cancel"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(Ucb_cancel), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("下一步"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 220, 40);
	//为"next"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(Ucb_next), NULL);

	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), userLabel, 150, 240);
	gtk_fixed_put(GTK_FIXED(fixed), userInput111, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), passwdLabel, 150, 340);
	gtk_fixed_put(GTK_FIXED(fixed), passwdInput111, 300, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);


	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}
