#pragma once
class Stage02 :public IGameObject
{
public:
	Stage02();
	~Stage02();

	void Render(RenderContext& rc);

	ModelRender s02;
	PhysicsStaticObject physicsStaticObject;
};
