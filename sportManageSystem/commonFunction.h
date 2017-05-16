#include <gtk/gtk.h>
GtkWidget *bgImage;
GtkWidget *logo;
GtkWidget *authorTitle;	//作者小字图片
GtkWidget *window = NULL;
GtkWidget *fixed = NULL;
gchar* _T(char* str)
{
	return g_locale_to_utf8(str, -1, 0, 0, 0);
}

char* __T(const gchar* str)
{
	return g_locale_from_utf8(str, -1, 0, 0, 0);
}

/*
@Description: 从一个图片中获取信息得到pixbuf
@param:       gchar filename
*/
void initialWindow(GtkWidget *fixed){

	authorTitle = gtk_image_new_from_file("author.png");

	//生产背景图组件
	bgImage = gtk_image_new_from_file("backgroundImage.png");
	gtk_widget_set_size_request(GTK_WIDGET(bgImage), 800, 600);

	//生产Logo组件
	logo = gtk_image_new_from_file("logo.png");
	gtk_widget_set_size_request(GTK_WIDGET(logo), 160, 70);

	gtk_fixed_put(GTK_FIXED(fixed), bgImage, 0, 0);

	gtk_fixed_put(GTK_FIXED(fixed), logo, 320, 30);


	gtk_fixed_put(GTK_FIXED(fixed), authorTitle, 320, 573);

}
GdkPixbuf *create_pixbuf(const gchar * filename)
{
	GdkPixbuf *pixbuf;
	GError *error = NULL;
	/*
	* 函数gdk_pixbuf_new_from_file() 从一个图片文件中加载图象数据，从而生成一个新的 pixbuf，
	* 至于文件中包含图象的格式，是由系统自动检测的。如果该函数返回值是NULL 的话，程序就会出现错误。
	*/
	pixbuf = gdk_pixbuf_new_from_file(filename, &error);
	if (!pixbuf) {
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}
	return pixbuf;
}

/*
*	功能：获取textview内容
*	参数：GtkTextView *textview，传入textview
*	返回：gchar字符串
*/
gchar *getTextFromTextview(GtkTextView *textview){
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);
	GtkTextIter start, end;
	gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer), &start, &end); //获取缓冲区的起始和结束位置

	const GtkTextIter s = start, e = end;
	gchar *text = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer), &s, &e, true);

	g_print("%s\n", text);

	return text;
}

/*
*	功能：设置textview内容
*	参数：GtkTextBuffer *textview，传入textview
*			gchar *text， 设置传入的字符串
*	返回：空
*/
void setTextToTextview(GtkTextView *textview, char *text){
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);
	GtkTextIter start, end;
	gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer), &start, &end); //获取缓冲区的起始和结束位置
	gchar *test = _T(text);
	gtk_text_buffer_set_text(buffer, test, strlen(test));
}