#pragma once
class Stage05 :public IGameObject
{
public:
	Stage05();
	~Stage05();

	void Render(RenderContext& rc);

	ModelRender s05;
	PhysicsStaticObject physicsStaticObject;
};
