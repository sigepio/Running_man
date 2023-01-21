#include "stdafx.h"
#include "move_floor.h"
#include "Player.h"
move_floor::move_floor() {
	mf.Init("Assets/modelData/move_floor.tkm");

	mf.Update();
	m_physicsStaticObject.CreateFromModel(mf.GetModel(), mf.GetModel().GetWorldMatrix());

	position_move.z = 2500.0f;
	m_collisionObject = NewGO<CollisionObject>(0, "collisionObject");
	m_player = FindGO<Player>("player");

	m_collisionObject->CreateBox(
		position_move,
		Quaternion::Identity,
		COLLISION_SIZE
	);
	m_collisionObject->SetIsEnableAutoDelete(false);
}

move_floor::~move_floor() {
	DeleteGO(m_collisionObject);
}

void move_floor::Update() {
	
	move_number++;





	if (move_number % 550 == 0) {
		move_speed *= -1;
	}

	position_move.z += move_speed;


	m_physicsStaticObject.SetPosition(position_move);
	Vector3 cpm;
	cpm = position_move;
	cpm.y += 30;
	m_collisionObject->SetPosition(cpm);
	mf.SetPosition(position_move);

	if (m_collisionObject->IsHit(m_player->GetCharacterController()) == true)
	{
		//動く床の移動速度をキャラクターの移動速度に加算。
		m_player->AddMoveSpeed(move_speed);
	}
	else {
		m_player->addmovespeed = 0.0f;
	}

	mf.Update();
}

void move_floor::Render(RenderContext& rc) {
	mf.Draw(rc);
}