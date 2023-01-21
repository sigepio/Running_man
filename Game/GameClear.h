
#pragma once
class Result_rank;
class GameClear:public IGameObject
{
public:GameClear();
	  ~GameClear();
	  void Update();
	  void Render(RenderContext& rc);

	  Result_rank* result_rank;
	  SpriteRender spriteRender;
	  float clear_time = 0.0f;
	  SoundSource* dramroll = nullptr;
	  FontRender time_font;
	  int next_state = 0;
	  float count = 4.0f;
	  int play_stage = 0;
	  int time_check = 0;
	  int clear_rank = 0;
	  SpriteRender rank_Render;
};

