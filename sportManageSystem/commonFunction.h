#include <gtk/gtk.h>
GtkWidget *bgImage;
GtkWidget *logo;
GtkWidget *authorTitle;	//����С��ͼƬ
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
@Description: ��һ��ͼƬ�л�ȡ��Ϣ�õ�pixbuf
@param:       gchar filename
*/
void initialWindow(GtkWidget *fixed){

	authorTitle = gtk_image_new_from_file("author.png");

	//��������ͼ���
	bgImage = gtk_image_new_from_file("backgroundImage.png");
	gtk_widget_set_size_request(GTK_WIDGET(bgImage), 800, 600);

	//����Logo���
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
	* ����gdk_pixbuf_new_from_file() ��һ��ͼƬ�ļ��м���ͼ�����ݣ��Ӷ�����һ���µ� pixbuf��
	* �����ļ��а���ͼ��ĸ�ʽ������ϵͳ�Զ����ġ�����ú�������ֵ��NULL �Ļ�������ͻ���ִ���
	*/
	pixbuf = gdk_pixbuf_new_from_file(filename, &error);
	if (!pixbuf) {
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}
	return pixbuf;
}

/*
*	���ܣ���ȡtextview����
*	������GtkTextView *textview������textview
*	���أ�gchar�ַ���
*/
gchar *getTextFromTextview(GtkTextView *textview){
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);
	GtkTextIter start, end;
	gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer), &start, &end); //��ȡ����������ʼ�ͽ���λ��

	const GtkTextIter s = start, e = end;
	gchar *text = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer), &s, &e, true);

	g_print("%s\n", text);

	return text;
}

/*
*	���ܣ�����textview����
*	������GtkTextBuffer *textview������textview
*			gchar *text�� ���ô�����ַ���
*	���أ���
*/
void setTextToTextview(GtkTextView *textview, char *text){
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(textview);
	GtkTextIter start, end;
	gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer), &start, &end); //��ȡ����������ʼ�ͽ���λ��
	gchar *test = _T(text);
	gtk_text_buffer_set_text(buffer, test, strlen(test));
}