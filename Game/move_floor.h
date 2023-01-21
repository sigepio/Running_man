#pragma once

class Player;
class move_floor :public IGameObject
{
public:
	move_floor();
	~move_floor();

	void Render(RenderContext& rc);
	void Update();
	Player *m_player;
	ModelRender mf;
	PhysicsStaticObject m_physicsStaticObject;
	CollisionObject *m_collisionObject;

	Vector3 position_move;
	int move_number = 0;
	float move_speed=-3;

	Vector3 COLLISION_HEIGHT = Vector3(0.0f, 5.0f, 0.0f);
	Vector3	COLLISION_SIZE = Vector3(300.0f, 5.0f, 300.0f);
	Vector3 firstPosition_move;
};

