#include "Character.h"

Character::Character(const Vec2 & pos)
	:
	sprite("Images//link90x90.bmp"),
	pos(pos)
{
	for (int i = 0; i < (int)Sequence::StandingLeft; i++)
	{
		animations.emplace_back(Animation(90, 90 * i, 90, 90, 4, sprite, 0.15f));
	}
	for (int i = (int)Sequence::StandingLeft; i < (int)Sequence::Count; i++)
	{
		animations.emplace_back(Animation(0, 90 * (i - (int)Sequence::StandingLeft), 90, 90, 1, sprite, 0.15f));
	}
}

void Character::Update(float dt)
{
	pos += vel * dt;
	animations[(int)iCurSequence].Update(dt);
}

void Character::SetDirection(const Vec2 & dir)
{
	if (dir.x > 0.0f) {
		iCurSequence = Sequence::WalkingRight;
	}
	else if (dir.x < 0.0f) {
		iCurSequence = Sequence::WalkingLeft;
	}
	else if (dir.y > 0.0f) {
		iCurSequence = Sequence::WalkingDown;
	}
	else if (dir.y < 0.0f) {
		iCurSequence = Sequence::WalkingUp;
	}
	else {
		if (vel.x > 0) {
			iCurSequence = Sequence::StandingRight;
		}
		if (vel.x < 0) {
			iCurSequence = Sequence::StandingLeft;
		}
		if (vel.y > 0) {
			iCurSequence = Sequence::StandingDown;
		}
		if (vel.y < 0) {
			iCurSequence = Sequence::StandingUp;
		}
	}
	vel = dir * speed;
}

void Character::Draw(Graphics & gfx) const
{
	animations[(int)iCurSequence].Draw((Vei2)pos, gfx);
}
