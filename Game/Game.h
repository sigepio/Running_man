#pragma once
#include "sound/SoundSource.h"

class Title;
class Player;
class GameCamera;
class BackGround;
class Gameover;
class Stage01;
class Stage02;
class Stage03;
class Stage04;
class Stage05;
class Stage06;
class move_floor;
class GameClear;
class Needl01;

//Gameシーンを管理するクラス。
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//更新処理。
	void Update();
	void Render(RenderContext& rc);
	void InitSky();
	SkyCube* m_skyCube = nullptr;
	Title* title;
	Gameover* gameover;
	Player* player; //プレイヤー。
	Stage01* stage01;
	Stage02* stage02;
	Stage03* stage03;
	Stage04* stage04;
	Stage05* stage05;
	Stage06* stage06;
	Needl01* needl01;
	move_floor* move;
	GameCamera* gameCamera;			//ゲームカメラ。
	BackGround* backGround;
	SoundSource* gameBGM;		//ゲーム中のBGM。
	SpriteRender filter_render;
	LevelRender stage_level;
	GameClear* game_clear;
	int ks = 0;
	float time = 0.0;
	int select_stage=0;

	bool Start();
};

