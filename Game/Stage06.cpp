#include "stdafx.h"
#include "Stage06.h"
Stage06::Stage06() {
	s06.Init("Assets/modelData/stage06.tkm");
	s06.Update();
	physicsStaticObject.CreateFromModel(s06.GetModel(), s06.GetModel().GetWorldMatrix());
}
Stage06::~Stage06()
{

}

void Stage06::Render(RenderContext& rc)
{
	s06.Draw(rc);
}