#include <gtk\gtk.h>



void checkInformation(){

	GtkWidget *nameLabel;
	GtkWidget *nameInput;

	GtkWidget *holderLable;
	GtkWidget *holderInput;

	GtkWidget *timeLabel;
	GtkWidget *timeInput;

	GtkWidget *placeLabel;
	GtkWidget *placeInput;

	GtkWidget *introductionLabel;
	GtkWidget *introductionInput;

	GtkWidget *fixedSub;

	GtkWidget *scrolledWindow2;

	nameLabel = gtk_label_new(_T("名称"));
	gtk_widget_set_size_request(GTK_WIDGET(nameLabel), 100, 40);
	nameInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(nameInput), 180, 40);

	holderLable = gtk_label_new(_T("主办方"));
	gtk_widget_set_size_request(GTK_WIDGET(holderLable), 100, 40);
	holderInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(holderInput), 180, 40);

	timeLabel = gtk_label_new(_T("时间"));
	gtk_widget_set_size_request(GTK_WIDGET(timeLabel), 100, 40);
	timeInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(timeInput), 180, 40);

	placeLabel = gtk_label_new(_T("地点"));
	gtk_widget_set_size_request(GTK_WIDGET(placeLabel), 100, 40);
	placeInput = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(placeInput), 180, 40);


	introductionLabel = gtk_label_new(_T("运动会简介"));
	gtk_widget_set_size_request(GTK_WIDGET(introductionLabel), 280, 40);

	introductionInput = gtk_text_view_new();
	gtk_widget_set_size_request(GTK_WIDGET(introductionInput), 280, 180);
	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(introductionInput), GTK_WRAP_CHAR);
	setTextToTextview(GTK_TEXT_VIEW(introductionInput), sInfo.introduction);

	//新建一个scrolled组件
	scrolledWindow2 = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow2), 280, 180);

	fixed = gtk_fixed_new();

	initialWindow(fixed);

	fixedSub = gtk_fixed_new();

	GtkWidget *instituteListLabel;
	GtkWidget *instituteListName;
	GtkWidget *instituteListPNum;
	GtkWidget *instituteListANum;
	GtkWidget *instituteListOperate;

	GtkWidget *instituteListGrid;

	instituteListLabel = gtk_label_new(_T("参赛单位"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListLabel), 600, 40);
	instituteListName = gtk_label_new(_T("单位名称"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListName), 170, 40);
	instituteListPNum = gtk_label_new(_T("参加项目数"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListPNum), 170, 40);
	instituteListANum = gtk_label_new(_T("参加人数"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListANum), 170, 40);
	instituteListOperate = gtk_label_new(_T("操作"));
	gtk_widget_set_size_request(GTK_WIDGET(instituteListOperate), 90, 40);

	instituteListGrid = gtk_grid_new();

	gtk_grid_attach(GTK_GRID(instituteListGrid), instituteListLabel, 0, 0, 600, 40);
	gtk_grid_attach(GTK_GRID(instituteListGrid), instituteListName, 0, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(instituteListGrid), instituteListPNum, 170, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(instituteListGrid), instituteListANum, 340, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(instituteListGrid), instituteListOperate, 510, 40, 90, 40);

	int n = 10;

	for (int i = 0; i < n; i++){
		GtkWidget *name = gtk_label_new(_T("DW0"));
		gtk_widget_set_size_request(GTK_WIDGET(name), 170, 40);
		GtkWidget *PNum = gtk_label_new(_T("DW0"));
		gtk_widget_set_size_request(GTK_WIDGET(PNum), 170, 40);
		GtkWidget *ANum = gtk_label_new(_T("DW0"));
		gtk_widget_set_size_request(GTK_WIDGET(ANum), 170, 40);
		GtkWidget *operate = gtk_button_new_with_label(_T("查看"));
		gtk_widget_set_size_request(GTK_WIDGET(operate), 90, 40);

		gtk_grid_attach(GTK_GRID(instituteListGrid), name, 0, 80 + i * 40, 170, 40);
		gtk_grid_attach(GTK_GRID(instituteListGrid), PNum, 170, 80 + i * 40, 170, 40);
		gtk_grid_attach(GTK_GRID(instituteListGrid), ANum, 340, 80 + i * 40, 170, 40);
		gtk_grid_attach(GTK_GRID(instituteListGrid), operate, 510, 80 + i * 40, 90, 40);
	}


	GtkWidget *itemListLabel;
	GtkWidget *itemListName;
	GtkWidget *itemListTime;
	GtkWidget *itemListPlace;
	GtkWidget *itemListOperate;

	GtkWidget *itemListGrid;

	itemListLabel = gtk_label_new(_T("运动会项目"));
	gtk_widget_set_size_request(GTK_WIDGET(itemListLabel), 600, 40);
	itemListName = gtk_label_new(_T("项目名称"));
	gtk_widget_set_size_request(GTK_WIDGET(itemListName), 170, 40);
	itemListTime = gtk_label_new(_T("时间"));
	gtk_widget_set_size_request(GTK_WIDGET(itemListTime), 170, 40);
	itemListPlace = gtk_label_new(_T("地点"));
	gtk_widget_set_size_request(GTK_WIDGET(itemListPlace), 170, 40);
	itemListOperate = gtk_label_new(_T("操作"));
	gtk_widget_set_size_request(GTK_WIDGET(itemListOperate), 90, 40);

	itemListGrid = gtk_grid_new();

	gtk_grid_attach(GTK_GRID(itemListGrid), itemListLabel, 0, 0, 600, 40);
	gtk_grid_attach(GTK_GRID(itemListGrid), itemListName, 0, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(itemListGrid), itemListTime, 170, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(itemListGrid), itemListPlace, 340, 40, 170, 40);
	gtk_grid_attach(GTK_GRID(itemListGrid), itemListOperate, 510, 40, 90, 40);


	for (int i = 0; i < 10; i++){
		GtkWidget *name = gtk_label_new(_T("DW0"));
		gtk_widget_set_size_request(GTK_WIDGET(name), 170, 40);
		GtkWidget *time = gtk_label_new(_T("DW0"));
		gtk_widget_set_size_request(GTK_WIDGET(time), 170, 40);
		GtkWidget *place = gtk_label_new(_T("DW0"));
		gtk_widget_set_size_request(GTK_WIDGET(place), 170, 40);
		GtkWidget *operate = gtk_button_new_with_label(_T("查看"));
		gtk_widget_set_size_request(GTK_WIDGET(operate), 90, 40);

		gtk_grid_attach(GTK_GRID(itemListGrid), name, 0, 80 + i * 40, 170, 40);
		gtk_grid_attach(GTK_GRID(itemListGrid), time, 170, 80 + i * 40, 170, 40);
		gtk_grid_attach(GTK_GRID(itemListGrid), place, 340, 80 + i * 40, 170, 40);
		gtk_grid_attach(GTK_GRID(itemListGrid), operate, 510, 80 + i * 40, 90, 40);
	}

	gtk_fixed_put(GTK_FIXED(fixedSub), nameLabel, 0, 0);
	gtk_fixed_put(GTK_FIXED(fixedSub), nameInput, 100, 0);

	gtk_fixed_put(GTK_FIXED(fixedSub), holderLable, 0, 60);
	gtk_fixed_put(GTK_FIXED(fixedSub), holderInput, 100, 60);

	gtk_fixed_put(GTK_FIXED(fixedSub), timeLabel, 0, 120);
	gtk_fixed_put(GTK_FIXED(fixedSub), timeInput, 100, 120);

	gtk_fixed_put(GTK_FIXED(fixedSub), placeLabel, 0, 180);
	gtk_fixed_put(GTK_FIXED(fixedSub), placeInput, 100, 180);


	gtk_fixed_put(GTK_FIXED(fixedSub), introductionLabel, 320, 0);
	gtk_fixed_put(GTK_FIXED(fixedSub), scrolledWindow2, 320, 40);

	gtk_fixed_put(GTK_FIXED(fixedSub), instituteListGrid, 0, 260);

	gtk_fixed_put(GTK_FIXED(fixedSub), itemListGrid, 0, 300 + 40 * (n + 2));

	GtkWidget *scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrolledWindow), 600, 460);

	gtk_container_add(GTK_CONTAINER(scrolledWindow), fixedSub);

	gtk_fixed_put(GTK_FIXED(fixed), scrolledWindow, 100, 140);

	//将textView添加到scrolled容器中
	gtk_container_add(GTK_CONTAINER(scrolledWindow2), introductionInput);

	gtk_container_add(GTK_CONTAINER(window), fixed);
	//显示
	gtk_widget_show_all(window);
}