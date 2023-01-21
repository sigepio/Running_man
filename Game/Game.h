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

//Game�V�[�����Ǘ�����N���X�B
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//�X�V�����B
	void Update();
	void Render(RenderContext& rc);
	void InitSky();
	SkyCube* m_skyCube = nullptr;
	Title* title;
	Gameover* gameover;
	Player* player; //�v���C���[�B
	Stage01* stage01;
	Stage02* stage02;
	Stage03* stage03;
	Stage04* stage04;
	Stage05* stage05;
	Stage06* stage06;
	Needl01* needl01;
	move_floor* move;
	GameCamera* gameCamera;			//�Q�[���J�����B
	BackGround* backGround;
	SoundSource* gameBGM;		//�Q�[������BGM�B
	SpriteRender filter_render;
	LevelRender stage_level;
	GameClear* game_clear;
	int ks = 0;
	float time = 0.0;
	int select_stage=0;

	bool Start();
};

