/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "boo.h"

#include "boot/stage.h"
#include "boot/archive.h"
#include "boot/main.h"
#include "boot/mem.h"

//Charts
static u8 boo_cht_boo_blitz[] = {
	#include "iso/chart/boo-blitz.json.cht.h"
};

static IO_Data boo_cht[][1] = {
	{
		(IO_Data)boo_cht_boo_blitz,
	}
};

//Characters
//Boyfriend
#include "character/bf.c"

//Daddy Dearest
#include "character/boo.c"

//Girlfriend
#define CHAR_GF_TUTORIAL
#include "character/gf.c"
#undef CHAR_GF_TUTORIAL

static fixed_t Char_GF_GetParallax(Char_GF *this)
{
	(void)this;
	return FIXED_DEC(7,10);
}

//Week 1 textures
static Gfx_Tex boo_tex_back0; //Stage and back
static Gfx_Tex boo_tex_back1; //Curtains

//Week 1 background functions
static void Boo_Load(void)
{
	//Load assets
	IO_Data overlay_data;
	
	Gfx_LoadTex(&stage.tex_hud0, overlay_data = Overlay_DataRead(), 0); Mem_Free(overlay_data); //hud0.tim
	Gfx_LoadTex(&stage.tex_hud1, overlay_data = Overlay_DataRead(), 0); Mem_Free(overlay_data); //hud1.tim
	
	Gfx_LoadTex(&boo_tex_back0, overlay_data = Overlay_DataRead(), 0); Mem_Free(overlay_data); //back0.tim
	
	//Load characters
	stage.player = Char_BF_New(FIXED_DEC(60,1), FIXED_DEC(100,1));
	if (stage.stage_id == StageId_1_4)
	{
		//GF as opponent
		stage.opponent = Char_GF_New(FIXED_DEC(0,1), FIXED_DEC(-10,1));
		stage.gf = NULL;
	}
	else
	{
		//Dad as opponent
		stage.opponent = Char_Boo_New(FIXED_DEC(-130,1), FIXED_DEC(0,1));
		stage.gf = Char_GF_New(FIXED_DEC(0,1), FIXED_DEC(-10,1));
	}
}

static void Boo_Tick()
{
	//Stage specific events
	if (stage.flag & STAGE_FLAG_JUST_STEP)
	{
		switch (stage.stage_id)
		{
			case StageId_1_1:
				//BF peace
				if (stage.song_step >= 0 && (stage.song_step & 0x1F) == 28)
					stage.player->set_anim(stage.player, PlayerAnim_Peace);
				break;
			case StageId_1_2:
				//GF bopping
				if (stage.stage_id == StageId_1_2)
				{
					if (stage.song_step >= 0 && stage.song_step < 0x1C0 && ((stage.song_step - 0x40) & 0x80) == 0)
						stage.gf_speed = 8;
					else
						stage.gf_speed = 4;
				}
				break;
			case StageId_1_4:
				//BF and GF peace + cheer
				stage.gf_speed = 8;
				if (stage.song_step > 64 && stage.song_step < 192 && (stage.song_step & 0x3F) == 60)
				{
					stage.player->set_anim(stage.player, PlayerAnim_Peace);
					stage.opponent->set_anim(stage.opponent, CharAnim_UpAlt);
				}
				break;
			default:
				break;
		}
	}
}

static void Boo_DrawBG()
{
	fixed_t fx, fy;

	RECT stage_src = {0, 0, 160, 81};
	RECT stage_dst = {
		0,
		56,
		SCREEN_WIDTH,
		162,
	};

	Gfx_DrawTex(&boo_tex_back0, &stage_src, &stage_dst, stage.camera.bzoom);
}

static IO_Data Boo_GetChart(void)
{
	return boo_cht[stage.stage_id - StageId_7_1][0];
}

static boolean Boo_LoadScreen(void)
{
	return false;
}

static boolean Boo_NextStage(void)
{
	switch (stage.stage_id)
	{
		case StageId_1_1: //Bopeebo
			stage.stage_id = StageId_1_2;
			return true;
		case StageId_1_2: //Fresh
			stage.stage_id = StageId_1_3;
			return true;
		case StageId_1_3: //Dadbattle
			return false;
		case StageId_1_4: //Tutorial
			return false;
		default:
			return false;
	}
}

void Boo_SetPtr(void)
{
	//Set pointers
	stageoverlay_load = Boo_Load;
	stageoverlay_tick = Boo_Tick;
	stageoverlay_drawbg = Boo_DrawBG;
	stageoverlay_drawmd = NULL;
	stageoverlay_drawfg = NULL;
	stageoverlay_free = NULL;
	stageoverlay_getchart = Boo_GetChart;
	stageoverlay_loadscreen = Boo_LoadScreen;
	stageoverlay_nextstage = Boo_NextStage;
}
