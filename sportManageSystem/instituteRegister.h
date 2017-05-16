#include <gtk\gtk.h>


GtkWidget *nameInput9;
GtkWidget *sloganInput9;
GtkWidget *introductionInput9;

void show_inputUnitName()
{
	//弹出框
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("请输入参赛单位名称"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}


//从参赛单位注册界面跳转到参赛单位管理界面
void instituteRegister_to_instituteManage(GtkWidget *button, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(nameInput9))), "") == 0){
		//提示必须输入参赛单位的名字
		show_inputUnitName();
	}
	else{
		strcpy_s(MunitRegisterNode->unitInfomation.unitName, __T(gtk_entry_get_text(GTK_ENTRY(nameInput9))));
		strcpy_s(MunitRegisterNode->unitInfomation.unitSolgan, __T(gtk_entry_get_text(GTK_ENTRY(sloganInput9))));
		strcpy_s(MunitRegisterNode->unitInfomation.unitIntroduction, __T(getTextFromTextview(GTK_TEXT_VIEW(introductionInput9))));
		addAccountNode(accountlist, MunitAccount);
		addUnitNode(unitlist, MunitRegisterNode);
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		instituteManage();
	}
}

//从参赛单位注册界面跳转到领队注册界面
void instituteRegister_to_leaderRegister(GtkWidget *button, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	leaderRegister();
}

//参赛单位注册界面
void instituteRegister(){

	//定义各种组件

	GtkWidget *scrolledWindow;

	//定义名称的label和entry
	GtkWidget *nameLabel;

	//定义口号的label和entry
	GtkWidget *sloganLabel;

	//定义简介的label和entry
	GtkWidget *introductionLabel;

	//定义确定和返回按钮
	GtkWidget *cancel;
	GtkWidget *confirm;


	//得到fixed布局，并初始化窗口
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//设置返回和确定按钮
	cancel = gtk_button_new_with_label(_T("上一步"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(instituteRegister_to_leaderRegister), NULL);

	confirm = gtk_button_new_with_label(_T("完成"));
	gtk_widget_set_size_request(GTK_WIDGET(confirm), 220, 40);
	g_signal_connect_swapped(G_OBJECT(confirm), "clicked", G_CALLBACK(instituteRegister_to_instituteManage), NULL);

	//设置名称的label和entry
	nameLabel = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);

	nameInput9 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput9), 480, 40);

	//设置口号的label和entry
	sloganLabel = gtk_label_new(_T("口号"));
	gtk_widget_set_size_request(GTK_WIDGET(sloganLabel), 100, 40);

	sloganInput9 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(sloganInput9), 480, 40);

	//设置简介的label和entry
	introductionLabel = gtk_label_new(_T("简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 600, 40);

	introductionInput9 = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput9), 600, 100);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput9), GTK_WRAP_CHAR);


	//新建一个scrolled组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 100);

	//将各组件添加到fixed布局上
	gtk_fixed_put(GTK_FIXED(fixed), nameLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), nameInput9, 220, 180);
	gtk_fixed_put(GTK_FIXED(fixed), sloganLabel, 100, 240);
	gtk_fixed_put(GTK_FIXED(fixed), sloganInput9, 220, 240);
	gtk_fixed_put(GTK_FIXED(fixed), introductionLabel, 100, 300);
	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 340);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), confirm, 440, 520);

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), introductionInput9);

	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//显示
	gtk_widget_show_all(window);
}
