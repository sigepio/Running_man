#pragma once
class Stage01:public IGameObject
{
public:
	Stage01();
	~Stage01();

	void Render(RenderContext& rc);

	ModelRender s01;
	PhysicsStaticObject physicsStaticObject;
};

