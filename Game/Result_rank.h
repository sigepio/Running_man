#pragma once
class Result_rank :public IGameObject
{
public:Result_rank();
	  ~Result_rank();
	  void Update();
	  void Render(RenderContext& rc);

	  int delivery_rank;
	  SpriteRender rankRender;
};

