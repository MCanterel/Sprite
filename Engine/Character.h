#pragma once
#include "Animation.h"
#include "Vec2.h"
#include "Mouse.h"

class Character
{
public:
	Character(const Vec2& pos);
	void Update(float dt);
	void SetDirection(const Vec2& dir);
	void SetDirection(const Mouse& mouse);

	void Draw(Graphics& gfx) const;
private:
	enum class Sequence {
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		Count
	};
private:
	Surface sprite;
	Vec2 pos;
	Vec2 vel = { 0.0f, 0.0f };
	std::vector<Animation> animations;
	Sequence iCurSequence = Sequence::StandingDown;
	float speed = 120.0f;
	int width;
	int height;
};

