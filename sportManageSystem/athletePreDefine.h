void initItemInfo();
void itemInfo_to_athleteInfo(GtkWidget *button, gpointer data);
void athleteInfo_to_itemInfo(GtkWidget *button, gpointer data);
void addNPewEvent(GtkWidget *button, gpointer data);
void initAthleteInfoWindow();

void AcheckWindow();

void AcheckWindow_to_manager(GtkWidget *button, gpointer data);
void athleteInfo_to_checkSM(GtkWidget *button, gpointer data);

void Ashow_changeFailed();

participantNode *par_node = makeParticipantNode({ "", "", "", "", 0, 0 });



//unitNode  *unit_node = makeUnitNode({ "", "", "", "", "", "", 0, 0 });
//participantNode *participant = makeParticipantNode({ "", "", "", "", 0, 0 });
//GtkWidget *playerSelect;