#pragma once
class Game;

class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();

	void Render(RenderContext& rc);

	Game* b_game;

	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
	int STC = 0;
};

