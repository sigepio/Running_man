#pragma once

//�v���C���[�N���X�B
class Player : public IGameObject
{
public:
	enum EnPlayerState
	{
		enPlayerState_Idle,
		enPlayerState_Walk,
		enPlayerState_Jump,
		enPlayerState_Run,
		enPlayerState_Fall,
	};
	Player();
	~Player();
	//�X�V�����B
	void Update();
	//�`�揈���B
	void Render(RenderContext& rc);
	//�ړ������B
	void Move();
	//��]�����B
	void Rotation();
	//�X�e�[�g�Ǘ��B
	void ManageState();
	//�A�j���[�V�����̍Đ��B
	void PlayAnimation();

	//�����o�ϐ��B
	ModelRender modelRender;	//���f�������_�\�B
	Vector3 position;			//���W�B
	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
		enAnimationClip_Fall,
	};
	FontRender fontRender;
	AnimationClip animationClips[enAnimationClip_Num];		//�A�j���[�V�����N���b�v�B
	CharacterController characterController;  //�L�����N�^�[�R���g���[���[�B
	Vector3 moveSpeed;		//�ړ����x�B
	Quaternion rotation;  //�N�H�[�^�j�I���B
	int playerState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
	int starCount = 0;	//�W�߂����̐����J�E���g����B
	int dash = 1;
	int Goal_check = 0;
	Vector3 Goal_position;
	Vector3 n01_position;
	int catch_stage = 0;
	float addmovespeed;
	SpriteRender count_down_Render;
	void AddMoveSpeed(const float& addMoveSpeed)
	{
		addmovespeed += addMoveSpeed;
	}
	CharacterController& GetCharacterController()
	{
		return characterController;
	}
};
