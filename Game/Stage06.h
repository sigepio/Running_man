#pragma once
class Stage06 :public IGameObject
{
public:
	Stage06();
	~Stage06();

	void Render(RenderContext& rc);

	ModelRender s06;
	PhysicsStaticObject physicsStaticObject;
};
