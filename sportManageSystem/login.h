#include<gtk\gtk.h>
#include<string.h>

//登录框控件结构体
struct loginEntry0{
	GtkWidget *usernameInput;
	GtkWidget *passwordInput;
};

//登录框控件
loginEntry0 loginWidget0;


/*
*	功能：弹出登录失败信息框
*/
void show_loginFailed()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("请检查用户名或密码"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("登陆失败"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

/*
*功能：login按钮回调
*判断是否登录成功并跳转界面或弹出失败信息
*/
void loginWindow_to_athleteInfo(GtkWidget *button, gpointer data){
	loginEntry0 *login = (loginEntry0*)data;
	loginEntry0 loginValue = *login;

	const gchar *usernametext = gtk_entry_get_text(GTK_ENTRY(loginValue.usernameInput));
	const gchar *passwordtext = gtk_entry_get_text(GTK_ENTRY(loginValue.passwordInput));

	accountNode *node = getAccountNodeByNameAndPasswd(accountlist, __T(usernametext), __T(passwordtext));
	if (node == NULL){
		printf("failed");
		show_loginFailed();
	}
	else{
		int type = node->account.type;
		printf("%d\n", type);
		//show_loginFailed();
		if (type == 0){
			gtk_container_remove(GTK_CONTAINER(window), fixed);
			managerAccount = node;
			manager();
		}
		else if (type == 1){
			gtk_container_remove(GTK_CONTAINER(window), fixed);

			unit_node = getUnitNodeByID(unitlist, node->account.id);
			leader();
		}
		else if (type == 2){
			gtk_container_remove(GTK_CONTAINER(window), fixed);
			referee_node = getRefereeNodeByID(refereelist, node->account.id);
			initReferee();
		}
		else if (type == 3){
			gtk_container_remove(GTK_CONTAINER(window), fixed);
			par_node = getParticipantNodeByID(parlist, node->account.id);
			initAthleteInfoWindow();
		}
	}
}

void login_to_register(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	registration();
}


void initLoginWindow(){
	GtkWidget *bgImage;  //背景图片
	GtkWidget *loginBox; //登录框
	GtkWidget *authorTitle;	//作者小字图片
	GtkWidget *loginButton; //登录按钮
	GtkWidget *registerButton; //注册按钮

	loginWidget0.usernameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(loginWidget0.usernameInput), 190, 30);

	loginWidget0.passwordInput = gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(loginWidget0.passwordInput), FALSE);
	gtk_widget_set_size_request(GTK_WIDGET(loginWidget0.passwordInput), 190, 30);

	authorTitle = gtk_image_new_from_file("author.png");
	loginBox = gtk_image_new_from_file("login.png");
	bgImage = gtk_image_new_from_file("backgroundImage.png");

	loginButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(loginButton), _T("登陆"));
	gtk_widget_set_size_request(GTK_WIDGET(loginButton), 240, 30);
	g_signal_connect(G_OBJECT(loginButton), "clicked", G_CALLBACK(loginWindow_to_athleteInfo), &loginWidget0);

	registerButton = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(registerButton), _T("注册新用户"));
	gtk_widget_set_size_request(GTK_WIDGET(registerButton), 70, 20);
	g_signal_connect(G_OBJECT(registerButton), "clicked", G_CALLBACK(login_to_register), NULL);
	gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("logo.png"));
	gtk_widget_set_size_request(GTK_WIDGET(authorTitle), 160, 15);
	gtk_widget_set_size_request(GTK_WIDGET(loginBox), 320, 400);
	gtk_widget_set_size_request(GTK_WIDGET(bgImage), 800, 600);

	fixed = gtk_fixed_new();
	gtk_fixed_put(GTK_FIXED(fixed), bgImage, 0, 0);
	gtk_fixed_put(GTK_FIXED(fixed), authorTitle, 320, 573);
	gtk_fixed_put(GTK_FIXED(fixed), loginBox, 253, 98);
	gtk_fixed_put(GTK_FIXED(fixed), loginWidget0.usernameInput, 347, 250);
	gtk_fixed_put(GTK_FIXED(fixed), loginWidget0.passwordInput, 347, 305);
	gtk_fixed_put(GTK_FIXED(fixed), loginButton, 297, 373);
	gtk_fixed_put(GTK_FIXED(fixed), registerButton, 365, 440);
	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);
}