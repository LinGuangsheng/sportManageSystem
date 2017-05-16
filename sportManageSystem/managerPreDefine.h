#include <gtk\gtk.h>
//因为在跳转的过程中，可能B中调用A，A中又要调用B，而C语言要求使用函数前，必须先定义函数，所以先把函数定义好（函数内容可以先不理）
//这些是界面生成函数

void newPlayer();
void manager();
void eventInfoChange();
void eventCheck();
void eventInfoManage();
void eventRegister();
void smInfoManage();


void instituteManage();

void leaderRegister();

void instituteRegister();


void changeInstitute();

void changeAthlete();



void changeLeader();

//void checkWindow();

void changeInstituteAthlete();


void McheckWindow_to_manager(GtkWidget *button, gpointer data);

void McheckWindow();

void manager_to_McheckWindow();


void create_CkRI_window();

void create_RIM_window();

void create_SRI_window();

void addReferee();

void create_registration_window();

void create_refereeRegistration_window();

//这些事界面跳转函数（参数是固定的）
void eventRegisterCancel();
void manager_to_eventInfoManage(GtkWidget *button, gpointer data);

void checkWindow_to_manager(GtkWidget *button, gpointer data);

void changeAthlete_cancel(GtkWidget *button, gpointer data);

void cb_cancel(GtkWidget *widget, gpointer data);

void cb_next(GtkWidget *widget, gpointer data);

void addNewEvent(GtkWidget *button, gpointer data);
void addRefereeEvent(GtkWidget *widget, gpointer data);

void refereeCancel(GtkWidget *widget, gpointer data);

void deleteUnit(GtkWidget *button, gpointer data);
void manager_to_smInfoManage(GtkWidget *button, gpointer data);
void smInfoManage_to_eventInfoChange(GtkWidget *button, gpointer data);
void smInfoManage_to_manager(GtkWidget *button, gpointer data);
void eventInfoManage_to_newPlayer(GtkWidget *button, gpointer data);
void eventInfoManage_to_eventRegister(GtkWidget *button, gpointer data);
void eventInfoManage_to_eventInfoChange(GtkWidget *button, gpointer data);
void newPlayer_to_manager(GtkWidget *button, gpointer data);
void newPlayer_to_eventInfoChange(GtkWidget *button, gpointer data);


void changeInstitute_cancel(GtkWidget *button, gpointer data);

void deleteRefereeEvent(GtkWidget *widget, gpointer data);

void instituteManage_to_changeInstitute(GtkWidget *button, gpointer data);

void instituteManage_to_leaderRegister(GtkWidget *button, gpointer data);

void leaderRegister_to_instituteRegister(GtkWidget *button, gpointer data);

void instituteRegister_to_leaderRegister(GtkWidget *button, gpointer data);

void leaderRegister_to_instituteManage(GtkWidget *button, gpointer data);


void changeInstitute_to_instituteManage(GtkWidget *button, gpointer data);


void instituteRegister_to_instituteManage(GtkWidget *button, gpointer data);


void changeInstitute_to_changeLeader(GtkWidget *button, gpointer data);

void changeLeader_to_changeInstitute(GtkWidget *button, gpointer data);

void changeInstitute_to_changeInstituteAthlete(GtkWidget *button, gpointer data);

void changeInstituteAthlete_to_changeInstitute(GtkWidget *button, gpointer data);

void changeAthlete_to_changeInstituteAthlete(GtkWidget *button, gpointer data);

void instituteManage_to_manage(GtkWidget *button, gpointer data);

void manage_to_instituteManage(GtkWidget *button, gpointer data);


void CkRI_to_RIM(GtkWidget *widget, gpointer data);

void RIM_to_CRI(GtkWidget *widget, gpointer data);

void RIM_to_CkRI(GtkWidget *widget, gpointer data);

void SRI_to_RIM(GtkWidget *widget, gpointer data);
//返回
void eventInfoManage_to_manager(GtkWidget *button, gpointer data);
void smInfoManage_to_manager(GtkWidget *button, gpointer data);
void eventInfoChange_to_smInfoManage(GtkWidget *button, gpointer data);
void newPlayer_to_eventInfoManage(GtkWidget *button, gpointer data);
void eventRegister_to_eventInfoManage(GtkWidget *button, gpointer data);
void eventInfoChange_to_eventInfoManage(GtkWidget *button, gpointer data);
void eventInfoChange_to_manager(GtkWidget *button, gpointer data);

void eventCheck_to_eventInfoManage_cancel(GtkWidget *button, gpointer data);
void eventCheck_deleteParticipant(GtkWidget *button, gpointer data);

void deleteRefereeEvent(GtkWidget *widget, gpointer data);

void deleteEvent(GtkWidget *button, gpointer data);

void participantDeleteEvent(GtkWidget *button, gpointer data);

void smInfoManage_to_manager_cancel();

void instituteManage_to_changeInstitute(GtkWidget *button, gpointer data);

void RIM_to_Manage(GtkWidget *widget, gpointer data);

void RIM_to_addReferee(GtkWidget *widget, gpointer data);

void refereeR_cancel(GtkWidget *widget, gpointer data);

void refereeR_next(GtkWidget *widget, gpointer data);

void Mshow_changeFailed();

unitNode *MunitNode = makeUnitNode({ "", "", "", "", "", "", 0, 0 });

participantNode *MpartNode = makeParticipantNode({ "", "", "", "", 0, 0 });

eventNode *Mevent = makeEventNode({ "", "", "", "","", 0, 0 });

refereeNode *Mreferee = makeRefereeNode({ "", "", "", 0, 0 });

unitNode *MunitRegisterNode = makeUnitNode({ "", "", "", "", "", "", 0, 0 });

refereeNode *MrefereeRegister = makeRefereeNode({ "", "", "", 0, 99 });

accountNode *MunitAccount = makeAccountNode({ 0, "", "", 4 });

accountNode *MrefereeAccount = makeAccountNode({ 0, "", "", 4 });

accountNode *managerAccount = makeAccountNode({ 0, "", "", 0 });