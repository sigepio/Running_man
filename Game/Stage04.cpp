#include "stdafx.h"
#include "Stage04.h"
Stage04::Stage04() {
	s04.Init("Assets/modelData/stage04.tkm");
	s04.Update();
	physicsStaticObject.CreateFromModel(s04.GetModel(), s04.GetModel().GetWorldMatrix());
}
Stage04::~Stage04()
{

}

void Stage04::Render(RenderContext& rc)
{
	s04.Draw(rc);
}