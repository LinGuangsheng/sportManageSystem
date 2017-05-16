
#include <gtk/gtk.h>
#include <string.h>


GtkWidget *userInput12;
GtkWidget *passwdInput12;

// 按钮"cancel"的回调函数
void refereeR_cancel(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	create_RIM_window();
}

void show_refereeAccountExist()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("该用户名已存在，请更换"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注册失败"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

void show_inputRefereeAccount()
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
void refereeR_next(GtkWidget *widget, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(userInput12))), "") == 0 || strcmp(__T(gtk_entry_get_text(GTK_ENTRY(passwdInput12))), "") == 0){
		//出错了的对话框
		show_inputRefereeAccount();
	}
	else if (getAccountNodeByName(accountlist, __T(gtk_entry_get_text(GTK_ENTRY(userInput12)))) != NULL){
		//给出账号已经存在的提示
		show_refereeAccountExist();
	}
	else{
		accountSet = accountSet + 1;
		refereeInfo referee = {};
		MrefereeRegister = makeRefereeNode(referee);
		accountInfo account = {};
		MrefereeAccount = makeAccountNode(account);
		MrefereeRegister->refereeInfomation.id = (long)accountSet;
		MrefereeAccount->account.id = (long)accountSet;
		strcpy_s(MrefereeAccount->account.name, __T(gtk_entry_get_text(GTK_ENTRY(userInput12))));
		strcpy_s(MrefereeAccount->account.passwd, __T(gtk_entry_get_text(GTK_ENTRY(passwdInput12))));
		MrefereeAccount->account.type = 2;
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		addReferee();
	}
}


void create_refereeRegistration_window(){

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

	userInput12 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(userInput12), 300, 40);

	passwdLabel = gtk_label_new(_T("密码"));
	gtk_widget_set_size_request(GTK_WIDGET(passwdLabel), 200, 40);

	passwdInput12 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(passwdInput12), 300, 40);
	gtk_entry_set_visibility(GTK_ENTRY(passwdInput12), FALSE);



	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("取消"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 120, 40);
	//为"cancel"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(refereeR_cancel), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("下一步"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 120, 40);
	//为"next"连接“单击事件”要调用的回调函数
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(refereeR_next), NULL);

	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), userLabel, 150, 240);
	gtk_fixed_put(GTK_FIXED(fixed), userInput12, 300, 240);
	gtk_fixed_put(GTK_FIXED(fixed), passwdLabel, 150, 340);
	gtk_fixed_put(GTK_FIXED(fixed), passwdInput12, 300, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);


	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}