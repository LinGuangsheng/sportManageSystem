

void playerManage();

void leader();

void teamInfoChange();

void playerInfoChange();

void addPlayer();

void teamPerformanceCheck();

void teamInformChangeConfirm(GtkWidget *button, gpointer data);

void addPlayer_to_playerManage(GtkWidget *button, gpointer data);

void playerInfoChange_to_playerManage(GtkWidget *button, gpointer data);

void leader_to_playerManage(GtkWidget *button, gpointer data);

void playerManage_to_leader(GtkWidget *button, gpointer data);

void leader_to_teamInfoChange(GtkWidget *button, gpointer data);

void teamInfoChange_to_leader(GtkWidget *button, gpointer data);

void leader_to_checkSM(GtkWidget *button, gpointer data);

void UcheckWindow_to_manager(GtkWidget *button, gpointer data);

void UcheckWindow();

void leaderPasswordChange(GtkButton *button, gpointer   user_data);

void show_changeFailed();

void deleteParticipant(GtkWidget *button, gpointer data);


void leader_to_teamPerformanceCheck(GtkWidget *button, gpointer data);

unitNode  *unit_node = makeUnitNode({ "", "", "", "", "", "", 0, 0 });
participantNode *participant = makeParticipantNode({ "", "", "", "", 0, 0 });

participantNode *participantRegister = makeParticipantNode({ "", "", "", "", 0, 0 });

accountNode *accountR = makeAccountNode({});