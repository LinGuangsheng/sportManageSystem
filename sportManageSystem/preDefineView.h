#ifndef __PREDEFINEVIEW_H__
#define __PREDEFINEVIEW_H__

#include <gtk/gtk.h>

//界面生成函数
void create_registration_window();
void create_AR_window();
void create_AtR_window();
void create_LR_window();
void create_RR_window();
void create_UR_window();
void create_RIM_window();
void create_SRI_window();
void create_CRI_window();
void create_CkRI_window();

//界面跳转函数
void R_to_AR(GtkWidget *widget, gpointer data);
void R_to_AtR(GtkWidget *widget, gpointer data);
void R_to_LR(GtkWidget *widget, gpointer data);
void R_to_RR(GtkWidget *widget, gpointer data);
void cb_cancel(GtkWidget *widget, gpointer data);
void cb_next(GtkWidget *widget, gpointer data);
void AR_to_R(GtkWidget *widget, gpointer data);
void AtR_to_R(GtkWidget *widget, gpointer data);
void LR_to_R(GtkWidget *widget, gpointer data);
void LR_to_UR(GtkWidget *widget, gpointer data);
void RR_to_R(GtkWidget *widget, gpointer data);
void UR_to_RR(GtkWidget *widget, gpointer data);
void RIM_to_CRI(GtkWidget *widget, gpointer data);
void RIM_to_CkRI(GtkWidget *widget, gpointer data);
void SRI_to_RIM(GtkWidget *widget, gpointer data);
void CRI_to_RIM(GtkWidget *widget, gpointer data);
void CkRI_to_RIM(GtkWidget *widget, gpointer data);

#endif