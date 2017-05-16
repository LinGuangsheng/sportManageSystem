#include <gtk\gtk.h>

#include <base.h>

#include <account.h>
#include <baseList.h>
#include <event.h>
#include <eventDetail.h>
#include <participants.h>
#include <unit.h>
#include <referee.h>

#include <test.h>

#include <commonFunction.h>
#include <preDefine.h>
#include <managerPreDefine.h>
#include <registerPredefine.h>

#include <unitPreDefine.h>
#include <unitNewPlayerAccount.h>
#include <leader.h>
#include <playerManage.h>
#include <playerInfoChange.h>
#include <teamInfoChange.h>
#include <addPlayer.h>
#include <athletePreDefine.h>
#include <itemInfo.h>
#include <athleteInfo.h>

#include <unitAccountRegister.h>
#include <refereeAccountRegister.h>
#include <eventInfoManage.h>
#include <manager.h>
#include <eventRegister.h>
#include <eventInfoChange.h>
#include <smInfoManage.h>
#include <changeLeader.h>
#include <changeAthlete.h>
#include <changeInstituteAthlete.h>
#include <checkInformation.h>
#include <changeInstitute.h>
#include <instituteRegister.h>
#include <leaderRegister.h>
#include <instituteManage.h>
#include <checkRefereeInfo.h>
#include <refereeInfoManage.h>
#include <setRefereeInfo.h>
#include <addReferee.h>

#include <refereePredefine.h>

#include <initReferee.h>




#include <athleteRegister.h>

#include <login.h>
#include <registration.h>
#include <leaderR.h>
#include <refereeR.h>
#include <unitRegister.h>

#include <teamPerformanceCheck.h>
#include <checkSportMeetingInformation.h>

#include <unitSMcheck.h>

#include <athleteCheckSM.h>

#include <refereeCHeckSM.h>
#include <checkScore.h>
#include <checkBook.h>









void storeData(){
	s.accountSize = accountlist->size;
	s.eventSize = eventlist->size;
	s.participantSize = parlist->size;
	s.refereeSize = refereelist->size;
	s.unitSize = unitlist->size;
	FILE *fp;
	fopen_s(&fp, "base/Manager", "wb");
	fwrite(&m, sizeof(Manager), 1, fp);
	fclose(fp);
	fopen_s(&fp, "base/sportInfo", "wb");
	fwrite(&sInfo, sizeof(sportInfo), 1, fp);
	fclose(fp);
	fopen_s(&fp, "base/size", "wb");
	fwrite(&s, sizeof(size), 1, fp);
	fclose(fp);
	fopen_s(&fp, "base/accountSet", "wb");
	fwrite(&accountSet, sizeof(int), 1, fp);
	fclose(fp);
	fopen_s(&fp, "base/eventSet", "wb");
	fwrite(&eventSet, sizeof(int), 1, fp);
	fopen_s(&fp, "base/flag", "wb");
	fwrite(&flag, sizeof(int), 1, fp);
	fclose(fp);
	//save account
	saveIntoFile(accountlist);
	saveEvent(eventlist);
	saveParticipant(parlist);
	saveReferee(refereelist);
	saveUnit(unitlist);
}

void getData(){
	FILE *fp;
	fopen_s(&fp, "base/Manager", "rb");
	fread(&m, sizeof(Manager), 1, fp);
	fclose(fp);
	fopen_s(&fp, "base/sportInfo", "rb");
	fread(&sInfo, sizeof(sportInfo), 1, fp);
	fclose(fp);
	fopen_s(&fp, "base/size", "rb");
	fread(&s, sizeof(size), 1, fp);
	fclose(fp);
	fopen_s(&fp, "base/accountSet", "rb");
	fread(&accountSet, sizeof(int), 1, fp);
	fclose(fp);
	fopen_s(&fp, "base/eventSet", "rb");
	fread(&eventSet, sizeof(int), 1, fp);
	fclose(fp);
	fopen_s(&fp, "base/flag", "rb");
	fread(&flag, sizeof(int), 1, fp);
	printf("%d", flag);
	fclose(fp);
	accountlist = getAcountFromFile();
	eventlist = getEvent();
	parlist = getParticipant();
	refereelist = getReferee();
	unitlist = getUnit();
}



int deleteWindow(){
	storeData();
	return FALSE;
}

int deleteWindow_noStore(){
	return FALSE;
}



void show_whetherStore()
{
	//弹出框
	GtkWidget *dialog;
		dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK_CANCEL, _T("是否保存修改？"), "title");

		gtk_window_set_title(GTK_WINDOW(dialog), _T("注意"));


		gint response = gtk_dialog_run(GTK_DIALOG(dialog));
		if (response == GTK_RESPONSE_OK)
		{
			printf("clicked");
			//这里写gettext代码
			gtk_widget_destroy(dialog);
			deleteWindow();

		}
		if (response == GTK_RESPONSE_CANCEL)
		{
			gtk_widget_destroy(dialog);
			deleteWindow_noStore();
		}
		
}





static void activate(GtkApplication* app, gpointer user_Data){
	//设置窗口，辩题和大小
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Sport");
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
	//窗口不可改变
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
	/*
	* 设置窗口在显示器中的位置为居中。
	*   GTK_WIN_POS_NONE            ：不固定
	*   GTK_WIN_POS_CENTER          : 居中
	*   GTK_WIN_POS_MOUSE           : 出现在鼠标位置
	*   GTK_WIN_POS_CENTER_ALWAYS   : 窗口改变大小的时候仍然居中
	*/
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(show_whetherStore), NULL);
	initLoginWindow();
}

//addAccountNode(accountlist, accountnode1);

//main方法中的代码从官方文档拷贝而来，都是相同的
int main(int argc, char **argv){
	getData();

	printf("%d", flag);

	GtkApplication *app;
	int status;

	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}
