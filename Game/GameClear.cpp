#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"
#include"Result_rank.h"

GameClear::GameClear() {
	
	spriteRender.Init("Assets/sprite/result.DDS", 1920.0f, 1080.0f);
	g_soundEngine->ResistWaveFileBank(10, "Assets/sound/dramroll.wav");
	dramroll = NewGO<SoundSource>(0);
	dramroll->Init(10);
	dramroll->Play(false);
	
}

GameClear::~GameClear() {
}

void GameClear::Update() {
	time_check = clear_time * 100;
	switch (play_stage)
	{
	case 1:
		if (time_check < 900)
			clear_rank = 1;
		else if (time_check < 1000)
			clear_rank = 2;
		else if (time_check < 1100)
			clear_rank = 3;
		else if (time_check >=1100)
			clear_rank = 4;
		break;
	case 2:
		if (time_check < 900)
			clear_rank = 1;
		else if (time_check < 1000)
			clear_rank = 2;
		else if (time_check < 1100)
			clear_rank = 3;
		else if (time_check >= 1100)
			clear_rank = 4;
		break;
	case 3:
		if (time_check < 900)
			clear_rank = 1;
		else if (time_check < 1000)
			clear_rank = 2;
		else if (time_check < 1100)
			clear_rank = 3;
		else if (time_check >= 1100)
			clear_rank = 4;
		break;
	case 4:
		if (time_check < 900)
			clear_rank = 1;
		else if (time_check < 1000)
			clear_rank = 2;
		else if (time_check < 1100)
			clear_rank = 3;
		else if (time_check >= 1100)
			clear_rank = 4;
		break;
	case 5:
		if (time_check < 1300)
			clear_rank = 1;
		else if (time_check < 1400)
			clear_rank = 2;
		else if (time_check < 1500)
			clear_rank = 3;
		else if (time_check >= 1600)
			clear_rank = 4;
		break;
	case 6:
		if (time_check < 6000)
			clear_rank = 1;
		else if (time_check < 7000)
			clear_rank = 2;
		else if (time_check < 8000)
			clear_rank = 3;
		else if (time_check >= 9000)
			clear_rank = 4;
		break;
	default:
		break;
	}

	if (dramroll->IsPlaying() == false) {
		wchar_t text[256];
		swprintf_s(text, 256, L"%.3f", clear_time);
		time_font.SetPosition({ -100.0f,-50.0f,0.0f });
		time_font.SetScale(2);
		time_font.SetText(text);
		next_state = 1;
		result_rank = NewGO<Result_rank>(0, "result_rank");
		result_rank->delivery_rank = clear_rank;
	}
	if (g_pad[0]->IsTrigger(enButtonA)&&next_state==1) {
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}
	
	
	spriteRender.Update();
	rank_Render.Update();
}

void GameClear::Render(RenderContext& rc) {
	spriteRender.Draw(rc);
	time_font.Draw(rc);
}
