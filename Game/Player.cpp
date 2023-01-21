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

//�X�V�����B
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

	//�n�ʂɕt���Ă�����B
	if (characterController.IsOnGround())
	{
		//�d�͂𖳂����B
		moveSpeed.y = 0.0f;
		//A�{�^���������ꂽ��B
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//�W�����v������B
			moveSpeed.y = 150.0f;
			
		}
	}
	//�n�ʂɕt���Ă��Ȃ�������B
	else
	{
		//�d�͂𔭐�������B
		moveSpeed.y -= 3.5f;
	}


	//�L�����N�^�[�R���g���[���[���g���č��W���ړ�������B
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//�G�`������ɍ��W��������B
	modelRender.SetPosition(position);
}

void Player::Rotation()
{
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)�B
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f&& characterController.IsOnGround())
	{
		//�L�����N�^�[�̕�����ς���B
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//�G�`������ɉ�]��������B
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

//�X�e�[�g�Ǘ��B
void Player::ManageState()
{
	//�n�ʂɕt���Ă��Ȃ�������B
	if (characterController.IsOnGround() == false)
	{
		//�X�e�[�g��1(�W�����v��)�ɂ���B
		playerState = 1;
		if (modelRender.IsPlayingAnimation() == false)
		{
			playerState = 4;
		}
		//������ManageState�̏������I��点��B
		return;
	}

	//�n�ʂɕt���Ă�����B
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)�B
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f && characterController.IsOnGround())
	{
		//�X�e�[�g��2(����)�ɂ���B
		if (playerState != 3) {
			playerState = 2;
		}
	}
	//x��z�̈ړ����x������������(�X�e�B�b�N�̓��͂�����������)�B
	else 
	{
		//�X�e�[�g��0(�ҋ@)�ɂ���B
		playerState = 0;
	}
}

//�A�j���[�V�����̍Đ��B
void Player::PlayAnimation()
{
	//switch���B
	switch (playerState) {
		//�v���C���[�X�e�[�g��0(�ҋ@)��������B
	case 0:
		//�ҋ@�A�j���[�V�������Đ�����B
		modelRender.PlayAnimation(enAnimationClip_Idle,0.3);
		break;
		//�v���C���[�X�e�[�g��1(�W�����v��)��������B
	case 1:
		//�W�����v�A�j���[�V�������Đ�����B
		modelRender.PlayAnimation(enAnimationClip_Jump,0.3);
		break;
		//�v���C���[�X�e�[�g��2(����)��������B
	case 2:
		//�����A�j���[�V�������Đ�����B
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

//�`�揈���B
void Player::Render(RenderContext& rc)
{

	modelRender.Draw(rc);
}