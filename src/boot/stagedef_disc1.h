#include "week1/week1.h"
#include "week2/week2.h"
#include "week3/week3.h"
#include "week4/week4.h"
#include "week6/week6.h"
#include "boo/boo.h"

static const StageDef stage_defs[StageId_Max] = {
	//Week 1
	{ //StageId_1_1 (Bopeebo)
		"\\WEEK1\\WEEK1.EXE;1", Week1_SetPtr,
		"\\WEEK1\\WEEK1_1.MUS;1"
	},
	{ //StageId_1_2 (Fresh)
		"\\WEEK1\\WEEK1.EXE;1", Week1_SetPtr,
		"\\WEEK1\\WEEK1_2.MUS;1"
	},
	{ //StageId_1_3 (Dadbattle)
		"\\WEEK1\\WEEK1.EXE;1", Week1_SetPtr,
		"\\WEEK1\\WEEK1_3.MUS;1"
	},
	{ //StageId_1_4 (Tutorial)
		"\\WEEK1\\WEEK1.EXE;1", Week1_SetPtr,
		"\\WEEK1\\WEEK1_4.MUS;1"
	},
	
	{ //StageId_2_1 (Spookeez)
		"\\WEEK2\\WEEK2.EXE;1", Week2_SetPtr,
		"\\WEEK2\\WEEK2_1.MUS;1"
	},
	{ //StageId_2_2 (South)
		"\\WEEK2\\WEEK2.EXE;1", Week2_SetPtr,
		"\\WEEK2\\WEEK2_2.MUS;1"
	},
	{ //StageId_2_3 (Monster)
		"\\WEEK2\\WEEK2.EXE;1", Week2_SetPtr,
		"\\WEEK2\\WEEK2_3.MUS;1"
	},
	
	{ //StageId_3_1 (Pico)
		"\\WEEK3\\WEEK3.EXE;1", Week3_SetPtr,
		"\\WEEK3\\WEEK3_1.MUS;1"
	},
	{ //StageId_3_2 (Philly Nice)
		"\\WEEK3\\WEEK3.EXE;1", Week3_SetPtr,
		"\\WEEK3\\WEEK3_2.MUS;1"
	},
	{ //StageId_3_3 (Blammed)
		"\\WEEK3\\WEEK3.EXE;1", Week3_SetPtr,
		"\\WEEK3\\WEEK3_3.MUS;1"
	},
	
	{ //StageId_4_1 (Satin Panties)
		"\\WEEK4\\WEEK4.EXE;1", Week4_SetPtr,
		"\\WEEK4\\WEEK4_1.MUS;1"
	},
	{ //StageId_4_2 (High)
		"\\WEEK4\\WEEK4.EXE;1", Week4_SetPtr,
		"\\WEEK4\\WEEK4_2.MUS;1"
	},
	{ //StageId_4_3 (MILF)
		"\\WEEK4\\WEEK4.EXE;1", Week4_SetPtr,
		"\\WEEK4\\WEEK4_3.MUS;1"
	},
	{ //StageId_4_4 (Test)
		"\\WEEK4\\WEEK4.EXE;1", Week4_SetPtr,
		"\\WEEK4\\WEEK4_4.MUS;1"
	},
	
	{ //StageId_5_1 (Cocoa)
		"\\WEEK5\\WEEK5.EXE;1", Week4_SetPtr,
		"\\WEEK5\\WEEK5_1.MUS;1"
	},
	{ //StageId_5_2 (Eggnog)
		"\\WEEK5\\WEEK5.EXE;1", Week4_SetPtr,
		"\\WEEK5\\WEEK5_2.MUS;1"
	},
	{ //StageId_5_3 (Winter Horrorland)
		"\\WEEK5\\WEEK5.EXE;1", Week4_SetPtr,
		"\\WEEK5\\WEEK5_3.MUS;1"
	},
	
	{ //StageId_6_1 (Senpai)
		"\\WEEK6\\WEEK6.EXE;1", Week6_SetPtr,
		"\\WEEK6\\WEEK6_1.MUS;1"
	},
	{ //StageId_6_2 (Roses)
		"\\WEEK6\\WEEK6.EXE;1", Week6_SetPtr,
		"\\WEEK6\\WEEK6_2.MUS;1"
	},
	{ //StageId_6_3 (Thorns)
		"\\WEEK6\\WEEK6.EXE;1", Week6_SetPtr,
		"\\WEEK6\\WEEK6_3.MUS;1"
	},
	{
		"\\BOO\\BOO.EXE;1", Boo_SetPtr,
		"\\BOO\\BOO.MUS;1"
	}
};
