#pragma once

//プレイヤークラス。
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
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	//移動処理。
	void Move();
	//回転処理。
	void Rotation();
	//ステート管理。
	void ManageState();
	//アニメーションの再生。
	void PlayAnimation();

	//メンバ変数。
	ModelRender modelRender;	//モデルレンダ―。
	Vector3 position;			//座標。
	enum EnAnimationClip {		//アニメーション。
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
		enAnimationClip_Fall,
	};
	FontRender fontRender;
	AnimationClip animationClips[enAnimationClip_Num];		//アニメーションクリップ。
	CharacterController characterController;  //キャラクターコントローラー。
	Vector3 moveSpeed;		//移動速度。
	Quaternion rotation;  //クォータニオン。
	int playerState = 0;	//プレイヤーのステート(状態)を表す変数。
	int starCount = 0;	//集めた☆の数をカウントする。
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
