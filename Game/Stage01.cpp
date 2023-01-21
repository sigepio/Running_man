#include "stdafx.h"
#include "Stage01.h"
#include "Player.h"

Stage01::Stage01() {
	s01.Init("Assets/modelData/stage01.tkm");
	
	s01.Update();
	physicsStaticObject.CreateFromModel(s01.GetModel(), s01.GetModel().GetWorldMatrix());
	
}
Stage01::~Stage01()
{

}

void Stage01::Render(RenderContext& rc)
{
	s01.Draw(rc);
}