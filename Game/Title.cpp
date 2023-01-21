#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include <random>

//•Ï”‚Ì‰Šú‰»

Title::Title(){
	srand(time(NULL));
	pose_selection = rand()%MAX;
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/title_BGM.wav");
	//ƒQ[ƒ€’†‚ÌBGM‚ğÄ¶‚·‚éB
	titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(3);
	titleBGM->Play(true);

	stage_selection = 0;
	selection_Confirm = 0;
}

Title::~Title()
{
	DeleteGO(titleBGM);
}

void Title::Update()
{

	title_time++;
	if (selection == 0&&game_page==0) {
		selection_arrow.Init("Assets/sprite/MENU01.dds", 1920.0f, 1080.0f);
	}
	if (selection == 1 && game_page == 0) {
		selection_arrow.Init("Assets/sprite/MENU02.dds", 1920.0f, 1080.0f);
	}
	if (g_pad[0]->IsTrigger(enButtonDown) && selection == 0&&game_page==0) {
		selection = 1;
	}
	if (g_pad[0]->IsTrigger(enButtonUp) && selection == 1 && game_page == 0) {
		selection = 0;
	}
	if (game_page == 0) {
		if (pose_selection ==0)
			spriteRender.Init("Assets/sprite/MAIN_MENU.dds", 1920.0f, 1080.0f);
		else if(pose_selection==1)
			spriteRender.Init("Assets/sprite/MAIN_MENU02.dds", 1920.0f, 1080.0f);
		else if(pose_selection ==2)
			spriteRender.Init("Assets/sprite/MAIN_MENU03.dds", 1920.0f, 1080.0f);
		else if(pose_selection ==3)
			spriteRender.Init("Assets/sprite/MAIN_MENU04.dds", 1920.0f, 1080.0f);
		else if(pose_selection==4)
			spriteRender.Init("Assets/sprite/MAIN_MENU05.dds", 1920.0f, 1080.0f);
	}
	if (g_pad[0]->IsTrigger(enButtonA) && game_page == 0&&selection==0) {
		game_page = 1;
	}
	if (game_page == 1) {
		T_counter += 0.1;
		spriteRender.Init("Assets/sprite/home_base.DDS", 1920.0f, 1080.0f);
		if (stage_selection >= 0 && stage_selection <= 5) {
			if (g_pad[0]->IsTrigger(enButtonDown)&&stage_selection>=1) {
				stage_selection--;
			}
			else if (g_pad[0]->IsTrigger(enButtonUp)&&stage_selection<=4) {
				stage_selection++;
			}

			if(stage_selection==0)
				selection_arrow.Init("Assets/sprite/select_V2_01.dds", 1920.0f, 1080.0f);
			if (stage_selection == 1)
				selection_arrow.Init("Assets/sprite/select_V2_02.dds", 1920.0f, 1080.0f);
			if (stage_selection == 2)
				selection_arrow.Init("Assets/sprite/select_V2_03.dds", 1920.0f, 1080.0f);
			if (stage_selection == 3)
				selection_arrow.Init("Assets/sprite/select_V2_04.dds", 1920.0f, 1080.0f);
			if (stage_selection == 4)
				selection_arrow.Init("Assets/sprite/select_V2_05.dds", 1920.0f, 1080.0f);
			if (stage_selection == 5)
				selection_arrow.Init("Assets/sprite/select_V2_06.dds", 1920.0f, 1080.0f);
			if (g_pad[0]->IsTrigger(enButtonA) && T_counter > 1) {
				game_page = 3;
				T_counter = 0;
			}
		}
	}
	if (game_page == 3) {
		bgm_state = 2;
		selection_arrow.Init("Assets/sprite/Now Loading.DDS", 1920.0f, 1080.0f);
		T_counter += 0.1;
		titleBGM->Stop();
		if (T_counter > 2) {
			DeleteGO(titleBGM);
			Game* game = NewGO<Game>(0, "game");
			game->ks = stage_selection + 1;
			DeleteGO(this);
			
		}
	}
	
}

void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
	selection_arrow.Draw(rc);
	
}