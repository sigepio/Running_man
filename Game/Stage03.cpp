#include "stdafx.h"
#include "Stage03.h"
Stage03::Stage03() {
	s03.Init("Assets/modelData/stage03.tkm");
	s03.Update();
	physicsStaticObject.CreateFromModel(s03.GetModel(), s03.GetModel().GetWorldMatrix());
}
Stage03::~Stage03()
{

}

void Stage03::Render(RenderContext& rc)
{
	s03.Draw(rc);
}