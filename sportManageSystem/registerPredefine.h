void registration();

void LR_to_R(GtkWidget *widget, gpointer data);
void LR_to_UR(GtkWidget *widget, gpointer data);
void create_LR_window();

void UR_to_LR(GtkWidget *widget, gpointer data);

void RR_to_Login(GtkWidget *widget, gpointer data);
void RR_to_R(GtkWidget *widget, gpointer data);

void create_RR_window();


void create_UR();



accountNode *Raccount = makeAccountNode({ 0, "", "", 4 });

unitNode * Runit = makeUnitNode({ "", "", "", "", "", "", 0, 0 });

refereeNode *Rreferee = makeRefereeNode({ "", "", "", 0, 99 });

participantNode *Rparticipant = makeParticipantNode({ "", "", "", "", 0, 0 });


