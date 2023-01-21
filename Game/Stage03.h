#pragma once
class Stage03 :public IGameObject
{
public:
	Stage03();
	~Stage03();

	void Render(RenderContext& rc);

	ModelRender s03;
	PhysicsStaticObject physicsStaticObject;
};
