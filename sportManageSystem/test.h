accountList *accountlist = initAccountList();

accountInfo account0 = { 99999, "管理员", "123456", 0 };
accountNode *accountN0 = makeAccountNode(account0);

accountInfo account1 = { 1, "参赛选手1", "34", 3 };
accountNode *accountN1 = makeAccountNode(account1);

accountInfo account2 = { 2, "参赛选手2", "34", 3 };
accountNode *accountN2 = makeAccountNode(account2);

accountInfo account3 = { 3, "参赛选手3", "34", 3 };
accountNode *accountN3 = makeAccountNode(account3);

accountInfo account4 = { 4, "参赛选手4", "34", 3 };
accountNode *accountN4 = makeAccountNode(account4);
					 
accountInfo account5 = { 5, "参赛选手5", "34", 3 };
accountNode *accountN5 = makeAccountNode(account5);

accountInfo account6 = { 6, "参赛选手6", "34",  3};
accountNode *accountN6 = makeAccountNode(account6);

accountInfo account7 = { 7, "参赛选手7", "34", 3 };
accountNode *accountN7 = makeAccountNode(account7);

accountInfo account8 = { 8, "参赛选手8", "34", 3 };
accountNode *accountN8 = makeAccountNode(account8);
					 
accountInfo account9 = { 9, "参赛选手9", "34", 3 };
accountNode *accountN9 = makeAccountNode(account9);

accountInfo account10 = { 10, "参赛选手10", "34", 3 };
accountNode *accountN10 = makeAccountNode(account10);

accountInfo account11 = { 11, "领队11", "34", 1 };
accountNode *accountN11 = makeAccountNode(account11);

accountInfo account12 = { 12, "领队12", "34", 1 };
accountNode *accountN12 = makeAccountNode(account12);

accountInfo account13 = { 13, "裁判员13", "34", 2 };
accountNode *accountN13 = makeAccountNode(account13);

accountInfo account14 = { 14, "裁判员14", "34", 2 };
accountNode *accountN14 = makeAccountNode(account14);


participantInfo par1 = { "par1", "parIntro1", "parGradeandMajor1", "parcontact1", 0, 1, 11 };
participantNode *parN1 = makeParticipantNode(par1);

participantInfo par2 = { "par2", "parIntro2", "parGradeandMajor2", "parcontact2", 0, 2, 11 };
participantNode *parN2 = makeParticipantNode(par2);

participantInfo par3 = { "par3", "parIntro3", "parGradeandMajor3", "parcontact3", 0, 3, 11 };
participantNode *parN3 = makeParticipantNode(par3);

participantInfo par4 = { "par4", "parIntro4", "parGradeandMajor4", "parcontact4", 0, 4, 11 };
participantNode *parN4 = makeParticipantNode(par4);

participantInfo par5 = { "par5", "parIntro5", "parGradeandMajor5", "parcontact5", 0, 5, 11 };
participantNode *parN5 = makeParticipantNode(par5);

participantInfo par6 = { "par6", "parIntro6", "parGradeandMajor6", "parcontact6", 0, 6, 12 };
participantNode *parN6 = makeParticipantNode(par6);

participantInfo par7 = { "par7", "parIntro7", "parGradeandMajor7", "parcontact7", 0, 7, 12 };
participantNode *parN7 = makeParticipantNode(par7);

participantInfo par8 = { "par8", "parIntro8", "parGradeandMajor8", "parcontact8", 0, 8, 12 };
participantNode *parN8 = makeParticipantNode(par8);

participantInfo par9 = { "par9", "parIntro9", "parGradeandMajor9", "parcontact9", 0, 9, 12 };
participantNode *parN9 = makeParticipantNode(par9);

participantInfo par10 = { "par10", "parIntro10", "parGradeandMajor10", "parcontact10", 0, 10, 12 };
participantNode *parN10 = makeParticipantNode(par10);

unitInfo unit11 = { "leader11", "leaderIntro11", "leaderContact11", "unit11", "unitSlogon11", "unitIntro11", 0, 11 };
unitNode *unitN11 = makeUnitNode(unit11);

unitInfo unit12 = { "leader12", "leaderIntro12", "leaderContact12", "unit12", "unitSlogon12", "unitIntro12", 0, 12 };
unitNode *unitN12 = makeUnitNode(unit12);


eventInfo event1 = { "name1", "intro1", "rule1", "place1", "time1", 0,0,0, 1 };
eventNode *eventN1 = makeEventNode(event1);

