#include "stdafx.h"
#include "Player.h"
#include "Needl01.h"

Player::Player()
{
	
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle_w.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk_w.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump_w.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	animationClips[enAnimationClip_Run].Load("Assets/animData/run_w.tka");
	animationClips[enAnimationClip_Run].SetLoopFlag(true);
	//animationClips[enAnimationClip_Fall].Load("Assets/animData/fall.tka");
	//animationClips[enAnimationClip_Fall].SetLoopFlag(true);
	
	modelRender.Init("Assets/modelData/by_bob.tkm", animationClips, enAnimationClip_Num);

	position.x = 0.0f;
	position.y = 100.0f;
	position.z = 0.0f;
	characterController.Init(25.0f, 75.0f, position);
}

Player::~Player()
{

}

//更新処理。
void Player::Update()
{


	modelRender.SetPosition(position);

	
	Move();

	
	Rotation();

	
	ManageState();

	
	PlayAnimation();

	
	modelRender.Update();

	Vector3 diff = position - Goal_position;

	if (position.y <= -500.0) {
		Goal_check = 2;
	}


	if (diff.Length() <= 200.0f) {
		Goal_check = 1;
	}

	const auto& collisions = g_collisionObjectManager->FindCollisionObjects("needle01_collision");
	for (auto collision:collisions) {
		if (collision->IsHit(characterController)) {
			Goal_check = 2;
		}
	}

}

void Player::Move()
{
	
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	
	forward.y = 0.0f;
	right.y = 0.0f;

	
	right *= stickL.x * 120.0f*dash;
	forward *= stickL.y * 120.0f*dash;

	moveSpeed.z += addmovespeed;
	moveSpeed += right + forward;

	//地面に付いていたら。
	if (characterController.IsOnGround())
	{
		//重力を無くす。
		moveSpeed.y = 0.0f;
		//Aボタンが押されたら。
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//ジャンプさせる。
			moveSpeed.y = 150.0f;
			
		}
	}
	//地面に付いていなかったら。
	else
	{
		//重力を発生させる。
		moveSpeed.y -= 3.5f;
	}


	//キャラクターコントローラーを使って座標を移動させる。
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//絵描きさんに座標を教える。
	modelRender.SetPosition(position);
}

void Player::Rotation()
{
	//xかzの移動速度があったら(スティックの入力があったら)。
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f&& characterController.IsOnGround())
	{
		//キャラクターの方向を変える。
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//絵描きさんに回転を教える。
		modelRender.SetRotation(rotation);
		if (g_pad[0]->IsPress(enButtonX)) {
			playerState = 3;
			dash = 3;
		}
		else {
			playerState = 2;
			dash = 1;
		}
	}
}

//ステート管理。
void Player::ManageState()
{
	//地面に付いていなかったら。
	if (characterController.IsOnGround() == false)
	{
		//ステートを1(ジャンプ中)にする。
		playerState = 1;
		if (modelRender.IsPlayingAnimation() == false)
		{
			playerState = 4;
		}
		//ここでManageStateの処理を終わらせる。
		return;
	}

	//地面に付いていたら。
	//xかzの移動速度があったら(スティックの入力があったら)。
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f && characterController.IsOnGround())
	{
		//ステートを2(歩き)にする。
		if (playerState != 3) {
			playerState = 2;
		}
	}
	//xとzの移動速度が無かったら(スティックの入力が無かったら)。
	else 
	{
		//ステートを0(待機)にする。
		playerState = 0;
	}
}

//アニメーションの再生。
void Player::PlayAnimation()
{
	//switch文。
	switch (playerState) {
		//プレイヤーステートが0(待機)だったら。
	case 0:
		//待機アニメーションを再生する。
		modelRender.PlayAnimation(enAnimationClip_Idle,0.3);
		break;
		//プレイヤーステートが1(ジャンプ中)だったら。
	case 1:
		//ジャンプアニメーションを再生する。
		modelRender.PlayAnimation(enAnimationClip_Jump,0.3);
		break;
		//プレイヤーステートが2(歩き)だったら。
	case 2:
		//歩きアニメーションを再生する。
		modelRender.PlayAnimation(enAnimationClip_Walk, 0.3);
		break;
	case 3:
		modelRender.PlayAnimation(enAnimationClip_Run, 0.3);
		break;
	case 4:
		modelRender.PlayAnimation(enAnimationClip_Fall, 0.3);
		break;
	}
}

//描画処理。
void Player::Render(RenderContext& rc)
{

	modelRender.Draw(rc);
}