#include "stdafx.h"
#include "Stage05.h"
Stage05::Stage05() {
	s05.Init("Assets/modelData/stage05.tkm");
	s05.Update();
	physicsStaticObject.CreateFromModel(s05.GetModel(), s05.GetModel().GetWorldMatrix());
}
Stage05::~Stage05()
{

}

void Stage05::Render(RenderContext& rc)
{
	s05.Draw(rc);
}