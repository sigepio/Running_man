#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "Star.h"
#include "sound/SoundEngine.h"
#include "GameClear.h"
#include "Title.h"
#include "Stage01.h"
#include "Stage02.h"
#include "Stage03.h"
#include "Stage04.h"
#include "Stage05.h"
#include "Stage06.h"
#include "move_floor.h"
#include "Gameover.h"
#include "nature/SkyCube.h"
#include "Needl01.h"

void Game::InitSky()
{
	// 現在の空を破棄。
	DeleteGO(m_skyCube);
	m_skyCube = NewGO<SkyCube>(0, "skycube");

	m_skyCube->SetLuminance(1.0f);
	m_skyCube->SetScale(1000);
	m_skyCube->SetType((EnSkyCubeType)0);

	filter_render.Init("Assets/sprite/filter.dds", 1920.0f, 1080.0f);

	// 環境光の計算のためのIBLテクスチャをセットする。
	g_renderingEngine->SetAmbientByIBLTexture(m_skyCube->GetTextureFilePath(), 1.0f);
	// 環境日光の影響が分かりやすいように、ディレクションライトはオフに。
	g_renderingEngine->SetDirectionLight(0.2, g_vec3Zero, g_vec3Zero);
}


Game::Game()
{


	InitSky();
	SkyCube* m_skyCube = nullptr;

	g_engine->SetFrameRateMode(K2EngineLow::enFrameRateMode_Fix, 60);

	
	player = NewGO<Player>(1, "player");

	
	gameCamera = NewGO<GameCamera>(0, "gamecamera");


	//ゲーム中のBGMを読み込む。
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/play_BGM.wav");
	//ゲーム中のBGMを再生する。
	gameBGM = NewGO<SoundSource>(0);
	gameBGM->Init(1);
	gameBGM->Play(true);
}


Game::~Game()
{
	DeleteGO(player);
	DeleteGO(gameCamera);
	DeleteGO(gameBGM);
	DeleteGO(stage01);
	DeleteGO(stage02);
	DeleteGO(stage03);
	DeleteGO(stage04);
	DeleteGO(stage05);
	DeleteGO(stage06);
	DeleteGO(move);
	//DeleteGO(needl01);
}
bool Game::Start() {
	//背景のオブジェクトを作る。

	

	switch (ks)
	{
	case 1:
		stage01 = NewGO<Stage01>(0);
		player->catch_stage = 1;
		select_stage = 1;
		stage_level.Init("Assets/stage01.tkl", [&](LevelObjectData& objData) {
			if (objData.ForwardMatchName(L"Goal") == true) {
				player->Goal_position = objData.position;
			}
			return true;
			});
		break;
		
	case 2:
		stage02 = NewGO<Stage02>(0);
		player->catch_stage = 2;
		select_stage = 2;
		stage_level.Init("Assets/stage02.tkl", [&](LevelObjectData& objData) {
			if (objData.ForwardMatchName(L"Goal") == true) {
				player->Goal_position = objData.position;
			}
			return true;
			});
		break;
	case 3:
		stage03 = NewGO<Stage03>(0);
		player->catch_stage = 3;
		select_stage = 3;
		stage_level.Init("Assets/stage03.tkl", [&](LevelObjectData& objData) {
			if (objData.ForwardMatchName(L"Goal") == true) {
				player->Goal_position = objData.position;
			}
			return true;
			});
		break;
	case 4:
		stage04 = NewGO<Stage04>(0);
		move = NewGO<move_floor>(0);
		player->catch_stage = 4;
		select_stage = 4;
		stage_level.Init("Assets/stage04.tkl", [&](LevelObjectData& objData) {
			if (objData.ForwardMatchName(L"Goal") == true) {
				player->Goal_position = objData.position;
			}
			return true;
			});
		break;
	case 5:
		stage05 = NewGO<Stage05>(0);
		player->catch_stage = 5;
		select_stage = 5;
		stage_level.Init("Assets/stage05.tkl", [&](LevelObjectData& objData) {
			if (objData.ForwardMatchName(L"Goal") == true) {
				player->Goal_position = objData.position;
			}
			return true;
			});
		break;
	case 6:
		stage06 = NewGO<Stage06>(0);
		
		player->catch_stage = 6;
		select_stage = 6;
		stage_level.Init("Assets/stage06.tkl", [&](LevelObjectData& objData) {
			if (objData.ForwardMatchName(L"Goal") == true) {
				player->Goal_position = objData.position;
			}
			/*if (objData.ForwardMatchName(L"Goal") == true) {
				player->Goal_position = objData.position;
			}
			if (objData.ForwardMatchName(L"Goal") == true) {
				player->Goal_position = objData.position;
			}*/
			return true;
			});
		//needl01 = NewGO<Needl01>(0);
		break;
	default:
		break;
	}
		 
	return true;
}

//更新処理。
void Game::Update()
{
	int i = player->Goal_check;
	if (i < 1) {
		time += 0.017;
	}

	
	if (i == 1) {
		
		game_clear=NewGO<GameClear>(0, "gameclear");
		game_clear->clear_time = time;
		game_clear->play_stage = select_stage;
		DeleteGO(this);
	}
	if (i == 2) {
		NewGO<Gameover>(0, "gameover");
		DeleteGO(this);
	}
}

void Game::Render(RenderContext& rc) {
	//filter_render.Draw(rc);
}