#ifndef __COMMON_FUNC_H__
#define __COMMON_FUNC_H__

#include <gtk/gtk.h>

//设置window窗口，是全局变量，一直使用
GtkWidget *window = NULL;

//设置fixed布局，是全局变量，一直使用
GtkWidget *fixed = NULL;

//支持中文
gchar* _T(char* str){
	return g_locale_to_utf8(str, -1, 0, 0, 0);
}

//GTK转中文
char* __T(const gchar* str)
{
	return g_locale_from_utf8(str, -1, 0, 0, 0);
}

/*
@Description: 从一个图片中获取信息得到pixbuf
@param:       gchar filename
*/
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



void initialWindow(){
	GtkWidget *bgImage;
	GtkWidget *logo;
	//生产背景图组件
	bgImage = gtk_image_new_from_file("backgroundImage.png");
	gtk_widget_set_size_request(GTK_WIDGET(bgImage), 800, 600);

	//生产Logo组件
	logo = gtk_image_new_from_file("logo.png");
	gtk_widget_set_size_request(GTK_WIDGET(logo), 160, 70);

	//fixed是全局变量，所以这里可以直接使用
	gtk_fixed_put(GTK_FIXED(fixed), bgImage, 0, 0);

	gtk_fixed_put(GTK_FIXED(fixed), logo, 320, 30);
}

#endif