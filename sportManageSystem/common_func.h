#ifndef __COMMON_FUNC_H__
#define __COMMON_FUNC_H__

#include <gtk/gtk.h>

//����window���ڣ���ȫ�ֱ�����һֱʹ��
GtkWidget *window = NULL;

//����fixed���֣���ȫ�ֱ�����һֱʹ��
GtkWidget *fixed = NULL;

//֧������
gchar* _T(char* str){
	return g_locale_to_utf8(str, -1, 0, 0, 0);
}

//GTKת����
char* __T(const gchar* str)
{
	return g_locale_from_utf8(str, -1, 0, 0, 0);
}

/*
@Description: ��һ��ͼƬ�л�ȡ��Ϣ�õ�pixbuf
@param:       gchar filename
*/
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



void initialWindow(){
	GtkWidget *bgImage;
	GtkWidget *logo;
	//��������ͼ���
	bgImage = gtk_image_new_from_file("backgroundImage.png");
	gtk_widget_set_size_request(GTK_WIDGET(bgImage), 800, 600);

	//����Logo���
	logo = gtk_image_new_from_file("logo.png");
	gtk_widget_set_size_request(GTK_WIDGET(logo), 160, 70);

	//fixed��ȫ�ֱ����������������ֱ��ʹ��
	gtk_fixed_put(GTK_FIXED(fixed), bgImage, 0, 0);

	gtk_fixed_put(GTK_FIXED(fixed), logo, 320, 30);
}

#endif