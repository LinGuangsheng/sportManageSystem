void initReferee();

refereeNode *referee_node = makeRefereeNode({ "", "", "", 0, 0 });

void Rshow_changeFailed();
void refereePasswordChange(GtkButton *button, gpointer   user_data);
void initReferee_to_checkSportMeetingInfomation(GtkButton *button, gpointer   user_data);

void RcheckWindow_to_manager(GtkWidget *button, gpointer data);

void RcheckWindow();

eventNode *Revent = makeEventNode({});

void checkRScore(GtkWidget *button, gpointer data);

void checkScore();