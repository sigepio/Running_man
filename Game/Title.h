#pragma once
#include "sound/SoundSource.h"

//タイトル。
class BackGround;
class Title : public IGameObject
{
	public:
	Title();
	~Title();
	void Update();
	void Render(RenderContext& rc);
	
	SpriteRender spriteRender;
	SpriteRender selection_arrow;
	SpriteRender s_arrow;
	SoundSource* titleBGM;		
	int game_page=0;
	int selection = 0;
	int pose_selection = 0;
	int MAX = 5;
	int stage_selection = 0;
	float T_counter = 0;
	int selection_Confirm = 0;
	int title_time = 0;
	int bgm_state = 0;
};

