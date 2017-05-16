#include <gtk\gtk.h>
void newPlayer_to_manager(){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	manager();
}

void newPlayer_to_eventInfoChange(){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	eventInfoChange();
}

void newPlayer(){
	GtkWidget *playerUnitLabel;
	GtkWidget *playerUnitInput;
	GtkWidget *playerListLabel;
	GtkWidget *finish;
	GtkWidget *cancel;


	GtkWidget *facultyList;

	GtkWidget *facultyListTitle;
	GtkWidget *facultyListName;
	GtkWidget *facultyListItemNum;
	GtkWidget *facultyListXSN;
	GtkWidget *facultyListOperator;
	GtkWidget *scrolledWindow;


	//以下控件的设置方法相同，先得到控件，然后设置大小



	playerUnitLabel = gtk_label_new(_T("选手所属单位"));
	gtk_widget_set_size_request(GTK_WIDGET(playerUnitLabel), 140, 40);


	playerListLabel = gtk_label_new(_T("选手列表"));
	gtk_widget_set_size_request(GTK_WIDGET(playerListLabel), 600, 40);
	//加了这段上面那个就显示不出来了？

	//ComboBox控件
	playerUnitInput = gtk_combo_box_text_new();
	gtk_widget_set_size_request(GTK_WIDGET(playerUnitInput), 340, 40);

	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(playerUnitInput), _T("至诚书院"));
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(playerUnitInput), _T("弘毅书院"));
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(playerUnitInput), _T("思源书院"));
	gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(playerUnitInput), _T("知行书院"));



	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("取消"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 220, 40);
	g_signal_connect_swapped(G_OBJECT(cancel), "clicked", G_CALLBACK(newPlayer_to_eventInfoChange), NULL);


	finish = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(finish), _T("完成"));
	gtk_widget_set_size_request(GTK_WIDGET(finish), 220, 40);
	g_signal_connect_swapped(G_OBJECT(finish), "clicked", G_CALLBACK(newPlayer_to_eventInfoChange), NULL);


	facultyList = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(facultyList), 600, 300);



	facultyListName = gtk_label_new(_T("姓名"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListName), 130, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListName, 0, 40, 130, 40);

	facultyListItemNum = gtk_label_new(_T("年级专业"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListItemNum), 130, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListItemNum, 130, 40, 130, 40);


	facultyListOperator = gtk_label_new(_T("选择"));
	gtk_widget_set_size_request(GTK_WIDGET(facultyListOperator), 210, 40);
	gtk_grid_attach(GTK_GRID(facultyList), facultyListOperator, 260, 40, 210, 40);

	//新建一个scrolled组件
	scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 120);
	//新建一个gred布局，用于存放列表项
	GtkWidget *itemGrid = gtk_grid_new();
	gtk_widget_set_size_request(GTK_WIDGET(itemGrid), 600, 40);
	//通过循环，将列表项添加进itemGrid
	for (int i = 0; i < 9; i++){

		GtkWidget *facultyListName_i = gtk_label_new(_T("XM0"));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListName_i), 130, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListName_i, 0, i * 40, 130, 40);

		GtkWidget *facultyListItemNum_i = gtk_label_new(_T("P0"));
		gtk_widget_set_size_request(GTK_WIDGET(facultyListItemNum_i), 130, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), facultyListItemNum_i, 130, i * 40, 130, 40);


		GtkWidget *empty = gtk_label_new(_T(" "));
		gtk_widget_set_size_request(GTK_WIDGET(empty), 130, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), empty, 227, i * 40, 130, 40);



		//GtkWidget *deletes = gtk_button_new_with_label(_T("删除"));
		//gtk_widget_set_size_request(GTK_WIDGET(deletes), 70, 40);
		//gtk_grid_attach(GTK_GRID(itemGrid), deletes, 530, i * 40, 70, 40);

		GtkWidget *trigger = gtk_check_button_new();
		gtk_widget_set_size_request(GTK_WIDGET(trigger), 70, 40);
		gtk_grid_attach(GTK_GRID(itemGrid), trigger, 530, i * 40, 70, 40);

		//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolledWindow), itemGrid);
		//gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);
	}

	//将itemGrid添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow), itemGrid);

	gtk_grid_attach(GTK_GRID(facultyList), scrolledWindow, 0, 80, 600, 220);

	//得到fixed布局，并把控件部署上去
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	gtk_fixed_put(GTK_FIXED(fixed), facultyList, 160, 280);

	gtk_fixed_put(GTK_FIXED(fixed), playerUnitLabel, 160, 180);
	gtk_fixed_put(GTK_FIXED(fixed), playerUnitInput, 300, 180);

	gtk_fixed_put(GTK_FIXED(fixed), playerListLabel, 100, 240);

	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), finish, 440, 520);


	//将布局加载到窗口上
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);
}