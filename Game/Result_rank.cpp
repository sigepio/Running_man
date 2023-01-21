#include "stdafx.h"
#include "Result_rank.h"
Result_rank::Result_rank() {
	
}
Result_rank::~Result_rank() {

}

void Result_rank::Update() {
	switch (delivery_rank)
	{
	case 1:
		rankRender.Init("Assets/sprite/rank_s.DDS", 1920.0f, 1080.0f);
		break;
	case 2:
		rankRender.Init("Assets/sprite/rank_a.DDS", 1920.0f, 1080.0f);
		break;
	case 3:
		rankRender.Init("Assets/sprite/rank_b.DDS", 1920.0f, 1080.0f);
		break;
	case 4:
		rankRender.Init("Assets/sprite/rank_c.DDS", 1920.0f, 1080.0f);
		break;
	default:
		break;
	}
	if (g_pad[0]->IsTrigger(enButtonA)) {
		DeleteGO(this);
	}

	rankRender.Update();
}
void Result_rank::Render(RenderContext& rc) {
	rankRender.Draw(rc);
}