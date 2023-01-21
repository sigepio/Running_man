#pragma once
class Player;

class Needl01 :public IGameObject
{
public:Needl01();
	  ~Needl01();
	  void Update();
	  void Render(RenderContext& rc);

	  ModelRender n01;
	  Vector3 n01_position;
	  Vector3 s01_position;
	  Vector3 r01_position;
	  Player* player;

	  float n01z=10.0;
};

