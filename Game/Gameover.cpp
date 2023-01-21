#include "stdafx.h"
#include "Gameover.h"
#include "stdafx.h"
#include "Title.h"

Gameover::Gameover() {
	//画像の読み込み
	spriteRender.Init("Assets/sprite/gameover_base.dds", 1920.0f, 1080.0f);
	miss[0].Init("Assets/sprite/miss_m.dds", 1920.0f, 1080.0f);
	miss[1].Init("Assets/sprite/miss_i.dds", 1920.0f, 1080.0f);
	miss[2].Init("Assets/sprite/miss_s01.dds", 1920.0f, 1080.0f);
	miss[3].Init("Assets/sprite/miss_s02.dds", 1920.0f, 1080.0f);
	//画像の初期位置
	miss_position[0].y = 1600.0f;
	miss_position[1].y = -1600.0f;
	miss_position[2].y = 1600.0f;
	miss_position[3].y = -1600.0f;
	for (int i = 0; i <= 3; i++) {
		miss[i].Update();
		miss[i].SetPosition(miss_position[i]);
	}
	
}

Gameover::~Gameover() {

}

void Gameover::Update() {
	//移動プログラム
	if (character_move_state == 0) {
		miss_position[0].y -= 50.0f;
		if (miss_position[0].y <= 300) {
			character_move_state++;
		}
	}
	else if (character_move_state == 1) {
		miss_position[1].y += 50.0f;
		if (miss_position[1].y >= 300) {
			character_move_state++;
		}
	}
	else if (character_move_state == 2) {
		miss_position[2].y -= 50.0f;
		if (miss_position[2].y <= 300) {
			character_move_state++;
		}
	}
	else if (character_move_state == 3) {
		miss_position[3].y += 50.0f;
		if (miss_position[3].y >= 300) {
			character_move_state++;
		}
	}

	//タイトルへ
	if (g_pad[0]->IsPress(enButtonA)&& character_move_state == 4) {
		title = NewGO<Title>(0,"title");
		DeleteGO(this);
	}

	for (int i = 0; i <= 3; i++) {
		miss[i].Update();
		miss[i].SetPosition(miss_position[i]);
	}


}

void Gameover::Render(RenderContext& rc) {
	spriteRender.Draw(rc);
	miss[0].Draw(rc);
	miss[1].Draw(rc);
	miss[2].Draw(rc);
	miss[3].Draw(rc);
}