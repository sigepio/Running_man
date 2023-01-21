#include "stdafx.h"
#include "BackGround.h"
#include "Title.h"
#include "Game.h"

BackGround::BackGround()
{
	//コメントアウトする。
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	//modelRender.Init("Assets/modelData/stage/stage.tkm");
	
	switch (STC)
	{
	case 1:
		modelRender.Init("Assets/modelData/stage01.tkm");
		break;
	case 2:
		modelRender.Init("Assets/modelData/stage02.tkm");
		break;
	case 3:
		modelRender.Init("Assets/modelData/stage03.tkm");
		break;
	case4:
		modelRender.Init("Assets/modelData/stage04.tkm");
		break;
	case 5:
		modelRender.Init("Assets/modelData/stage05.tkm");
		break;
	case 6:
		modelRender.Init("Assets/modelData/stage06.tkm");
		break;
	default:
		break;
	}
	
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

BackGround::~BackGround()
{

}

void BackGround::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}