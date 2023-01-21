#pragma once
class Title;
class Gameover :public IGameObject
{
public:Gameover();
	  ~Gameover();
	  void Update();
	  void Render(RenderContext& rc);

	  Title* title;
	  SpriteRender spriteRender;
	  SpriteRender miss[4];
	  Vector3 miss_position[4];
	  int character_move_state = 0;
};

