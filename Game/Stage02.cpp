#include "stdafx.h"
#include "Stage02.h"

Stage02::Stage02() {
	s02.Init("Assets/modelData/stage02.tkm");
	s02.Update();
	physicsStaticObject.CreateFromModel(s02.GetModel(), s02.GetModel().GetWorldMatrix());
}
Stage02::~Stage02()
{

}

void Stage02::Render(RenderContext& rc)
{
	s02.Draw(rc);
}