eventInfo event2 = { "name2", "intro2", "rule2", "place2", "time2", 0,0,0, 2 };
eventNode *eventN2 = makeEventNode(event2);


refereeInfo referee13 = { "referee13", "refereeIntro13", "refereeContact13", 0, 13 };
refereeNode *refereeN13 = makeRefereeNode(referee13);

refereeInfo referee14 = { "referee14", "refereeIntro14", "refereeContact14", 0, 14 };
refereeNode *refereeN14 = makeRefereeNode(referee14);


eventList   *eventlist = initEventList();
	  
unitList *unitlist = initUnitList();

participantList *parlist = initParticipantList();

refereeList *refereelist = initRefereeList();








void addData() {





	addAccountNode(accountlist, accountN0);	/*addAccountNode(accountlist, accountN1);	addAccountNode(accountlist, accountN2);	addAccountNode(accountlist, accountN3);	addAccountNode(accountlist, accountN4);	addAccountNode(accountlist, accountN5);	addAccountNode(accountlist, accountN6);	addAccountNode(accountlist, accountN7);	addAccountNode(accountlist, accountN8);	addAccountNode(accountlist, accountN9);	addAccountNode(accountlist, accountN10);	addAccountNode(accountlist, accountN11);	addAccountNode(accountlist, accountN12);	addAccountNode(accountlist, accountN13);	addAccountNode(accountlist, accountN14);	
	addParticipantNode(parlist, parN1);
	addParticipantNode(parlist, parN2);
	addParticipantNode(parlist, parN3);
	addParticipantNode(parlist, parN4);
	addParticipantNode(parlist, parN5);
	addParticipantNode(parlist, parN6);
	addParticipantNode(parlist, parN7);
	addParticipantNode(parlist, parN8);
	addParticipantNode(parlist, parN9);
	addParticipantNode(parlist, parN10);

	addUnitNode(unitlist, unitN11);
	addUnitNode(unitlist, unitN12);

	addUnitParticipantByID(unitlist, 11, 1);
	addUnitParticipantByID(unitlist, 11, 2);
	addUnitParticipantByID(unitlist, 11, 3);
	addUnitParticipantByID(unitlist, 11, 4);
	addUnitParticipantByID(unitlist, 11, 5);
	addUnitParticipantByID(unitlist, 12, 6);
	addUnitParticipantByID(unitlist, 12, 7);
	addUnitParticipantByID(unitlist, 12, 8);
	addUnitParticipantByID(unitlist, 12, 9);
	addUnitParticipantByID(unitlist, 12, 10);

	addEventNode(eventlist, eventN1);
	addEventNode(eventlist, eventN2);

	addEventParticipantByID(eventlist, 1, 1);
	addEventParticipantByID(eventlist, 1, 2);
	addEventParticipantByID(eventlist, 1, 3);
	addEventParticipantByID(eventlist, 1, 4);
	addEventParticipantByID(eventlist, 1, 5);
	addEventParticipantByID(eventlist, 1, 6);

	addEventParticipantByID(eventlist, 2, 5);
	addEventParticipantByID(eventlist, 2, 6);
	addEventParticipantByID(eventlist, 2, 7);
	addEventParticipantByID(eventlist, 2, 8);
	addEventParticipantByID(eventlist, 2, 9);
	addEventParticipantByID(eventlist, 2, 10);

	addParticipantEventByID(parlist, 1, { 1, "", 0 });
	addParticipantEventByID(parlist, 2, { 1, "", 0 });
	addParticipantEventByID(parlist, 3, { 1, "", 0 });
	addParticipantEventByID(parlist, 4, { 1, "", 0 });
	addParticipantEventByID(parlist, 5, { 1, "", 0 });
	addParticipantEventByID(parlist, 6, { 1, "", 0 });

	addParticipantEventByID(parlist, 5, { 2, "", 0 });
	addParticipantEventByID(parlist, 6, { 2,"", 0 });
	addParticipantEventByID(parlist, 7, { 2, "", 0 });
	addParticipantEventByID(parlist, 8, { 2, "", 0 });
	addParticipantEventByID(parlist, 9, { 2, "", 0 });
	addParticipantEventByID(parlist, 10, { 2, "", 0 });


	addRefereeNode(refereelist, refereeN13);
	addRefereeNode(refereelist, refereeN14);

	addRefereeEventByID(refereelist, 13, 1);
	addRefereeEventByID(refereelist, 14, 2);*/

}


