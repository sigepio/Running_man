#pragma once
class Stage04 :public IGameObject
{
public:
	Stage04();
	~Stage04();

	void Render(RenderContext& rc);

	ModelRender s04;
	PhysicsStaticObject physicsStaticObject;
};
