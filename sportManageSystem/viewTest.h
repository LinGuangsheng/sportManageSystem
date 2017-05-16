void test(){
	GtkWidget *scrollView;
	GtkWidget *subFixed;


	fixed = gtk_fixed_new();
	subFixed = gtk_fixed_new();

	scrollView = gtk_scrolled_window_new(NULL,NULL);
	gtk_widget_set_size_request(GTK_WIDGET(scrollView), 600, 300);

	gtk_container_add(GTK_CONTAINER(scrollView), subFixed);


	gtk_fixed_put(GTK_FIXED(fixed), scrollView, 100, 180);

	gtk_container_add(GTK_CONTAINER(window), fixed);
	//œ‘ æ
	gtk_widget_show_all(window);

}