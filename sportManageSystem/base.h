
typedef struct Manager{
	char name[200];
	char contact[200];
	char intro[2000];
};


typedef struct sportInfo{
	char name[200];
	char host[200];
	char time[200];
	char place[200];
	char introduction[2000];
};


typedef struct size{
	int eventSize;

	int accountSize;

	int unitSize;

	int refereeSize;

	int participantSize;
};

int accountSet = 14;

int eventSet = 2;


int flag = 0;

size s = { 0, 0, 0, 0, 0 };

Manager m = { "", "", "" };

sportInfo sInfo = { "", "", "", "", "" };