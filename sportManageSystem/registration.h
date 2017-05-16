
#include <gtk/gtk.h>
#include <string.h>
gchar *active;
GtkWidget *userTypeInput;
GtkTreeModel *combobox_treemodel;
GtkTreeIter iter;


GtkWidget *userInput13;
GtkWidget *passwdInput13;

void show_registerExist()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("���û����Ѵ��ڣ������"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��ʧ��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}


void show_registerAccount()
{
	//������
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
		GTK_BUTTONS_OK, _T("�������û���������"), "title");

	gtk_window_set_title(GTK_WINDOW(dialog), _T("ע��"));

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}


//��ť"cancel"�Ļص�����
void R_cancel(GtkWidget *widget, gpointer data){
	gtk_container_remove(GTK_CONTAINER(window), fixed);
	initLoginWindow();
}

// ��ť"next"�Ļص�����
void R_next(GtkWidget *widget, gpointer data){
	if (strcmp(__T(gtk_entry_get_text(GTK_ENTRY(userInput13))), "") == 0 || strcmp(__T(gtk_entry_get_text(GTK_ENTRY(passwdInput13))), "") == 0){
		//�����˵ĶԻ���
		show_inputUnitAccount();
	}
	else if (getAccountNodeByName(accountlist, __T(gtk_entry_get_text(GTK_ENTRY(userInput13)))) != NULL){
		//�����˺��Ѿ����ڵ���ʾ
		show_unitAccountExist();
	}
	else{

		Raccount = makeAccountNode({});
		strcpy_s(Raccount->account.name, __T(gtk_entry_get_text(GTK_ENTRY(userInput13))));
		strcpy_s(Raccount->account.passwd, __T(gtk_entry_get_text(GTK_ENTRY(passwdInput13))));


		combobox_treemodel = gtk_combo_box_get_model(GTK_COMBO_BOX(userTypeInput));
		gtk_combo_box_get_active_iter(GTK_COMBO_BOX(userTypeInput), &iter);
		gtk_tree_model_get(combobox_treemodel, &iter, 1, &active, -1);
		gtk_container_remove(GTK_CONTAINER(window), fixed);
		if (strcmp(active, _T("����Ա")) == 0){
			printf_s(active);
			create_RR_window();
		}
		else if (strcmp(active, _T("���")) == 0){
			printf_s(active);
			create_LR_window();
		}
		else{
			printf_s(active);
			create_AtR_window();
		}
	}
}


void registration(){

	//������ؿؼ�
	GtkWidget *userLabel;
	GtkWidget *passwdLabel;
	GtkWidget *userTypeLabel;
	GtkWidget *next;
	GtkWidget *cancel;
	GtkWidget *combobox;
	GtkTreeStore *store;

	GtkCellRenderer *renderer;


	//��������fixed���ֺͳ�ʼ��window
	fixed = gtk_fixed_new();
	initialWindow(fixed);

	//���¿ؼ������÷�����ͬ���ȵõ��ؼ���Ȼ�����ô�С
	userLabel = gtk_label_new(_T("�û���"));
	gtk_widget_set_size_request(GTK_WIDGET(userLabel), 200, 40);

	userInput13 = gtk_entry_new();
	gtk_widget_set_size_request(GTK_WIDGET(userInput13), 270, 40);

	passwdLabel = gtk_label_new(_T("����"));
	gtk_widget_set_size_request(GTK_WIDGET(passwdLabel), 200, 40);

	passwdInput13 = gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(passwdInput13), FALSE);

	gtk_widget_set_size_request(GTK_WIDGET(passwdInput13), 270, 40);

	userTypeLabel = gtk_label_new(_T("�û�����"));
	gtk_widget_set_size_request(GTK_WIDGET(userTypeLabel), 200, 40);

	//ComboBox�ؼ�
	store = gtk_tree_store_new(2, GDK_TYPE_PIXBUF, G_TYPE_STRING);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter, 0, create_pixbuf(""), 1, _T("����Ա"), -1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter, 0, create_pixbuf(""), 1, _T("���"), -1);
	gtk_tree_store_append(store, &iter, NULL);
	gtk_tree_store_set(store, &iter, 0, create_pixbuf(""), 1, _T("����ѡ��"), -1);
	userTypeInput = gtk_combo_box_new_with_model(GTK_TREE_MODEL(store));
	gtk_widget_set_size_request(GTK_WIDGET(userTypeInput), 270, 40);


	// ����GtkTreeModel�е�ÿһ������������б������ʾ
	renderer = gtk_cell_renderer_pixbuf_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(userTypeInput), renderer, FALSE);
	gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(userTypeInput), renderer, "pixbuf", 0, NULL);
	renderer = gtk_cell_renderer_text_new();
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(userTypeInput), renderer, FALSE);
	gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(userTypeInput), renderer, "text", 1, NULL);
	gtk_combo_box_set_active(GTK_COMBO_BOX(userTypeInput), 0);

	cancel = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(cancel), _T("ȡ��"));
	gtk_widget_set_size_request(GTK_WIDGET(cancel), 180, 40);
	//Ϊ"cancel"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(cancel), "clicked", G_CALLBACK(R_cancel), NULL);

	next = gtk_button_new();
	gtk_button_set_label(GTK_BUTTON(next), _T("��һ��"));
	gtk_widget_set_size_request(GTK_WIDGET(next), 180, 40);
	//Ϊ"next"���ӡ������¼���Ҫ���õĻص�����
	g_signal_connect(G_OBJECT(next), "clicked", G_CALLBACK(R_next), NULL);

	//���������ӵ�fixed������
	gtk_fixed_put(GTK_FIXED(fixed), userLabel, 100, 180);
	gtk_fixed_put(GTK_FIXED(fixed), userInput13, 300, 180);
	gtk_fixed_put(GTK_FIXED(fixed), passwdLabel, 100, 280);
	gtk_fixed_put(GTK_FIXED(fixed), passwdInput13, 300, 280);
	gtk_fixed_put(GTK_FIXED(fixed), userTypeLabel, 100, 380);
	gtk_fixed_put(GTK_FIXED(fixed), userTypeInput, 300, 380);
	gtk_fixed_put(GTK_FIXED(fixed), cancel, 140, 520);
	gtk_fixed_put(GTK_FIXED(fixed), next, 440, 520);


	//�����ּ��ص�������
	gtk_container_add(GTK_CONTAINER(window), fixed);

	//��ʾ
	gtk_widget_show_all(window);
}
