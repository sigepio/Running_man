#include "stdafx.h"
#include "Needl01.h"
#include "Player.h"

Needl01::Needl01() {
	n01.Init("Assets/modelData/needle.tkm");

	s01_position.x = -1860.0f;
	s01_position.z = 1700.0f;
	r01_position.x = -1860.0f;
	r01_position.z = 4060.0f;

	n01_position = s01_position;


	auto collisionObject = NewGO<CollisionObject>(0);

	collisionObject->CreateBox(n01_position, Quaternion::Identity, Vector3(60.0f, 300.0f, 60.0f));
	collisionObject->SetName("needle01_collision");


	n01.SetPosition(s01_position);
	n01.Update();


}

Needl01::~Needl01() {

}

void Needl01::Update() {
	n01_position.z += n01z;
	if (n01_position.z<s01_position.z || n01_position.z>r01_position.z) {
		n01z *= -1;
	}
	n01.SetPosition(n01_position);

	n01.Update();
}

void Needl01::Render(RenderContext& rc) {
	n01.Draw(rc);
}